# regex for checking if fist and last letter are the same
# regex = r'^(\w)(\w*)\1$'
# Path: Array/new.py
def is_palindrome(s):
    re




import re
def is_palindrome(s):
    return re.match(r'^(\w)(\w*)\1$', s)
print(is_palindrome('abjhsfa'))