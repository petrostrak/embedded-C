#include <stdio.h>

long long int x = 0xFFFEABCD11112345;

/*
    0xFF    0x55fec997c030
    0xFE    0x55fec997c031
    0xAB    0x55fec997c032
    0xCD    0x55fec997c033
    0x11    0x55fec997c034
    0x11    0x55fec997c035
    0x23    0x55fec997c036
    0x34    0x55fec997c037
    *x      &x
*/

int main()
{
    char *addr = (char*)&x;
    printf("Value of x is %d\n", *addr); // This will fetch 1 byte of data stored in x
    printf("Address of x is %p\n", addr);

    for (char i = 0; i < 7; i++)
    {
        addr++;
        printf("Value of x is %d\n", *addr);
        printf("Address of x is %p\n", addr);
    }
    
    return 0;
}
