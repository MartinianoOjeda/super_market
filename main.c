#include "super_market.h"

FILE *f;
DIR *d;
products p;
string_len2 name;

int main() {
    strcpy(name, "lista_de_productos");
    createFolders();
    openFileWrite(f, PRODUCTS, name);
    system("cls");
    chargeRegister(5, 5, 1, f, p);
    while(1);

    return 0;
}