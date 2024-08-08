#include"2servicios.h"
#include"registros.h"
#include<iostream>
#include<string>
#include<unistd.h>
#include<fstream>
using namespace std;

void servicios(){
	int op;
	do{
		ifstream archivos;
		string texto;
		cout<<"-----------------------------------"<<endl;
		cout<<"             SERVICIOS             "<<endl;
		cout<<"-----------------------------------"<<endl;
		cout<<"1. Medicina general"<<endl;
		cout<<"2. Pediatria"<<endl;
		cout<<"3. Odontologia"<<endl;
		cout<<"4. Obstetricia"<<endl;
		cout<<"5. Ginecologia"<<endl;
		cout<<"6. Cardiologia"<<endl;
		cout<<"7. Oftalmologia"<<endl;
		cout<<"8. Radiologia"<<endl;
		cout<<"9. Neumologia"<<endl;
		cout<<"10. Psicologia"<<endl;
		cout<<"11. Nutricion"<<endl;
		cout<<"0. Volver "<<endl;
		cout<<"-----------------------------------"<<endl;
		cout<<"Seleccione una opcion: ";cin>>op;
		switch(op){
			case 1:
				system("cls");
				archivos.open("medicinageneral.txt",ios::in);//Abrir el archivo en modo lectura
				while(!archivos.eof()){//Mientras no sea el final del archivo
					getline(archivos,texto);
					cout<<texto<<endl;
				}
				archivos.close();
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
					archivos.open("pediatria.txt",ios::in);//Abrir el archivos en modo lectura
				while(!archivos.eof()){//Mientras no sea el final del archivo
					getline(archivos,texto);
					cout<<texto<<endl;
				}
				archivos.close();
				system("pause");
				system("cls");
				break;
			case 3:
				system("cls");
				archivos.open("odontologia.txt",ios::in);//Abrir el archivos en modo lectura
				while(!archivos.eof()){//Mientras no sea el final del archivo
 	  				getline(archivos,texto);
					cout<<texto<<endl;
				}
				archivos.close();
				system("pause");
				system("cls");
				break;
			case 4:
				system("cls");
				archivos.open("obstetricia.txt",ios::in);//Abrir el archivos en modo lectura
  				while(!archivos.eof()){//Mientras no sea el final del archivo
					getline(archivos,texto);
					cout<<texto<<endl;
				}
				archivos.close();
				system("pause");
				system("cls");
				break;
			case 5:
				system("cls");
				archivos.open("ginecologia.txt",ios::in);//Abrir el archivos en modo lectura
				while(!archivos.eof()){//Mientras no sea el final del archivo
					getline(archivos,texto);
					cout<<texto<<endl;
				}
				archivos.close();
				system("pause");
				system("cls");
				break;
			case 6:
				system("cls");
				archivos.open("cardiologia.txt",ios::in);//Abrir el archivos en modo lectura
				while(!archivos.eof()){//Mientras no sea el final del archivo
					getline(archivos,texto);
					cout<<texto<<endl;
				}
				archivos.close();
				system("pause");
				system("cls");
				break;
			case 7:
				system("cls");
				archivos.open("oftalmologia.txt",ios::in);//Abrir el archivos en modo lectura
				while(!archivos.eof()){//Mientras no sea el final del archivo
					getline(archivos,texto);
					cout<<texto<<endl;
				}
				archivos.close();
				system("pause");
				system("cls");
				break;
			case 8:
				system("cls");
				archivos.open("radiologia.txt",ios::in);//Abrir el archivos en modo lectura
				while(!archivos.eof()){//Mientras no sea el final del archivo
					getline(archivos,texto);
					cout<<texto<<endl;
				}
				archivos.close();
				system("pause");
				system("cls");
				break;
			case 9:
				system("cls");
				archivos.open("neumologia.txt",ios::in);//Abrir el archivos en modo lectura
				while(!archivos.eof()){//Mientras no sea el final del archivo
					getline(archivos,texto);
					cout<<texto<<endl;
				}
				archivos.close();
				system("pause");
				system("cls");
				break;
			case 10:
				system("cls");
				archivos.open("psicologia.txt",ios::in);//Abrir el archivos en modo lectura
				while(!archivos.eof()){//Mientras no sea el final del archivo
					getline(archivos,texto);
					cout<<texto<<endl;
				}
				archivos.close();
				system("pause");
				system("cls");
				break;
			case 11:
				system("cls");
				archivos.open("nutricion.txt",ios::in);//Abrir el archivos en modo lectura
				while(!archivos.eof()){//Mientras no sea el final del archivo
					getline(archivos,texto);
					cout<<texto<<endl;
				}
				archivos.close();
				system("pause");
				system("cls");
				break;
			case 0:
				system("cls");
				return;
				break;
			default:
				system("cls");
				break;
		}
	}while(op!=0);
}