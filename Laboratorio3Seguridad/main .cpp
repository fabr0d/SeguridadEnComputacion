#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<double> equis;
vector<double> yes;

int main()
{
	//y=A*pow(e,(B*x));
	cout << "ingrese cantidad de hora: " << endl;
	double horas; cin >> horas;
	double E_x = 0;
	double E_lnY = 0;
	double E_Yprima_por_X = 0;
	double E_powX = 0;
	for (size_t i = 0; i < horas; i++)
	{
		equis.push_back(i+1);
		E_x = E_x + equis[i];
	}
	cout << "ingrese las y's" << endl;
	double slave;
	for (size_t i = 0; i < horas; i++)
	{
		cin >> slave;
		yes.push_back(slave);
	}
	vector<double>lnY;
	for (size_t i = 0; i < horas; i++)
	{
		double LocalSlave = log(yes[i]);
		//cout << " E_xLocalSlave " << LocalSlave << endl;
		lnY.push_back(LocalSlave);
		E_lnY = E_lnY + lnY[i];
	}
	vector<double>Yprima_por_X;
	for (size_t i = 0; i < horas; i++)
	{
		double LocalSlave = lnY[i] * equis[i];
		//cout << " Yprima_por_XLocalSlave " << LocalSlave << endl;
		Yprima_por_X.push_back(LocalSlave);
		E_Yprima_por_X = E_Yprima_por_X + Yprima_por_X[i];
	}
	vector<double>powX;
	for (size_t i = 0; i < horas; i++)
	{
		double LocalSlave = pow(equis[i], 2);
		//cout << " powXLocalSlave " << LocalSlave << endl;
		powX.push_back(LocalSlave);
		E_powX = E_powX + powX[i];
	}
	//cout << " E_x: " << E_x << endl;
	//cout << " E_lnY: " << E_lnY << endl;
	//cout << " E_Yprima_por_X: " << E_Yprima_por_X << endl;
	//cout << " E_powX: " << E_powX << endl;
	double B = (horas * E_Yprima_por_X - E_x * E_lnY) / (horas * E_powX - pow(E_x, 2));
	//cout << "B: " << B << endl;
	double A_prima = (E_lnY / horas) - B * (E_x / horas);
	//cout << "A_prima: " << A_prima << endl;
	double A = log(A_prima);
	//cout << "A: " << A << endl;
	cout << "y = " << A << " * e ^ (" << B << " *x)" << endl;
	cout << "ingrese las horas en el que quiere saber la cantidad de infectados: " << endl;
	double slaveX; cin >> slaveX;
	cout << "La cantidad de infectados sera: " << A * exp(B * slaveX) << endl;

}
//nota no poner ceros causa que algunos calculos den infinito
//Cantidad de X's o horas
//40
//las y's
//1 6 8 11 12 20 28 39 58 86 106 135 193 256 313 344 383 416 480 580 634 669 807 950 1065 1319 1414 1594 1756 2281 2561 2954 4342 5256 5897 6848 7519 9784 10303 11475