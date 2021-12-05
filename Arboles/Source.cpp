#include"Arbol.h"

	Nodo* arbol = NULL;


int main() {
	int opc, numero;
	int contador=0;

	do
	{
			system("cls");
			cout << "\n\n\t\tElija una opcion" << endl
				<< "\t1) Agregar dato" << endl
				<< "\t2) Mostrar Arbol" << endl
				<< "\t3) Mostrar cantidad de Nodos"<<endl
				<< "\t4) Mostrar cantidad de Hojas"<<endl
				<< "\t5) Mostrar altura del arbol"<<endl
				<< "\t6) Mostrar el mayor valor del arbol"<<endl
				<< "\t7) Borrar el nodo de menor valor"<<endl
				<< "\t0) Salir" << endl;
				cin >> opc;

		system("cls");

		switch (opc)
		{
		case 1:
			cout << "\n\n\tDigite un numero: ";
			cin >> numero;
			InsertarNodo(arbol,numero);
			cout << "\n\n";
			//system("pause");
			
			break;

		case 2:
			MostrarArbol_Vistachida(arbol,0);
		//	MostrarArbol_Vistapreorden(arbol, *&contador);
			cout << "\n\n";
			system("pause");
			break;

		case 3:
			Contador(arbol, 2);
			system("pause");
			break;

		case 4:
			Contador(arbol,1);
			system("pause");
			break;

		case 5:
			Arbol_altura(arbol);
			system("pause");
			break;

		case 6:
			Arbol_mayor(arbol);
			system("pause");
			break;

		case 7:
			Borrar_menor(arbol,true);
			system("pause");
			break;

		default:
			if (opc != 0) {
				cout << "\n\nOpcion no valida\n\n";
				system("pause");
			}
			break;
		}


	} while (opc!=0);


}