#include<iostream>
#include<unistd.h>
#include<ctime>
#include<string>
using namespace std;
int a=0;
struct USUARIOS{
	int dni;
	string nombres;
	string apellidos;
	int celular;
	int edad;
	char sexo[20];
}us[100];

void menu();
void registro();
void ingresardt(int x);
void iniciosesion();

int main(){
    menu();
    return 0;
}

void menu(){//Primer menú del programa
    int op;
    do{
    	cout<<"\t\t\tBienvenido al programa CDS\n";
        cout<<"1. Registrarse"<<endl; 
        cout<<"2. Iniciar sesion"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Seleccione una opcion: ";cin>>op;
        switch(op){
        case 1:
            system("cls");
            registro();
            break;
        case 2:
        	system("cls");
        	iniciosesion();
            break;
        case 0:
            system("cls");
            cout<<"Saliendo del programa";
            for(int i=1;i<=3;i++){
            	cout<<".";
            	sleep(1);
			}
            break;
        default:
        	system("cls");
            cout<<"Opcion invalida. Intentelo de nuevo\n";
            system("pause");
            system("cls");
            break;
        }
    }while(op!=0);
}

void registro(){//menú para la opción 1.Registro
	int op;
	do{
		cout<<"1. Ingresar Datos personales\n";
		cout<<"2. Volver\n";
		cout<<"Selecione una opcion: ";cin>>op;
		switch(op){
			case 1:
				system("cls");
				ingresardt(a);
				a++;
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

void ingresardt(int x){
	cout<<"DNI: ";cin>>us[x].dni;
	cin.ignore();
	cout<<"Nombres: ";getline(cin, us[x].nombres);
	cout<<"Apellidos: ";getline(cin, us[x].apellidos);
	cout<<"Numero de celular: ";cin>>us[x].celular;
	cout<<"Edad: ";cin>>us[x].edad;
	cout<<"Sexo: ";cin>>us[x].sexo;
	system("pause");
	system("cls");
}

void iniciosesion(){//menú para la opción 2. Iniciar sesión
	int op,dni,dniprueba=2024;//Variable para comprobar;
	do{
		cout<<"1. Ingresar DNI\n";
		cout<<"2. Volver\n";
		cout<<"Selecione una opcion: ";cin>>op;
		switch(op){
			case 1:
				system("cls");
				cout<<"DNI:";cin>>dni;
				if(dni==dniprueba){
					system("cls");
					//menu2();
				}else{
					system("cls");
					cout<<"DNI mal ingresado o no esta registrado\n";
					system("pause");
					system("cls");
				}
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

