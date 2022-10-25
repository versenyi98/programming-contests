import os
import json
import urllib

from pathlib import Path


def generate_table_for_kattis(directory: Path) -> str:
    buffer = "| ID | Link to description | Link to solution |\n"
    buffer += "|:---|:---|:---:|\n"

    problem_directories = os.listdir(directory)

    for problem_directory in problem_directories:

        with open(directory / problem_directory / "info.json") as info_json:
            data = json.load(info_json)

        name = data["Name"]
        problem_id = data["ID"]
        url = data["URL"]

        buffer += f"| {problem_id} | [{name}]({url}) | [Solution](./Kattis/{urllib.parse.quote(name)})|\n"

    return buffer


def main():
    repo_path = Path(__file__).parent.parent

    kattis_table_buffer = generate_table_for_kattis(repo_path / "Kattis")

    with open(repo_path / "README.md", "w") as readme_handle:
        readme_handle.write("## Kattis\n")
        readme_handle.write(kattis_table_buffer)


if __name__ == "__main__":
    main()
