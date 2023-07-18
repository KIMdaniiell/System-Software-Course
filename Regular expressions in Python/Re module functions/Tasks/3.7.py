# Задание 1
"""
import re

regex = r"https:\/\/imgur\.com\/[a-zA-Z0-9]{7}"
result = re.findall(regex, input(), flags=0)
for i in result:
    print(i)
"""

# Задание 2
"""
import re

regex = r"(?<![a-zA-Z0-9\-_@.])[a-zA-Z0-9\-_]+@[a-zA-Z0-9]+\.[a-zA-Z0-9]+(?![a-zA-Z0-9\-_@.])"
result = re.findall(regex, input(), flags=0)
for i in result:
    print(i)
"""

# Задание 3
"""
import re

regex = r"((\d\d)?\d\d([.\/])\d\d\3\d\d(?(2)|\d\d))"
result = re.findall(regex, input(), flags=0)
for i in result:
    print(i[0])
"""

# Задание 4
"""
import re

regex = r"(?<!\d|:)(?:[0-1]\d|2[0-3]):(?:[0-5]\d)(?!\d|:)"
result = re.findall(regex, input(), flags=0)
for i in result:
    print(i)
"""

# Задание 5
import re

input = r'<html lang="en"><head><meta charset="UTF-8"><meta http-equiv="X-UA-Compatible" content="IE=edge"><meta name="viewport" content="width=device-width, initial-scale=1.0"><title>Пролистай вниз</title><link rel="stylesheet" href="./css/normalize.css"><link rel="stylesheet" href="./css/style.css"><link rel="icon" href="./img/icon.jpg"></head><body><header><h1 class="privet">Привет!<br>Пролистай страничку вниз.</h1><img src="./img/photo.jpg" alt="" class="logo_icon"></header><main><p class="paragraph">Чтобы продолжить - отправь боту любое фото.</p></main><footer><a class="link" href="./img/photo.jpg" download="">Фото</a><p class="link">id стикера - CAACAgIAAxkBAAIDxWITCaZnaUelQ0SNlHMTrjd2klAmAAIBAQACVp29CiK-nw64wuY0IwQ</p><a class="link" href="./img/tochno.txt" download="">Документ</a></footer></body></html>'
a_regex = r"<a.*?>"
href_regex = r"((?<=href=([\"']))\S*?(?=\2))"
a_result = re.findall(a_regex, input, flags=0)
for a in a_result:
    href_result = re.findall(href_regex, a, flags=0)
    for href in href_result:
        print(href[0])
