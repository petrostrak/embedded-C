#include <stdio.h>
#include <stdint.h>
#include <math.h>

/*
Write a program to calculate the area of different
geometrical figures, -circle, trianle, trapezoid, square
and rectangle
*/

uint8_t get_geometrical_figure();
void calculate_triangle();
void calculate_trapezoid();
void calculate_circle();
void calculate_circle();
void calculate_square();
void calculate_rectangle();

char geometrical_figure;

int main(int argc, char const *argv[])
{
    printf("--- Area Calculation ---\n");
    printf("Triangle    --> t\n");
    printf("Trapezoid   --> z\n");
    printf("Circle      --> c\n");
    printf("Square      --> s\n");
    printf("Rectangle   --> r\n");
    geometrical_figure = get_geometrical_figure();
    switch (geometrical_figure)
    {
    case 't':
        calculate_triangle();
        break;
    case 'z':
        calculate_trapezoid();
        break;
    case 'c':
        calculate_circle();
        break;
    case 's':
        calculate_square();
        break;
    default:
        calculate_rectangle();
        break;
    }

    return 0;
}

uint8_t get_geometrical_figure() {
    printf("Choose a geometrical figure 't, z, c, s, r': ");
    scanf("%c", &geometrical_figure);

    return geometrical_figure;
}

void calculate_triangle() {
    float base, height;
    printf("In order to calculate the area of the triagle, provide the base and the height: ");
    scanf("%f%f", &base, &height);
    printf("The area of the triangle is %f\n", (height * base) / 2);
}

void calculate_trapezoid() {
    float base1, base2, height;
    printf("In order to calculate the area of the trapezoid, provide the base1, base2 and the height: ");
    scanf("%f%f%f", &base1, &base2, &height);
    printf("The area of the trapezoid is %f\n", ((base1 + base2) / 2) * height);
}

void calculate_circle() {
    float radius;
    printf("In order to calculate the area of the circle, provide the radius: ");
    scanf("%f", &radius);
    printf("The area of the circle is %f\n", M_PI * pow(radius, 2.0));
}

void calculate_square() {
    float side;
    printf("In order to calculate the area of the square, provide the side: ");
    scanf("%f", &side);
    printf("The area of the square is %f\n", pow(side, 2.0));
}

void calculate_rectangle() {
    float side1, side2;
    printf("In order to calculate the area of the rectangle, provide the side1 and side2: ");
    scanf("%f%f", &side1, &side2);
    printf("The area of the rectangle is %0.00f\n", side1 * side2);
}