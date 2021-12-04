#include"Arbol.h"

	Nodo* arbol = NULL;

int main() {
	int opc, numero;

	do
	{
			system("cls");
			cout << "\n\n\tElija una opcion" << endl
				<< "1) Agregar dato" << endl
				<< "2) Mostrar Arbol" << endl
				<< "3) Mostrar cantidad de Nodos"<<endl
				<< "4) Mostrar cantidad de Hojas"<<endl
				<< "0) Salir" << endl;
				cin >> opc;

		system("cls");

		switch (opc)
		{
		case 1:
			cout << "\n\n\tDigite un numero: ";
			cin >> numero;
			InsertarNodo(arbol,numero);
			cout << "\n\n";
			system("pause");
			
			break;

		case 2:
			MostrarArbol_Vistachida(arbol,0);
		//	MostrarArbol_Vistapreorden(arbol, 0);
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

		default:
			if (opc != 0) {
				cout << "\n\nOpcion no valida\n\n";
				system("pause");
			}
			break;
		}


	} while (opc!=0);


}