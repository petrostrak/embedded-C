#include <stdio.h>
#include <stdint.h>

int main(int argc, char const *argv[])
{
    printf("Please give 2 integers: ");
    int32_t a, b;
    scanf("%d%d", &a, &b);

    printf("--- Bitwise Operations ---\n");
    printf("&(AND):  a & b = %d\n", a & b);
    printf("|(OR) :  a | b = %d\n", a | b);
    printf("^(XOR):  a ^ b = %d\n", a ^ b);
    printf("~(NOT): ~a     = %d\n", ~a);

    return 0;
}