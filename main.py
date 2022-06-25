import re


def checkValidArc(string):
    valid_arc = r'^(\d+i\|)(\d+[a-hj-zA-Z]\|)+$'
    if re.search(valid_arc, string):
        return True
    else:
        return False