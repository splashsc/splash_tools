from playwright.sync_api import Playwright, sync_playwright, expect


def run(playwright: Playwright) -> None:
    browser = playwright.firefox.launch(headless=False)
    context = browser.new_context()
    page = context.new_page()
    page.goto("https://accounts.myzyxel.com/users/sign_in")
    page.get_by_placeholder("Email").fill("1844113527@qq.com")
    page.get_by_placeholder("Password").click()
    page.get_by_placeholder("Password").fill("Xupt66..")
    page.get_by_label("Remember me.").check()
    page.goto("https://portal.myzyxel.com/")
    page.get_by_role("link", name="Firmware Download").click()
    page.goto("https://portal.myzyxel.com/my/firmwares")
    # page.goto("https://firmware.cdn.cloud.zyxel.com/firmware/ABPS/5.37(ABPS.0)/firmware.zip?X-Amzn-Trace-Id=Root=1-64b52d6e-4f4651d26ed7684404021949&Expires=1689681646&Signature=A~~vBt9mUY1-6GxlN3uAESaKlElWzN873dyby3DsJwCSNqvAJXQ8E5Rd4CthiwvnWK3vyBjnrx9r-7UaJtEjxgRTZsN0XnniKMB~fQ5WgimOyz~UEKU5xYKubVmoKYzP15K7lWWIwQ5U26xNlnKfCaYaIwImqnLmeP-yNULZfUVsPT7GmR5qtOiyPTc-b8J4NxpUTFagrDSVTSMSUIq8f8AghtF2NQ8fljATIIjaClWO0Xz-OzjUhq~9H5xi5S5JcCsBKwE~eflWclop-xjMFurPZFiJxDZvFQVQrmtjFY-L1vZs0HVHakWNCcrdDcgS4H84GaGG880EaeUrGrq9Kw__&Key-Pair-Id=APKAJ6HN6ZLE3RHU434A")

    # ---------------------
    # context.close()
    # browser.close()


with sync_playwright() as playwright:
    run(playwright)
