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
            if (j > i)  //skipping (0,0)
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
void backSubstitution(float arr[n][n + 1])
{
    float value[n];
    value[n - 1] = arr[n - 1][n] / arr[n - 1][n - 1];   //back substitution
    for (int i = n - 2; i >= 0; --i)
    {
        float sum = 0;
        for (int j = i + 1; j < n; ++j)
        {
            sum = sum + arr[i][j] * value[j];
        }
        value[i] = (arr[i][n] - sum) / arr[i][i];
    }
    for (int i = 0; i < n; ++i)
        pf("unknown %d: %f\n", i + 1, value[i]);
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
    backSubstitution(arr);   //back substitution
    return 0;
}