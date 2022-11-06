import re
import os

websDefineAction = 'websFormDefine'
moduleRegister = 'moduleRegister'
pattern = '.*"(.*)"'
path = "./pseudocode/"


def extract(file_name):
    for line in open(path + file_name):
        # print(line)
        if websDefineAction in line:
            result = str(re.findall(r'.*"(.*)"', line))

            if result != '[]':
                result = result.replace("'","").replace("[","").replace("]","")
                print(result)
                save_file(result)

        '''elif moduleRegister in line:
            result = re.findall(r'.*"(.*)"', line)
            print(result)
            save_file(result)'''


def save_file(api_name):
    with open("api.txt", "a") as f:
        f.write(str(api_name) + "\n")


def traverse(f):
    fs = os.listdir(f)
    for f_name in fs:
        print(f_name)
        extract(f_name)
    return 0

