#include "file.h"

#define N_PRODUCTS 100

typedef char string15[15];
typedef sales p_list[N_PRODUCTS];

typedef struct cust{
    int code;
    int dni;
    string15 name;
    string15 last_name;
}customers;

typedef struct date_info{
    int day;
    int month;
    int year;
}dates;

typedef struct sale{
    dates date; 
    customers client;
    products product_sale;
}sales;

typedef struct buy{
    p_list products_sale;
}buyout;

