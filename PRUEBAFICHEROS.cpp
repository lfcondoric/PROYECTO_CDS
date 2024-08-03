#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;

void lectura();

int main(){
	lectura();
	return 0;
}

void lectura(){
	ifstream textoprueba;
	string texto;
		
	textoprueba.open("texto.txt",ios::in);//Abrir el archivos en modo lectura
	
	if(textoprueba.fail()){
		cout<<"No se pudo abrir el archivos\n";
		exit(1);
	}
	
	while(!textoprueba.eof()){//Mientras no sea el final del archivo
		getline(textoprueba,texto);
		cout<<texto<<endl;
	}
	
	textoprueba.close();
}