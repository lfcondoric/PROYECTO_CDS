#include"3citas.h"
#include"registros.h"
#include<iostream>
#include<string>
#include<unistd.h>
using namespace std;

int remplazarhorita(int tur,int horita){
	if(tur==1){
		switch(horita){

			case 6:{
				return 1;
				break;
			}
			case 7:{
				return 2;
				break;
			}
			case 8:{
				return 3;
				break;
			}
			case 9:{
				return 4;
				break;
			}
			case 10:{
				return 5;
				break;
			}
			case 11:{
				return 6;
				break;
			}
		}
	}
	else{
		if(tur==2){
			switch(horita){
			
				case 14:{
					return 1;
					break;
				}
				case 15:{
					return 2;
					break;
				}
				case 16:{
					return 3;
					break;
				}
				case 17:{
					return 4;
					break;
				}
				case 18:{
					return 5;
					break;
				}
				case 19:{
					return 6;
					break;
				}
			}
		}
	}
}

int inimes(int ano, int mes){
	int a= (14-mes)/12;
	int y=  ano -a;
	int m= mes+12*a-2;
	int dia= 1,d;
	d=(dia+y+y/4-y/100+y/400+(3*m)/12)%7;
	return d;
}

int caldiames(int ano,int mes){
	if(mes==1||mes==3||mes==5||mes==6||mes==8||mes==10||mes==12){
		return 31;
	}
	else{
		if(mes==2){
			if((ano%4==0)||(ano%100==0 && ano%400==0)){
				return 29;
			}
			else{
				return 28;
			}
		}
		else{
			return 30;
		}
	}

}

void remplass(int tur,int mes, int dia, int xu){
	if(tur==1){
		mec[mes].mesit[dia].manana[xu]='n';
	}
	else{
	mec[mes].mesit[dia].tardd[xu]='n';	
	}
}

void mesdias(int ano, int mes){
	int z= inimes(ano,mes);
	for(int i=1;i<=z;i++){
		cout<<"   ";
	}
	int diasMes=caldiames(ano,mes);
	for(int dia=1; dia<=diasMes;dia++){
		printf("%4d",dia);
		if(z%7==0){
			cout<<endl;
		}
		z=z+1;
	}
}

void pantalla(int tur,string doc,int mes,int dia){
	float horari;
	if(tur==1){
		horari=6;
	}
	else{
		horari=14;
	}
	if(tur==1){
		cout<<"------------------------------------------"<<endl;
		cout<<"                  MANANA                  "<<endl;
		cout<<"------------------------------------------"<<endl;
		cout<<"HORA             DOCTOR     DISPONIBILIDAD"<<endl;
		cout<<"------------------------------------------"<<endl;
		string producto=" ";
		for(int i=1; i<=6;i++){
			if(i<10){
				cout<<horari<<espaciar(2,16)<< doc<<espaciar(producto.size(),10)<<mec[mes].mesit[dia].manana[i]<<endl;
			horari=horari+1;
			}
			else{
				cout<<horari<<espaciar(1,16)<< doc<<espaciar(producto.size(),10)<<mec[mes].mesit[dia].manana[i]<<endl;
			horari=horari+1;
			}
		}
	}
	else{
		cout<<"------------------------------------------"<<endl;
		cout<<"                   TARDE                  "<<endl;
		cout<<"------------------------------------------"<<endl;
		cout<<"HORA             DOCTOR     DISPONIBILIDAD"<<endl;
		cout<<"------------------------------------------"<<endl;
		string producto=" ";
		for(int i=1; i<=6;i++){
			cout<<horari<<espaciar(4,18)<< doc<<espaciar(producto.size(),12)<<mec[mes].mesit[dia].tardd[i]<<endl;
			horari=horari+1;
		}
	}
}

void calendario(){
	cout<<" Lun Mar Mie Jue Vie Sab Dom"<<endl;
}


string espaciar(int tam, int valor){
	int espacio =0;
	string texto =" ";
	espacio=valor-tam;
	for(int i=1;i<espacio;i++){
		texto= texto+" ";
	}
	return texto;
}

string namemes(int mes){
	switch(mes){
		case 1:{
			return "ENERO";
			break;
		}
		case 2:{
			return "FEBRERO";
			break;
		}
		case 3:{
			return "MARZO";
			break;
		}
		case 4:{
			return "ABRIL";
			break;
		}
		case 5:{
			return "MAYO";
			break;
		}
		case 6:{
			return "JUNIO";
			break;
		}
		case 7:{
			return "JULIO";
			break;
		}
		case 8:{
			return "AGOSTO";
			break;
		}
		case 9:{
			return "SEPTIEMBRE";
			break;
		}
		case 10:{
			return "OCTUBRE";
			break;
		}
		case 11:{
			return "NOVIEMBRE";
			break;
		}
		case 12:{
			return "DICIEMBRE";
			break;
		}
	}

}