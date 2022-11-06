import requests

cookies = {
    'bLanguage': 'cn',
}

headers = {
    'Host': '192.168.26.199',
    'Cache-Control': 'max-age=0',
    'Upgrade-Insecure-Requests': '1',
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/107.0.0.0 Safari/537.36 Edg/107.0.1418.26',
    'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9',
    # 'Accept-Encoding': 'gzip, deflate',
    'Accept-Language': 'zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6',
    'Connection': 'close',
    # 'Cookie': 'bLanguage=cn',
}

response = requests.get('http://192.168.26.199/goform/telnet', cookies=cookies, headers=headers, verify=False, allow_redirects=False)
print(response.status_code)
print(response.url)