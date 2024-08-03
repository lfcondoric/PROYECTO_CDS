#include<iostream>
#include<unistd.h>
#include<ctime>
#include<string>
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

struct USUARIOS{
	int dni;
	string nombres;
	string apellidos;
	int edad;
	char sexo[20];
	FECHA nacimiento;
	DOMI domicilio;
}us[100];

void menu();
void registro();
void ingresardt(int x);
void iniciosesion();
void verificardni(int dni);
void menu2(int a);
void seguro(int a);
void registrosds(int a);
void menucitas(int a);
void citas(int op);
void fecha();

int main(){
    menu();
    return 0;
}

void menu(){//Primer menú del programa
    int op;
    do{
    	cout<<"\t\t\tBienvenido al programa CDS\n";
        cout<<"1. Registrarse"<<endl; 
        cout<<"2. Iniciar sesion"<<endl;
        cout<<"0. Salir"<<endl;
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
		cout<<"1. Ingresar Datos personales\n";
		cout<<"2. Volver\n";
		cout<<"Selecione una opcion: ";cin>>op;
		switch(op){
			case 1:
				system("cls");
				ingresardt(a);//Al mandar una copia de a estoy mandando el indice donde quiero que se guarden los datos de un usuario
				a++;
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
	cout<<"DNI: ";cin>>us[x].dni;
	cin.ignore();
	cout<<"Nombres: ";getline(cin, us[x].nombres);
	cout<<"Apellidos: ";getline(cin, us[x].apellidos);
	system("pause");
	system("cls");
}

void iniciosesion(){//menú para la opción 2. Iniciar sesión
	int op,a;
	do{
		cout<<"1. Ingresar DNI\n";
		cout<<"2. Volver\n";
		cout<<"Selecione una opcion: ";cin>>op;
		switch(op){
			case 1:
				system("cls");
				cout<<"DNI:";cin>>a;
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
			menu2(i);//<-- si se cumple el if llamaría a la función señalada
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
	do{
		cout<<"1. Registro al Seguro de Salud\n";
		cout<<"2. Servicios que brinda\n";
		cout<<"3. Citas\n";
		cout<<"4. Farmacia\n";
		cout<<"5. Notificaciones\n";
		cout<<"0. Cerrar Sesión\n";
		cout<<"Seleccione una opcion: ";cin>>op;
		switch(op){
			case 1:
				system("cls");
				seguro(a);
				break;
			case 2:
				system("cls");
				//servicios();
				break;
			case 3:
				system("cls");
				menucitas(a);
				break;
			case 4:
				system("cls");
				//farmacia();
				break;
			case 5:
				system("cls");
				//notificaciones();
				break;
			case 0:
				cout<<"Cerrando sesion";
           			for(int i=1;i<=3;i++){
            		cout<<".";
            	sleep(1);
				}
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

void seguro(int a){
	int op;
	do{
		cout<<"1. Continuar con el registro\n";
		cout<<"2. Beneficios e informacion sobre el SDS\n";
		cout<<"3. Volver\n";
		cout<<"Selecione una opcion: ";cin>>op;
		switch(op){
			case 1:
				system("cls");
				registrosds(a);
				break;
			case 2:
				system("cls");
				//info();
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
	cout<<"----INGRESE SUS DATOS PERSONALES-----";
	cout<<"\n1. DE LA AFILIACIÓN\n";
	cout<<"- Fecha: \n";//<<Agrear fecha actual con la libreria ctime
	cout<<"\n2. DATOS DEL ASEGURADO\n";
	cout<<"- Tipo de documento: DNI\n Nro.Documento: "<<us[a].dni<<endl;
	cout<<"- Nombre: "<<us[a].nombres<<endl;
	cout<<"- Apellidos: "<<us[a].apellidos<<endl;;
	cout<<"- Fecha de nacimiento: \nDia:";cin>>us[a].nacimiento.dia;cout<<"Mes: ";cin>>us[a].nacimiento.mes;cout<<"Anio: ";cin>>us[a].nacimiento.anio;
	cout<<"- Edad: ";cin>>us[a].edad;//Se piensa habilitar algunas lecturas de datos adicionales de acuerdo a la edad del afiliado
	cout<<"- Sexo: ";cin>>us[a].sexo;
	cout<<"\n4. DOMICILIO DEL ASEGURADO\n";
	cin.ignore();
	cout<<"- Departamento: ";getline(cin, us[a].domicilio.departamento);
	cout<<"- Provincia: ";getline(cin, us[a].domicilio.provincia);
	cout<<"- Distrito: ";getline(cin, us[a].domicilio.distrito);
	cout<<"- Direccion: ";getline(cin, us[a].domicilio.direcion);
	//Se piensa agregar mas lecturas de datos
	system("cls");
	return;

}
void menucitas(int a){
	int op;
	do{
		system("cls");
		cout<<"--------SERVICIOS---------"<<endl;
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
				citas(op);
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
	}while(op!=0);
}
void citas(int op){
	
}