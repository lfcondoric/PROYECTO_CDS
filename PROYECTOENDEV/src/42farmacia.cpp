#include"4farmacia.h"
#include"registros.h"
#include<iostream>
#include<string>
#include<unistd.h>
using namespace std;

void antibioticos(int a,int op){
	int m;
	do{
		system("cls");
		cout<<"--------------------------------------"<<endl;
		cout<<"              ANTIBIOTICOS             "<<endl;
		cout<<"--------------------------------------"<<endl;
		cout<<"1. Amoxicilina"<<endl;
		cout<<"2. Ceftriaxona"<<endl;
		cout<<"3. Vancomicina"<<endl;			
		cout<<"4. Ciprofloxacina"<<endl;
		cout<<"0. Volver"<<endl;
		cout<<"--------------------------------------"<<endl;
		cout<<"Seleccione una opcion: ";cin>>m;
		switch(m){
			case 1:
			case 2:
			case 3:
			case 4:
				system("cls");
				pedido(a,op,m, us[a].e+1);
				system("pause");
				return;
				break;
			case 0:
				system("cls");
				return;
				break;
			default:
				system("cls");
				break;
		}
	}while(m!=0);
}

void analgesicos(int a,int op){
	int m;
	do{
		system("cls");
		cout<<"--------------------------------------"<<endl;
		cout<<"              ANALGESICOS             "<<endl;
		cout<<"--------------------------------------"<<endl;
		cout<<"1. Parecetamol"<<endl;
		cout<<"2. Ibuprofeno"<<endl;
		cout<<"3. Morfina"<<endl;			
		cout<<"4. Tramadol"<<endl;
		cout<<"0. Volver"<<endl;
		cout<<"--------------------------------------"<<endl;
		cout<<"Seleccione una opcion: ";cin>>m;
		switch(m){
			case 1:
			case 2:
			case 3:
			case 4:
				system("cls");
				pedido(a,op,m, us[a].e+1);
				system("pause");
				return;
				break;
			case 0:
				system("cls");
				return;
				break;
			default:
				system("cls");
				break;
		}
	}while(m!=0);
}

void anestesicos(int a,int op){
	int m;
	do{
		system("cls");
		cout<<"--------------------------------------"<<endl;
		cout<<"              ANESTESICOS             "<<endl;
		cout<<"--------------------------------------"<<endl;
		cout<<"1. Lidocaina"<<endl;
		cout<<"2. Propofol"<<endl;
		cout<<"3. Midazolam"<<endl;			
		cout<<"0. Volver"<<endl;
		cout<<"--------------------------------------"<<endl;
		cout<<"Seleccione una opcion: ";cin>>m;
		switch(m){
			case 1:
			case 2:
			case 3:
				system("cls");
				pedido(a,op,m,us[a].e+1);
				system("pause");
				return;
				break;
			case 0:
				system("cls");
				return;
				break;
			default:
				system("cls");
				break;
		}
	}while(m!=0);
}

void anticoagulantes(int a,int op){
	int m;
	do{
		system("cls");
		cout<<"--------------------------------------"<<endl;
		cout<<"            ANTICOAGULANTES           "<<endl;
		cout<<"--------------------------------------"<<endl;
		cout<<"1. Heparina"<<endl;
		cout<<"2. Warfarina"<<endl;
		cout<<"3. Enoxaparina"<<endl;			
		cout<<"0. Volver"<<endl;
		cout<<"--------------------------------------"<<endl;
		cout<<"Seleccione una opcion: ";cin>>m;
		switch(m){
			case 1:
			case 2:
			case 3:
				system("cls");
				pedido(a,op,m,us[a].e+1);
				system("pause");
				return;
				break;
			case 0:
				system("cls");
				return;
				break;
			default:
				system("cls");
				break;
		}
	}while(m!=0);
}

void antihipertensivos(int a,int op){
	int m;
	do{
		system("cls");
		cout<<"--------------------------------------"<<endl;
		cout<<"           ANTIHIPERTENSIVOS          "<<endl;
		cout<<"--------------------------------------"<<endl;
		cout<<"1. Lisinopril"<<endl;
		cout<<"2. Losartan"<<endl;
		cout<<"3. Metroprolol"<<endl;			
		cout<<"0. Volver"<<endl;
		cout<<"--------------------------------------"<<endl;
		cout<<"Seleccione una opcion: ";cin>>m;
		switch(m){
			case 1:
			case 2:
			case 3:
				system("cls");
				pedido(a,op,m,us[a].e+1);
				system("pause");
				return;
				break;
			case 0:
				system("cls");
				return;
				break;
			default:
				system("cls");
				break;
		}
	}while(m!=0);
}

