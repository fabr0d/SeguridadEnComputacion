#include <iostream>
#include <string>
#include <regex>
#include <ctime>
#include <stdlib.h>
using namespace std;

string alfabetoMayuscula = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
string alfabetoMinuscula = { "abcdefghijklmnopqrstuvwxyz" };
string numeros = { "0123456789" };

bool checkofequalusername(string password, string username)
{
	int count2 = 0;
	for (int i = 0; i < password.size(); i++)
	{
		if (password[i]==username[count2])
		{
			count2++;
		}
		else
		{
			count2 = 0;
		}
	}
	if (count2!=username.size())
	{
		return false;
	}
	else
	{
		true;
	}
}

bool checkforMayus(string password, string username)
{

}

bool checkforMinus(string password, string username)
{

}

bool checkforNoAlfanumeric(string password, string username)
{

}

bool checkforThreeSameLetters(string password, string username)
{

}

bool checkforUserCorrectButIncorrectPasswordThreeTimeIn60Seconds(string password, string username)
{

}

bool checkforPasswordOnlyBetween8and10AM(string password, string username)
{

}

int main() {
	string user = "FabrizioFlores";
	string password = "ThisIsASecurePassw0rd!";

	while (true)
	{
		string inputuser, inputpassword;
		cout << "Ingrese su usuario por favor:";
		cin >> inputuser;
		if (inputuser==user)
		{
			cout << "ingrese su password por favor:";
			if (checkofequalusername(inputpassword,inputuser)==true)
			{
				cout << "El password contiene dentro su username" << endl;
				cout << "reingrese su passwordl por favor" << endl;
			}
			else if (checkforMayus(inputpassword, inputuser)==true)
			{

			}
			else if (checkforMinus(inputpassword, inputuser) == true)
			{

			}
			else if (checkforNoAlfanumeric(inputpassword, inputuser) == true)
			{

			}
			else if (checkforThreeSameLetters(inputpassword, inputuser) == true)
			{

			}
			else if (checkforUserCorrectButIncorrectPasswordThreeTimeIn60Seconds(inputpassword, inputuser) == true)
			{

			}
			else if (checkforPasswordOnlyBetween8and10AM(inputpassword, inputuser) == true)
			{

			}
		}
		else
		{
			cout << "Usuario invalido" << endl;
			cout << " ingrese usuario denuevo" << endl;
			continue;
		}

	}
	//cin >> cadena;
	//isip(cadena);
	//isvarname(cadena);
	
	// current date/time based on current system
	time_t now = time(0);

	cout << "Number of sec since January 1,1970:" << now << endl;

	tm* ltm = localtime(&now);

	// print various components of tm structure.
	cout << "Year:" << 1900 + ltm->tm_year << endl;
	cout << "Month: " << 1 + ltm->tm_mon << endl;
	cout << "Day: " << ltm->tm_mday << endl;
	cout << "Time: " << 1 + ltm->tm_hour << ":";
	cout << 1 + ltm->tm_min << ":";
	cout << 1 + ltm->tm_sec << endl;


	return 0;
}

/*

Objetivo.
Trabajo individual donde el alumno realizará un programa pequeño de control de acceso con password
Procedimiento:
El alumno implementará en cualquiera de los siguientes lenguajes de programación: C++ o en Python. El
programa deberá pedir un usuario, un password y devolverá la información de que dicho password cumple
o no con las políticas indicadas más adelante y tiene acceso o no.
El usuario y password lo establecerá previamente e implementará en su programa
El alumno preparará un software y lo enviará desde su correo institucional al correo eheredia@ucsp.edu.pe

Políticas de password:
1. El usuario será su nombre y su apellido y el password deberá de tener por lo menos 8 caracteres,
Cualquier otro usuario no permitirá el acceso.
2. El password no debe contener el nombre de usuario.
3. El password debe contener al menos una mayúscula.
4. El password debe contener al menos una minúscula.
5. El password debe contener al menos un carácter no alfanumérico.
6. El password no debe repetir ningún carácter tres veces consecutivos.
7. Si el usuario es correcto y el password falla más de 3 veces en 60 segundos debe indicar que
posteriormente se bloqueara al usuario (solo indicar que se bloqueará, para poder hacer las
pruebas)
8. El password solo se puede digitar de 8 am a 10 am. Tomará de referencia la hora del ordenador
donde corre el programa.
*/

