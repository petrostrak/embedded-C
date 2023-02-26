#include <stdio.h>
#include <stdint.h>

// Write a program that receives 2 numbers from user and prints the biggest.
// If they are same, print "both numbers are equal"
int main(int argc, char const *argv[])
{   
    float a, b;
    printf("Give two integers to compare: ");

    if (!scanf("%f", &a)) {
        printf("invalid input\n");
        return 0;
    }

    if (!scanf("%f", &b)) {
        printf("invalid input\n");
        return 0;
    }

    int32_t int1 = a; 
    int32_t int2 =  b;

    if (int1 == int2) {
        printf("Numbers are equal!\n");
    } else {
        if (int1 < int2) {
            printf("%d is bigger\n", int2);
        } else {
            printf("%d is bigger\n", int1);
        }
    }

    return 0;
}
