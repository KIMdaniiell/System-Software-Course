# Задание 1
"""
import re

regex = r"[\.\?!,:]"
replace = ""

result = re.subn(regex, replace, input())
print(result[1])
"""

# Задание 2

import re

regex = r"\d"
replace = "X"

result = re.subn(regex, replace, input())
print(result[1])