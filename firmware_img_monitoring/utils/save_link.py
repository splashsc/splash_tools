import datetime

current_time = datetime.datetime.now()
file_name = current_time.strftime("%Y-%m-%d_%H-%M-%S")
# save file


def save_text_to_file(text, file_path):
    with open(file_path + file_name, 'a+') as file:
        file.write(text+'\n')

