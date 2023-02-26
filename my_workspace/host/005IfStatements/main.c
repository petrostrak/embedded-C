#include <stdio.h>
#include <stdint.h>

int main()
{
    uint8_t age;
    printf("What is your age?");
    scanf("%d", &age);

    if (age < 18)
    {
        printf("Sorry, the minimum age for casting a vote is 18 years.\n");
        
    } else {
        printf("You can vote!\n");
    }

    return 0;
}
