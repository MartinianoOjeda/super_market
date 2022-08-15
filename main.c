#include "super_market.h"

FILE *f;
DIR *d;

int main() {
    string15 name; 
    createFolders();
    scanf("%[^\n]s", name);
    f = openFileWrite(f, 1, name);
    showCustomers(d);
    while(1);

    return 0;
}