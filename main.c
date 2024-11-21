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
void show_users();

int cont_users=3;

struct Users data_users[50];

int main(){
    // This is an example that as working with structs in C

    strcpy(data_users[0].name, "Jorge");
    strcpy(data_users[0].lastname, "Ozuna");
    data_users[0].nip[0] = 3;
    data_users[0].nip[1] = 4;
    data_users[0].nip[2] = 4;
    data_users[0].nip[3] = 5;

    strcpy(data_users[0].number_card, "12341234234");
    strcpy(data_users[0].phone_number, "3316787878");

    strcpy(data_users[1].name, "Emma");
    strcpy(data_users[1].lastname, "Myers");
    data_users[1].nip[0] = "7777";

    strcpy(data_users[1].number_card, "8128987623983201");
    strcpy(data_users[1].phone_number, "0932938765");

    strcpy(data_users[2].name, "Rogelio");
    strcpy(data_users[2].lastname, "Zoro");
    data_users[2].nip[0] = 7;
    data_users[2].nip[1] = 5;
    data_users[2].nip[2] = 3;
    data_users[2].nip[3] = 8;

    strcpy(data_users[2].number_card, "8128987623983201");
    strcpy(data_users[2].phone_number, "0932938765");

    // Write the code below
    int band = 1;
    do {
        //system("cls");
        fflush(stdin);
        int opt;

        menu_principal();
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                add_new_user();
                break;
            case 2:
                transfer_money();
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
                band = 0;
                break;
            default:
                break;
        }
    } while(band == 1);
    show_users();
    getch();
    return 0;
}

void menu_principal() {
    printf("\n");
    printf("\n¿Que movimiento deseas realizar?");
    printf("\n1 - Agregar nuevo usuario");
    printf("\n2 - Depositar en mi cuenta");
    printf("\n3 - Verificar saldo de tarjeta");
    printf("\n4 - Transferir dinero");
    printf("\n5 - Recargar tiempo aire");
    printf("\n6 - Cambiar nip");
    printf("\n7 - Salir");
    printf("\nIngrese su opcion: ");
}

void add_new_user() {
    struct Users u1;
    printf("Ingresa tu nombre: ");
    scanf("%49s", u1.name); //se pone %49 en vez de 50 para dejar el espacio del \0.

    printf("Ingresa tu apellido: ");
    scanf("%49s", u1.lastname);

    printf("Ingresa tu número de teléfono (10 dígitos): ");
    scanf("%10s", u1.phone_number);

    printf("Ingresa tu número de tarjeta (16 dígitos): ");
    scanf("%16s", u1.number_card);

    printf("Ingresa tu NIP de 4 dígitos: \n");
    for (int i = 0; i < 4; i++) {  //este es un ciclo que lee número por número de su NIP
        printf("Ingresa el dígito %i: ", i+1);
        scanf("%d", &u1.nip[i]);
    }
    u1.saldo=0;
    data_users[cont_users] = u1; //Guardar los datos ingresados en el arreglo del struct
    cont_users++;//aumento para saber cuántos usuarios hay realmente
    printf("Tu registro fue exitoso, regresando al menu...");
}

void deposit_own_acc() {}

void check_card() {}

void transfer_money() {
       //encontrar si el usuario existe con su numero y nip
    char verification_pnum[10], verification_nip[4], verification_card[16];
    int i, validador=0, transferencia, verification_transfer, cliente;
    printf("\nIngresa tu numero de telefono: ");
    scanf("%10s", verification_pnum);
    for(i=0;i<cont_users;i++){
        if (strcmp(verification_pnum, data_users[i].phone_number) == 0) {
            printf("\nIngresa tu NIP: ");
            scanf("%4s", verification_nip);
            if (strcmp(verification_nip, data_users[i].nip) == 0){
                printf("%s ", data_users[i].name);
                printf("%s \n", data_users[i].lastname);
                printf("saldo: %i\n", data_users[i].saldo);
                cliente = i; //para si se llega a concluir, saber a quien quitarle dinero
                validador = 1; //si sus datos estan bien, seguimos con la siguiente parte
            }

        }
    }
    if(validador == 0){
        printf("Los datos ingresados son erroneos");
    }

    if(validador == 1){//inicio del if si puso bien sus datos
        printf("Ingresa cuanto quieres transferir: ");
        scanf("%i", &transferencia);
        if( data_users[cliente].saldo > transferencia){
            printf("Ingresa su numero de tarjeta: ");
            scanf("%s", verification_card);
            for(i=0;i<cont_users;i++){
                if (strcmp(verification_card, data_users[i].number_card) == 0) {
                    printf("El numero de cuenta %s pertenece a %s %s",verification_card, data_users[i].name, data_users[i].lastname);
                    printf("\nEstas seguro de que quieres transferirle %i pesos? \n1.Si 2.No: ", transferencia);
                    scanf("%i", &verification_transfer);
                    if(verification_transfer == 1){
                        data_users[i].saldo += transferencia;
                        data_users[cliente].saldo -= transferencia;
                        printf("Transferencia exitosa :)");
                    }
                    if(verification_transfer == 0){
                        printf("Vuelve a ingresar tus datos, regresando al menu...");
                    }
                }
                else{
                    printf("No hay ninguna tarjeta con ese numero");
                }
            }
        }
        if( data_users[cliente].saldo < transferencia){
            printf("No tienes los suficientes fondos, vuelve a intentarlo con un monto menor");
        }
    }//fin del if si puso bien sus datos
}

void recharge_airtime() {}

void change_nip() {}

void show_users() {
    int i, j;
    printf("MOSTRAR USUARIOS");
    for(i = 0; i < cont_users; i++) {
        printf("\n--------------------------");
        printf("\nNombre: %s", data_users[i].name);
        printf("\nApellido: %s", data_users[i].lastname);
        printf("\nNumber phone: %s", data_users[i].phone_number);
        printf("\nNumber card: ");
        for(j = 0; j < 16; j++) {
            printf("%c", data_users[i].number_card[j]);
        }
        printf("\nNIP: ");
        for(j = 0; j < 4; j++) {
            printf("%d", data_users[i].nip[j]);
        }
    }
}
