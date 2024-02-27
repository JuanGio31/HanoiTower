#include <iostream>

using namespace std;

//-------------------------------Nodo-------------------------
template <typename T>

class Nodo
{
private:
    T dato;
    Nodo *siguiente;

public:
    // getters & setters
    T obtenerDato()
    {
        return this->dato;
    }
    void modificarDato(T dato)
    {
        this->dato = dato;
    }
    Nodo *obtenerSiguiente()
    {
        return this->siguiente;
    }
    void modificarSiguiente(Nodo *siguiente)
    {
        this->siguiente = siguiente;
    }
    // fin

    // Constructor
    Nodo(T dato, Nodo *siguiente)
    {
        this->dato = dato;
        this->siguiente = siguiente;
    }
    // fin
};

// ---------------------------Lista Simple -------------------
template <typename T>
class ListaSimple
{
private:
    int dimension;
    Nodo<T> *cabecera;
    Nodo<T> *cola;

public:
    bool estaVacia()
    {
        if (dimension == 0)
        {
            return true;
        }
        return false;
    }

    int
    obtenerDimension()
    {
        return this->dimension;
    }

    Nodo<T> *obtenerCabecera()
    {
        return this->cabecera;
    }

    Nodo<T> *obtenerCola()
    {
        return this->cola;
    }

    void modificarCabecera(Nodo<T> *cabecera)
    {
        this->cabecera = cabecera;
    }

    void modificarCola(Nodo<T> *cola)
    {
        this->cola = cola;
    }

    ListaSimple()
    {
        this->cabecera = nullptr;
        this->cola = nullptr;
        this->dimension = 0;
    }

    Nodo<T> *obtenerDatoIndice(int pos)
    {
        int i = 1;
        Nodo<T> *actual = this->cabecera;
        if (pos < 0 || pos > dimension)
        {
            return nullptr;
        }
        else if (pos == 1)
        {
            return cabecera;
        }
        else
        {
            while (actual)
            {
                if (i == pos)
                {
                    break;
                }
                else
                {
                    actual = actual->obtenerSiguiente();
                    i++;
                }
            }
        }
        return actual;
    }

    void
    agregarFinal(T valor)
    {
        Nodo<T> *nuevo = new Nodo<T>(valor, nullptr);
        if (this->cabecera)
        {
            Nodo<T> *actual = this->cabecera;
            while (actual->obtenerSiguiente())
            {
                actual = actual->obtenerSiguiente();
            }
            actual->modificarSiguiente(nuevo);
            modificarCola(actual->obtenerSiguiente());
        }
        else
        {
            this->cabecera = nuevo;
            modificarCola(nuevo);
        }
        this->dimension++;
    }

    void eliminarFinal()
    {
        if (dimension == 0)
        {
            cout << "La lista esta vacia.!";
        }
        else
        {

            if (this->cabecera)
            {
                Nodo<T> *actual = this->cabecera;
                Nodo<T> *prev = actual;

                while (actual->obtenerSiguiente())
                {
                    prev = actual;
                    actual = actual->obtenerSiguiente();
                }

                if (actual == this->cabecera)
                {
                    this->cabecera = this->cabecera->obtenerSiguiente();
                    modificarCola(cabecera);
                    delete actual;
                    this->dimension--;
                }
                else
                {
                    prev->modificarSiguiente(nullptr);
                    modificarCola(prev);
                    delete actual;
                    this->dimension--;
                }
            }
            else
            {
                cout << "La lista esta vacia." << endl;
            }
        }
    }

    void imprimirLista()
    {
        Nodo<T> *actual = this->cabecera;
        while (actual)
        {
            cout << actual->obtenerDato() << " ";
            actual = actual->obtenerSiguiente();
        }
        cout << endl
             << endl;
    }
};