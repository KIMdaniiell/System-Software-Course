# Задание 1
"""
import re

re_byte = r"[0-9A-F]{2}"
regex = fr"(?:{re_byte}:){{5}}{re_byte}"
pattern = re.compile(regex)
"""


# Задание 2
"""
import re


regex = r"\b[a-z]+"
pattern = re.compile(regex)

match = pattern.search(input(), int(input()), int(input()))
if match is not None:
    print(match.group())
"""    