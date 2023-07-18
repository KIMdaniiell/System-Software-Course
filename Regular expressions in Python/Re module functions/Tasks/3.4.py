# Задание 1
"""
import re

regex = r"[a-zA-Z]+"

match = re.match(regex, input(), flags=0)
if match is not None:
    print(f"Первое слово в предложении: {match.group()}")
"""

# Задание 2
"""
import re

regex = r"(?:[a-z]+ ){11,}(?:[a-z]+)"

match = re.match(regex, input(), flags=0)
if match is not None:
    print("возможно, это seed-фраза")
"""

# Задание 3
import re

regex = r".*(?=@)"
match = re.match(regex, input(), flags=0)
if match is not None:
    print(match.group())
