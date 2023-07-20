# Задание 1
"""
import re

regex = r"\d+"

result = re.sub(regex, lambda d: str(int(d[0])**2), input())
print(result)
"""


# Задание 2
"""
import re

regex = r"\b[Аа][а-яА-ЯёЁ]*"

result = re.sub(regex, lambda w: rf"удалено({len(w[0])})", input())
print(result)
"""


# Задание 3
"""
import re

regex = r"(?<![a-zA-Z])[ap]m\b"

result = re.sub(regex, lambda w: 'am' if w[0]=='pm' else 'pm', input())
print(result)
"""


# Задание 4

import re

regex = r"\d+"

result = re.sub(regex, lambda d: str(int(d[0])//3) if int(d[0]) % 3 == 0 else d[0], input())
print(result)