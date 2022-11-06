import argparse
import json
import os
import requests

from pathlib import Path
from abc import ABC, abstractmethod
from lxml import etree

import readme_generator


class ProblemScraper(ABC):

    def __init__(self, url):
        self.url = url
        result = requests.get(url)
        self.tree = etree.HTML(result.text)

    @abstractmethod
    def get_testcases(self):
        pass

    @abstractmethod
    def get_problem_name(self):
        pass


class KattisProblemScraper(ProblemScraper):

    def get_testcases(self):
        xpath_expression = "//table/tr[2]/td[1]/pre"
        elements = self.tree.xpath(xpath_expression)

        return [element.text for element in elements]

    def get_problem_name(self):
        xpath_expression = "//h1"
        return self.tree.xpath(xpath_expression)[0].text


class WorkspaceCreator(ABC):

    def __init__(self, url):
        self.problem_scraper = None
        self.base_path = Path(__file__).absolute().parent.parent
        self.url = url

    def create_workspace(self):
        self.create_directory()
        self.write_testcases()
        self.write_info_json()

    @abstractmethod
    def create_directory(self):
        pass

    @abstractmethod
    def write_testcases(self):
        pass

    @abstractmethod
    def write_info_json(self):
        pass


class KattisWorkspaceCreator(WorkspaceCreator):

    def __init__(self, url):
        super().__init__(url)
        self.problem_scraper = KattisProblemScraper(url)
        self.kattis_dir = self.base_path / "Kattis"
        self.problem_dir = None

    def create_directory(self):
        self.problem_dir = self.kattis_dir / self.problem_scraper.get_problem_name()
        if not os.path.exists(self.problem_dir):
            os.mkdir(self.problem_dir)

    def write_testcases(self):
        testcases = self.problem_scraper.get_testcases()

        for idx, testcase in enumerate(testcases):
            file_path = self.problem_dir / f"in{idx}"
            with open(file_path, "w") as file_handle:
                file_handle.write(testcase)

    def write_info_json(self):
        name = self.problem_scraper.get_problem_name()
        id = self.url.split('/')[-1]

        info = {
            "Name": name,
            "URL": self.url,
            "ID": id
        }

        with open(self.problem_dir / "info.json", "w") as json_handle:
            json.dump(info, json_handle, indent=4)


def prepare_workspace_for_problem(url: str):
    if url.find("kattis") != -1:
        workspace_creator = KattisWorkspaceCreator(url)
        workspace_creator.create_workspace()


def main():
    arg_parser = argparse.ArgumentParser()
    arg_parser.add_argument("url")

    args = arg_parser.parse_args()

    prepare_workspace_for_problem(args.url)
    readme_generator.main()


if __name__ == "__main__":
    main()
