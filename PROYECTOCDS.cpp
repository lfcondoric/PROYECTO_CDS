#include<iostream>
#include<unistd.h>
#include<ctime>
using namespace std;

void menu();

int main(){
    menu();
    return 0;
}

void menu(){   //Primer menú del programa
    int op,e=0;
    do{
    	cout<<"\t\t\tBienvenido al programa CDS\n";
        cout<<"1. Registrarse"<<endl; 
        cout<<"2. Iniciar sesion"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Seleccion opcion: ";cin>>op;
        switch(op){
        case 1:
            system("cls");
            break;
        case 2:
        	system("cls");
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
            break;
        }
    }while(op!=0);
}

