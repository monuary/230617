#include<cmath>
#include<iostream>
using namespace std;

double x1 = -0.0523;
double x2 = -0.1523;
double x3 = 1.1950;

double p1 = 0.66;
double p2 = -2.868;
double p3 = -1.229;

double v1 = 1;
double v2 = 1.05;
double v3 = x3;

double G1 = -0.5;
double G2 = 0.999;

double B1 = 10;
double B2 = -19.98;

int main()
{
	double y1 = p1 - v2 * v1 * (G1 * cos(x1) + B1 * sin(x1)) - v2 * v2 * G2 - v2 * v3 * (G1 * cos(x1 - x2) + B1 * sin(x1 - x2));
	double y2 = p2 - v3 * v1 * (G1 * cos(x2) + B1 * sin(x2)) - v3 * v2 * (G1 * cos(x2 - x1) + B1 * sin(x2 - x1)) - v3 * v3 * G2;
	double y3 = p3 - v3 * v1 * (G1 * sin(x2) - B1 * cos(x2)) - v3 * v2 * (G1 * sin(x2 - x1) - B1 * cos(x2 - x1)) - v3 * v3 * (-B2);

	double j1 = v2 * v1 * ((-G1) * sin(x1) + B1 * cos(x1)) + v2 * v3 * ((-G1) * sin(x1 - x2) + B1 * cos(x1 - x2));
	double j2 = v2 * v3 * (G1 * sin(x1 - x2) - B1 * cos(x1 - x2));
	double j3 = v2 * (G1 * cos(x1 - x2) + B1 * sin(x1 - x2));
	double j4 = v3 * v2 * (G1 * sin(x2 - x1) - B1 * cos(x2 - x1));
	double j5 = v3 * v1 * ((-G1) * sin(x2) + B1 * cos(x2)) + v3 * v2 * ((-G1) * sin(x2 - x1) + B1 * cos(x2 - x1));
	double j6 = v1 * (G1 * cos(x2) + B1 * sin(x2)) + v2 * (G1 * cos(x2 - x1) + B1 * sin(x2 - x1)) + 2 * v3 * G2;
	double j7 = v3 * v2 * ((-G1) * cos(x2 - x1) - B1 * sin(x2 - x1));
	double j8 = v3 * v1 * (G1 * cos(x2) + B1 * sin(x2)) - v3 * v2 * (G1 * cos(x2 - x1) + B1 * cos(x2 - x1));
	double j9 = v1 * (G1 * sin(x2) - B1 * cos(x2)) - v2 * (G1 * sin(x2 - x1) - B1 * cos(x2 - x1)) - 2 * v3 * (-B2);

	double detJ = j1 * (j5 * j9 - j6 * j8) - j2 * (j4 * j9 - j6 * j7) + j3 * (j4 * j8 - j5 * j7);

	double J1 = (j5 * j9 - j6 * j8) / detJ;
	double J2 = -(j2 * j9 - j3 * j8) / detJ;
	double J3 = (j2 * j6 - j3 * j5) / detJ;
	double J4 = -(j4 * j9 - j6 * j7) / detJ;
	double J5 = (j1 * j9 - j3 * j7) / detJ;
	double J6 = -(j1 * j6 - j3 * j4) / detJ;
	double J7 = (j4 * j8 - j5 * j7) / detJ;
	double J8 = -(j1 * j8 - j2 * j7) / detJ;
	double J9 = (j1 * j5 - j2 * j4) / detJ;

	double dx1 = J1 * y1 + J2 * y2 + J3 * y3;
	double dx2 = J4 * y1 + J5 * y2 + J6 * y3;
	double dx3 = J7 * y1 + J8 * y2 + J9 * y3;

	double X1 = x1 + dx1;
	double X2 = x2 + dx2;
	double X3 = x3 + dx3;

	cout << "y1 : " << y1 << endl;
	cout << "y2 : " << y2 << endl;
	cout << "y3 : " << y3 << endl;
	cout << "X1 : " << X1 << endl;
	cout << "X2 : " << X2 << endl;
	cout << "X3 : " << X3 << endl;
}