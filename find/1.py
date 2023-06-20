import os
import imghdr

img_file = ["jpeg","png","gif","tiff","rgb","pbm","pgm","ppm","rast","xbm","bmp","webp","exr"]

def traverse_directory(directory):
    file_list = []
    for root, dirs, files in os.walk(directory):
        for file in files:
            file_list.append(os.path.join(root, file))
    return file_list




directory = "/home/iot/Desktop/_ax3004i_ml_14_162.bin.extracted/squashfs-root"
file_list = traverse_directory(directory)
# print(file_list)

def is_binary_file(file_path):
    try:
        print(type(imghdr.what(file_path)))
        if imghdr.what(file_path) in img_file:
            return False
        else:
            with open(file_path, 'rb') as f:
                data = f.read(8000)
                if b'\0' in data:
                    return True
                else:
                    return False
    except OSError as err:
        print(err)
        return False

binary_files = []
for file_path in file_list:
    if is_binary_file(file_path):
        binary_files.append(file_path)

for file_path in binary_files:
    print(file_path)