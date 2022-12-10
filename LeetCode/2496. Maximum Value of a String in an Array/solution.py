def length_of_str(line):
    return int(line) if line.isnumeric() else len(line)


class Solution:
    def maximumValue(self, strs: List[str]) -> int:
        return max(list(map(length_of_str, strs)))