import os
from random import sample
import requests

from lxml import etree

def get_changed_files():
    f = open("changed_files.txt", "r")
    changed_files = f.read().split('\n')
    f.close()

    return changed_files

def get_changed_kattis_folders(changed_files):
    changed_folders = set()

    for file in changed_files:
        # check if is in Kattis folder
        if file.find('Kattis') < 0:
            continue

        file = file[file.find('/') + 1:-1]
        file = file[:file.find('/')]
        changed_folders.add(file)

    return changed_folders

def get_sample_from_readme(readme):
    readme_content = readme.read().strip()

    r = requests.get(readme_content)

    dom = etree.HTML(r.content)

    sample_input = dom.xpath('//table[@summary="sample data"]/tr[2]/td[1]/pre/text()')
    sample_output = dom.xpath('//table[@summary="sample data"]/tr[2]/td[2]/pre/text()')

    return sample_input, sample_output

def save_sample_input(sample):
    for idx, input_ in enumerate(sample):
        f = open(f"in{idx}", "w")
        f.write(input_)
        f.close()

def get_output(folder, num_of_samples, cpp_path):
    os.system(f"g++ {cpp_path} -o main")

    results = []

    for idx in range(num_of_samples):
        os.system(f"./main < in{idx} > out{idx}")

        f = open(f"out{idx}", "r")
        results.append(f.read())
        f.close()

    return results

def main():
    changed_files = get_changed_files()

    changed_folders = get_changed_kattis_folders(changed_files)

    for folder in changed_folders:
        readme_path = "Kattis/" + folder + "/README.md"
        if not os.path.exists(readme_path):
            continue

        readme = open(readme_path, "r")
        sample_input, sample_output = get_sample_from_readme(readme)

        save_sample_input(sample_input)

        output = []

        folder_escaped = folder.replace(' ','\ ')
        cpp_path = f"Kattis/{folder}/main.cpp"
        cpp_path_escaped = f"Kattis/{folder_escaped}/main.cpp"

        if os.path.exists(cpp_path):
            output = get_output(folder, len(sample_input), cpp_path_escaped)

        print(f'Testing "{folder}"')

        num_of_samples = len(sample_output)

        for i in range(num_of_samples):
            if output[i] != sample_output[i]:
                print(f"Test #{i + 1}: FAILED")
                raise AssertionError ("Test failed")
            else:
                print(f"Test #{i + 1}: PASSED")
        assert output == sample_output

if __name__ == "__main__":
    main()