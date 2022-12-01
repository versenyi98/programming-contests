from abc import ABC, abstractmethod


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
