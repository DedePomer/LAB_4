//ВАРИАНТ 24 Чирков Д.И.

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <locale.h>

using namespace std;



int countNum(unsigned long long n)
{
	int count = 0;
	if (n == 0)
		return 1;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return count;
}
int minNum(unsigned long long n)
{
	int minN = n % 10, m;
	while (n > 0)
	{
		m = n % 10;
		if (minN > m)
		{
			minN = m;
		}
		n = n / 10;
		
	}
	return minN;
}
int searchZero(unsigned long long n)
{
	int count = 0;
	if (n == 0)
		return 0;
	while (n > 0)
	{
		if (n % 10 == 0)
		{
			count++;
		}
		n = n / 10;	
	}
	return count;
}

void main()
{
	setlocale(LC_ALL, "RUS");
	unsigned long long n, nw = 0,N;
	int c ,MIN, countN, count0;
	/*cout << "Enter a number ";
	cin >> n;*/
	n = 22222222202221;// 
	c = countNum(n);
	count0 = searchZero(n);
	
	for (int i = 0; i < c; i++)
	{
		countN = 0;
		N = 0;
		MIN = minNum(n);
		if (nw > 0 && count0 > 0) // Добавляем числу 0
		{
			nw = nw * pow(10, count0);
			count0 = 0;
		}
		nw = nw * 10 + MIN;

		while (n > 0)
		{
			if (n % 10 != MIN) // Запись в новое число, если != MIN
			{
				N = N * 10 + n % 10;
			}
			else if (countN == 0 && n % 10 == MIN) // Изменение в счётчике
			{
				countN++; // Нужен для записи одинаковых цифр
			}
			else if (countN > 0 && n % 10 == MIN) // Запись в новое число, если == MIN
			{
				N = N * 10 + n % 10;
			}
			n = n / 10;
		}
	
		n = N;
	}
	std:: cout << nw;
}


