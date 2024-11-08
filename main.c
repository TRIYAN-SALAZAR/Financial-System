#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "librerias/data_of_users.h"

void menu_principal();
void add_new_user();
void deposit_own_acc();
void check_card();
void transfer_money();
void recharge_airtime();
void change_nip();

struct Users data_users[];

int main(){
    strcpy(data_users[0].name, "Jorge");
    strcpy(data_users[0].lastname, "Ozuna");
    data_users[0].nip = 3434;
    data_users[0].number_card = 34342309324;
    data_users[0].phone_number = 3315660281;

    strcpy(data_users[1].name, "Emma");
    strcpy(data_users[1].lastname, "Myers");
    data_users[1].nip = 7777;
    data_users[1].number_card = 99999999999;
    data_users[1].phone_number = 903298493984;

    int i;
    for(i = 0; i < 2; i++) {
        printf("\n--------------------------");
        printf("\nNombre: %s", data_users[i].name);
        printf("\nApellido: %s", data_users[i].lastname);
        printf("\nNip: %d", data_users[i].nip);
        printf("\nNumber card: %lld", data_users[i].number_card);
        printf("\nNumber phone: %lld", data_users[i].phone_number);
    }

    getch();
    return 0;
}

