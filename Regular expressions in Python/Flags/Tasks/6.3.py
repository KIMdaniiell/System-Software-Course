# Задание 1
"""
import re, sys

text = ''.join(sys.stdin.readlines())
regex = r"^[re.escape('^$')]*$"

result = re.findall(regex, text, re.MULTILINE)
print(result)
"""