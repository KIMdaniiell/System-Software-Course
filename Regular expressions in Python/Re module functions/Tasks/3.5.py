# Задание 1
"""
import re

regex = r"\d{13,}"

match = re.fullmatch(regex, input(), flags=0)
print(match is not None)
"""

# Задание 2
"""
import re

regex = r"[a-zA-Z0-9@#$%^&*()_\-+!?]{8,}"
match = re.fullmatch(regex, input(), flags=0)
print(match is not None)
"""

# Задание 3
"""
import re

regex = r"\+?(?:\d(?:[ \-()]){0,2}){10,}\d"

match = re.fullmatch(regex, input(), flags=0)
print(match is not None)
"""

# Задание 4
"""
import re

regex = r"((?:^|[-+])(?:\d*x(?:\^\d*)?|\d+))+"
match = re.fullmatch(regex, input(), flags=0)
print(match is not None)
"""
