import os
import sys
import extract_the_api
import batch_test_interface
from optparse import OptionParser




if __name__ == "__main__":
    parser = OptionParser()
    parser.add_option("-t", "--target", dest="target", help="The full address of the test target is required",
                      default="http://127.0.0.1/")
    parser.add_option("-p", "--path", dest="path", help="", default="./pseudocode/")

    (options, args) = parser.parse_args()
    # eg : python3 main.py -t "http://127.0.0.1" -p "./pseudocode/" -f "websFormDefine"

    try:
        os.remove('./api.txt')
        os.remove('./api_unauthorized.txt')
    except:
        pass

    extract_the_api.traverse(options.path)
    batch_test_interface.batch_requests('./api.txt', options.target)