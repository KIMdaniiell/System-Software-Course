import re

match = re.match(input(), input())

# Задание 1
# Код писать сюда \(❤‿❤)/
print(match.group(0))
print(match.start())
print(match.end())
print(match.pos)
print(match.endpos)
print(match.re)
print(match.string)

# Задание 2
# Код писать сюда \(❤‿❤)/
if match is not None:
    g_zero = match.group(0)
    if g_zero is not None:
        print(g_zero)
