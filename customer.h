#include "file.h"

#define N_PRODUCTS 100

typedef products p_list[N_PRODUCTS];

typedef struct cust{
    int code;
    int dni;
    string_len2 name;
    string_len2 last_name;
}customers;

typedef struct date_info{
    int day;
    int month;
    int year;
}date;

typedef struct sale{
    date sale_date; 
    customers client;
    p_list product_sales;
}sales;

