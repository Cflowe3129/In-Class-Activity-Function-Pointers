#include <stdio.h>
#include <stdlib.h>

/* IMPLEMENT ME: Declare your functions here */
int add (int a, int b);
int subtract (int a, int b);
int multiply (int a, int b);
int divide (int a, int b);
int end (int a, int b);
int input, a = 5, b = 3;
int (*functionPointers[]) (int, int) = { add, subtract, multiply, divide, end };


int main (void)
{
	/* IMPLEMENT ME: Insert your algorithm here */

  printf("Operand 'a' : 5 | Operand 'b' : 3\nSpecify the operation to perform (0 : add | 1 : subtract | 2 : Multiply | 3 : divide | 4 : exit): ");
  scanf("%d", &input);  

  (*functionPointers[input]) (a, b);
  
	return 0;
}



/* IMPLEMENT ME: Define your functions here */
int add (int a, int b) 
{ 
  printf ("Adding 'a' and 'b'\nX = %d\n\n", (a+b)); 
  
  printf("Operand 'a' : 5 | Operand 'b' : 3\nSpecify the operation to perform (0 : add | 1 : subtract | 2 : Multiply | 3 : divide | 4 : exit): ");
  scanf("%d", &input); 
  (*functionPointers[input]) (a, b);
  return a + b; 
}

int subtract (int a, int b) 
{ 
  printf ("Subtracting 'a' and 'b'\nX = %d\n\n", (a-b)); 
  
  printf("Operand 'a' : 5 | Operand 'b' : 3\nSpecify the operation to perform (0 : add | 1 : subtract | 2 : Multiply | 3 : divide | 4 : exit): ");
  scanf("%d", &input); 
  (*functionPointers[input]) (a, b);
  return a - b; 
}

int multiply (int a, int b) 
{ 
  printf ("Multiplying 'a' and 'b'\nX = %d\n\n", (a*b)); 
  
  printf("Operand 'a' : 5 | Operand 'b' : 3\nSpecify the operation to perform (0 : add | 1 : subtract | 2 : Multiply | 3 : divide | 4 : exit): ");
  scanf("%d", &input); 
  (*functionPointers[input]) (a, b);
  return a * b; 
}

int divide (int a, int b) 
{ 
  printf ("Dividing 'a' and 'b'\nX = %d\n\n", (a/b)); 
  
  printf("Operand 'a' : 5 | Operand 'b' : 3\nSpecify the operation to perform (0 : add | 1 : subtract | 2 : Multiply | 3 : divide | 4 : exit): ");
  scanf("%d", &input); 
  (*functionPointers[input]) (a, b);
  return a / b; 
}

int end (int a, int b) 
{ 
  return 0;
}