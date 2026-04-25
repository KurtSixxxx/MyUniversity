#include <stdio.h>
#include <float.h>

int main (){
	float x;
	double y;
	
	x = 10882000;
	y = x * 1.23456e100;
	x = x * -FLT_MAX * 2.0f;
	y = y * FLT_MAX * 2.0;
	
	printf("valore di x dopo molt. n virgola mobile: %6e\n", x);
	printf("valore di y : %6E\n" , y);
	
	return 0;
	
}
