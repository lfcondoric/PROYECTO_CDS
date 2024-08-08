#include"1registro.h"
#include"registros.h"
#include<iostream>
#include<string>
#include<unistd.h>
#include<ctime>
#include<fstream>
using namespace std;

void seguro(int a){
	int op;
	do{
		cout<<"--------------------------------------"<<endl;
		if(us[a].menperso==0){//Este if tiene como función imprimir el menú indicado para el usuario
			cout<<"\t1. Continuar con el registro\n";
		}else{
			cout<<"\t1. Imprimir ficha de registro\n";
		}
		cout<<"\t2. Informacion sobre el SDS\n";
		cout<<"\t3. Volver\n";
		cout<<"--------------------------------------"<<endl;
		cout<<"Selecione una opcion: ";cin>>op;
			switch(op){
			case 1:
				system("cls");
				if(us[a].menperso==0){//Este if tiene como función imprimir el menú indicado para el usuario
					registrosds(a);
				return;
				}else{
					imprimir(a);
				}
				break;
			case 2:
				system("cls");
				info();
				break;
			case 3:
				system("cls");
				return;
				break;
			default:
        		system("cls");
          	 	break;
		}
	}while(op!=2);
}

void registrosds(int a){
	time_t now=time(0);
	tm *time=localtime(&now);//Establece la hora y fecha actual de acuerdo a la fecha y hora local de la pc

	int year = 1900 + time->tm_year;//se suma 1900, porque la libreria toma en cuenta los años desde el año 1900
	int month = 1 + time->tm_mon;
	
	us[a].menperso=1;//Guadar para saber el tipo de menú que se debe imprimir de acuerdo a la interacción del usuario;
	
	cout<<"--------------------------------------"<<endl;
	cout<<"     INGRESE SUS DATOS PERSONALES     "<<endl;
	cout<<"--------------------------------------"<<endl;
	cout<<"1. DATOS DE LA AFILIACION\n";
	cout<<"\tFecha:"<<time->tm_mday<<"/"<<month<<"/"<<year<<endl;
	cout<<"\n2. DATOS DEL ASEGURADO\n";
	cout<<"- Tipo de documento: DNI\n -Nro.Documento: "<<us[a].dni<<endl;
	cout<<"- Nombre: "<<us[a].nombres<<endl;
	cout<<"- Apellidos: "<<us[a].apellidos<<endl;;
	cout<<"- Fecha de nacimiento: \n\tDia: ";cin>>us[a].nacimiento.dia;cout<<"\tMes: ";cin>>us[a].nacimiento.mes;cout<<"\tAnio: ";cin>>us[a].nacimiento.anio;
	cout<<"- Edad: ";cin>>us[a].edad;//Se piensa habilitar algunas lecturas de datos adicionales de acuerdo a la edad del afiliado
	cout<<"- Sexo: ";cin>>us[a].sexo;
	cout<<"--------------------------------------"<<endl;
	cout<<"       DOMICILIO DEL ASEGURADO        "<<endl;
	cout<<"--------------------------------------"<<endl;
	cin.ignore();
	cout<<"- Departamento: ";getline(cin, us[a].domicilio.departamento);
	cout<<"- Provincia: ";getline(cin, us[a].domicilio.provincia);
	cout<<"- Distrito: ";getline(cin, us[a].domicilio.distrito);
	cout<<"- Direccion: ";getline(cin, us[a].domicilio.direcion);
	//Se piensa agregar mas lecturas de datos
	system("cls");
	return;
}

void info(){
	ifstream info;
	string texto;
	
	info.open("texto.txt",ios::in);//Abrir el archivos en modo lectura
	while(!info.eof()){//Mientras no sea el final del archivo
		getline(info,texto);
		cout<<texto<<endl;
	}
	info.close();
	system("pause");
	system("cls");
}

void imprimir(int a){
	cout<<"---------------------------------------------------------------"<<endl;
	cout<<"                      DATOS DEL ASEGURADO                      "<<endl;
	cout<<"---------------------------------------------------------------"<<endl;
	cout<<"\t"<<"DNI: "<<us[a].dni<<endl;
	cout<<"\t"<<"NOMBRES: "<<us[a].nombres<<endl;
	cout<<"\t"<<"APELLIDOS: "<<us[a].apellidos<<endl;
	cout<<"\t"<<"FECHA DE NACIMIENTO: "<<us[a].nacimiento.dia<<"/"<<us[a].nacimiento.mes<<"/"<<us[a].nacimiento.anio<<endl;
	cout<<"\t"<<"EDAD: "<<us[a].edad<<endl;
	cout<<"\t"<<"SEXO: "<<us[a].sexo<<endl;
	cout<<"---------------------------------------------------------------"<<endl;
	cout<<"                    DOMICILIO DEL ASEGURADO                    "<<endl;
	cout<<"---------------------------------------------------------------"<<endl;
	cout<<"\t"<<"DEPARTAMENTO: "<<us[a].domicilio.departamento<<endl;
	cout<<"\t"<<"PROVINCIA: "<<us[a].domicilio.provincia<<endl;
	cout<<"\t"<<"DISTRITO: "<<us[a].domicilio.distrito<<endl;
	cout<<"\t"<<"DIRECCION: "<<us[a].domicilio.direcion<<endl;
	cout<<"---------------------------------------------------------------"<<endl;
	system("pause");
	system("cls");
}