#include "miniwin.h"
using namespace miniwin;
const int TAM = 25;
struct Coordenadas
{
    int x, y;
};
struct Pieza
{
    Coordenadas pivote;
    Coordenadas extremos[3];
};
void cuadrado(int x, int y){
    rectangulo_lleno(1 + x * TAM,
                     1 + y * TAM,
                     x * TAM + TAM,
                     y * TAM + TAM);
}
void crear_Pieza(const Pieza &P){
    color(VERDE);
    cuadrado(P.pivote.x, P.pivote.y); //central
    for(int i = 0; i < 3; i++){
        cuadrado(P.pivote.x + P.extremos[i].x,
                 P.pivote.y + P.extremos[i].y);
    }
}
int main()
{
    vredimensiona(500,500);
    Pieza s1 = {{2,2},{{-1,-1},{0,-1},{1,0}}};
    crear_Pieza(s1);
    refresca();
}

