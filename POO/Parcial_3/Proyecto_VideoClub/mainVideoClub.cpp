#include <iostream>
#include "Menu.cpp"

using namespace std;

int main()
{
    Menu objMenu;
    while (!objMenu.validarContrasena());
    objMenu.menuPrincipal();

    return 0;
}