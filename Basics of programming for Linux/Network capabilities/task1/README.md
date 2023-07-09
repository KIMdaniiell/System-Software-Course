# Host resolver

Разработайте утилиту командной строки, принимающую на вход имя хоста и печатающую в стандартный поток вывода список IP-адресов, ассоциированных с данным именем.

**Пример вызова**
>./solution yandex.ru

>213.180.204.3
>
>93.158.134.3
>
>213.180.193.3


#### Представление решения
Решение предоставляется в виде двух файлов solution.c и Makefile, в последнем предполагается цель по умолчанию, которая приводит к сборке Вашего приложения. Бинарный файл вашего решения должен иметь имя solution.

#### Вывод
Программа выводит в стандартный поток вывода IP-адреса, причем каждый адрес должен быть выведен на отдельной строчке, оканчивающейся символом конца строки.