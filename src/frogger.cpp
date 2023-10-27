#include <Ventana.hpp>
#include <Dibujo.hpp>
#include <Actualizable.hpp>
#include <Controlador.hpp>
#include <Frog.hpp>
#include <curses.h>
#include <unistd.h>
#include <list>
using namespace std;


int main(int argc, char const *argv[])
{
    Ventana v;
    Frog* fr = new Frog();
    Controlador* control = new Controlador(); 

    Dibujo* d1 = new Dibujo(2,1,"frog");
    Dibujo* d2 = new Dibujo(20,1,"frogjump");

    list<Dibujo*> dibujos;
    dibujos.push_back(d1);
    dibujos.push_back(d2);
    dibujos.push_back(fr);

    list<Actualizable*> actualizables;
    actualizables.push_back(control);
    actualizables.push_back(fr);
    
    bool ejecucion = true;
    while (ejecucion)
    {
        v.Actualizar(actualizables);
        v.Dibujar(dibujos);
    } 

    return 0;
}