#include <iostream>
#include <string>
#include <regex>
#include <ctime>
#include <stdlib.h>
#include <unistd.h>
#include <cctype>
#include <cstring>
#include <stdio.h>
#include <cstdio>
using namespace std;

unsigned int microseconds;
time_t now;
tm* ltm;

//El password no debe contener el nombre de usuario.
bool checkforPasswordNotHaveUsername(string password, string username)
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
		return true;
	}
	else
	{
		return false;
	}
}
//El password debe contener al menos una mayúscula.
bool checkforPasswordHaveAtLeastOneCapitalLetter(string password)
{
	for (int i = 0; i < password.size(); i++)
	{
		if (isupper(password[i]))
		{
			return true;
		}
	}
	return false;
}
//El password debe contener al menos una minúscula.
bool checkforPasswordHaveAtLeastOneLowercase(string password)
{
	for (int i = 0; i < password.size(); i++)
	{
		if (islower(password[i]))
		{
			return true;
		}
	}
	return false;
}
//El password debe contener al menos un carácter no alfanumérico.
bool checkforPasswordHaveAtLeastOneNonAlfanumericItem(string password)
{
	for (int i = 0; i < password.size(); i++)
	{
		if ( (password[i]<48) or (password[i]>57 and password[i]<65) or (password[i]>90 and password[i]<97) or (password[i]>122) )
		{
			return true;
		}
	}
	return false;
}
//El password no debe repetir ningún carácter tres veces consecutivos.
bool checkforPasswordNotHaveThreeSameCharacters(string password)
{
	bool temp=true;
	for (int i = 0; i < password.size()-2; i++)
	{
		if (password[i]==password[i+1] and password[i+1]==password[i+2])
		{
			temp=false; //HaveThreeSameCharacters
		}
	}
	return temp;
}

//El password solo se puede digitar de 8 am a 10 am. Tomará de referencia la hora del ordenador donde corre el programa.
bool checkforPasswordOnlyBetween8and10AM()
{
	now = time(0);
	ltm = localtime(&now);

	if ( ((1 + ltm->tm_hour) >= 8 and (1 + ltm->tm_min) >= 0 and (1 + ltm->tm_sec) >= 0 ) and
		 ((1 + ltm->tm_hour) <= 10 and (1 + ltm->tm_min) <= 0 and (1 + ltm->tm_sec) <= 0 ) )
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main() {
	string user = "FabrizioFlores";
	string password = "ThisIsASecurePassw0rd!";
	bool programLife = true;
	string teststring;
	string inputuser, inputpassword;
	

	cout << "Ingrese su usuario por favor:"<<endl;
	cin >> inputuser;
	while (inputuser!=user)
	{
		cout << "Usuario invalido, intente denuevo:" << endl;
		cin >> inputuser;
	}
	cout<<"Usuario Correcto!"<<endl;
	clock_t start;
    double duration;
    int counter=0;
    now = time(0);
	ltm = localtime(&now);
	cout<<"Hora Local: "<<(1 + ltm->tm_hour)<<":" << (1 + ltm->tm_min)<<":" << (1 + ltm->tm_sec) <<endl;
    if (checkforPasswordOnlyBetween8and10AM() == true)
	{
		cout<<"La hora de ingreso es la permitida :)"<<endl;
		start = clock();
		duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
		
		while (counter!=3 and duration<61)
		{
			cout<<"Ingrese su contraseña por favor:"<<endl;
			cin>>inputpassword;
			counter++;

			cout<<"Intentos en menos de 60 segundos: "<<counter<<endl;
			duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
			cout<<"Tiempo: "<<duration<<" Segundos."<<endl;

			bool PasswordNotHaveUsername = checkforPasswordNotHaveUsername(inputpassword,inputuser);
			bool PasswordHaveAtLeastOneCapitalLetter = checkforPasswordHaveAtLeastOneCapitalLetter(inputpassword);
			bool PasswordHaveAtLeastOneLowercase = checkforPasswordHaveAtLeastOneLowercase(inputpassword);
			bool PasswordHaveAtLeastOneNonAlfanumericItem = checkforPasswordHaveAtLeastOneNonAlfanumericItem(inputpassword);
			bool PasswordNotHaveThreeSameCharacters = checkforPasswordNotHaveThreeSameCharacters(inputpassword);
			if (PasswordNotHaveUsername==true and 
				PasswordHaveAtLeastOneCapitalLetter==true and
				PasswordHaveAtLeastOneLowercase==true and
				PasswordHaveAtLeastOneNonAlfanumericItem==true and
				PasswordNotHaveThreeSameCharacters == true and inputpassword==password)
			{
				cout<<"Contraseña Correcta, Felicidades!"<<endl;
				cout<<"Bienvenido: "<<inputuser<<endl;
				system("PAUSE");
				system("CLS");
				break;
			}
			else 
			{
				cout<<"Se equivoco en la contraseña."<<endl;
				if (PasswordNotHaveUsername == false)
				{
					cout<<"Su contraseña tiene dentro su usuario"<<endl;
				}
				if (PasswordHaveAtLeastOneCapitalLetter == false)
				{
					cout<<"Su contraseña no tiene por lo menos una letra mayuscula"<<endl;
				}
				if (PasswordHaveAtLeastOneLowercase == false)
				{
					cout<<"Su contraseña no tiene por lo menos una letra minuscula"<<endl;
				}
				if (PasswordHaveAtLeastOneNonAlfanumericItem == false)
				{
					cout<<"Su contraseña no tiene por lo menos un caracter no alfanumerico"<<endl;
				}
				if (PasswordNotHaveThreeSameCharacters == false)
				{
					cout<<"Su contraseña tiene 3 caracteres iguales consecutivos"<<endl;
				}
				if (inputpassword != password)
				{
					cout<<"La contraseña no coincide con la cuenta"<<endl;
				}

				//duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
				if (counter<3 and duration>60) //Si el numero de intentos es menor a 3 pero el contador sobrepasa los 60 segundos, los intentos se reinician
				{
					counter=0;
					start = clock();
				}
				if (counter == 3 and duration < 61)
				{
					cout<<"Su usuario sera bloqueado por 3 intentos fallidos en menos de 60 segundos"<<endl;
					cout<<"Si desea reiniciar el contador de intentos y de tiempo escriba: hackear"<<endl;
					string hack2;cin>>hack2;
					if (hack2=="hackear")
					{
						counter=0;
						start = clock();
						cout<<"Usted hackeo el sistema :O ! "<<endl;
					}
					else
					{
						cout<<"Bloqueando..."<<endl;
					}
				}
			}				
		}
	}
	else
	{
		cout<<"Alternativo, escriba 'hackear' para poder ingresar la contraseña:"<<endl;
		string hackval; cin>>hackval;
		if (hackval=="hackear")
		{
			start = clock();
		duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
		
		while (counter!=3 and duration<61)
		{
			cout<<"Ingrese su contraseña por favor:"<<endl;
			cin>>inputpassword;
			counter++;

			cout<<"Intentos en menos de 60 segundos: "<<counter<<endl;
			duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
			cout<<"Tiempo: "<<duration<<" Segundos."<<endl;

			bool PasswordNotHaveUsername = checkforPasswordNotHaveUsername(inputpassword,inputuser);
			bool PasswordHaveAtLeastOneCapitalLetter = checkforPasswordHaveAtLeastOneCapitalLetter(inputpassword);
			bool PasswordHaveAtLeastOneLowercase = checkforPasswordHaveAtLeastOneLowercase(inputpassword);
			bool PasswordHaveAtLeastOneNonAlfanumericItem = checkforPasswordHaveAtLeastOneNonAlfanumericItem(inputpassword);
			bool PasswordNotHaveThreeSameCharacters = checkforPasswordNotHaveThreeSameCharacters(inputpassword);
			if (PasswordNotHaveUsername==true and 
				PasswordHaveAtLeastOneCapitalLetter==true and
				PasswordHaveAtLeastOneLowercase==true and
				PasswordHaveAtLeastOneNonAlfanumericItem==true and
				PasswordNotHaveThreeSameCharacters == true and inputpassword==password)
			{
				cout<<"Contraseña Correcta, Felicidades!"<<endl;
				cout<<"Bienvenido: "<<inputuser<<endl;
				system("PAUSE");
				system("CLS");
				break;
			}
			else 
			{
				cout<<"Se equivoco en la contraseña."<<endl;
				if (PasswordNotHaveUsername == false)
				{
					cout<<"Su contraseña tiene dentro su usuario"<<endl;
				}
				if (PasswordHaveAtLeastOneCapitalLetter == false)
				{
					cout<<"Su contraseña no tiene por lo menos una letra mayuscula"<<endl;
				}
				if (PasswordHaveAtLeastOneLowercase == false)
				{
					cout<<"Su contraseña no tiene por lo menos una letra minuscula"<<endl;
				}
				if (PasswordHaveAtLeastOneNonAlfanumericItem == false)
				{
					cout<<"Su contraseña no tiene por lo menos un caracter no alfanumerico"<<endl;
				}
				if (PasswordNotHaveThreeSameCharacters == false)
				{
					cout<<"Su contraseña tiene 3 caracteres iguales consecutivos"<<endl;
				}
				if (inputpassword != password)
				{
					cout<<"La contraseña no coincide con la cuenta"<<endl;
				}

				//duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
				if (counter<3 and duration>60) //Si el numero de intentos es menor a 3 pero el contador sobrepasa los 60 segundos, los intentos se reinician
				{
					counter=0;
					start = clock();
				}
				if (counter == 3 and duration < 61)
				{
					cout<<"Su usuario sera bloqueado por 3 intentos fallidos en menos de 60 segundos"<<endl;
					cout<<"Si desea reiniciar el contador de intentos y de tiempo escriba: hackear"<<endl;
					string hack2;cin>>hack2;
					if (hack2=="hackear")
					{
						counter=0;
						start = clock();
						cout<<"Usted hackeo el sistema :O ! "<<endl;
					}
					else
					{
						cout<<"Bloqueando..."<<endl;
					}
				}
			}				
		}
		}
		else	
		{
			cout<<"Adios"<<endl;
		}
	}


	
	return 0;
}


