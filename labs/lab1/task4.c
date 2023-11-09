#include <stdio.h>
int main()
{
	float a, b, c, x;
	printf("Equation ax+b=c, Please input a, b, c \n");
	scanf("%f", &a);
	scanf("%f", &b);
	scanf("%f", &c);
	x= (c-b)/a;
	printf("x = %f \n", x);
}
