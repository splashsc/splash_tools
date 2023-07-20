import sys
sys.path.append('../')
import os.path
import requests
from bs4 import BeautifulSoup
from utils import  save_link


# Function to crawl the website and print links containing "vmw"
def spider_crawl_link():
    url = "https://download.sophos.com/network/SophosFirewall/installers/index.html"
    response = requests.get(url)
    soup = BeautifulSoup(response.content, "html.parser")
    links = soup.find_all("a")
    # print("111")
    # print(links)

    for link in links:
        # print(type(link))
        link = link.get("href")
        str(link)
        if 'VMW' in link:
            print(link)
            var = save_link.save_text_to_file(link, "./spider/sophos/sophos-")

# def diff_file



# Call the function to crawl the website
# crawl_link()
