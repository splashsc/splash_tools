# encoding:utf-8
import os
#程序功能
#选中文件夹读取文件
from PyQt5 import QtWidgets
from PyQt5.QtGui import QFont
from PyQt5.QtWidgets import QFileDialog, QWidget
from PyQt5.QtCore import QRect


class MyWindow(QWidget):
    def __init__(self):
        super(MyWindow, self).__init__()
        #主程序框的大小
        self.resize(600, 400)

        #文字
        self.myText = QtWidgets.QLabel(self)
        #label文字框的大小
        self.myText.setGeometry(QRect(100.0, 100.0, 1000.0, 40.0))
        self.myText.setText("路径为：")
        #定义字体
        self.myText.setFont(QFont("", 14, QFont.Bold))

        #按钮
        self.myButton = QtWidgets.QPushButton(self)
        self.myButton.setGeometry(QRect(250.0, 200.0, 80.0, 40.0))
        self.myButton.setObjectName("btn")
        self.myButton.setText("选择目录")
        #msg函数绑定点击事件
        self.myButton.clicked.connect(self.msg)


    def msg(self):
        str = QFileDialog.getExistingDirectory(self, "选择文件夹", "/")
        self.myText.setText("路径为：" + str)
        #输出文件路径及文件名
        list = traverse(str)
        for i in list:
            print(i)
            os.system("{} a {}.zip {}".format(path_7z, str+'/'+i, str+'/'+i))
        self.myText.setText("路径为：" + str + "\n所有文件压缩完成")


def save_valid(valid_file, TARGET):
    with open(valid_file, "a") as f:
        f.write(TARGET + "\n")



def traverse(f):
    #list存文件名
    list = []
    fs = os.listdir(f)
    for f1 in fs:
        tmp_path = os.path.join(f, f1)
        f_name = tmp_path.split("\\")[-1]
        list.append(f_name)
        #if not os.path.isdir(tmp_path):
        #    list.append(tmp_path)
    return list


if __name__ == "__main__":
    import sys
    path_7z = "E:/7-Zip/7z.exe"
    app = QtWidgets.QApplication(sys.argv)
    myshow = MyWindow()
    myshow.show()
    sys.exit(app.exec_())