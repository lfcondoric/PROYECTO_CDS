#include<iostream>
#include<unistd.h>
#include<ctime>
using namespace std;

void menu();
void registro();
void ingresardt();
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
				ingresardt();
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

void ingresardt(){
	cout<<"DNI: "<<endl;
	cout<<"Nombres: "<<endl;
	cout<<"Apellidos: "<<endl;
	cout<<"Numero de celular: "<<endl;
	cout<<"Edad: "<<endl;
	cout<<"Sexo: "<<endl;
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

