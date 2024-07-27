#include<iostream>
#include<ctime>
#include<string>
using namespace std;
int main(){
	time_t now=time(0);
	tm *time=localtime(&now);
	
	string dia_semana[20];
	dia_semana[0]="Domingo";
	dia_semana[1]="Lunes";
	dia_semana[2]="Martes";
	dia_semana[3]="Miercoles";
	dia_semana[4]="Jueves";
	dia_semana[5]="Viernes";
	dia_semana[6]="Sabado";
	
	
	cout<<"Dia de la semana: "<<dia_semana[time->tm_wday]<<endl;
	return 0;
}