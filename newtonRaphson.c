//newtonRaphson method
//for x*x*x -3x -5 = 0
#include<stdio.h>
#include<math.h>
#define pf printf
#define sf scanf
float eqn(float x)
{
	return (x * x * x - 3 * x - 5);
}
float eqn1(float x)
{
	return (3 * x * x - 3);
}
float diff(float x)
{

}
int main(int argc, char const *argv[])
{
	int x1, x2;
	do {
		pf("Enter the point x1 and x2\n");
		sf("%d %d", &x1, &x2);
		if (eqn(x1)*eqn(x2) < 0)
			break;
		else
			pf("Wrong value, Try again!\n");
	} while (1)
		int x0;
	if (x1 > x2)
		x0 = x2;
	else
		x0 = x1;
	int ite;
	pf("Enter number of iterations\n");
	sf("%d", &ite);
	while (ite--)
	{

	}
	return 0;
}