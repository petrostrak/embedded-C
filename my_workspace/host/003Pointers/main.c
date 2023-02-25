#include <stdio.h>

int main()
{
    char x = 100;
    printf("The address of x is %p\n", &x);

    char* ptr_x = (char*)&x; // create a pointer var and store the address of x
    char value_of_x = *ptr_x;
    printf("The value of ptr_x is %d and the actual size of it is %d\n",value_of_x, sizeof(value_of_x));

    *ptr_x = 65; // perform write operation on the pointer to store the value 65
    printf("The new value of ptr_x is %d\n", *ptr_x);
    
    return 0;
}
