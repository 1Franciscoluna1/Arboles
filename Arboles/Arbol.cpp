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
            Contar_Nodos(arbol, &contador);
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

void Contar_Nodos(Nodo* arbol, int* Contador)
{
    if (arbol == NULL) {
        if (Contador == 0) {
            cout << "\n\n\tArbol vacio\n\n";
        }
    }
        else
        {
        *Contador += 1;
            Contar_Nodos(arbol->Izquierda,Contador);
            Contar_Nodos(arbol->Derecha, Contador);
        }

}

void Arbol_altura(Nodo* arbol)
{
    int contador;

    if (arbol == NULL) {
        cout << "\n\n\tArbol Vacio\n\n";
    }
    else
    {
        contador = altura(arbol);
        cout << "\n\n\tEl tamaño del arbol es de " << contador + 1 << " niveles\n\n";
    }
}

int altura(Nodo* arbol)
{
    if (arbol==NULL)
    {
        return  -1;
    }
    else
    {
        int AltIzq, AltDer;

            AltDer = altura(arbol->Derecha);
            AltIzq = altura(arbol->Izquierda);

            if (AltIzq > AltDer)
                return AltIzq + 1;
            else
                return AltDer + 1;
        
    }
}

void Arbol_mayor(Nodo* arbol)
{
    if (arbol == NULL) {
        cout << "\n\n\tArbol Vacio\n\n";
    }
    else
    {
        Nodo* mayor;
        
        mayor = Mayor(arbol);

        cout << "El dato mas alto del arbol es " << mayor->Dato << endl<<endl;
    }
}

Nodo* Mayor(Nodo* arbol)
{
        return arbol->Derecha ? Mayor(arbol->Derecha) : arbol;
    
}

void Borrar_menor(Nodo*& arbol, bool es_raiz)
{
    if (arbol == NULL && es_raiz == true)
    {
        cout << "\n\n\tArbol Vacio\n\n";
    }
    else
    {
        Nodo* El_Menor = Menor(arbol);

        if (arbol == NULL) return;

        if (El_Menor->Dato < arbol->Dato) {
            Borrar_menor(arbol->Izquierda, El_Menor);
        }
        else if (El_Menor->Dato > arbol->Dato) {
            Borrar_menor(arbol->Derecha, El_Menor);
        }

        else
        {
            Nodo* p = arbol;
            arbol = unirArbol(arbol->Izquierda, arbol->Derecha);

            cout << "\n\n\t Queda eliminado el nodo " << p->Dato << endl;
            free(p);
        }
        
    }
}

Nodo* Menor(Nodo* arbol)
{
    return arbol->Izquierda ? Menor(arbol->Izquierda) : arbol;
}

Nodo* unirArbol(Nodo* izq, Nodo* der)
{
    if (izq == NULL) return der;
    if (der == NULL) return izq;

    Nodo* centro = unirArbol(izq->Derecha, der->Izquierda);
    izq->Derecha = centro;
    der->Izquierda = izq;
    return der;
}
