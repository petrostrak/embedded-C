#include<stdarg.h>

int addition(int count, ...)
{
  va_list args;
  int i, sum;

  va_start (args, count);

  sum = 0;
  for (i = 0; i < count; i++)
    sum += va_arg (args, int);

  va_end (args);
  return sum;
}

int subtraction(int count, ...)
{
    va_list args;
    int i, sum = 0;
    for ( i = 0; i < count; i++)
    {
        sum -= va_arg(args, int);
    }

    va_end(args);
    return sum;
}

int multiplication(int a, int b)
{
    return a * b;
}

int division(int a, int b)
{
    return a / b;
}