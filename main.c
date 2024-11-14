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
void close_sesion();
int is_sesion_active();

struct Users data_users[];

int main(){
    // This is an example that as working with structs in C

    strcpy(data_users[0].name, "Jorge");
    strcpy(data_users[0].lastname, "Ozuna");
    data_users[0].nip[0] = 3;
    data_users[0].nip[1] = 4;
    data_users[0].nip[2] = 4;
    data_users[0].nip[3] = 5;
    
    strcpy(data_users[0].number_card, "34342309324");
    strcpy(data_users[0].phone_number, "3315660281");

    strcpy(data_users[1].name, "Emma");
    strcpy(data_users[1].lastname, "Myers");
    data_users[1].nip[0] = 7;
    data_users[1].nip[1] = 5;
    data_users[1].nip[2] = 3;
    data_users[1].nip[3] = 8;

    strcpy(data_users[1].number_card, "9999999999");
    strcpy(data_users[1].phone_number, "903298493984");

    int i;
    for(i = 0; i < 2; i++) {
        printf("\n--------------------------");
        printf("\nNombre: %s", data_users[i].name);
        printf("\nApellido: %s", data_users[i].lastname);
        printf("\nNip: %d", data_users[i].nip);
        printf("\nNumber card: %lld", data_users[i].number_card);
        printf("\nNumber phone: %lld", data_users[i].phone_number);
    }

    // Write the code below
    do {
        char opt;
        menu_principal();

        switch (opt) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                close_sesion();
                break;
            default:
                
        }
    } while(1 == 1);
    getch();
    return 0;
}

void menu_principal() {
    printf("\n¿Que movimiento deseas realizar?");
    printf("\n1 - Agregar nuevo usuario");
    printf("\n2 - Depositar en mi cuenta");
    printf("\n3 - Verificar saldo de tarjeta");
    printf("\n4 - Transferir dinero");
    printf("\n5 - Recargar tiempo aire");
    printf("\n6 - Cambiar nip");

    if(is_sesion_active()) {
        printf("7 - Salir");
    }
}

void add_new_user() {
    printf("Un ejemplo para un commit");
}

void deposit_own_acc() {}

void check_card() {}

void transfer_money() {}

void recharge_airtime() {}

void change_nip() {}

void close_sesion() {}

int is_sesion_active() {
    if(sesion.is_active == 1) {
        return 1;
    }

    return 0;
}