//ВАРИАНТ 24 Чирков Д.И.

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <locale.h>

using namespace std;

int ind = 0;

int countNum(int n)
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
int minNum(int n)
{
	ind = 1;
	int minN = n % 10, m, i=1;
	while (n > 0)
	{
		i++;
		m = n % 10;
		if (minN > m)
		{
			ind = i;
			minN = m;
		}
		n = n / 10;
		
	}
	return minN;
}
int POW10(int n, int m)
{
	int c = 1;
	for (int i = 1; i <= m; i++)
	{
		c = c * n;
	}
	return c;
}

void main()
{
	setlocale(LC_ALL, "RUS");
	int n, c, nw=0,N;
	bool tf = true;
	/*cout << "Введите число ";
	cin >> n;*/
	n = 523;
	c = countNum(n);
	

	for (int i = 0; i < c; i++)
	{
		nw = nw * 10 + minNum(n);
		N = 0;
		for (int j =1; j <= countNum(n); j++)
		{		
			if (j == ind)
			{
				tf = false;
			}
			else
			{
				if (tf)
					N = N * 10 + n % POW10(10, j);// проблемс
				else
					N = N * 10 + n % POW10(10, j - 1);
			}
		}
		n = N;
		tf = true;
	}
}


