# Задание 1
"""
import re

regex = r"\w+"
it = re.finditer(regex, input(), flags=0)
for match in it:
    print(match.group())
"""

# Задание 2
"""
import re

regex = r"\b[а-яА-ЯёЁa-zA-Z]{5}\b"
it = re.finditer(regex, input(), flags=0)
for match in it:
    print(match.group())
"""

# Задание 3
"""
import re

regex = r"[0-9]+,[0-9]+ ₽"                      # r"[0-9,]+ ₽" 
it = re.finditer(regex, input(), flags=0)
for match in it:
    print(match.group())
"""