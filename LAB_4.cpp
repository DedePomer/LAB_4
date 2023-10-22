//ВАРИАНТ 24 Чирков Д.И.

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <locale.h>

using namespace std;



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

void main()
{
	setlocale(LC_ALL, "RUS");
	int n, c, nw=0,N,MIN;
	cout << "Enter a number ";
	cin >> n;
	c = countNum(n);
	
	for (int i = 0; i < c; i++)
	{
		MIN = minNum(n);
		nw = nw * 10 + MIN;
		N = 0;

		while (n > 0)
		{ 
			if (n % 10 != MIN)
			{
				N = N * 10 + n % 10;
			}
			n = n / 10;
		}
		n = N;
	}
	cout << nw;
}


