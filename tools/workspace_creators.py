import json
import os
import sys

from pathlib import Path
from abc import ABC, abstractmethod

from problem_scrapers import KattisProblemScraper, AoCProblemScraper


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


class NoWorkspaceCreator(WorkspaceCreator):
    def create_directory(self):
        pass

    def write_testcases(self):
        pass

    def write_info_json(self):
        pass


class LeetCodeWorkspaceCreator(WorkspaceCreator):
    def __init__(self, problem_name):
        super().__init__(None)
        self.leetcode_dir = self.base_path / "LeetCode"
        self.problem_name = problem_name
        self.problem_dir = None

    def create_directory(self):
        problem_id, problem_name = self.problem_name.split('.')
        problem_dir = "0" * (4 - len(problem_id)) + problem_id + "." + problem_name

        self.problem_dir = self.leetcode_dir / problem_dir
        if not os.path.exists(self.problem_dir):
            os.mkdir(self.problem_dir)

    def write_testcases(self):
        pass

    def write_info_json(self):
        problem_id, problem_name = self.problem_name.split('.')

        url = f"https://leetcode.com/problems/{problem_name.strip().lower().replace(' ', '-')}/"

        info = {
            "Name": problem_name.strip(),
            "URL": url,
            "ID": problem_id.strip()
        }

        with open(self.problem_dir / "info.json", "w") as json_handle:
            json.dump(info, json_handle, indent=4)


class AocWorkspaceCreator(WorkspaceCreator):
    def __init__(self, url):
        super().__init__(url)
        self.problem_scraper = AoCProblemScraper(url)
        self.kattis_dir = self.base_path / "Advent of Code"
        self.problem_dir = None

    def create_directory(self):
        year_dir = self.url.split('/')[-3]
        problem_dir = self.problem_scraper.get_problem_name()
        problem_dir = problem_dir.replace("-", "").strip().replace(":", " -")
        problem_dir_split = problem_dir.split()
        if len(problem_dir_split[1]) == 1:
            problem_dir_split[1] = "0" + problem_dir_split[1]
        problem_dir = " ".join(problem_dir_split)
        self.problem_dir = self.kattis_dir / year_dir / problem_dir

        if not os.path.exists(self.problem_dir):
            os.mkdir(self.problem_dir)

    def write_testcases(self):
        pass

    def write_info_json(self):
        problem_name = self.problem_scraper.get_problem_name()
        problem_name = problem_name.replace("-", "").split(":")[-1].strip()

        year = self.url.split('/')[-3]
        day = self.url.split('/')[-1]

        info = {
            "Name": problem_name,
            "URL": self.url,
            "Year": year,
            "Day": day
        }

        with open(self.problem_dir / "info.json", "w") as json_handle:
            json.dump(info, json_handle, indent=4)


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