#include<iostream>
#include<unistd.h>
#include<ctime>
#include<string>
using namespace std;

int a=0;//Varible global para determinar en que índice se encuentra almacenada los datos

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
	int celular;
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
				ingresardt(a);
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
	cout<<"Numero de celular: ";cin>>us[x].celular;
	cout<<"Edad: ";cin>>us[x].edad;
	cout<<"Sexo: ";cin>>us[x].sexo;
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
				//citas();
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
				system("cls");
				menu();
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
		cout<<"2. Beneficios e información sobre el SDS\n";
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
	cout<<"- Fecha de nacimiento: \n Dia:";cin>>us[a].nacimiento.dia;cout<<"Mes: ";cin>>us[a].nacimiento.mes;cout<<"Anio: ";cin>>us[a].nacimiento.anio;
	cout<<"- Edad: "<<us[a].edad<<endl;
	cout<<"\n3. DOMICILIO DEL ASEGURADO\n";
	cin.ignore();
	cout<<"- Departamento: ";getline(cin, us[a].domicilio.departamento);
	cout<<"- Provincia: ";getline(cin, us[a].domicilio.provincia);
	cout<<"- Distrito: ";getline(cin, us[a].domicilio.distrito);
	cout<<"- Direccion: ";getline(cin, us[a].domicilio.direcion);

}
