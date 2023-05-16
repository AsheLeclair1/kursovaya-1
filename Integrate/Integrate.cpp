// Integrate.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
// Функция, для которой необходимо вычислить производную/интеграл
double f1(double x) {
return x* x;
}

double f2(double x) {
return cos(2.0*x+1.0);
}

double f3(double x) {
return 3.0*sin(x-2.0);
}

// Функция для вычисления производной функции f(x) в точке x с шагом h
double derivative(double x, double h) {
char key='99';
std::cout << "Выберите функцию: " << std::endl;
std::cout << "1 - f(x)= x * x" << std::endl;
std::cout << "2 - f(x)= cos(2.0*x+1.0)" << std::endl;
std::cout << "3 - f(x)= 3.0*sin(x-2.0)" << std::endl;
std::cin >> key;
		switch(key)
		{
		case '1':{
			return (f1(x + h) - f1(x - h)) / (2 * h);
			break;
				 }
		case '2':{
			return (f2(x + h) - f2(x - h)) / (2 * h);
			break;
				 }
		case '3':{
			return (f3(x + h) - f3(x - h)) / (2 * h);
			break;
				 }
		default:{
			return 0;
				}
		}

}

// Функция для вычисления интеграла функции f(x) на отрезке [a, b] с числом разбиений n
double integral(double a, double b, int n) {
double h = (b - a) / n;
double sum = 0.0;
char key='99';
std::cout << "Выберите функцию: " << std::endl;
std::cout << "1 - f(x)= x * x" << std::endl;
std::cout << "2 - f(x)= cos(2.0*x+1.0)" << std::endl;
std::cout << "3 - f(x)= 3.0*sin(x-2.0)" << std::endl;
std::cin >> key;
for (int i = 0; i < n; i++) {
double x1 = a + i * h;
double x2 = a + (i + 1) * h;
		switch(key)
		{
		case '1':{
			sum += (f1(x1) + f1(x2)) / 2.0 * h;
			break;
				 }
		case '2':{
			sum += (f2(x1) + f2(x2)) / 2.0 * h;
			break;
				 }
		case '3':{
			sum += (f3(x1) + f3(x2)) / 2.0 * h;
			break;
				 }
		default:{
			return 0;
				}
		}
}
return sum;
}

int main() {
	setlocale(LC_ALL, "Russian");
 
double x = 1.0;
double h = 0.0001;
double a = 0.0;
double b = 1.0;
int n = 1000;

char key='99';
while (key!='0')
{
	system("cls");
std::cout << "1 - Производная " << std::endl;
std::cout << "2 - Интеграл" << std::endl;
std::cout << "0 - Выход " << std::endl;
std::cin >> key;
		switch(key)
		{
		case '1':{
			std::cout << "Введите точку x " << std::endl;
			std::cin >> x;
			std::cout << "Введите точность h " << std::endl;
			std::cin >> h;
			double dx = derivative(x, h);
			std::cout << "Производная функции f(x) в точке x = " << x << " равна " << dx << std::endl;
			break;
				 }
		case '2':{
			std::cout << "Введите начало интервала а " << std::endl;
			std::cin >> a;
			std::cout << "Введите конец интервала b " << std::endl;
			std::cin >> b;
			std::cout << "Введите количество отрезков n " << std::endl;
			std::cin >> n;
			double int_f = integral(a, b, n);
			std::cout << "Интеграл функции f(x) на отрезке [" << a << ", " << b << "] равен " << int_f << std::endl;
			break;
				 }
		}
		system("pause");
}
return 0;
}
