# Задание 1
"""
import re

regex = r"[aeioyuAEIOUауоыиэяюёеАУОЫИЭЯЮЁЕ]"
replace = "!"

new_line = re.sub(regex, replace, input())
print(new_line)
"""

# Задание 2
"""
import re

regex = r"<.*?>"
replace = ""

new_line = re.sub(regex, replace, input())
print(new_line)
"""

# Задание 3
"""
import re

fio = input().split(" ")
f = fio[0][:len(fio[0])-2]
i = fio[1][:len(fio[1])-2]
o = fio[2][:len(fio[2])-2]

regex = rf"{f}\w+ {i[0]}\. {o[0]}\.|{f}\w+ {i}\w+ {o}\w+"
replace = "ФИО"

new_line = re.sub(regex, replace, input())
print(new_line)
"""
