from solution import Solution

if __name__ == "__main__":
    solution = Solution()
    with open("in", "r") as infile:
        for line in infile.read().split("\n"):
            print(solution.closeStrings(*line.split()))