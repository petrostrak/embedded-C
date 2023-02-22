#include <stdio.h>
#include "math.h"

// function prototyping


int main()
{
    int a = 4, b = 2, c = 4;
    int result = addition(3, a, b, c);
    printf("The result is %d\n", result);
    
    result = subtraction(3, a, b, c);
    printf("The result is %d\n", result);
    
    result = multiplication(a, b);
    printf("The result is %d\n", result);
    
    result = division(a, b);
    printf("The result is %d\n", result);
    
    return 0;
}

