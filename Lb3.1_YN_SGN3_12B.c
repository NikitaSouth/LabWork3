//Лабораторная работа 3.1
#include <stdio.h>
#include <math.h>

int main() 
{
	double previous, error, divider = 1, sum = 0;
	int n = 1;
	printf("Please, enter the admissible error: ");
	scanf_s("%lf", &error);
	if (error > 0){
		do{
			previous = sum;
			divider = divider * n;
			sum = previous + (1 / divider);
			n++;
			//printf("%lf\n", divider);
		} while (fabs(sum - previous) >= error);
		n = n - 1;// Из-за цикла с постпроверкой n прибавляется лишний раз
		printf("sum: %10.8lf, error: %lf, n: %d", sum, error, n);
	}
	else{
		printf("error must be a digit higher than zero\n\a");
	}
}