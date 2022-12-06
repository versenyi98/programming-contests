import argparse

import readme_generator
from workspace_creators import NoWorkspaceCreator, AocWorkspaceCreator,\
    KattisWorkspaceCreator, LeetCodeWorkspaceCreator


def prepare_workspace_for_problem(url: str):
    workspace_creator = NoWorkspaceCreator(url)

    if url.find("kattis") != -1:
        workspace_creator = KattisWorkspaceCreator(url)
    elif url.find("adventofcode") != -1:
        workspace_creator = AocWorkspaceCreator(url)
    elif url.find(". ") != -1:
        workspace_creator = LeetCodeWorkspaceCreator(url)

    workspace_creator.create_workspace()


def main():
    arg_parser = argparse.ArgumentParser()
    arg_parser.add_argument("url")

    args = arg_parser.parse_args()

    prepare_workspace_for_problem(args.url)
    readme_generator.main()


if __name__ == "__main__":
    main()
