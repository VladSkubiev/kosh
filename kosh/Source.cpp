#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
#define n 100
using namespace std;

float f(float x, float y)
{
	return (x * x - (y / (2 * x)));
}
float ya(float x)
{
	return ((2 * pow(x,3)) / 7) + (5 / (7 * sqrt(x)));
}
int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int k;
	float a, b, h, x, y[n];
	float m1, m2, m3, m4;
	a = 1; b = 2; h = (b - a) / (n - 1);
	y[1] = 1;
	for (k = 1; k < n - 1; k++)
	{
		x = k * h;
		m1 = h * f(x, y[k]);
		m2 = h * f(x + h / 2, y[k] + m1 / 2);
		m3 = h * f(x + h / 2, y[k] + m2 / 2);
		m4 = h * f(x + h, y[k] + m3);
		y[k + 1] = y[k] + (m1 + 2 * m2 + 2 * m3 + m4) / 6;
	}

	for (k = 1; k < n; k++)
	{
		x = k * h;

		cout <<"numerical = "<< y[k]<<"\t\t"<<"analytical = " << ya(x)<< "\n";
	}
	system("PAUSE");
	return 0;
}

