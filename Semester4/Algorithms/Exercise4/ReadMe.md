Задачи:

1. Реализирайте конзолно приложение, което сравнява времето за изпълнение на всеки от описаните по-горе четири алгоритъма за сортиране и алгоритмите за бързо сортиране и цифрова сортировка върху цели числа. За целта използвайте масив от случайно генерирани цели числа с
  1. 1000 елемента;
  2. 2000 елемента;
  3. 5000 елемента;
  4. 10000 елемента;
  5. 20000 елемента;
  6. 50000 елемента.
За отчитане на времето за изпълнение на всеки от алгоритмите използвайте функцията GetTickCount(), която връща като резултат времето в милисекунди от началото на стартиране на системата (библиотека windows.h) .
В главната функция преди и след извикване на съответната функция за сортиране извикайте функцията GetTickCount() и разликата от двете стойности определете като време за изпълнение на съответната функция за сортиране.
За генериране на масива от случайни числа можете да използвате следните функции (библиотеки <stdlib.h> и <time.h>):
srand( (unsigned)time( NULL ) );
rand ();
2. Реализирайте конзолно приложение, което сравнява времето за изпълнение на всеки от описаните по-горе четири алгоритъма за сортиране и алгоритмъма за бързо сортиране върху реални числа. За целта използвайте масив от случайно генерирани реални числа с
А) 1000 елемента;
Б) 2000 елемента;
В) 5000 елемента;
Г) 10000 елемента;
Д) 20000 елемента;
Е) 50000 елемента.