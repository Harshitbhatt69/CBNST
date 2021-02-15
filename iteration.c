#include<stdio.h>
#include<math.h>
#define EPSILON 0.0001

float valueoffx(float x)
{
    return x * x * x + x * x - 1;
}
float findvalueat(float x)
{
    return 1 / sqrt(1 + x);
}
float diff(float x)
{
    return 1 / 2.0 * pow(1, pow((1 + x), 3 / 2.0));
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int maxIteration, i;
    float a, b, x, x0;
    printf("Enter max. number of iterations =>");
    scanf("%d", &maxIteration);
    do
    {
        printf("Enter the value of a and b(starting boundary)=>");
        scanf("%f%f", &a, &b);
        if (valueoffx(a)*valueoffx(b) > 0)
        {
            printf("Boundary values are invalid");
            continue;
        }
        else
        {
            printf("\n\nRoots lie between %f and %f\n", a, b);
            break;
        }
    } while (1);
    x0 = (a + b) / 2;
    if (diff(x0) < 1)
        printf("\nCorrect function form. Iteration method can be applied\n\n");
    else
        printf("Incorrect function form. Iteration method cant be applied\n\n");
    for (i = 1; i <= maxIteration; i++)
    {
        x = findvalueat(x0);
        if (fabs(x - x0) < EPSILON)
        {
            printf("Iterations =%d, Final root=%f", i, x);
            return 0;
        }
        printf("Iteration = %d,Root = %f\n", i, x);
        x0 = x;
    }
    printf("Root = %f, Total iterations=%d", x, --i);
    return 0;
}