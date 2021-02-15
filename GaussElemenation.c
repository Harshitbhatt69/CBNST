//	Gauss elemenation method
#include <stdio.h>
#define pf printf
#define sf scanf
int n;
void output(float ar[n][n + 1]);
void inputoutput()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
void upperTriangular(float arr[n][n + 1])
{
	float ratio;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n + 1; ++j)
		{
			if (i < j)
			{
				ratio = arr[j][i] / arr[i][i];
				for (int k = 0; k < n + 1; ++k)
				{
					arr[j][k] -= ratio * (arr[i][k]);
				}
			}
		}
		output(arr);
		pf("=================\n");
	}
	// output(arr);
}
void backSubs(float arr[][n + 1])
{
	int i, j;
	float value[n];
	float sum;
	value[n - 1] = arr[n - 1][n] / arr[n - 1][n - 1];
	for (i = n - 2; i >= 0; i--)
	{
		sum = 0;
		for (j = i + 1; j < n; j++)
			sum = sum + arr[i][j] * value[j];
		value[i] = (arr[i][n] - sum) / arr[i][i];
	}
	for (int i = 0; i < n; ++i)
	{
		pf("%f ", value[i]);
	}
}
void  output(float arr[n][n + 1])
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n + 1; ++j)
		{
			pf("%f ", arr[i][j]);
		}
		pf("\n");
	}
}
int main(int argc, char const *argv[])
{
	inputoutput();
	pf("Enter the total number of unknown\n");
	sf("%d", &n);
	float arr[n][n + 1];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n + 1; ++j)
		{
			sf("%f", &arr[i][j]);
		}
	}
	upperTriangular(arr);
	backSubs(arr);
	return 0;
}
