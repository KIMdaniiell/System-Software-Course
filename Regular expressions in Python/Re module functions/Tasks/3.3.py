# Задание 1
# Код писать сюда \(❤‿❤)/
"""
import re

regex = r"#[a-z]+"
text = input()

match = re.search(regex, text, flags=0)
if match is not None:
    gr = match.group()
    if gr is not None:
        print(gr)
"""

# Задание 2
# Код писать сюда \(❤‿❤)/
"""
import re

lines = 4
line_number = 0
regex = r"[Кк]од"

for i in range(lines):
    line_number += 1
    match = re.search(regex, input(), flags=0)
    if match is not None:
        print(f"{line_number} {match.start()}")
        exit(0)
print("код не найден")
"""

# Задание 3
"""
import re

lines  = 5
regex = r"(?<=\bActivation key: )(?:[0-9A-Z]{5}-){4}(?:[0-9A-Z]{5})"

for i in range(lines):
    match = re.search(regex, input(), flags=0)
    if match is not None:
        print(match.group())
"""

# Задание 4
import re

regex = r"(?<=\bt=)[0-9.+]*"

match = re.search(regex, input(), flags=0)
if match is not None:
    print(f"t={match.group()}")
