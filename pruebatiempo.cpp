#include<iostream>
#include<ctime>
using namespace std;
int main(){
	time_t now=time(0);
	tm *time=localtime(&now);
	cout<<"Hora: "<<time->tm_hour<<endl;
	cout<<"Minuto: "<<time->tm_min<<endl;
	cout<<"Segundo: "<<time->tm_sec<<endl;
	return 0;
}