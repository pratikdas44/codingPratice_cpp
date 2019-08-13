//program to find data type of input in c
// C program to find data type 
#include <math.h> 
#include <stdio.h> 
#include <stdlib.h> 
# define MAX_INPUT 100 

int main() 
{ 
	// To read input 
	char value[MAX_INPUT] = ""; 

	// To store numeric value of input if a 
	// number (float or integer) 
	double temp; 

	// To store integral value of input 
	int n; 

	// To store string value of input 
	char str[MAX_INPUT] = ""; 

	// Precision for integer checking 
	double val = 1e-12; 

	fgets(value, 100, stdin); // Read input 

	// Check for integers. 
	if (sscanf(value, "%lf", &temp) == 1) 
	{ 
		n = (int)temp; // typecast to int. 
		if (fabs(temp - n) / temp > val) 
			printf("The input is a floating point\n");		 
		else
			printf("The input is an integer\n");		 
	} 

	// Check for string 
	else if (sscanf(value, "%s", str) == 1)	 
		printf("The input is a string\n"); 
	
	else // No match.	 
		printf("input not recognized\n");	 
} 
