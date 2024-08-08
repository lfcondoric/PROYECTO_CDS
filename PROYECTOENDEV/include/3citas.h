#ifndef CITAS3_H
#define CITAS3_H
#include<iostream>
#include<string>
using namespace std;

//Funciones para establecer la cita
int remplazarhorita(int tur,int horita);
int inimes(int ano, int mes);
int caldiames(int ano,int mes);
void remplass(int tur,int mes, int dia, int xu);
void mesdias(int ano, int mes);
void pantalla(int tur,string doc,int mes,int dia);
void calendario();
string namemes(int mes);
string espaciar(int tam, int valor);
//------------------------------------------------

//Funciones para interactuar con el menú de citas
void menucitas(int a);
void historialdeC(int a);
void citas(int a,int op, int e);
//------------------------------------------------




#endif