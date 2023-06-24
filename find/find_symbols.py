import os
import argparse

parser = argparse.ArgumentParser(description='Traverse a directory and separate ELF and non-ELF files.')
parser.add_argument('-d', '--directory', type=str, help='The directory to traverse/root.')
parser.add_argument('-f', '--file', type=str, help='The file to save.')

args = parser.parse_args()

elf_files = []
non_elf_files = []

def traverse_directory(directory):
    for root, dirs, files in os.walk(directory):
        for file in files:
            file_path = os.path.join(root, file)
            if os.path.isfile(file_path):
                if os.access(file_path, os.X_OK):
                    with open(file_path, 'rb') as f:
                        if f.read(4) == b'\x7fELF':
                            elf_files.append(file_path)
                        else:
                            non_elf_files.append(file_path)

traverse_directory(args.directory)


for file_path in elf_files:

    os.system(f"echo {file_path} >> {args.file}")
    os.system(f"nm -D {file_path} >> {args.file}")
    with open(args.file, "a") as f:
        f.write("-----------------------------------\n\n")

# print("ELF files:")
# for file in elf_files:
#     print(file)

# print("\nNon-ELF files:")
# for file in non_elf_files:
#     print(file)

