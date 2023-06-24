import os

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


traverse_directory("/home/iot/Desktop/_ax3004i_ml_14_162.bin.extracted/squashfs-root")

for file_path in elf_files:
    os.system(f"echo {file_path} >> elf_results.txt")
    os.system(f"nm -D {file_path} >> elf_results.txt")
    with open("elf_results.txt", "a") as f:
        f.write("\n\n")

# print("ELF files:")
# for file in elf_files:
#     print(file)

# print("\nNon-ELF files:")
# for file in non_elf_files:
#     print(file)
