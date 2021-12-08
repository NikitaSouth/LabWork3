//Лабораторная работа 3.2
#include <stdio.h>
#include <math.h>

double areaOverAll(double stepSize, double a, int n);
double areaFragmental(double stepSize, double a, int i);

void main()
{
	double a, b, step, error, area = 0, previousArea; int n = 2;//n - число апроксимирующих фигур, которое будет увеличиваться во внешнем цикле с постпроверкой
	printf("Please enter a and b borders: ");
	scanf_s("%lf%lf", &a, &b);
	if (a >= b  || a <= 0){
		printf("Error: a must be a digit below b and higher 0\a");
	}
	else{
		printf("Enter an admissible error: ");
		scanf_s("%lf", &error);
		if (error > 0){
			do{
				previousArea = area;
				step = (b - a) / n; //подсчет длины шага при n-ом количестве фигур
				area = areaOverAll(step, a, n);
				n = n * 2;
			} while (fabs(area - previousArea) >= error); // цикл будет повторяться до момента, пока модуль разности площади и площади с пред итерации не будет меньше погрешности;
			n = n / 2; //Из-за использования цикла с постпроверкой n лишний раз умножается на 2
			printf("amount of rectangles = %d\nArea = %10.8lf", n, area);
		}
		else{
			printf("Error: an admissible error must be higher than zero\a");
		}
	}
}

double areaOverAll(double stepSize, double a, int n)
{
	double areaOL = 0;
	int i = 1;
	while (i <= n){
		areaOL = areaOL + areaFragmental(stepSize, a, i);
		i++;
	} 
	return(areaOL);
}

double areaFragmental(double stepSize, double a, int i) //Расчет площади одного из n прямоугольников
{
	return(stepSize * fabs(log(a + stepSize * (i - 1))));
}