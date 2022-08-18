#include "folders.h"

#define CUSTOMERS 1
#define PRODUCTS 2
#define FEATURES 11
#define STRING_LENGTH 60
#define TXT ".txt"

typedef char string_len1[50];
typedef char string_len2[25];

typedef struct prod{
    int code;
    int bar_code;
    string_len1 description;
    string_len2 trademark;
    float price;
    string_len2 category1;
    string_len2 category2;
    int category3;
    int stock_u;
    float stock_w;
}products;

void openFileWrite(FILE *, int, string_len2);
FILE * openFileRead(FILE *, int, string_len2);
FILE * openFileReadAndWrite(FILE *, int, string_len2);
FILE * openFileAdd(FILE *, string_len2);
void closeFile(FILE *);
void removeFile(string_len1);
void recordRegister(FILE *, products);
void chargeRegister(int, int, int, FILE *, products);

//d = 1 CUSTUMERS FOLDER , d = 2 PRODUCTS FOLDER
void openFileWrite(FILE *f, int d, string_len2 f_name) {
    char ext[] = TXT;
    char path[20] = "";
    switch(d) {
        case CUSTOMERS: strcpy(path, DIR_CUSTOMERS);
        break;
        case PRODUCTS: strcpy(path, DIR_PRODUCTS);
        break;
    }
    strcat(path, f_name);
    strcat(path, ext);
    f = fopen(path, "w");
}

FILE * openFileRead(FILE *f, int d, string_len2 f_name) {
    char ext[] = ".txt";
    char path[20] = "";
    switch(d) {
        case CUSTOMERS: strcpy(path, DIR_CUSTOMERS);
        break;
        case PRODUCTS: strcpy(path, DIR_PRODUCTS);
        break;
    }
    strcat(path, f_name);
    strcat(path, ext);
    return f = fopen(path, "r");
}

FILE * openFileReadAndWrite(FILE *f, int d, string_len2 f_name) {
    char ext[] = ".txt";
    char path[20] = "";
    switch(d) {
        case CUSTOMERS: strcpy(path, DIR_CUSTOMERS);
        break;
        case PRODUCTS: strcpy(path, DIR_PRODUCTS);
        break;
    }
    strcat(path, f_name);
    strcat(path, ext);
    return f = fopen(path, "r+");
}

FILE * openFileAdd(FILE *f, string_len2 f_name) {
    char ext[] = ".txt";
    strcat(f_name, ext);
    return f = fopen(f_name, "a");
}

void closeFile(FILE*f) {
    fclose(f);
}

void removeFile(string_len2 f_name) {
    remove(f_name);
    printf("\nFILE DELTED\n");
}

void recordRegister(FILE *f, products p) {
    fwrite(&p, sizeof(products), 1, f);
}

void chargeRegister(int x, int y, int n, FILE *f, products p) {
    gotoXY(x, y);
    switch (n) {
        case 1: printf("-CODIGO INTERNO: "); scanf("%d", &p.code); fflush(stdin);
        break;
        case 2: printf("-CODIGO DE BARRAS: "); scanf("%d", &p.bar_code); fflush(stdin);
        break;
        case 3: printf("-DESCRIPCION: "); scanf("%[^\n]s", &p.description); fflush(stdin);
        break;
        case 4: printf("-MARCA: "); scanf("%[^\n]s", &p.trademark); fflush(stdin);
        break;
        case 5: printf("-PRECIO: "); scanf("%f", &p.price); fflush(stdin);
        break;
        case 6: printf("-CATEGORIA I: "); scanf("%[^\n]s", &p.category1); fflush(stdin);
        break;
        case 7: printf("-CATEGORIA II: "); scanf("%[^\n]s", &p.category2); fflush(stdin);
        break;
        case 8: printf("-NO PESABLE [1] - PESABLE [2]: "); scanf("%d", &p.category3); fflush(stdin);
        break;
        case 9: printf("-STOCK: "); scanf("%d", &p.stock_u); fflush(stdin);
        break;
        case 10: printf("-STOCK: "); scanf("%f", &p.stock_w); fflush(stdin);
        break;
        default: break;
    }
    recordRegister(f, p);
    gotoXY(x, y);
    int i;
    for(i=0;i<STRING_LENGTH;i++) {
        printf(" ");
    }
    n+=1;
    if(n < FEATURES) {
        chargeRegister(x, y, n, f, p);
    }
}