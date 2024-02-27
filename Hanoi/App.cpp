#include <iostream>
#include "ListaSimple.hpp"
using namespace std;

void printMap();
void iniciarJuego();
void limpiarPantalla();
void printWin();
void printLoser();
void modalidad(int);

// declarar Listas
ListaSimple<int> torre_1;
ListaSimple<int> torre_2;
ListaSimple<int> torre_3;
bool gano = false;
int longitud = 0;

void llenarLista(int opcion)
{
    switch (opcion)
    {
    case 7:
        torre_1.agregarFinal(7);
        torre_1.agregarFinal(6);
        torre_1.agregarFinal(5);
        torre_1.agregarFinal(4);
        torre_1.agregarFinal(3);
        torre_1.agregarFinal(2);
        torre_1.agregarFinal(1);
        longitud = 7;
        break;
    case 6:
        torre_1.agregarFinal(6);
        torre_1.agregarFinal(5);
        torre_1.agregarFinal(4);
        torre_1.agregarFinal(3);
        torre_1.agregarFinal(2);
        torre_1.agregarFinal(1);
        longitud = 6;
        break;
    case 5:
        torre_1.agregarFinal(5);
        torre_1.agregarFinal(4);
        torre_1.agregarFinal(3);
        torre_1.agregarFinal(2);
        torre_1.agregarFinal(1);
        longitud = 5;
        break;
    case 4:
        torre_1.agregarFinal(4);
        torre_1.agregarFinal(3);
        torre_1.agregarFinal(2);
        torre_1.agregarFinal(1);
        longitud = 4;
        break;
    case 3:
        torre_1.agregarFinal(3);
        torre_1.agregarFinal(2);
        torre_1.agregarFinal(1);
        longitud = 3;
        break;
    default:
        cout << "Opcion no valida, ingresar num de [3-7]" << endl;
        break;
    }
}

int main()
{
    cout << "Bienvenido a <Hanoi>.\n";

    int op = 0;
    while (true)
    {
        cout << "Ingrese la cantidad de discos > ";
        cin >> op;
        llenarLista(op);

        if (op > 2 && op < 8)
        {
            break;
        }
    }

    iniciarJuego();
    return 0;
}
void evaluar()
{
    int contador = 0;
    if (longitud == torre_3.obtenerDimension())
    {
        int i = longitud;
        int j = 1;
        while (i > 0)
        {

            if (i == torre_3.obtenerDatoIndice(j)->obtenerDato())
            {
                contador++;
            }

            if (contador == longitud)
            {
                gano = true;
                break;
            }

            i--;
            j++;
        }
    }
}

void iniciarJuego()
{
    int teclado = -1;
    string opciones = "1. Mover disco [T1]->[T2].\t"
                      "2. Mover disco [T1]->[T3].\t"
                      "3. Mover disco [T2]->[T1].\t\n\n"
                      "4. Mover disco [T2]->[T3].\t"
                      "5. Mover disco [T3]->[T1].\t"
                      "6. Mover disco [T3]->[T2].\n\n"
                      "\t\t\t\t0. Salir.\n"
                      "\nIngrese una opcion > ";

    while (true)
    {
        printMap();
        if (gano)
        {
            break;
        }
        cout << opciones;
        cin >> teclado;

        if (teclado == 0)
        {
            cout << "\nAdios.....\n\n";
            break;
        }
        else
        {
            limpiarPantalla();
            modalidad(teclado);
            cout << endl;
        }
        evaluar();
    }

    if (gano)
    {
        printWin();
    }
    else
    {
        printLoser();
    }

    cout << endl
         << endl;
}

void modalidad(int opcion)
{
    int aux;
    switch (opcion)
    {
    case 1:
        if (torre_1.estaVacia())
        {
            break;
        }

        aux = torre_1.obtenerCola()->obtenerDato();
        torre_2.agregarFinal(aux);
        torre_1.eliminarFinal();
        break;
    case 2:
        if (torre_1.estaVacia())
        {
            break;
        }
        aux = torre_1.obtenerCola()->obtenerDato();
        torre_3.agregarFinal(aux);
        torre_1.eliminarFinal();
        break;
    case 3:
        if (torre_2.estaVacia())
        {
            break;
        }
        aux = torre_2.obtenerCola()->obtenerDato();
        torre_1.agregarFinal(aux);
        torre_2.eliminarFinal();
        break;
    case 4:
        if (torre_2.estaVacia())
        {
            break;
        }
        aux = torre_2.obtenerCola()->obtenerDato();
        torre_3.agregarFinal(aux);
        torre_2.eliminarFinal();
        break;
    case 5:
        if (torre_3.estaVacia())
        {
            break;
        }
        aux = torre_3.obtenerCola()->obtenerDato();
        torre_1.agregarFinal(aux);
        torre_3.eliminarFinal();
        break;
    case 6:
        if (torre_3.estaVacia())
        {
            break;
        }
        aux = torre_3.obtenerCola()->obtenerDato();
        torre_2.agregarFinal(aux);
        torre_3.eliminarFinal();
        break;
    default:
        cout << "\nOpcion no valida.\n";
        break;
    }
}

string obtenerdiscos(ListaSimple<int> lista, int indice, int op1, int op2)
{
    string tmp = "";
    if (op1 != 1)
    {
        tmp += "   ";
    }
    else
    {
        tmp += "|   ";
    }

    if (lista.estaVacia() || lista.obtenerDatoIndice(indice) == nullptr)
    {
        tmp += "         |         ";
    }
    else
    {
        switch (lista.obtenerDatoIndice(indice)->obtenerDato())
        {
        case 1:
            tmp += "        ***        ";
            break;
        case 2:
            tmp += "       *****       ";
            break;
        case 3:
            tmp += "      *******      ";
            break;
        case 4:
            tmp += "     *********     ";
            break;
        case 5:
            tmp += "    ***********    ";
            break;
        case 6:
            tmp += "   *************   ";
            break;
        case 7:
            tmp += "  ***************  ";
            break;
        }
    }
    if (op2 == 3)
    {
        tmp += "   |";
    }
    else
    {
        // tmp += "  ";
    }

    return tmp;
}
void printCuerpo()
{
    int i = longitud;
    while (i > 0)
    {
        cout << obtenerdiscos(torre_1, i, 1, 0) << obtenerdiscos(torre_2, i, 0, 0) << obtenerdiscos(torre_3, i, 0, 3) << endl;
        i--;
    }
}

void printHeader()
{
    cout << " + - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - +\n"
         << "|            1                     2                     3            |\n"
         << "|                                                                     |\n"
         << "|            |                     |                     |            |\n"
         << "|            |                     |                     |            |\n";
}

void printFooter()
{
    cout << "|   MMMMMMMMMMMMMMMMMMM   MMMMMMMMMMMMMMMMMMM   MMMMMMMMMMMMMMMMMMM   |\n"
         << "|                                                                     |\n"
         << " + - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - +\n";
}

void printMap()
{
    printHeader();
    printCuerpo();
    printFooter();
    cout << "\n";
}

void printWin()
{
    string winString = " + - - - - - - - - - - - - - - - - +\n"
                       "|    WW    WW  WWWWWWWW  WW    WW   |\n"
                       "|    WW    WW  WW    WW  WWW   WW   |\n"
                       "|    WW ++ WW  WW    WW  WW WW WW   |\n"
                       "|    WW WW WW  WW    WW  WW   WWW   |\n"
                       "|     WW  WW   MMMWMMMM  WW    WW   |\n"
                       " + - - - - - - - - - - - - - - - - +";

    cout << winString << endl;
}

void printLoser()
{
    string loser = " + - - - - - - - - - - - - - - - - - - - - - - - +\n"
                   "|   MM       MMMMMMM  MMMMMMM  MMMMMMM  MMMMMMM   |\n"
                   "|   MM       MM   MM  MM       MM       MM   MM   |\n"
                   "|   MM       MM   MM  MMMMMMM  MMMMM    MMMMM+    |\n"
                   "|   MM       MM   MM       MM  MM       MM  MM    |\n"
                   "|   MMMMMMM  MMMMMMM  MMMMMMM  MMMMMMM  MM   MM   |\n"
                   " + - - - - - - - - - - - - - - - - - - - - - - - +";
    cout << loser << endl;
}

#ifdef _WIN32
#include <windows.h>
#endif

void limpiarPantalla()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}