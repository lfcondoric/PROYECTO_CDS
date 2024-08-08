#include<iostream>
#include<string>
#include<unistd.h>
#include"registros.h"
#include"1registro.h"
#include"2servicios.h"
#include"3citas.h"
#include"4farmacia.h"
#include"menu.h"
using namespace std;

int a = 0;
int tope = 0;

void menu();

int main(){
	menu();
	return 0;
}

void menu(){//Primer menú del programa
    int op;
    do{
		cout<<"----------------------------------------------------------------------------"<<endl;
    	cout<<"\t\t\tBIENVENIDO AL PROGRAMA CDS"<<endl;
		cout<<"----------------------------------------------------------------------------"<<endl;
        cout<<"1. Registrarse"<<endl; 
        cout<<"2. Iniciar sesion"<<endl;
        cout<<"0. Salir"<<endl;
		cout<<"----------------------------------------------------------------------------"<<endl;
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

void menu2(int a){//Segundo Menu principal
	int op;
	//Este if tiene como función imprimir el menú indicado para el usuario
	do{
		cout<<"--------------------------------------"<<endl;
		cout<<"		BIENVENIDO\n";
		cout<<"--------------------------------------"<<endl;
		if(us[a].menperso==0){
		cout<<"\t1. Registro al Seguro de Salud\n";
		}else{
		cout<<"\t1. Seguro de Salud\n";
		}
		cout<<"\t2. Servicios que brinda\n";
		cout<<"\t3. Citas\n";
		cout<<"\t4. Farmacia\n";
		cout<<"\t0. Cerrar Sesion\n";
		cout<<"--------------------------------------"<<endl;
		cout<<"Seleccione una opcion: ";cin>>op;
		switch(op){
			case 1:
				system("cls");
				seguro(a);
				return; //<-- retornara hacia la funcion verificar dni
				break;
			case 2:
				system("cls");
				servicios();
				break;
			case 3:
				system("cls");
				menucitas(a);
				break;
			case 4:
				system("cls");
				farmacia(a);
				break;
			case 0:
				cout<<"Cerrando sesion";
           			for(int i=1;i<=3;i++){
            		cout<<".";
            	sleep(1);
				}
				us[a].x=1;
				system("cls");
				return;
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
