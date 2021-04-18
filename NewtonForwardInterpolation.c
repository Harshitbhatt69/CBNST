#include <stdio.h>
#define pf printf
#define sf scanf
void inputoutput()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int main(int argc, char const *argv[])
{
	inputoutput();
	int n;
	pf("Enter no. of terms\n\n");
	sf("%d", &n);
	float arr[100][100];

	pf("Enter the value of X\n\n");
	for (int i = 0; i < n; ++i)
		sf("%f", &arr[i][0]);

	pf("Enter the value of Y\n\n");
	for (int i = 0; i < n; ++i)
		sf("%f", &arr[i][1]);

	float x;
	pf("Enter the value of X which you want\n\n");
	sf("%f", &x);

	//difference table
	pf("Difference Table\n\n");
	for (int i = 2; i < n + 1; ++i)
	{
		for (int j = 0; j < n + 1 - i; ++j)
		{
			arr[j][i] = arr[j + 1][i - 1] - arr[j][i - 1];
		}
	}

	//difference table o/p
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= n - i; j++)
		{
			pf("%f", arr[i][j]);
		}
		pf("\n");
	}

	float u = (x - arr[0][0]) / (arr[1][0] - arr[0][0]);
	float y = arr[0][1];	//y = f(x)
	float u1 = u;
	int fact = 1;
	for (int i = 2; i <= n; ++i)
	{
		y += u1 * arr[0][i] / fact;
		u1 *= (u - (i - 1));
		fact *= i;
	}
	pf("\n\n Value at X=%g is =%f", x, y);
	return 0;
}