#pragma once
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include <algorithm>


using namespace std;


struct Nodo {
	int Dato;
	Nodo* Izquierda;
	Nodo* Derecha;
};


	Nodo* crearNodo(int Numero);
	void InsertarNodo(Nodo*& arbol, int Numero);

	void MostrarArbol_Vistachida(Nodo* arbol, int contador);
	void MostrarArbol_Vistapreorden(Nodo* arbol,int contador);

	void Contador(Nodo* arbol,int Tipo);
	int Contar_Hojas(Nodo* arbol, int contador);
	void Contar_Nodos(Nodo* arbol, int* Contador);

	void Arbol_altura(Nodo* arbol);
	int	altura(Nodo* arbol);

	void Arbol_mayor(Nodo* arbol);
	Nodo* Mayor(Nodo* arbol);

	void Borrar_menor(Nodo*& arbol, bool es_raiz);
	Nodo* Menor(Nodo* arbol);
	Nodo* unirArbol(Nodo* izq, Nodo* derecho);