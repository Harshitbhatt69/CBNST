//Gause elemenation
#include<stdio.h>
#define ll long long
#define pf printf
#define sf scanf
// #define error 0.001
int n;
void upperTriangularMatrix(float arr[n][n + 1])
{
    for (int i = 0; i < n; ++i) //i for rows
    {
        for (int j = 0; j < n; ++j) //j for colbs
        {
            if (j != i)  //skipping (0,0)
            {
                float ratio = arr[j][i] / arr[i][i];
                for (int k = 0; k < n + 1; k++)
                {
                    arr[j][k] -= ratio * arr[i][k];    //2nd row - 1st row
                }
            }
            pf("Intermediate forms: \n");
            for (int a = 0; a < n; ++a)
            {
                for (int b = 0; b < n + 1; ++b)
                {
                    pf("%f\t", arr[a][b]);
                }
                pf("\n");
            }
            pf("\n");
        }
    }
}
void findVals(float arr[n][n + 1])
{
    for (int i = 0; i < n; i++)
    {
        printf("Value of unknown %d = %f\n", i + 1, arr[i][n] / arr[i][i]);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    pf("Enter total number of unknowns\n");
    sf("%d", &n);
    float arr[n][n + 1];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n + 1; ++j)
        {
            sf("%f", &arr[i][j]);
        }
    }
    upperTriangularMatrix(arr);  //upper triangular matrix
    findVals(arr);   //back substitution
    return 0;
}