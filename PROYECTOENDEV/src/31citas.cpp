#include"3citas.h"
#include"registros.h"
#include<iostream>
#include<string>
#include<unistd.h>
#include<fstream>

using namespace std;

void menucitas(int a){
	int op;
	if(us[a].menperso==1){
		do{
			system("cls");
			cout<<"-----------------------------------"<<endl;
			cout<<"                CITA               "<<endl;
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
			cout<<"-----------------------------------"<<endl;
			cout<<"12.		HISTORIAL DE CITAS		  "<<endl;
			cout<<"-----------------------------------"<<endl;
			cout<<"0. Volver "<<endl;
			cout<<"-----------------------------------"<<endl;
			cout<<"Seleccione una opcion: ";cin>>op;
			switch(op){
				case 1:
				case 2:
				case 3:
				case 4:
				case 5:
				case 6:
				case 7:
				case 8:
				case 9:
				case 10:
				case 11:
					system("cls");
					citas(a, op, us[a].i+1);
					system("pause");
					break;
				case 12:
					system("cls");
					historialdeC(a);
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
	}
}

void historialdeC(int a){
	if(us[a].i>0){
		for(int i=1;i<=us[a].i;i++){
		cout<<"-----------------------------------------------"<<endl;
		cout<<"FECHA DE SOLICITUD: "<<us[a].citas[i].fdia<<"/"<<us[a].citas[i].fmes<<"/"<<us[a].citas[i].fano<<endl;
		cout<<"-----------------------------------------------"<<endl;
		cout<<"                  CITA MEDICA                  "<<endl;
		cout<<"-----------------------------------------------"<<endl;
		cout<<"INFORMACION DEL PACIENTE"<<endl;
		cout<<"\tNombres: "<<us[a].citas[i].nombres<<endl;
		cout<<"\tApellidos: "<<us[a].citas[i].apellidos<<endl;
		cout<<"\tDNI: "<<us[a].citas[i].dni<<endl;
		cout<<"-----------------------------------------------"<<endl;
		cout<<"INFORMACION DE LA CITA"<<endl;
		cout<<"\tFecha: "<<us[a].ala[i].me<<"/"<<us[a].ala[i].di<<"/"<<us[a].ala[i].an<<endl;
		cout<<"\tHora: "<<us[a].ala[i].h<<endl;
		cout<<"\tMedico: "<<us[a].citas[i].medico<<endl;
		cout<<"\tEspecialidad: "<<us[a].citas[i].especialidad<<endl;
		cout<<"\tConsultorio: "<<us[a].citas[i].consultorio<<endl;
		cout<<"-----------------------------------------------"<<endl;
		cout<<"\n\n";
	}
		system("pause");
		system("cls");
	}else{
		cout<<"NO HA HECHO CITAS RECIENTEMENTE\n";
		system("pause");
		system("cls");
	}
}