import os
import glob

def sort_files_by_creation_time(directory):
    files = glob.glob(directory + '/*')
    sorted_files = sorted(files, key=os.path.getctime, reverse=True)
    return sorted_files[:2]

# Specify the directory
directory = '../spider/sophos/'

# Call the function
sorted_files = sort_files_by_creation_time(directory)

# Print the file paths
for file_path in sorted_files:
    print(file_path)