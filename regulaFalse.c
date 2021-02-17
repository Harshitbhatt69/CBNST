#include<stdio.h>
#include<math.h>
#define EPSILON 0.001
float findvalueat(float x)
{
    return x * x * x - 2 * x - 5;
}
int main()
{
    int maxIteration, i = 1;
    float x1, x2, x, x3;
    printf("Enter maximum number of iterations =>");
    scanf("%d", &maxIteration);
    do
    {
        printf("Enter the value for x1 and x2\t");
        scanf("%f %f", &x1, &x2);
        if (findvalueat(x1)*findvalueat(x2) > 0)
        {
            printf("Roots are invalid");
            continue;
        }
        else
            /*{
                printf("Roots lie between %f and %f\n", x1, x2);
            }*/
            break;
    } while (1);
    x = (x1 * findvalueat(x2) - x2 * findvalueat(x1)) / (findvalueat(x2) - findvalueat(x1));
    do
    {
        if (findvalueat(x1)*findvalueat(x) < 0)
            x2 = x;
        else if (findvalueat(x)*findvalueat(x2) < 0)
            x1 = x;

        x3 = (x1 * findvalueat(x2) - x2 * findvalueat(x1)) / (findvalueat(x2) - findvalueat(x1));
        if (fabs(x3 - x) < EPSILON)     // 3 correct decimal places
        {
            printf("\n\nRoot  = %f Total iterations = %d (approx)", x, i--);
            return 0;
        }
        printf("Iterations = %d Roots = %f\n", i, x);
        x = x3;
        i++;
    } while (i <= maxIteration);
    printf("\n\nRoot = %f Total iterations = %d (approx)", x, --i);
    return 0;
}