#include<iostream>
#include<string>
#include<unistd.h>
#include"registros.h"
#include"menu.h"
using namespace std;

USUARIOS us[100];
 
void registro(){//menú para la opción 1.Registro
	int op;
	do{
		cout<<"--------------------------------------"<<endl;
		cout<<"1. Ingresar Datos personales\n";
		cout<<"2. Volver\n";
		cout<<"--------------------------------------"<<endl;
		cout<<"Selecione una opcion: ";cin>>op;
		switch(op){
			case 1:
				system("cls");
				ingresardt(a);//Al mandar una copia de a, estoy mandando el indice donde quiero que se guarden los datos de un usuario
				a++;
				return;
				break;
			case 2:
				system("cls");
				break;
			default:
        		system("cls");
            	break;
			}
	}while(op!=2);
}

void ingresardt(int x){//Registro de datos
	cout<<"--------------------------------------"<<endl;
	cout<<"DNI: ";cin>>us[x].dni;
	cin.ignore();
	cout<<"Nombres: ";getline(cin, us[x].nombres);
	cout<<"Apellidos: ";getline(cin, us[x].apellidos);
	cout<<"--------------------------------------"<<endl;
	system("pause");
	system("cls");
}

void iniciosesion(){//menú para la opción 2. Iniciar sesión
	int op,a;
	do{
		cout<<"--------------------------------------"<<endl;
		cout<<"1. Ingresar DNI\n";
		cout<<"2. Volver\n";
		cout<<"--------------------------------------"<<endl;
		cout<<"Selecione una opcion: ";cin>>op;
		switch(op){
			case 1:
				system("cls");
				cout<<"DNI: ";cin>>a;
				for(int i=0;i<100;i++){//Verificar si el dni esta registrado
					if(a==us[i].dni){//Compara el dni ingresado con los demás registrados anteriormente
						system("cls");
						while(true){
							if(us[i].menperso==0){ //<-- Cuando el usuario no se haya registrado al SDS
								menu2(i);//<-- si se cumple el if llamaría a la función señalada
							}
							if(us[i].menperso==1){//<-- Este if funcionara cuando vuelva del registro al SDS, para abrir un menu perzonalizado
								menu2(i);				
							}
							if(us[i].x==1){
								break;//<- cuando us[i].x sea igual a 1 el bucle rompera, permitiendo cerrar sesión de forma correcta
								us[i].x=0;
							}
						}
						return;
					}
				}
				//En caso de que no se cumpla
				system("cls");
				cout<<"DNI mal ingresado o no esta registrado\n";
				system("pause");
				system("cls");
				return;
				break;
			case 2:
				system("cls");
				break;
			default:
        		system("cls");
            	break;
		}
	}while(op!=2);
}
