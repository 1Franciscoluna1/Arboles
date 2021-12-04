#pragma once
#include<iostream>
#include<conio.h>
#include<stdlib.h>


using namespace std;

struct Nodo {
	int Dato;
	Nodo* Izquierda;
	Nodo* Derecha;
};


	Nodo* crearNodo(int Numero);
	void InsertarNodo(Nodo*& arbol, int Numero);

	void MostrarArbol_Vistachida(Nodo* arbol, int contador);
	void MostrarArbol_Vistapreorden(Nodo* arbol, int contador);

	void Contador(Nodo* arbol,int Tipo);
	int Contar_Hojas(Nodo* arbol, int contador);
	int Contar_Nodos(Nodo* arbol, int Contador);

	void Arbol_altura(Nodo* arbol);
	int altura(Nodo* arbol, int altura, int j, int i);
