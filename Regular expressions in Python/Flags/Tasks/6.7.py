# Задание 1

import re

regex = r"""(?:
    (?:\s*[+>~,]\s*|\s+)
    |
    [^:+>~,\s\\[\]]+(?:\\.[^:+>~,\s\\[\]]*)*
)
|
\[(?:
    [^\\[\]]*(?:\\.[^\\[\]]*)*
    |
    [^=]+=~?\s*
    (?:
        "[^\\"]*(?:\\.[^"\\]*)*"
        |
        '[^\\']*(?:\\.[^'\\]*)*'
    )
)\]
|
:[^\\:([]+(?:\\.[^\\:([]*)*
(?:
    \((?:
        [^\\()]*(?:\\.[^\\()]*)*
        |
        "[^\\"]*(?:\\.[^"\\]*)*"
        |
        '[^\\']*(?:\\.[^'\\]*)*'
    )\)
)?"""

pattern = re.compile(regex, re.VERBOSE)