#include <iostream>

using namespace std;
template <class T>
class Cola {
private:
    class Nodo {
    public:
        int info;
        Nodo *sig;
    };

    Nodo *raiz;
    Nodo *fondo;
public:
    Cola();
   // ~Cola();
    void insertar(int x);
    int extraer();
    void imprimir();
    bool vacia();
    int suma();
};

template <class T>
Cola<T>::Cola()
{
    raiz = NULL;
    fondo = NULL;
}

template <class T>
void Cola<T>::insertar(int x)
{
    Nodo *nuevo;
    nuevo = new Nodo();
    nuevo->info = x;
    nuevo->sig = NULL;
    if (vacia()) 
    {
        raiz = nuevo;
        fondo = nuevo;
    }
    else {
        fondo->sig = nuevo;
        fondo = nuevo;
    }
}
template <class T>
int Cola<T>::extraer()
{
    if (!vacia())
    {
        int informacion = raiz->info;
        Nodo *bor = raiz;
        if (raiz == fondo)
        {
            raiz = NULL;
            fondo = NULL;
        }
        else 
        {
            raiz = raiz->sig;
        }
        delete bor;
        return informacion;
    }
    else
        return -1;
}

template <class T>
void Cola<T>::imprimir()
{
    Nodo *reco = raiz;
  //  cout << "Listado de todos los elementos de la cola.\n";
    while (reco != NULL)
    {
        cout << reco->info << "-";
        reco = reco->sig;
    }
    cout << "\n";
}
template <class T>
bool Cola<T>::vacia()
{
    if (raiz == NULL)
        return true;
    else
        return false;
}
// no son para colas generales
template <class T>
int Cola<T>::suma(){
	Nodo *reco = raiz;
  	int aux=0;
    while (reco != NULL)
    {
        aux+= reco->info;
        reco = reco->sig;
    }
    
    return aux;
}


