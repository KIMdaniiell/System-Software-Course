#Задание 1

import re


regex = r"[123]"

pattern = re.compile(regex, re.DEBUG)
'''
IN
  LITERAL 49
  LITERAL 50
  LITERAL 51

 0. INFO 8 0b100 1 1 (to 9)
      in
 5.     RANGE 0x31 0x33 ('1'-'3')
 8.     FAILURE
 9: IN 5 (to 15)
11.   RANGE 0x31 0x33 ('1'-'3')
14.   FAILURE
15: SUCCESS
'''