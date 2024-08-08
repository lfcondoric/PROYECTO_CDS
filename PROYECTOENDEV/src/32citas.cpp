#include"3citas.h"
#include"registros.h"
#include<iostream>
#include<string>
#include<unistd.h>
#include<ctime>
using namespace std;

//info medicos
string medico[11]={"Dr.LUJAN","Dr.MAMANi","Dr.QUISPE","Dr.DELOCHO","Dra.Diaz ","Dra.CENTENO","Dr.QUISPE M.","Dr.CONDORI","Dr.MAMANI T.","Dra.GUTIERREZ","Dra.ONOFRE"};
//-----------------------------------------------------
mestarma mec[12];
nocit mecit[12];

void citas(int a,int op, int e){
	string S[11]={"Medicina general","Pediatria","Odontologia","Obstetricia","Ginecologia","Cardiologia","Oftalmologia","Radiologia","Neumologia","Psicologia","Nutricion"};

	// Obtener el tiempo actual
    time_t t = time(0);
    
    // Convertirlo a una cadena legible
    tm* tm_ptr = localtime(&t);

    // Guardar la fecha en formato "dd/mm/aaaa"
	us[a].citas[e].fdia=(tm_ptr->tm_mday);
 	us[a].citas[e].fmes=(tm_ptr->tm_mon + 1);
	us[a].citas[e].fano=(tm_ptr->tm_year + 1900);  

	int d=1;
	int ano,mes,dia,tur,horita,xu,act,oct;
	ano=(tm_ptr->tm_year + 1900);
	mes=(tm_ptr->tm_mon + 1);

	cout<<"-----------------------------------------------"<<endl;
	cout<<"                  CITA MEDICA                  "<<endl;
	cout<<"-----------------------------------------------"<<endl;
	cout<<"INFORMACION DEL PACIENTE"<<endl;
	cout<<"\tNombres: "<<us[a].nombres<<endl;
	us[a].citas[e].nombres=us[a].nombres;
	cout<<"\tApellidos: "<<us[a].apellidos<<endl;
	us[a].citas[e].apellidos=us[a].apellidos;
	cout<<"\tDNI: "<<us[a].dni<<endl;
	us[a].citas[e].dni=us[a].dni;
	us[a].citas[e].medico=medico[op-1];
	act=1;
	oct=0;
	tope++;
	if(tope<2){
		for(int a=1;a<=12;a++){
			for(int b=1;b<=31;b++){
				for(int c=1;c<=6;c++){
					mec[a].mesit[b].tardd[d]='s';
					mec[a].mesit[b].manana[c]='s';
					d++;
				}
			}
		}
	}
	switch(mes){
		case 1:{
			cout<<"----------------------------"<<endl;
			cout<<"            ENERO           "<<endl;
			calendario();
			mesdias(ano,mes);
			cout<<endl;
			do{
			cout<<"----------------------------"<<endl;
			cout<<"Elige un dia para tu cita: "<<endl;
			cin>>dia;
			int z = inimes(ano,mes);
			int i=1;
			int diasMes=caldiames(ano,mes);
			for(int de=1; de<=diasMes;de++){
				if(z%7==0){
					mecit[mes].daes[i]=de;
					i=i+1;
				}
				z=z+1;
			}
			cout<<endl;
			cout<<endl;
			for(int e=1;e<=5;e++){
				if(dia==mecit[mes].daes[e]){
					cout<<"ESTE DIA NO HAY ATENCION "<<endl;
					cout<<"INTRODUSCA OTRO NUMERO DE DIA: "<<endl;
					act=act+1;
				}
			}
			oct=oct+1;
			}while(oct!=act);
			system("cls");
			cout<<endl;
			cout<<"-----------Elige el horario------------"<<endl;
			cout<<"1.manana"<<endl;
			cout<<"2.tarde "<<endl;
			cout<<"---------------------------------------"<<endl;
			cout<<"EL HORARIO QUE ELIGES ES: "<<endl;
			cin>>tur;
			pantalla(tur,us[a].citas[e].medico, mes,dia);
			cout<<"ELIGE UNA HORA: "<<endl;
			cin>>horita;
			xu=remplazarhorita(tur, horita);
			remplass(tur, mes, dia, xu);
			system("cls");
			pantalla(tur,us[a].citas[e].medico, mes,dia);
			cout<<"-----LA CITA YA HA SIDO PRESTABLECIDA-------"<<endl;
			system("pause");
		break;
		}
		case 2:{
			cout<<"----------------------------"<<endl;
			cout<<"           FEBRERO          "<<endl;
			calendario();
			mesdias(ano,mes);
			cout<<endl;
			do{
			cout<<"----------------------------"<<endl;
			cout<<"Elige un dia para tu cita: "<<endl;
			cin>>dia;
			int z = inimes(ano,mes);
			int i=1;
			int diasMes=caldiames(ano,mes);
			for(int de=1; de<=diasMes;de++){
				if(z%7==0){
					mecit[mes].daes[i]=de;
					i=i+1;
				}
				z=z+1;
			}
			cout<<endl;
			cout<<endl;
			for(int e=1;e<=5;e++){
				if(dia==mecit[mes].daes[e]){
					cout<<"ESTE DIA NO HAY ATENCION "<<endl;
					cout<<"INTRODUSCA OTRO NUMERO DE DIA: "<<endl;
					act=act+1;
				}
			}
			oct=oct+1;
			}while(oct!=act);
			system("cls");
			cout<<endl;
			cout<<"-----------Elige el horario------------"<<endl;
			cout<<"1.manana"<<endl;
			cout<<"2.tarde "<<endl;
			cout<<"---------------------------------------"<<endl;
			cout<<"EL HORARIO QUE ELIGES ES: "<<endl;
			cin>>tur;
			pantalla(tur,us[a].citas[e].medico, mes,dia);
			cout<<"ELIGE UNA HORA: "<<endl;
			cin>>horita;
			xu=remplazarhorita(tur, horita);
			remplass(tur, mes, dia, xu);
			system("cls");
			pantalla(tur,us[a].citas[e].medico, mes,dia);
			cout<<"-----LA CITA YA HA SIDO PRESTABLECIDA-------"<<endl;
			system("pause");
		break;
		}
		case 3:{
			cout<<"---------------------------"<<endl;
			cout<<"            MARZO          "<<endl;
			calendario();
			mesdias(ano,mes);
			cout<<endl;
			do{
			cout<<"----------------------------"<<endl;
			cout<<"Elige un dia para tu cita: "<<endl;
			cin>>dia;
			int z = inimes(ano,mes);
			int i=1;
			int diasMes=caldiames(ano,mes);
			for(int de=1; de<=diasMes;de++){
				if(z%7==0){
					mecit[mes].daes[i]=de;
					i=i+1;
				}
				z=z+1;
			}
			cout<<endl;
			cout<<endl;
			for(int e=1;e<=5;e++){
				if(dia==mecit[mes].daes[e]){
					cout<<"ESTE DIA NO HAY ATENCION "<<endl;
					cout<<"INTRODUSCA OTRO NUMERO DE DIA: "<<endl;
					act=act+1;
				}
			}
			oct=oct+1;
			}while(oct!=act);
			system("cls");
			cout<<endl;
			cout<<"-----------Elige el horario------------"<<endl;
			cout<<"1.manana"<<endl;
			cout<<"2.tarde "<<endl;
			cout<<"---------------------------------------"<<endl;
			cout<<"EL HORARIO QUE ELIGES ES: "<<endl;
			cin>>tur;
			pantalla(tur,us[a].citas[e].medico, mes,dia);
			cout<<"ELIGE UNA HORA: "<<endl;
			cin>>horita;
			xu=remplazarhorita(tur, horita);
			remplass(tur, mes, dia, xu);
			system("cls");
			pantalla(tur,us[a].citas[e].medico, mes,dia);
			cout<<"-----LA CITA YA HA SIDO PRESTABLECIDA-------"<<endl;
			system("pause");
		break;
		}
		case 4:{
			cout<<"---------------------------"<<endl;
			cout<<"           ABRIL           "<<endl;
			calendario();
			mesdias(ano,mes);
			cout<<endl;
			do{
			cout<<"----------------------------"<<endl;
			cout<<"Elige un dia para tu cita: "<<endl;
			cin>>dia;
			int z = inimes(ano,mes);
			int i=1;
			int diasMes=caldiames(ano,mes);
			for(int de=1; de<=diasMes;de++){
				if(z%7==0){
					mecit[mes].daes[i]=de;
					i=i+1;
				}
				z=z+1;
			}
			cout<<endl;
			cout<<endl;
			for(int e=1;e<=5;e++){
				if(dia==mecit[mes].daes[e]){
					cout<<"ESTE DIA NO HAY ATENCION "<<endl;
					cout<<"INTRODUSCA OTRO NUMERO DE DIA: "<<endl;
					act=act+1;
				}
			}
			oct=oct+1;
			}while(oct!=act);
			system("cls");
			cout<<endl;
			cout<<"-----------Elige el horario------------"<<endl;
			cout<<"1.manana"<<endl;
			cout<<"2.tarde "<<endl;
			cout<<"---------------------------------------"<<endl;
			cout<<"EL HORARIO QUE ELIGES ES: "<<endl;
			cin>>tur;
			pantalla(tur,us[a].citas[e].medico, mes,dia);
			cout<<"ELIGE UNA HORA: "<<endl;
			cin>>horita;
			xu=remplazarhorita(tur, horita);
			remplass(tur, mes, dia, xu);
			system("cls");
			pantalla(tur,us[a].citas[e].medico, mes,dia);
			cout<<"-----LA CITA YA HA SIDO PRESTABLECIDA-------"<<endl;
			system("pause");
		break;
		}
		case 5:{
			cout<<"----------------------------"<<endl;
			cout<<"            MAYO            "<<endl;
			calendario();
			mesdias(ano,mes);
			cout<<endl;
			do{
			cout<<"----------------------------"<<endl;
			cout<<"Elige un dia para tu cita: "<<endl;
			cin>>dia;
			int z = inimes(ano,mes);
			int i=1;
			int diasMes=caldiames(ano,mes);
			for(int de=1; de<=diasMes;de++){
				if(z%7==0){
					mecit[mes].daes[i]=de;
					i=i+1;
				}
				z=z+1;
			}
			cout<<endl;
			cout<<endl;
			for(int e=1;e<=5;e++){
				if(dia==mecit[mes].daes[e]){
					cout<<"ESTE DIA NO HAY ATENCION "<<endl;
					cout<<"INTRODUSCA OTRO NUMERO DE DIA: "<<endl;
					act=act+1;
				}
			}
			oct=oct+1;
			}while(oct!=act);
			system("cls");
			cout<<endl;
			cout<<"-----------Elige el horario------------"<<endl;
			cout<<"1.manana"<<endl;
			cout<<"2.tarde "<<endl;
			cout<<"---------------------------------------"<<endl;
			cout<<"EL HORARIO QUE ELIGES ES: "<<endl;
			cin>>tur;
			pantalla(tur,us[a].citas[e].medico, mes,dia);
			cout<<"ELIGE UNA HORA: "<<endl;
			cin>>horita;
			xu=remplazarhorita(tur, horita);
			remplass(tur, mes, dia, xu);
			system("cls");
			pantalla(tur,us[a].citas[e].medico, mes,dia);
			cout<<"-----LA CITA YA HA SIDO PRESTABLECIDA-------"<<endl;
			system("pause");
		break;
		}
		case 6:{
			cout<<"---------------------------"<<endl;
			cout<<"            JUNIO           "<<endl;
			calendario();
			mesdias(ano,mes);
			cout<<endl;
			do{
			cout<<"----------------------------"<<endl;
			cout<<"Elige un dia para tu cita: "<<endl;
			cin>>dia;
			int z = inimes(ano,mes);
			int i=1;
			int diasMes=caldiames(ano,mes);
			for(int de=1; de<=diasMes;de++){
				if(z%7==0){
					mecit[mes].daes[i]=de;
					i=i+1;
				}
				z=z+1;
			}
			cout<<endl;
			cout<<endl;
			for(int e=1;e<=5;e++){
				if(dia==mecit[mes].daes[e]){
					cout<<"ESTE DIA NO HAY ATENCION "<<endl;
					cout<<"INTRODUSCA OTRO NUMERO DE DIA: "<<endl;
					act=act+1;
				}
			}
			oct=oct+1;
			}while(oct!=act);
			system("cls");
			cout<<endl;
			cout<<"-----------Elige el horario------------"<<endl;
			cout<<"1.manana"<<endl;
			cout<<"2.tarde "<<endl;
			cout<<"---------------------------------------"<<endl;
			cout<<"EL HORARIO QUE ELIGES ES: "<<endl;
			cin>>tur;
			pantalla(tur,us[a].citas[e].medico, mes,dia);
			cout<<"ELIGE UNA HORA: "<<endl;
			cin>>horita;
			xu=remplazarhorita(tur, horita);
			remplass(tur, mes, dia, xu);
			system("cls");
			pantalla(tur,us[a].citas[e].medico, mes,dia);
			cout<<"-----LA CITA YA HA SIDO PRESTABLECIDA-------"<<endl;
			system("pause");
		break;
		}
		case 7:{
			cout<<"---------------------------"<<endl;
			cout<<"           JULIO           "<<endl;
			calendario();
			mesdias(ano,mes);
			cout<<endl;
			do{
			cout<<"----------------------------"<<endl;
			cout<<"Elige un dia para tu cita: "<<endl;
			cin>>dia;
			int z = inimes(ano,mes);
			int i=1;
			int diasMes=caldiames(ano,mes);
			for(int de=1; de<=diasMes;de++){
				if(z%7==0){
					mecit[mes].daes[i]=de;
					i=i+1;
				}
				z=z+1;
			}
			cout<<endl;
			cout<<endl;
			for(int e=1;e<=5;e++){
				if(dia==mecit[mes].daes[e]){
					cout<<"ESTE DIA NO HAY ATENCION "<<endl;
					cout<<"INTRODUSCA OTRO NUMERO DE DIA: "<<endl;
					act=act+1;
				}
			}
			oct=oct+1;
			}while(oct!=act);
			system("cls");
			cout<<endl;
			cout<<"-----------Elige el horario------------"<<endl;
			cout<<"1.manana"<<endl;
			cout<<"2.tarde "<<endl;
			cout<<"---------------------------------------"<<endl;
			cout<<"EL HORARIO QUE ELIGES ES: "<<endl;
			cin>>tur;
			pantalla(tur,us[a].citas[e].medico, mes,dia);
			cout<<"ELIGE UNA HORA: "<<endl;
			cin>>horita;
			xu=remplazarhorita(tur, horita);
			remplass(tur, mes, dia, xu);
			system("cls");
			pantalla(tur,us[a].citas[e].medico, mes,dia);
			cout<<"-----LA CITA YA HA SIDO PRESTABLECIDA-------"<<endl;
			system("pause");
		break;
		}
		case 8:{
			cout<<"----------------------------"<<endl;
			cout<<"           AGOSTO           "<<endl;
			calendario();
			mesdias(ano,mes);
			cout<<endl;
			do{
			cout<<"----------------------------"<<endl;
			cout<<"Elige un dia para tu cita: "<<endl;
			cin>>dia;
			int z = inimes(ano,mes);
			int i=1;
			int diasMes=caldiames(ano,mes);
			for(int de=1; de<=diasMes;de++){
				if(z%7==0){
					mecit[mes].daes[i]=de;
					i=i+1;
				}
				z=z+1;
			}
			cout<<endl;
			cout<<endl;
			for(int e=1;e<=5;e++){
				if(dia==mecit[mes].daes[e]){
					cout<<"ESTE DIA NO HAY ATENCION "<<endl;
					cout<<"INTRODUSCA OTRO NUMERO DE DIA: "<<endl;
					act=act+1;
				}
			}
			oct=oct+1;
			}while(oct!=act);
			system("cls");
			cout<<endl;
			cout<<"-----------Elige el horario------------"<<endl;
			cout<<"1.manana"<<endl;
			cout<<"2.tarde "<<endl;
			cout<<"---------------------------------------"<<endl;
			cout<<"EL HORARIO QUE ELIGES ES: "<<endl;
			cin>>tur;
			pantalla(tur,us[a].citas[e].medico, mes,dia);
			cout<<"ELIGE UNA HORA: "<<endl;
			cin>>horita;
			xu=remplazarhorita(tur, horita);
			remplass(tur, mes, dia, xu);
			system("cls");
			pantalla(tur,us[a].citas[e].medico, mes,dia);
			cout<<"-----LA CITA YA HA SIDO PRESTABLECIDA-------"<<endl;
			system("pause");
		break;
		}
		case 9:{
			cout<<"------------------------------"<<endl;
			cout<<"          SEPTIEMBRE          "<<endl;
			calendario();
			mesdias(ano,mes);
			cout<<endl;
			do{
			cout<<"----------------------------"<<endl;
			cout<<"Elige un dia para tu cita: "<<endl;
			cin>>dia;
			int z = inimes(ano,mes);
			int i=1;
			int diasMes=caldiames(ano,mes);
			for(int de=1; de<=diasMes;de++){
				if(z%7==0){
					mecit[mes].daes[i]=de;
					i=i+1;
				}
				z=z+1;
			}
			cout<<endl;
			cout<<endl;
			for(int e=1;e<=5;e++){
				if(dia==mecit[mes].daes[e]){
					cout<<"ESTE DIA NO HAY ATENCION "<<endl;
					cout<<"INTRODUSCA OTRO NUMERO DE DIA: "<<endl;
					act=act+1;
				}
			}
			oct=oct+1;
			}while(oct!=act);
			system("cls");
			cout<<endl;
			cout<<"-----------Elige el horario------------"<<endl;
			cout<<"1.manana"<<endl;
			cout<<"2.tarde "<<endl;
			cout<<"---------------------------------------"<<endl;
			cout<<"EL HORARIO QUE ELIGES ES: "<<endl;
			cin>>tur;
			pantalla(tur,us[a].citas[e].medico, mes,dia);
			cout<<"ELIGE UNA HORA: "<<endl;
			cin>>horita;
			xu=remplazarhorita(tur, horita);
			remplass(tur, mes, dia, xu);
			system("cls");
			pantalla(tur,us[a].citas[e].medico, mes,dia);
			cout<<"-----LA CITA YA HA SIDO PRESTABLECIDA-------"<<endl;
			system("pause");
		break;
		}
		case 10:{
			cout<<"----------------------------"<<endl;
			cout<<"           OCTUBRE          "<<endl;
			calendario();
			mesdias(ano,mes);
			cout<<endl;
			do{
			cout<<"----------------------------"<<endl;
			cout<<"Elige un dia para tu cita: "<<endl;
			cin>>dia;
			int z = inimes(ano,mes);
			int i=1;
			int diasMes=caldiames(ano,mes);
			for(int de=1; de<=diasMes;de++){
				if(z%7==0){
					mecit[mes].daes[i]=de;
					i=i+1;
				}
				z=z+1;
			}
			cout<<endl;
			cout<<endl;
			for(int e=1;e<=5;e++){
				if(dia==mecit[mes].daes[e]){
					cout<<"ESTE DIA NO HAY ATENCION "<<endl;
					cout<<"INTRODUSCA OTRO NUMERO DE DIA: "<<endl;
					act=act+1;
				}
			}
			oct=oct+1;
			}while(oct!=act);
			system("cls");
			cout<<endl;
			cout<<"-----------Elige el horario------------"<<endl;
			cout<<"1.manana"<<endl;
			cout<<"2.tarde "<<endl;
			cout<<"---------------------------------------"<<endl;
			cout<<"EL HORARIO QUE ELIGES ES: "<<endl;
			cin>>tur;
			pantalla(tur,us[a].citas[e].medico, mes,dia);
			cout<<"ELIGE UNA HORA: "<<endl;
			cin>>horita;
			xu=remplazarhorita(tur, horita);
			remplass(tur, mes, dia, xu);
			system("cls");
			pantalla(tur,us[a].citas[e].medico, mes,dia);
			cout<<"-----LA CITA YA HA SIDO PRESTABLECIDA-------"<<endl;
			system("pause");
		break;
		}
		case 11:{
			cout<<"-----------------------------"<<endl;
			cout<<"          NOVIEMBRE          "<<endl;
			calendario();
			mesdias(ano,mes);
			cout<<endl;
			do{
			cout<<"----------------------------"<<endl;
			cout<<"Elige un dia para tu cita: "<<endl;
			cin>>dia;
			int z = inimes(ano,mes);
			int i=1;
			int diasMes=caldiames(ano,mes);
			for(int de=1; de<=diasMes;de++){
				if(z%7==0){
					mecit[mes].daes[i]=de;
					i=i+1;
				}
				z=z+1;
			}
			cout<<endl;
			cout<<endl;
			for(int e=1;e<=5;e++){
				if(dia==mecit[mes].daes[e]){
					cout<<"ESTE DIA NO HAY ATENCION"<<endl;
					cout<<"INTRODUSCA OTRO NUMERO DE DIA: "<<endl;
					act=act+1;
				}
			}
			oct=oct+1;
			}while(oct!=act);
			system("cls");
			cout<<endl;
			cout<<"-----------Elige el horario------------"<<endl;
			cout<<"1.manana"<<endl;
			cout<<"2.tarde "<<endl;
			cout<<"---------------------------------------"<<endl;
			cout<<"EL HORARIO QUE ELIGES ES: "<<endl;
			cin>>tur;
			pantalla(tur,us[a].citas[e].medico, mes,dia);
			cout<<"ELIGE UNA HORA: "<<endl;
			cin>>horita;
			xu=remplazarhorita(tur, horita);
			remplass(tur, mes, dia, xu);
			system("cls");
			pantalla(tur,us[a].citas[e].medico, mes,dia);
			cout<<"-----LA CITA YA HA SIDO PRESTABLECIDA-------"<<endl;
			system("pause");
		break;
		}
		case 12:{
			cout<<"-----------------------------"<<endl;
			cout<<"          DICIEMBRE          "<<endl;
			calendario();
			mesdias(ano,mes);
			cout<<endl;
			do{
			cout<<"----------------------------"<<endl;
			cout<<"Elige un dia para tu cita: "<<endl;
			cin>>dia;
			int z = inimes(ano,mes);
			int i=1;
			int diasMes=caldiames(ano,mes);
			for(int de=1; de<=diasMes;de++){
				if(z%7==0){
					mecit[mes].daes[i]=de;
					i=i+1;
				}
				z=z+1;
			}
			cout<<endl;
			cout<<endl;
			for(int e=1;e<=5;e++){
				if(dia==mecit[mes].daes[e]){
					cout<<"ESTE DIA NO HAY ATENCION"<<endl;
					cout<<"INTRODUSCA OTRO NUMERO DE DIA: "<<endl;
					act=act+1;
				}
			}
			oct=oct+1;
			}while(oct!=act);
			system("cls");
			cout<<endl;
			cout<<"-----------Elige el horario------------"<<endl;
			cout<<"1.manana"<<endl;
			cout<<"2.tarde "<<endl;
			cout<<"---------------------------------------"<<endl;
			cout<<"EL HORARIO QUE ELIGES ES: "<<endl;
			cin>>tur;
			pantalla(tur,us[a].citas[e].medico, mes,dia);
			cout<<"ELIGE UNA HORA: "<<endl;
			cin>>horita;
			xu=remplazarhorita(tur, horita);
			remplass(tur, mes, dia, xu);
			system("cls");
			pantalla(tur,us[a].citas[e].medico, mes,dia);
			cout<<"-----LA CITA YA HA SIDO PRESTABLECIDA-------"<<endl;
			system("pause");
		break;
		}
	}	
	system("cls");
	us[a].ala[tope].h=horita;
	us[a].ala[tope].di=dia;
	us[a].ala[tope].me=namemes(mes);
	us[a].ala[tope].an=ano;
	cout<<endl;
	cout<<"--------------------------------------------"<<endl;
	cout<<"                    CITA                    "<<endl;
	cout<<"--------------------------------------------"<<endl;
	cout<<"DIA:            "<<us[a].ala[tope].di<<endl;
	cout<<"MES:            "<<us[a].ala[tope].me<<endl;
	cout<<"ANO:            "<<us[a].ala[tope].an<<endl;
	cout<<"\tEspecialidad: "<<S[op-1]<<endl;
	us[a].citas[e].especialidad=S[op-1];
	cout<<"\tConsultorio: "<<op<<endl;
	us[a].citas[e].consultorio=op;
	cout<<"--------------------------------------------"<<endl;
	us[a].i=e;
}