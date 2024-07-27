#include<iostream>
#include<ctime>
#include<string>
using namespace std;
int main(){
	time_t now=time(0);
	tm *time=localtime(&now);//Establece la hora y fecha actual de acuerdo a la fecha y hora local de la pc
	
	int year = 1900 + time->tm_year;//se suma 1900, porque la libreria toma en cuenta los años desde el año 1900
	int month = 1 + time->tm_mon;
	
	
	cout<<"Fecha: "<<time->tm_mday<<"/"<<month<<"/"<<year<<endl;
	
	return 0;
}