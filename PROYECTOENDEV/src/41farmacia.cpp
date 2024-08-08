#include"4farmacia.h"
#include"registros.h"
#include<iostream>
#include<string>
#include<unistd.h>
#include<ctime>
using namespace std;

void farmacia(int a){
	int op;
	if(us[a].menperso==1){
		do{
			system("cls");
			cout<<"--------------------------------------"<<endl;
			cout<<"             MEDICAMENTOS             "<<endl;
			cout<<"--------------------------------------"<<endl;
			cout<<"1. Antiobioticos"<<endl;
			cout<<"2. Analgecicos y Antiinflamatorias"<<endl;
			cout<<"3. Anestesicos"<<endl;
			cout<<"4. Anticoagulantes"<<endl;
			cout<<"5. Antihipertensivos"<<endl;
			cout<<"--------------------------------------"<<endl;
			cout<<"6.       HISTORIAL DE PEDIDOS         "<<endl;
			cout<<"--------------------------------------"<<endl;
			cout<<"0. Volver"<<endl;
			cout<<"--------------------------------------"<<endl;
			cout<<"Seleccione una opcion: ";cin>>op;
			switch(op){
				case 1:
					system("cls");
					antibioticos(a,op);
					break;
				case 2:
					system("cls");
					analgesicos(a,op);
					break;
				case 3:
					system("cls");
					anestesicos(a,op);
					break;
				case 4:
					system("cls");
					anticoagulantes(a,op);
					break;
				case 5:
					system("cls");
					antihipertensivos(a,op);
					break;
				case 6:
					system("cls");
					historialdeP(a);
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
	}else{
		cout<<"Necesita estar registrado en el SDS";
		for(int i=1;i<=3;i++){
			cout<<".";
			sleep(1);
		}
		cout<<endl;
		system("cls");
		return;
	}
}

void historialdeP(int a){
	if(us[a].e>0){
		cout<<"-----------------------------------------------"<<endl;
		cout<<"FECHA: "<<us[a].medicamentos[1].dia<<"/"<<us[a].medicamentos[1].mes<<"/"<<us[a].medicamentos[1].ano<<endl;
		cout<<"-----------------------------------------------"<<endl;
		cout<<"PACIENTE: "<<us[a].medicamentos[1].nombres<<" "<<us[a].medicamentos[1].apellido<<endl;
		cout<<"EDAD: "<<us[a].medicamentos[1].edad<<endl;
		cout<<"-----------------------------------------------"<<endl;
		cout<<"             PEDIDO DE MEDICAMENTO             "<<endl;
		cout<<"-----------------------------------------------"<<endl;
	for(int i=1;i<=us[a].e;i++){
		cout<<"\tHORA: "<<us[a].medicamentos[i].hora<<":"<<us[a].medicamentos[i].minuto<<":"<<us[a].medicamentos[i].segundo<<endl;
		cout<<"\t"<<us[a].medicamentos[i].tanti<<": "<<us[a].medicamentos[i].tmedi<<endl;
		cout<<"\tUNIDADES: "<<us[a].medicamentos[i].unidades<<endl;
		cout<<"-----------------------------------------------"<<endl;
	}
	system("pause");
	system("cls");
	return;
	}else{
		cout<<"NO HA HECHO PEDIDOS RECIENTEMENTE\n";
	system("pause");
	system("cls");
	}
}

void fecha(int a, int e){
	// Obtener el tiempo actual
    time_t t = time(0);
    
    // Convertirlo a una cadena legible
    tm* tm_ptr = localtime(&t);

    // Imprimir la fecha en formato "dd/mm/aaaa"
    cout << "\tFECHA: "
			<< (tm_ptr->tm_mday) << "/"
            << (tm_ptr->tm_mon + 1) << "/"
            << (tm_ptr->tm_year + 1900) << endl;
    us[a].medicamentos[e].dia=tm_ptr->tm_mday;
    us[a].medicamentos[e].mes=tm_ptr->tm_mon + 1;
    us[a].medicamentos[e].ano=tm_ptr->tm_year + 1900;
	us[a].medicamentos[e].hora = tm_ptr->tm_hour;
    us[a].medicamentos[e].minuto = tm_ptr->tm_min;
    us[a].medicamentos[e].segundo = tm_ptr->tm_sec;
}

void pedido(int a,int op,int m,int e){
	string MD[5]={"ANTIBIOTICO","ANALGECICO","ANESTESICOS","ANTICOAGULANTES","ANTIHIPERTENSIVOS"};
	string AB[4];
	int n=0;
	int UNI[n];
	if(op==1){
		AB[0]="Amoxicilina"; AB[1]="Ceftriaxona"; AB[2]="Vancomicina"; AB[3]="Ciprofloxacina";
	} else if(op==2){
		AB[0]="Paracetamol"; AB[1]="Ibuprofeno"; AB[2]="Morfina"; AB[3]="Tramadol";
	} else if(op==3){
		AB[0]="Lidocaina"; AB[1]="Propofol"; AB[2]="Midazolam";
	} else if(op==4){
		AB[0]="Heparina"; AB[1]="Warfarina"; AB[2]="Enoxaparina";
	} else if(op==5){
		AB[0]="Lisinopril"; AB[1]="Losartan"; AB[2]="Metoprolol";
	}
	cout<<"-----------------------------------------------"<<endl;
	cout<<"             PEDIDO DE MEDICAMENTO             "<<endl;
	cout<<"-----------------------------------------------"<<endl;
	cout<<"\tPACIENTE: "<<us[a].nombres<<" "<<us[a].apellidos<<endl;
		us[a].medicamentos[e].nombres=us[a].nombres;
		us[a].medicamentos[e].apellido=us[a].apellidos;
	cout<<"\tEDAD: "<<us[a].edad<<endl;
		us[a].medicamentos[e].edad=us[a].edad;
	cout<<"-----------------------------------------------"<<endl;
	fecha(a,e);
	cout<<"\t"<<MD[op-1]<<": "<<AB[m-1]<<endl;
	cout<<"\t"<<"UNIDADES: ";cin>>UNI[n];
		us[a].medicamentos[e].tanti=MD[op-1];
		us[a].medicamentos[e].tmedi=AB[m-1];
		us[a].medicamentos[e].unidades=UNI[n];
	cout<<"-----------------------------------------------"<<endl;
	us[a].e=e;
}
