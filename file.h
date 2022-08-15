#include "folders.h"

#define CUSTOMERS 1
#define PRODUCTS 2


typedef char string50[50];
typedef char string15[15];

typedef struct prod{
    int code;
    int bar_code;
    string50 description;
    string15 trademark;
    float price;
    string15 category1;
    string15 category2;
    int stock_u;
    float stock_w;
}products;

FILE * openFileWrite(FILE *, int, string15);
FILE * openFileRead(FILE *, int, string15);
FILE * openFileReadAndWrite(FILE *, int, string15);
FILE * openFileAdd(FILE *, string15);
void closeFile(FILE *);
void removeFile(string15);
void recordRegister(FILE *, products);

FILE * openFileWrite(FILE *f, int d, string15 f_name) {
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
    return f = fopen(path, "w");
}

FILE * openFileRead(FILE *f, int d, string15 f_name) {
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

FILE * openFileReadAndWrite(FILE *f, int d, string15 f_name) {
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

FILE * openFileAdd(FILE *f, string15 f_name) {
    char ext[] = ".txt";
    strcat(f_name, ext);
    return f = fopen(f_name, "a");
}

void closeFile(FILE*f) {
    fclose(f);
}

void removeFile(string15 f_name) {
    remove(f_name);
    printf("\nFILE DELTED\n");
}

void recordRegister(FILE *f, products p) {
    fwrite(&p, sizeof(products), 1, f);
}

products chargeRegister(products p) {
    
}