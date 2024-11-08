#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include "librerias/data_of_users.h"

void menu_principal();
void add_new_user();
void deposit_own_acc();
void check_card();
void transfer_money();
void recharge_airtime();
void change_nip();

int main(){
    int i;
    for (i = 0; i < nips[i]; i++) {
        printf("\nNip %d: %d", i, nips[i]);
    }

    getch();
    return 0;
}

