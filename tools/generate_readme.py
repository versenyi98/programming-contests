import os
import json

from abc import ABC, abstractmethod
from urllib.parse import quote
from pathlib import Path

import constants


class HeaderProvider(ABC):
    @abstractmethod
    def get(self):
        pass


class KattisHeaderProvider(HeaderProvider):
    def get(self):
        header = "| ID | Link to description | Link to solution |\n" + \
                    "|:---|:---|:---:|\n"

        return header


class UVaHeaderProvider(HeaderProvider):
    def get(self):
        header = "| ID | UVa Online Judge | External | Link to solution |\n" + \
                    "|:---|:---|:---|:---:|\n"

        return header


class EntryBuilder(ABC):
    def __init__(self):
        self.entry = ""

    def get(self):
        return self.entry

    @abstractmethod
    def build(self, data):
        pass


class KattisEntryBuilder(EntryBuilder):
    def build(self, data):
        name = data["Name"]
        problem_id = data["ID"]
        url = data["URL"]

        path_to_solution = f"{constants.GITHUB_MASTER_BRANCH}/Kattis/{quote(name)}"

        self.entry = f"| {problem_id} | [{name}]({url}) | [Solution]({path_to_solution})|\n"
        return self


class UVaEntryBuilder(EntryBuilder):
    def build(self, data):
        name = data["Name"]
        id = data["ID"]
        url = data["Online Judge URL"]
        external_url = data["External URL"]

        path_to_solution = f"{constants.GITHUB_MASTER_BRANCH}/{quote(f'UVa Online Judge/{id} - {name}')}"

        self.entry = f"| {id} | [{name}]({url}) | [PDF]({external_url}) | [Solution]({path_to_solution})|\n"
        return self


class ReadmeContentProvider(ABC):
    @abstractmethod
    def __init__(self):
        self.entry_builder = None
        self.header_provider = None

    def get_header(self):
        return self.header_provider.get()

    def get_entry(self, data):
        return self.entry_builder.build(data).get()


class KattisReadmeContentProvider(ReadmeContentProvider):
    def __init__(self):
        self.entry_builder = KattisEntryBuilder()
        self.header_provider = KattisHeaderProvider()


class UVaReadmeContentProvider(ReadmeContentProvider):
    def __init__(self):
        self.entry_builder = UVaEntryBuilder()
        self.header_provider = UVaHeaderProvider()


class ReadmeAppender:
    def __init__(self):
        self.writers = []

    def write(self, text):
        for writer in self.writers:
            writer.write(text)

    def add_writer(self, writer):
        self.writers.append(writer)

    def remove_writer(self, writer):
        self.writers.remove(writer)


class ReadmeWriter:
    def __init__(self, path, content_provider):
        self.readme_appender = None
        self.content_provider = content_provider
        self.path = path

    def set_readme_appender(self, readme_appender):
        if self.readme_appender:
            self.readme_appender.remove_generator(self)

        self.readme_appender = readme_appender
        self.readme_appender.add_writer(self)

    def __enter__(self):
        print(f"Opening {self.path}")
        self.file = open(self.path, 'w')
        self.file.write(self.content_provider.get_header())
        return self

    def __exit__(self, exc_type, exc_value, tb):
        print(f"Closing {self.path}")
        self.readme_appender.remove_writer(self)
        self.file.close()

    def write(self, text):
        print(f"\tWrite into {self.path}")
        self.file.write(text)


class RecursiveReadmeWriter:
    def __init__(self, path, content_provider):
        self.path = path
        self.content_provider = content_provider
        self.readme_appender = ReadmeAppender()

    def generate(self):

        def generate_recursive(path: Path):
            print(f"Generate recursive: {path}")
            with ReadmeWriter(path / "README.md", self.content_provider) as readme_handle:
                readme_handle.set_readme_appender(self.readme_appender)

                info_json = path / "info.json"
                if info_json.exists():
                    with open(info_json, "r") as json_file:
                        data = json.load(json_file)
                    entry = self.content_provider.get_entry(data)
                    self.readme_appender.write(entry)

                content = sorted(os.listdir(path))
                for element in content:
                    element_path = path / str(element)
                    if os.path.isdir(element_path):
                        generate_recursive(element_path)

        return generate_recursive(self.path)


def generate_readme(path, content_provider):
    readme_writer = RecursiveReadmeWriter(path, content_provider)
    readme_writer.generate()


def main():
    base_path = Path(__file__).parent.parent
    generate_readme(base_path / "Kattis", KattisReadmeContentProvider())
    generate_readme(base_path / "UVa Online Judge", UVaReadmeContentProvider())


if __name__ == "__main__":
    main()
