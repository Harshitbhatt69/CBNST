/*
for equation 10x - 5y - 2z = 3
			  4x - 10y + 3z = 3
			   x + 6y + 10z = -3
*/
#include<stdio.h>
#include<math.h>
#define pf printf
#define sf scanf
#define err 0.0001
int ite;
float solnx(float y, float z)
{
	return (3 + (2 * z) + (5 * y)) / 10;
}
float solny(float x, float z)
{
	return ((4 * x) + (3 * z) + 3) / 10;
}
float solnz(float x, float y)
{
	return (-(6 * y) - 3 - x) / 10;
}
void soln(float arr[3][4])
{
	float x = 0, y = 0, z = 0;
	x = solnx(0, 0);
	y = solny(0, 0);
	z = solnz(0, 0);
	ite--;
	while (ite--)
	{
		float tempx = x;
		float tempy = y;
		float tempz = z;
		pf("value of old x: %f, y: %f, z:%f\n", tempx, tempy, tempz);
		//finding new x,y,z from old tempx,tempy,tempz
		x = solnx(tempy, tempz);
		y = solny(tempx, tempz);
		z = solnz(tempx, tempy);
		pf("value of new x: %f, y: %f, z:%f\n", x, y, z);
		if ((fabs(tempx - x) < err) || (fabs(tempy - y) < err) || (fabs(tempz - z) < err))
		{
			pf("Iteration used: %d \n", 17 - ite);
			pf("Root found... \n");
			pf("Value of x: %f, y: %f, z: %f", x, y, z);
			return;
		}
	}
	pf("Value of x: %f, y: %f, z: %f", x, y, z);
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// pf("Enter the number of iterations");
	ite = 17;
	float arr[3][4];
	arr[0][0] = 10;
	arr[0][1] = -5;
	arr[0][2] = -2;
	arr[0][3] = 3;
	arr[1][0] = 4;
	arr[1][1] = -10;
	arr[1][2] = 3;
	arr[1][3] = -3;
	arr[2][0] = 1;
	arr[2][1] = 6;
	arr[2][2] = 10;
	arr[2][3] = -3;
	soln(arr);
	return 0;
}