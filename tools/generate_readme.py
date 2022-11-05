import os
import json

from urllib.parse import quote
from pathlib import Path

import constants


class KattisHeaderProvider:
    def get_header(self):
        header = "| ID | Link to description | Link to solution |\n" + \
                    "|:---|:---|:---:|\n"

        return header


class KattisEntryBuilder:
    def __init__(self, data):
        self.entry = ""
        self.data = data

    def build(self):
        name = self.data["Name"]
        problem_id = self.data["ID"]
        url = self.data["URL"]

        path_to_solution = f"{constants.GITHUB_MASTER_BRANCH}/Kattis/{quote(name)}"

        self.entry += f"| {problem_id} | [{name}]({url}) | [Solution]({path_to_solution})|\n"

    def get(self):
        return self.entry


class ReadmeWriter:
    def __init__(self):
        self.generators = []

    def write(self, text):
        for generator in self.generators:
            generator.write(text)

    def add_generator(self, generator):
        self.generators.append(generator)

    def remove_generator(self, generator):
        self.generators.remove(generator)


class ReadmeGenerator:
    def __init__(self, file_name, header_provider):
        self.file_name = file_name
        self.writer = None
        self.header_provider = header_provider

    def set_writer(self, writer):
        if self.writer:
            self.writer.remove_generator(self)

        self.writer = writer
        self.writer.add_generator(self)

    def __enter__(self):
        self.file = open(self.file_name, 'w')
        self.file.write(self.header_provider.get_header())
        return self

    def __exit__(self, exc_type, exc_value, tb):
        self.writer.remove_generator(self)
        self.file.close()

    def write(self, text):
        self.file.write(text)


def generate_table_for_uva(directory: Path) -> str:
    buffer = "| ID | UVa Online Judge | External | Link to solution |\n"
    buffer += "|:---|:---|:---|:---:|\n"

    problem_directories = sorted(os.listdir(directory))

    for problem_directory in problem_directories:

        with open(directory / str(problem_directory) / "info.json") as info_json:
            data = json.load(info_json)

        name = data["Name"]
        problem_id = data["ID"]
        uva_url = data["Online Judge URL"]
        external_url = data["External URL"]

        path_in_repo = f"./{directory.stem}/{problem_directory}"
        buffer += f"| {problem_id} | [{name}]({uva_url}) | [PDF]({external_url}) | [Solution]({quote(path_in_repo)})|\n"

    return buffer


def main():
    base_path = Path(__file__).parent.parent
    kattis_path = base_path / "Kattis"
    kattis_content = sorted(os.listdir(kattis_path))

    readme_writer = ReadmeWriter()

    with ReadmeGenerator(kattis_path / "README.md", KattisHeaderProvider()) as kattis_generator:
        kattis_generator.set_writer(readme_writer)

        for element in kattis_content:
            task_path = kattis_path / str(element)

            if not os.path.isdir(task_path):
                continue

            with ReadmeGenerator(task_path / "README.md", KattisHeaderProvider()) as task_generator:
                task_generator.set_writer(readme_writer)

                task_info_path = task_path / "info.json"

                with open(task_info_path, "r") as task_info_handle:
                    task_data = json.load(task_info_handle)

                entry_builder = KattisEntryBuilder(task_data)
                entry_builder.build()
                entry = entry_builder.get()

                readme_writer.write(entry)


if __name__ == "__main__":
    main()
