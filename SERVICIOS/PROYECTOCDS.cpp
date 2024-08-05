#include<iostream>
#include<unistd.h>
#include<ctime>
#include<string>
#include<fstream>
using namespace std;

int a=0;//Variable global para determinar en que índice se encuentra almacenada los datos de los usuarios

struct FECHA{
	int dia,mes,anio;
};

struct DOMI{
	string departamento;
	string provincia;
	string distrito;
	string direcion;
};

struct CITAS{
	string medico;
	int fdia, dia, fmes, mes, fano, ano, dni;//<-- Los que f.... alamacenará la fecha actual en la que se solicito la cita. Dia,mes, ano es la fecha programada para la cita
	string especialidad;
	int consultorio;
	string nombres;
	string apellidos;
};

struct MEDI{
	string nombres;
	string apellido;
	int edad;
	string tanti;
	string tmedi;
	int dia, mes, ano;
};

struct nocit{
	int daes[5];
};

struct tarmas{
	char manana[6];
	char tardd[6];
};

struct mestarma{
	tarmas mesit[31];
};

string medico[11]={"Dr. LUJAN","Dr. MAMANI","Dr. QUISPE","Dr. DELOCHO","Dra. Diaz ","Dra. CENTENO","Dr. QUISPE M.","Dr. CONDORI","Dr. MAMANI T.","Dra. GUTIERREZ","Dra. ONOFRE "};

struct citass{
	int h;       
	int di;
	string me;
	int an;
};

struct USUARIOS{
	citass ala[50];
	int dni;
	string nombres;
	string apellidos;
	int edad;
	char sexo[20];
	FECHA nacimiento;
	DOMI domicilio;
	CITAS citas[100];
	MEDI medicamentos[100];
	int menperso = 0;//Menu perzonalizado
	int x = 0;
	int e = 0;//<-- Ayuda a almacenar los medicamentos en orden
	int i = 0;//<-- Ayuda a almacenar las citas en orden

}us[100];

string namemes(int mes);
string espaciar(int tam, int valor);
void remplass(int tur,int mes, int dia, int xu);
int remplazarhorita(int tur,int horita);
int inimes(int ano, int mes);
int caldiames(int ano,int mes);
void mesdias(int ano, int mes);
void calendario();
void menu();
void registro();
void ingresardt(int x);
void iniciosesion();
void verificardni(int dni);
void menu2(int a);
void seguro(int a);
void info();
void registrosds(int a);
void imprimir(int a);
void servicios();
void menucitas(int a);
void fecha(int a, int e);
void citas(int a,int op, int e);
void historialdeC(int a);
void farmacia(int a);
void antibioticos(int a,int op);
void pedido(int a,int op,int m,int e);
void historialdeP(int a);
void analgesicos(int a,int op);
void anestesicos(int a,int op);
void anticoagulantes(int a,int op);
void antihipertensivos(int a,int op);
void pantalla(int tur,string doc,int mes,int dia);

int tope=0;
mestarma mec[12];
nocit mecit[12];
int main(){
	nocit mecit[12];
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

void registro(){//menú para la opción 1.Registro
	int op;
	do{
		cout<<"--------------------------------------"<<endl;
		cout<<"1. Ingresar Datos personales\n";
		cout<<"2. Volver\n";
		cout<<"--------------------------------------"<<endl;
		cout<<"Selecione una opcion: ";cin>>op;
		switch(op){
			case 1:
				system("cls");
				ingresardt(a);//Al mandar una copia de a estoy mandando el indice donde quiero que se guarden los datos de un usuario
				a++;
				return;
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

void ingresardt(int x){//Registro de datos
	cout<<"--------------------------------------"<<endl;
	cout<<"DNI: ";cin>>us[x].dni;
	cin.ignore();
	cout<<"Nombres: ";getline(cin, us[x].nombres);
	cout<<"Apellidos: ";getline(cin, us[x].apellidos);
	cout<<"--------------------------------------"<<endl;
	system("pause");
	system("cls");
}

void iniciosesion(){//menú para la opción 2. Iniciar sesión
	int op,a;
	do{
		cout<<"--------------------------------------"<<endl;
		cout<<"1. Ingresar DNI\n";
		cout<<"2. Volver\n";
		cout<<"--------------------------------------"<<endl;
		cout<<"Selecione una opcion: ";cin>>op;
		switch(op){
			case 1:
				system("cls");
				cout<<"DNI: ";cin>>a;
				verificardni(a);
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

void verificardni(int dni){
	for(int i=0;i<100;i++){//Verificar si el dni esta registrado
		if(dni==us[i].dni){//Compara el dni ingresado con los demás registrados anteriormente
			system("cls");
			while(true){
				if(us[i].menperso==0){ //<-- Cuando el usuario no se haya registrado al SDS
					menu2(i);//<-- si se cumple el if llamaría a la función señalada
				}
				if(us[i].menperso==1){//<-- Este if funcionara cuando vuelva del registro al SDS, para abrir un menu perzonalizado
					menu2(i);				
				}
				if(us[i].x==1){
					break;//<- cuando us[i].x sea igual a 1 el bucle rompera, permitiendo cerrar sesión de forma correcta
					us[i].x=0;
				}
			}
			return;
		}
	}
	//En caso de que no se cumpla
	system("cls");
	cout<<"DNI mal ingresado o no esta registrado\n";
	system("pause");
	system("cls");
}

void menu2(int a){//Segundo Menu principal
	int op;
	//Este if tiene como función imprimir el menú indicado para el usuario
	if(us[a].menperso==0){
	do{
		cout<<"--------------------------------------"<<endl;
		cout<<"		BIENVENIDO\n";
		cout<<"--------------------------------------"<<endl;
		cout<<"\t1. Registro al Seguro de Salud\n";
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
	} else{
		do{
		cout<<"--------------------------------------"<<endl;
		cout<<"		BIENVENIDO\n";
		cout<<"--------------------------------------"<<endl;
		cout<<"\t1. Seguro de Salud\n";
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
}

void seguro(int a){
	int op;
	if(us[a].menperso==0){//Este if tiene como función imprimir el menú indicado para el usuario
		do{
			cout<<"--------------------------------------"<<endl;
			cout<<"\t1. Continuar con el registro\n";
			cout<<"\t2. Informacion sobre el SDS\n";
			cout<<"\t3. Volver\n";
			cout<<"--------------------------------------"<<endl;
			cout<<"Selecione una opcion: ";cin>>op;
			switch(op){
				case 1:
					system("cls");
					registrosds(a);
					return;
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
	}else{
		do{
			cout<<"--------------------------------------"<<endl;
			cout<<"\t1. Imprimir ficha de registro\n";
			cout<<"\t2. Informacion sobre el SDS\n";
			cout<<"\t3. Volver\n";
			cout<<"--------------------------------------"<<endl;
			cout<<"Selecione una opcion: ";cin>>op;
			switch(op){
				case 1:
					system("cls");
					imprimir(a);
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
	return;
}

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

void menucitas(int a){
	int op;
	do{
		system("cls");
		cout<<"-----------------------------------"<<endl;
		cout<<"            SERVICIOS              "<<endl;
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
}

void historialdeC(int a){
	if(us[a].i>0){
		for(int i=1;i<=us[a].i;i++){
		cout<<"-----------------------------------------------"<<endl;
		cout<<"FECHA DE SOICITUD: "<<us[a].citas[i].fdia<<"/"<<us[a].citas[i].fmes<<"/"<<us[a].citas[i].fano<<endl;
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
	tope=tope+1;
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
			cout<<"-----------ENERO-----------"<<endl;
			calendario();
			mesdias(ano,mes);
			cout<<endl;
			do{
			cout<<"elige un dia para tu cita: "<<endl;
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
					cout<<"ESTE DIA NO HAY ATENCIO "<<endl;
					cout<<"INTRODUSCA OTRO NUMERO DE DIA: "<<endl;
					act=act+1;
				}
			}
			oct=oct+1;
			}while(oct!=act);
			system("cls");
			cout<<endl;
			cout<<"-----------elige el horario------------"<<endl;
			cout<<"1.manana"<<endl;
			cout<<"2.tarde "<<endl;
			cout<<"EL HORARIO QUE ELIJES ES: "<<endl;
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
			cout<<"----------FEBRERO----------"<<endl;
			calendario();
			mesdias(ano,mes);
			cout<<endl;
			do{
			cout<<"elige un dia para tu cita: "<<endl;
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
					cout<<"ESTE DIA NO HAY ATENCIO "<<endl;
					cout<<"INTRODUSCA OTRO NUMERO DE DIA: "<<endl;
					act=act+1;
				}
			}
			oct=oct+1;
			}while(oct!=act);
			system("cls");
			cout<<endl;
			cout<<"-----------elige el horario------------"<<endl;
			cout<<"1.manana"<<endl;
			cout<<"2.tarde "<<endl;
			cout<<"EL HORARIO QUE ELIJES ES: "<<endl;
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
			cout<<"-----------MARZO-----------"<<endl;
			calendario();
			mesdias(ano,mes);
			cout<<endl;
			do{
			cout<<"elige un dia para tu cita: "<<endl;
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
					cout<<"ESTE DIA NO HAY ATENCIO "<<endl;
					cout<<"INTRODUSCA OTRO NUMERO DE DIA: "<<endl;
					act=act+1;
				}
			}
			oct=oct+1;
			}while(oct!=act);
			system("cls");
			cout<<endl;
			cout<<"-----------elige el horario------------"<<endl;
			cout<<"1.manana"<<endl;
			cout<<"2.tarde "<<endl;
			cout<<"EL HORARIO QUE ELIJES ES: "<<endl;
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
			cout<<"-----------ABRIL-----------"<<endl;
			calendario();
			mesdias(ano,mes);
			cout<<endl;
			do{
			cout<<"elige un dia para tu cita: "<<endl;
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
					cout<<"ESTE DIA NO HAY ATENCIO "<<endl;
					cout<<"INTRODUSCA OTRO NUMERO DE DIA: "<<endl;
					act=act+1;
				}
			}
			oct=oct+1;
			}while(oct!=act);
			system("cls");
			cout<<endl;
			cout<<"-----------elige el horario------------"<<endl;
			cout<<"1.manana"<<endl;
			cout<<"2.tarde "<<endl;
			cout<<"EL HORARIO QUE ELIJES ES: "<<endl;
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
			cout<<"------------MAYO------------"<<endl;
			calendario();
			mesdias(ano,mes);
			cout<<endl;
			do{
			cout<<"elige un dia para tu cita: "<<endl;
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
					cout<<"ESTE DIA NO HAY ATENCIO "<<endl;
					cout<<"INTRODUSCA OTRO NUMERO DE DIA: "<<endl;
					act=act+1;
				}
			}
			oct=oct+1;
			}while(oct!=act);
			system("cls");
			cout<<endl;
			cout<<"-----------elige el horario------------"<<endl;
			cout<<"1.manana"<<endl;
			cout<<"2.tarde "<<endl;
			cout<<"EL HORARIO QUE ELIJES ES: "<<endl;
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
			cout<<"-----------JUNIO-----------"<<endl;
			calendario();
			mesdias(ano,mes);
			cout<<endl;
			do{
			cout<<"elige un dia para tu cita: "<<endl;
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
					cout<<"ESTE DIA NO HAY ATENCIO "<<endl;
					cout<<"INTRODUSCA OTRO NUMERO DE DIA: "<<endl;
					act=act+1;
				}
			}
			oct=oct+1;
			}while(oct!=act);
			system("cls");
			cout<<endl;
			cout<<"-----------elige el horario------------"<<endl;
			cout<<"1.manana"<<endl;
			cout<<"2.tarde "<<endl;
			cout<<"EL HORARIO QUE ELIJES ES: "<<endl;
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
			cout<<"-----------JULIO-----------"<<endl;
			calendario();
			mesdias(ano,mes);
			cout<<endl;
			do{
			cout<<"elige un dia para tu cita: "<<endl;
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
					cout<<"ESTE DIA NO HAY ATENCIO "<<endl;
					cout<<"INTRODUSCA OTRO NUMERO DE DIA: "<<endl;
					act=act+1;
				}
			}
			oct=oct+1;
			}while(oct!=act);
			system("cls");
			cout<<endl;
			cout<<"-----------elige el horario------------"<<endl;
			cout<<"1.manana"<<endl;
			cout<<"2.tarde "<<endl;
			cout<<"EL HORARIO QUE ELIJES ES: "<<endl;
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
			cout<<"-----------AGOSTO-----------"<<endl;
			calendario();
			mesdias(ano,mes);
			cout<<endl;
			do{
			cout<<"elige un dia para tu cita: "<<endl;
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
					cout<<"ESTE DIA NO HAY ATENCIO "<<endl;
					cout<<"INTRODUSCA OTRO NUMERO DE DIA: "<<endl;
					act=act+1;
				}
			}
			oct=oct+1;
			}while(oct!=act);
			system("cls");
			cout<<endl;
			cout<<"-----------elige el horario------------"<<endl;
			cout<<"1.manana"<<endl;
			cout<<"2.tarde "<<endl;
			cout<<"EL HORARIO QUE ELIJES ES: "<<endl;
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
			cout<<"----------SEPTIEMBRE----------"<<endl;
			calendario();
			mesdias(ano,mes);
			cout<<endl;
			do{
			cout<<"elige un dia para tu cita: "<<endl;
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
					cout<<"ESTE DIA NO HAY ATENCIO "<<endl;
					cout<<"INTRODUSCA OTRO NUMERO DE DIA: "<<endl;
					act=act+1;
				}
			}
			oct=oct+1;
			}while(oct!=act);
			system("cls");
			cout<<endl;
			cout<<"-----------elige el horario------------"<<endl;
			cout<<"1.manana"<<endl;
			cout<<"2.tarde "<<endl;
			cout<<"EL HORARIO QUE ELIJES ES: "<<endl;
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
			cout<<"----------OCTUBRE----------"<<endl;
			calendario();
			mesdias(ano,mes);
			cout<<endl;
			do{
			cout<<"elige un dia para tu cita: "<<endl;
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
					cout<<"ESTE DIA NO HAY ATENCIO "<<endl;
					cout<<"INTRODUSCA OTRO NUMERO DE DIA: "<<endl;
					act=act+1;
				}
			}
			oct=oct+1;
			}while(oct!=act);
			system("cls");
			cout<<endl;
			cout<<"-----------elige el horario------------"<<endl;
			cout<<"1.manana"<<endl;
			cout<<"2.tarde "<<endl;
			cout<<"EL HORARIO QUE ELIJES ES: "<<endl;
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
			cout<<"----------NOVIEMBRE----------"<<endl;
			calendario();
			mesdias(ano,mes);
			cout<<endl;
			do{
			cout<<"elige un dia para tu cita: "<<endl;
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
					cout<<"ESTE DIA NO HAY ATENCIO "<<endl;
					cout<<"INTRODUSCA OTRO NUMERO DE DIA: "<<endl;
					act=act+1;
				}
			}
			oct=oct+1;
			}while(oct!=act);
			system("cls");
			cout<<endl;
			cout<<"-----------elige el horario------------"<<endl;
			cout<<"1.manana"<<endl;
			cout<<"2.tarde "<<endl;
			cout<<"EL HORARIO QUE ELIJES ES: "<<endl;
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
			cout<<"----------DICIEMBRE----------"<<endl;
			calendario();
			mesdias(ano,mes);
			cout<<endl;
			do{
			cout<<"elige un dia para tu cita: "<<endl;
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
					cout<<"ESTE DIA NO HAY ATENCIO "<<endl;
					cout<<"INTRODUSCA OTRO NUMERO DE DIA: "<<endl;
					act=act+1;
				}
			}
			oct=oct+1;
			}while(oct!=act);
			system("cls");
			cout<<endl;
			cout<<"-----------elige el horario------------"<<endl;
			cout<<"1.manana"<<endl;
			cout<<"2.tarde "<<endl;
			cout<<"EL HORARIO QUE ELIJES ES: "<<endl;
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
	system("cls");
	cout<<endl;
	cout<<"--------------------------------------------"<<endl;
	cout<<"---------------CITA---------------"<<endl;
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
			cout<<"6. HISTORIAL DE PEDIDOS"<<endl;
			cout<<"0. Salir"<<endl;
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
	for(int i=1;i<=us[a].e;i++){
		cout<<"-----------------------------------------------"<<endl;
		cout<<"-------------PEDIDO DE MEDICAMENTO-------------"<<endl;
		cout<<"-----------------------------------------------"<<endl;
		cout<<"\tPACIENTE: "<<us[a].medicamentos[i].nombres<<" "<<us[a].medicamentos[i].apellido<<endl;
		cout<<"\tEDAD: "<<us[a].medicamentos[i].edad<<endl;
		cout<<"-----------------------------------------------"<<endl;
		cout<<"\tFECHA: "<<us[a].medicamentos[i].dia<<"/"<<us[a].medicamentos[i].mes<<"/"<<us[a].medicamentos[i].ano<<endl;
		cout<<"\t"<<us[a].medicamentos[i].tanti<<": "<<us[a].medicamentos[i].tmedi<<endl;
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
		cout<<"0. Salir"<<endl;
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
		cout<<"0. Salir"<<endl;
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
		cout<<"0. Salir"<<endl;
		cout<<"--------------------------------------"<<endl;
		cout<<"Seleccione una opcion: ";cin>>m;
		switch(m){
			case 1:
			case 2:
			case 3:
				system("cls");
				pedido(a,op,m,us[a].e+1);
				system("pause");
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
		cout<<"0. Salir"<<endl;
		cout<<"--------------------------------------"<<endl;
		cout<<"Seleccione una opcion: ";cin>>m;
		switch(m){
			case 1:
			case 2:
			case 3:
				system("cls");
				pedido(a,op,m,us[a].e+1);
				system("pause");
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
		cout<<"0. Salir"<<endl;
		cout<<"--------------------------------------"<<endl;
		cout<<"Seleccione una opcion: ";cin>>m;
		switch(m){
			case 1:
			case 2:
			case 3:
				system("cls");
				pedido(a,op,m,us[a].e+1);
				system("pause");
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
}

void pedido(int a,int op,int m,int e){
	string MD[5]={"ANTIBIOTICO","ANALGECICO","ANESTESICOS","ANTICOAGULANTES","ANTIHIPERTENSIVOS"};
	string AB[4];
	if(op==1){
		AB[0]="Amoxicilina"; AB[1]="Ceftriaxona"; AB[2]="Vancomicina"; AB[3]="Ciprofloxacina";
	} else if(op==2){
		AB[0]="Paracetamol"; AB[1]="Ibuprofeno"; AB[2]="Morfina"; AB[3]="Tramadol";
	} else if(op==3){
		AB[0]="Lidocaina"; AB[1]="Propofol"; AB[2]="Midazolam";
	} else if(op==4){
		AB[0]="Heparina"; AB[1]="Warfarina"; AB[2]="Enoxaparina";
	} else if(op==5){
		AB[0]="Lisinopril"; AB[1]="Losartán"; AB[2]="Metoprolol";
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
		us[a].medicamentos[e].tanti=MD[op-1];
		us[a].medicamentos[e].tmedi=AB[m-1];
	cout<<"-----------------------------------------------"<<endl;
	us[a].e=e;
}


void calendario(){
	cout<<" Lun Mar Mie Jue Vie Sab Dom"<<endl;
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

int inimes(int ano, int mes){
	int a= (14-mes)/12;
	int y=  ano -a;
	int m= mes+12*a-2;
	int dia= 1,d;
	d=(dia+y+y/4-y/100+y/400+(3*m)/12)%7;
	return d;
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
		cout<<"------------------MANANA------------------"<<endl;
		cout<<"HORA             DOCTOR     DISPONIBILIDAD"<<endl;
		cout<<"------------------------------------------"<<endl;
		string producto=" ";
		for(int i=1; i<=6;i++){
			if(i<10){
				cout<<horari<<espaciar(2,12)<< doc<<espaciar(producto.size(),16)<<mec[mes].mesit[dia].manana[i]<<endl;
			horari=horari+1;
			}
			else{
				cout<<horari<<espaciar(1,12)<< doc<<espaciar(producto.size(),16)<<mec[mes].mesit[dia].manana[i]<<endl;
			horari=horari+1;
			}
		}
	}
	else{
		cout<<"------------------------------------------"<<endl;
		cout<<"------------------TARDE------------------"<<endl;
		cout<<"HORA             DOCTOR     DISPONIBILIDAD"<<endl;
		cout<<"------------------------------------------"<<endl;
		string producto=" ";
		for(int i=1; i<=6;i++){
			cout<<horari<<espaciar(4,18)<< doc<<espaciar(producto.size(),19)<<mec[mes].mesit[dia].tardd[i]<<endl;
			horari=horari+1;
		}
	}	
}

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

void remplass(int tur,int mes, int dia, int xu){
	if(tur==1){
		mec[mes].mesit[dia].manana[xu]='n';
	}
	else{
	mec[mes].mesit[dia].tardd[xu]='n';	
	}
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