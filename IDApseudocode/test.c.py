import re
import sys

fileneme = "123.c"
p1 = re.compile(r"[(](.*?)[)]", re.S)


def test(C_filename):
    for line in open(C_filename):

        global fileneme
        # print(fileneme)
        if "//----- (" in line :
            fileneme = str(re.findall(p1, line)) + ".c"
            fileneme = fileneme.replace("[", "").replace("]", "").replace("'", "").replace("'", "")
            print(fileneme)
            save_file("", fileneme)
        else:
            save_file(line, fileneme)


def save_file(content, filename):
    with open("code\\"+ filename, "a") as f:
        f.write(str(content))


if __name__ == '__main__':
    test("jhttpd.c")