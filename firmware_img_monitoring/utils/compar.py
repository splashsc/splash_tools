


def compare_files(file1, file2):
    with open(file1, 'r') as f1, open(file2, 'r') as f2:
        content1 = f1.readlines()
        content2 = f2.readlines()

        unique_content1 = set(content1) - set(content2)
        unique_content2 = set(content2) - set(content1)

        print(f"Unique content in {file1}:")
        for line in unique_content1:
            print(line.strip())

        print(f"\nUnique content in {file2}:")
        for line in unique_content2:
            print(line.strip())


file1 = '../2023-07-19_20-34-31-sophos_new.list'
file2 = '../2023-07-19_20-39-31-sophos_new.list'
compare_files(file1, file2)


