# Задание 1
"""
import re


def get_x(m):
    return {'o': 'x', 'O':'X'}[m[0]]


print(re.sub(r'(?i)o', get_x, input()))
"""


# Задание 2
"""
import re

regex = r"(?i)привет"
pattern = re.compile(regex)
result = pattern.findall(input())
print(result)
"""