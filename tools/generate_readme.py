import os
import json

from urllib.parse import quote
from pathlib import Path


def generate_table_for_uva(directory: Path) -> str:
    buffer = "| ID | UVa Online Judge | External | Link to solution |\n"
    buffer += "|:---|:---|:---|:---:|\n"

    problem_directories = os.listdir(directory)

    for problem_directory in problem_directories:

        with open(directory / str(problem_directory) / "info.json") as info_json:
            data = json.load(info_json)

        name = data["Name"]
        problem_id = data["ID"]
        uva_url = data["Online Judge URL"]
        external_url = data["External URL"]

        path_in_repo = f"./{directory.stem}/{problem_directory}/{problem_id} - {name}"
        buffer += f"| {problem_id} | [{name}]({uva_url}) | [PDF]({external_url}) | [Solution]({quote(path_in_repo)})|\n"

    return buffer


def generate_table_for_kattis(directory: Path) -> str:
    buffer = "| ID | Link to description | Link to solution |\n"
    buffer += "|:---|:---|:---:|\n"

    problem_directories = os.listdir(directory)

    for problem_directory in problem_directories:

        with open(directory / str(problem_directory) / "info.json") as info_json:
            data = json.load(info_json)

        name = data["Name"]
        problem_id = data["ID"]
        url = data["URL"]

        buffer += f"| {problem_id} | [{name}]({url}) | [Solution](./Kattis/{quote(name)})|\n"

    return buffer


def main():
    repo_path = Path(__file__).parent.parent

    kattis_table_buffer = generate_table_for_kattis(repo_path / "Kattis")
    uva_table_buffer = generate_table_for_uva(repo_path / "UVa Online Judge")

    kattis_readme_content = ["## Kattis\n", kattis_table_buffer]
    uva_readme_content = ["## UVa Online Judge\n", uva_table_buffer]

    with open(repo_path / "README.md", "w", encoding="utf-8") as readme_handle:
        for line in kattis_readme_content:
            readme_handle.write(line)
        for line in uva_readme_content:
            readme_handle.write(line)


if __name__ == "__main__":
    main()
