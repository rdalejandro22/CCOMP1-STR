#include <iostream>
#include <windows.h>
using namespace std;
char mapa[100][200] = {
"###################",
"#                 #",
"#                 #",
"#                 #",
"#                 #",
"#                 #",
"#                 #",
"#                 #",
"###################"
};
int x= 1;
int y= 1;
bool ejecucion = true;

int main()
{
    while(ejecucion==true)
    {
        system("cls");
        for(int visualizar=0; visualizar<10;visualizar++){
            cout << mapa[visualizar] << endl;}
        system("pause>nul");
        if(GetAsyncKeyState(VK_SPACE))
        {
            y = y+3;
            x = x+7;
            mapa[y][x] = '@';
        }
        if(GetAsyncKeyState(VK_DOWN)){
            int y2 = y+1;
            if(mapa[y2][x] != '#'){
                mapa[y][x] = ' ';
                y++;
                mapa[y][x] = '@';
            }
        }
        if(GetAsyncKeyState(VK_UP)){
            int y2 = y-1;
            if(mapa[y2][x] != '#'){
                mapa[y][x] = ' ';
                y--;
                mapa[y][x] = '@';
            }
        }
        if(GetAsyncKeyState(VK_RIGHT)){
            int x2 = x+1;
            if(mapa[y][x2] != '#'){
                mapa[y][x] = ' ';
                x++;
                mapa[y][x] = '@';
            }
        }
        if(GetAsyncKeyState(VK_LEFT)){
            int x2 = x-1;
            if(mapa[y][x2] != '#'){
                mapa[y][x] = ' ';
                x--;
                mapa[y][x] = '@';
            }
        }
        if(GetAsyncKeyState(VK_ESCAPE)){
            ejecucion=false;
        }
    }
    system("cls");
    cout << "GAME OVER";
    return 0;
}
