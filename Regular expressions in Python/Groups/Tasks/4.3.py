# Задание 1
"""
import re

delimiters = re.escape("+:=*/-")
regex = rf"\D*(?P<delimiter>[{delimiters}])\D*"

result = re.split(regex, input())

print(result)
"""


# Задание 2
"""
import re

delimiters = r"?&"
regex = fr"(?P<delimiter>[{delimiters}])"

result = re.split(regex, input())

print(result)
"""