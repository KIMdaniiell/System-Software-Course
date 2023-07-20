# Задание 1

import re, sys

text = ''.join(sys.stdin.readlines())
regex = r"(?<=start).*?(?=end)"

print(re.findall(regex, text, re.MULTILINE + re.DOTALL))