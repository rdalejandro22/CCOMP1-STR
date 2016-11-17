#include "miniwin.h"
#include <cstdlib>
#include <time.h>
/*

    cuadrado ||||   pivote = (0,0)
             ||||   extremos = (1,0),(0,1),(1,1)
    letra s  ||||   pivote = (0,0)
             ||||   extremos = (1,0),(-1,1),(0,1)
    s invert ||||   pivote = (0,0)
             ||||   extremos = (0,1),(1,1),(-1,0)
    letra l  ||||   pivote = (0,0)
             ||||   extremos = (0,-1),(0,1),(1,1)
    l invert ||||   pivote = (0,0)
             ||||   extremos = (0,-1),(0,1),(-1,1)
    largo    ||||   pivote = (0,0)
             ||||   extremos = (0,-1),(0,1),(0,2)
*/
using namespace miniwin;
const int TAM = 25;
const int FILAS = 20;
const int COLUMNAS = 10;
class Coordenadas
{
public:
    int x, y;
};
class Pieza
{
public:
    Coordenadas pivote;
    Coordenadas extremos[3];
    int color;
    Coordenadas posicion(int n) const {
        Coordenadas temp = {pivote.x, pivote.y};
        if(n != 0){
            temp.x += extremos[n-1].x;
            temp.y += extremos[n-1].y;
        }
    return temp;
    }  //extremos

};

/*struct Coordenadas
{
    int x, y;
};
struct Pieza
{
    Coordenadas pivote;
    Coordenadas extremos[3];
};*/
typedef int Tablero[COLUMNAS][FILAS];
void cuadrado(int x, int y){
    rectangulo_lleno(1 + x * TAM,
                     1 + y * TAM,
                     x * TAM + TAM,
                     y * TAM + TAM);
}
void crear_Pieza(Pieza &P){
    color(P.color);
    for(int i = 0; i < 4; i++){
        Coordenadas c = P.posicion(i);
        cuadrado(c.x, c.y);
    }
}
Coordenadas rotar_derecha(const Coordenadas &c){
    Coordenadas temp = {-c.y, c.x};
    return temp;
}
Coordenadas rotar_izquierda(const Coordenadas &c){
    Coordenadas temp = {c.y, -c.x};
    return temp;
}
void rotar_derecha(Pieza &P){
    for(int i = 0; i < 3; i++){
        P.extremos[i] = rotar_derecha(P.extremos[i]);
    }
}
void rotar_izquierda(Pieza &P){
    for(int i = 0; i < 3; i++){
        P.extremos[i] = rotar_izquierda(P.extremos[i]);
    }
}
void tablero_vacio(Tablero &T){
    for(int i=0; i < COLUMNAS; i++){
        for(int j=0; j < FILAS; j++){
            T[i][j] = NEGRO; //Casilla vacia
        }
    }
}
void tablero_lleno(const Tablero &T){
    for(int i=0; i < COLUMNAS; i++){
        for(int j=0; j < FILAS; j++){
            color(T[i][j]); //Casilla vacia
            cuadrado(i, j);
        }
    }
}
void tablero_fijar(Tablero &T, const Pieza &P){
    for(int i = 0; i < 4; i++){
        Coordenadas c = P.posicion(i);
        T[c.x][c.y] = P.color;
    }
}
bool tablero_conflicto(const Tablero &T, const Pieza &P){
    for(int i = 0; i < 4; i++){
        Coordenadas c = P.posicion(i);
        if(c.x < 0 || c.x >= COLUMNAS){
            return true;}
        if(c.y < 0 || c.y >= FILAS){
            return true;}
        if(T[c.x][c.y] != NEGRO){
            return true;}
    }
    return false;
}
Coordenadas extremos[6][3] = {
    {{1,0},{0,1},{1,1}},
    {{1,0},{-1,1},{0,1}},
    {{0,1},{1,1},{-1,0}},
    {{0,1},{0,-1},{1,1}},
    {{0,1},{0,-1},{-1,1}},
    {{0,1},{0,-1},{0,2}},
};
void pieza_nueva(Pieza &P){
    P.pivote.x = 5;
    P.pivote.y = 1;
    P.color = 1 + rand()%6;
    int pieza_aleatoria = rand() % 6;
    for(int i = 0; i < 3; i++){
        P.extremos[i] = extremos[pieza_aleatoria][i];
    }
}
bool tablero_filallena(Tablero &T, int fila){
        for(int i = 0; i < COLUMNAS; i++){
            if(T[i][fila] == NEGRO)
                return false;
        }
}
int main()
{
    vredimensiona(TAM*COLUMNAS,TAM*FILAS);
    srand(time(NULL));

    Tablero T;
    tablero_vacio(T);
    Pieza n;
    pieza_nueva(n);
    crear_Pieza(n);
    refresca();

    T[0][19] = VERDE;
    T[1][19] = AMARILLO;
    T[5][19] = CYAN;
    T[4][13] = AZUL;

    int t = tecla();
    while(t != ESCAPE){
        Pieza copia = n;
        if(t == ABAJO){
            n.pivote.y++;
        }
        if(t == ARRIBA){
            rotar_derecha(n);
        }
        if(t == IZQUIERDA){
            n.pivote.x--;
        }
        if(t == DERECHA){
            n.pivote.x++;
        }
        if(tablero_conflicto(T,n)){
            n = copia;
        }
        if(t == ESPACIO){
            tablero_fijar(T, n);
            pieza_nueva(n);
        }
        if(t != NINGUNA){
            borra();
            tablero_lleno(T);
            crear_Pieza(n);
            refresca();
        }
        t = tecla();
    }
    vcierra();
}

