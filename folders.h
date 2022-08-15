#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <dirent.h>

#define DIR_FILE "."
#define DIR_CUSTOMERS "./files/customers/"
#define DIR_PRODUCTS "./files/products/"

void createFolders();
    void createDirFiles();
    void createDirCustomers();
    void createDirProducts();
void showFiles(DIR *);
void showCustomers(DIR *);
void showProducts(DIR *);

void createDirFiles() {
    DIR *d;
    struct dirent *dir;
    char dir_name[6] = "";

    d = opendir(".");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if(dir->d_name == "files") {
                strcpy(dir_name, dir->d_name);
                break;
            }
        }
        if(dir_name != "files") {
            mkdir("files");
        }
        closedir(d);
    }
}

void createDirCustomers() {
    DIR *d;
    struct dirent *dir;
    char dir_name[10] = "";

    d = opendir("./files");

    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if(dir->d_name == "customers") {
                strcpy(dir_name, dir->d_name);
                break;
            }
        }
        if(dir_name != "customers") {
            mkdir("./files/customers");
        }
        closedir(d);
    }
}

void createDirProducts() {
    DIR *d;
    struct dirent *dir;
    char dir_name[9] = "";

    d = opendir("./files");

    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if(dir->d_name == "products") {
                strcpy(dir_name, dir->d_name);
                break;
            }
        }
        if(dir_name != "products") {
            mkdir("./files/products");
        }
        closedir(d);
    }
}

void createFolders() {
    createDirFiles();
    createDirCustomers();
    createDirProducts();
}

void showFiles(DIR * d) {
    struct dirent *dir;
    d = opendir("./files");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }
}

void showCustomers(DIR * d) {
    struct dirent *dir;
    d = opendir("./files/customers");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }
}

void showProducts(DIR * d) {
    struct dirent *dir;
    d = opendir("./files/products");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }
}
