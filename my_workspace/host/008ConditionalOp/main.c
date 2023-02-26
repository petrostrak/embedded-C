#include <stdio.h>
#include <stdint.h>

uint8_t get_age();

int main(int argc, char const *argv[])
{
    uint8_t age = get_age();
    (age < 18) ? printf("You are not eligible to vote\n") : printf("You are eligible to vote\n");
    return 0;
}

uint8_t get_age()
{
    uint8_t age;
    printf("Enter your age: ");
    scanf("%d", &age);

    return age; 
}
