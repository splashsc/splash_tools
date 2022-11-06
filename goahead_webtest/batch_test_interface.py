import requests


cookies = {
    '_:USERNAME:_': '',
    'EW9v1_user': '',
    'bLanguage': 'cn',
}


def get_requests(target):

    cookies = {
        'bLanguage': 'cn',
    }

    headers = {
        # 'Host': '192.168.26.199',
        'Cache-Control': 'max-age=0',
        'Upgrade-Insecure-Requests': '1',
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/107.0.0.0 Safari/537.36 Edg/107.0.1418.26',
        'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9',
        # 'Accept-Encoding': 'gzip, deflate',
        'Accept-Language': 'zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6',
        'Connection': 'close',
        # 'Cookie': 'bLanguage=cn',
    }

    response = requests.get(target, cookies=cookies, headers=headers, verify=False, allow_redirects=False, timeout=2)

    # print(response.status_code)
    if response.status_code == 200:
        return '200', response.text
    else:
        return '0'



def batch_requests(file,target):
    nowt = 0
    with open(file, 'r') as f:
        b = f.readlines()
        for b1 in b:
            b1 = b1.strip('\n')
            b1 = target + "/goform/" + b1
            nowt = nowt + 1

            try:
                result = get_requests(b1)
                if result[0] == '200':
                    save_file(b1, result[1])
                elif result[0] == '0':
                    pass
                    # save_file(b1)
            except Exception as e:
                print(e)
                pass


def save_file(api_name, response_text):
    with open("api_unauthorized.txt", "a") as f:
        f.write(str(api_name) + "\n")
        f.write(str(response_text) + "\n"+"----------"*8+"\n")



