# Домашнее задание: Фильтрация IP-адресов.

Цель:
1. Реализовать приложение обработки списка IP-адресов.
Программа из стандартного ввода читает данные. Данные хранятся построчно. Каждая строка состоит из трех полей, разделенных одним символом табуляции, и завершается символом конца строки. Формат строки:text1 \t text2 \t text3 \n.
- Поля text2 и text3 игнорируются. 
- Поле text1 имеет следующую структуру (ip4 address):n1.n2.n3.n4, где n1..4 – целое число от 0 до 255.

2. Требуется загрузить список IP-адресов в память и отсортировать их в обратном лексикографическом порядке.

3. Вывести в стандартный вывод следующее:
- Полный список адресов после сортировки. Одна строка - один адрес.
- Сразу следом список адресов, первый байт которых равен 1. Порядок сортировки не меняется. Одна строка - один адрес. Списки ничем не разделяются.
- Сразу продолжается список адресов, первый байт которых равен 46, а второй 70. Порядок сортировки не меняется. Одна строка - один адрес. Списки ничем не разделяются.
- Сразу продолжается список адресов, любой байт которых равен 46. Порядок сортировки не меняется. Одна строка - один адрес. Списки ничем не разделяются.

4. Добавить unit-тесты GoogleTest.