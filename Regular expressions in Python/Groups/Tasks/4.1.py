# Задание 1
"""
import re

regex = r"(?P<start><p.*?>)(?P<content>.*?)(?P<end><\/p)"

result = re.findall(regex, input())
for i in result:
    print(i[1])
"""

# Задание 2
"""
import re


def handle_match(m):
    if m is not None:
        full_link = m.group()
        protocol = m.group("protocol")
        domain = m.group("domain")
        param = m.group("param")
        anchor = m.group("anchor")
        print(f"Полная ссылка: {full_link}")
        print(f"Протокол: {protocol} | Домен: {domain} | Параметры: {param} | Якорь: {anchor}\n")


regex = r"(?P<protocol>https?):\/\/(?P<domain>[a-z\.]+)(?P<path>[a-z0-9\-_\/]*)(?P<param>\?[a-z=&0-9]+)*(?P<anchor>\#[a-z]+)?(?!\S)"
match_iterator = re.finditer(regex, input())
for match in match_iterator:
    handle_match(match)
"""

