#ifndef REGISTROS_H
#define REGISTROS_H
#include<string>
#include<iostream>
#include<unistd.h>
using namespace std;

//Para la opción farmacia
struct MEDI{
	string nombres;
	string apellido;
	int edad;
	string tanti;
	string tmedi;
	int unidades;
	int hora,minuto,segundo;
	int dia, mes, ano;
};
//---------------------------------------------------



//Completar espacio de citas
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

extern mestarma mec[12];
extern nocit mecit[12];
//-----------------------------------------------------




//Estructuras para el control de las citas
struct CITAS{
	string medico;
	int fdia, dia, fmes, mes, fano, ano, dni;//<-- Los que f.... alamacenará la fecha actual en la que se solicito la cita. Dia,mes, ano es la fecha programada para la cita
	string especialidad;
	int consultorio;
	string nombres;
	string apellidos;
};
struct citass{
	int h;       
	int di;
	string me;
	int an;
};
//-----------------------------------------------------



//Estructuras Para almacenar información del usuario
struct FECHA{
	int dia,mes,anio;
};

struct DOMI{
	string departamento;
	string provincia;
	string distrito;
	string direcion;
};
//---------------------------------------------------



struct USUARIOS{
	//Información del usuario
	int dni;
	int edad;
	char sexo[20];
	FECHA nacimiento;
	DOMI domicilio;
	string nombres;
	string apellidos;
	//citas
	citass ala[50];
	CITAS citas[100];
	int i = 0;//<-- Ayuda a almacenar las citas en orden
	int x = 0;
	//farmacia
	int e = 0;//<-- Ayuda a almacenar los medicamentos en orden
	MEDI medicamentos[100];
	int menperso = 0;//Menu perzonalizado
};
//variable global para determinar el inidice donde se guardaron los datos de usuario
extern int a;
//
extern int tope;

extern USUARIOS us[100];

#endif