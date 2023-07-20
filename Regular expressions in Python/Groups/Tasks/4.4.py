# Задание 1
"""
import re


regex = r"(?P<duplicate>[а-яА-ЯёЁ]+) (?P=duplicate)"
replace = r"\g<duplicate>"

result = re.sub(regex, replace, input())
print(result)
"""


# Задание 2
"""
import re


regex_word = r"(?P<word>[a-zA-Zа-яА-ЯёЁ ]*?)"
regex_strong = fr"\*\*{regex_word}\*\*"
regex_em = fr"\*{regex_word}\*"

result = re.sub(regex_strong, r"<strong>\g<word></strong>", input())
result = re.sub(regex_em, r"<em>\g<word></em>", result)
print(result)
"""


# Задание 3
"""
import re


regex = r"(?P<proxy>[0-9\.]+:[0-9]+)"
replace = fr"{re.escape(r'http://')}\g<proxy>"

result = re.sub(regex, replace, input())
print(result)
"""


# Задание 4
"""
import re

regex_month = r"(?P<month>\d\d)"
regex_day = r"(?P<day>\d\d)"
regex_year = r"(?P<year>\d\d\d\d)"
regex_delimiter = fr"(?P<delimiter>[{re.escape(r'./')}])"

regex = fr"{regex_month}{regex_delimiter}{regex_day}\2{regex_year}"
replace = rf"\g<day>\g<delimiter>\g<month>\g<delimiter>\g<year>"

result = re.sub(regex, replace, input())
print(result)
"""


# Задание 5
"""
import re

regex = r"(?P<main>[Ее]го|[Ее]ё|[Ии]х)(?P<suffix>н{1,2}[ыи][а-я])"

result = re.sub(regex, r"\g<main>", input())
print(result)
"""


# Задание 6
"""
import re


regex = rf"(?P<cost>\d+[{re.escape('₽$')}])"
string = r"Цена данного товара \g<cost>"

match = re.search(regex, input())
if match is not None:
    result = match.expand(string)
    print(result)
"""