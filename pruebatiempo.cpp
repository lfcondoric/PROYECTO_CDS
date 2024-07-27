#include<iostream>
#include<ctime>
#include<string>
#include<windows.h>
using namespace std;
int main(){
	time_t now=time(0);
	tm *time=localtime(&now);//Establece la hora y fecha actual de acuerdo a la fecha y hora local de la pc
	
	int sec = time->tm_sec, min = time->tm_min, hour = time->tm_hour;
	while(true){
	cout<<hour<<":"<<min<<":"<<sec<<endl;

	Sleep(1000);
	sec++;
	if(sec==60){
		min++;
		sec=0;
	}
	if(min==60){
		hour++;
		min=0;
	}
	if(hour>=24){
		hour=0;
	}
	system("cls");
	}


	
	
	return 0;
}