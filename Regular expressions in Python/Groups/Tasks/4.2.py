# Задание 1
"""
import re

regex = r"(?:(?<=<)|(?<=<\/))(?P<tag_title>[a-z0-9]+).*?(?=>)"

result = re.findall(regex, input())

print(result)
"""

# Задание 2

import re

regex = r"(?P<login>[0-9]+):(?P<password>[a-zA-Z0-9]+):(?P<token>[a-z0-9]+)(?!\S)"

result = re.findall(regex, input())

print(result)