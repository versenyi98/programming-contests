import constants

from urllib.parse import quote
from abc import ABC, abstractmethod


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