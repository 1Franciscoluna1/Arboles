#include "Arbol.h"


Nodo* crearNodo(int Numero)
{
    Nodo* nodo = new Nodo();

    nodo->Dato      = Numero;
    nodo->Derecha   = NULL;
    nodo->Izquierda = NULL;

    return nodo;
}

void InsertarNodo(Nodo*& arbol, int Numero)
{
    if (arbol == NULL) {
        Nodo* nodo = crearNodo(Numero);
        arbol = nodo;
    }
    else if (Numero!=arbol->Dato)
    {
        int valRaiz = arbol->Dato;
        if (Numero < valRaiz)
        {
            InsertarNodo(arbol->Izquierda,Numero);
        }
        else if (Numero > valRaiz)
        {
            InsertarNodo(arbol->Derecha, Numero);
        }


    }
    else
    {
        cout << "\n\n\tEl dato ya esta dentro del arbol\n\n";
    }
}

void MostrarArbol_Vistachida(Nodo* arbol, int contador)
{
    if (arbol==NULL) {
        if (contador == 0) {
            cout << "\n\n\tArbol vacio\n\n";
        }
        return;
    }
    else
    {
        MostrarArbol_Vistachida(arbol->Derecha,contador+1);
        for (int i = 0; i < contador; i++)
        {
            cout << "   ";
        }
        cout << arbol->Dato << endl;
        MostrarArbol_Vistachida(arbol->Izquierda,contador+1);
    }
}

void MostrarArbol_Vistapreorden(Nodo* arbol, int contador)
{
    if (arbol == NULL) {
        if (contador==0) {
            cout << "\n\n\tArbol vacio\n\n";
        }
        else
        {
        cout << " - ";
        }
    }
    else
    {
        contador++;
        cout << "( " << arbol->Dato << " ";
        MostrarArbol_Vistapreorden(arbol->Izquierda,1);
        MostrarArbol_Vistapreorden(arbol->Derecha,1);
        cout << " )";
    }
}

void Contador(Nodo* arbol,int Tipo)
{
    int contador = 0;
    if (arbol == NULL) {
        cout << "\n\n\tArbol Vacio\n\n";
    }
    else
    {
        if (Tipo==1)
        {
        contador = Contar_Hojas(arbol, contador);
        cout << "\n\n\tEl arbol cuenta con " << contador << " Hojas\n\n";
        }
        else if (Tipo==2)
        {
            contador = Contar_Nodos(arbol, contador);
            cout << "\n\n\tEl arbol cuenta con " << contador << " Nodos\n\n";
        }
    }
}

int Contar_Hojas(Nodo* arbol, int Contador)
{
    if (arbol == NULL) {
        return Contador;
    }
    else
    {
        if (arbol->Derecha == NULL && arbol->Izquierda == NULL) {
            return (Contador + 1);
        }
         Contador = Contar_Hojas(arbol->Derecha, Contador);
         Contador = Contar_Hojas(arbol->Izquierda, Contador);
         return (Contador);
    }
}

int Contar_Nodos(Nodo* arbol, int Contador)
{
    if (arbol==NULL)
    {
        return Contador;
    }
    Contador = Contar_Nodos(arbol->Derecha, Contador+1);
    Contador = Contar_Nodos(arbol->Izquierda, Contador);
    return (Contador);
}

void Arbol_altura(Nodo* arbol)
{
    int contador = 0;

    if (arbol == NULL) {
        cout << "\n\n\tArbol Vacio\n\n";
    }
    else
    {
        contador = altura(arbol,0,1,0);
        cout << "\n\n\tEl tamaño del arbol es de " << contador << " niveles\n\n";
    }
}

int altura(Nodo* arbol, int Altura, int j, int i)
{
    if (arbol!=NULL)
    {
        i++;

        if (i==j) {
            j++;
            Altura = j - 1;
        return Altura;
        }
        Altura = altura(arbol->Izquierda, Altura, j, i);
        Altura = altura(arbol->Derecha, Altura, j, i);
        i--;
    }
}
