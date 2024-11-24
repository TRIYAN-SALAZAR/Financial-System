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

int cont_users = 3;

struct Users data_users[50];

int main()
{
    // This is an example that as working with structs in C

    strcpy(data_users[0].name, "Jorge");
    strcpy(data_users[0].lastname, "Ozuna");

    memcpy(data_users[0].number_card, "1234567812345678", 16);
    data_users[0].number_card[16] = '\0';
    strcpy(data_users[0].phone_number, "3333333333");
    strcpy(data_users[0].nip, "3333");

    data_users[0].saldo = 103300;

    strcpy(data_users[1].name, "Emma");
    strcpy(data_users[1].lastname, "Myers");

    memcpy(data_users[1].number_card, "4444888899991111", 16);
    data_users[1].number_card[16] = '\0';

    strcpy(data_users[1].phone_number, "9999999999");
    memcpy(data_users[1].nip, "1234", 16);
    data_users[1].nip[4] = '\0';

    data_users[1].saldo = 8999000;

    strcpy(data_users[2].name, "Rogelio");
    strcpy(data_users[2].lastname, "Zoro");
    memcpy(data_users[2].nip, "1234", 4);
    data_users[2].nip[4] = '\0';
    data_users[2].saldo = 1000;
    memcpy(data_users[2].number_card, "9999222211110000", 16);
    data_users[2].number_card[16] = '\0';
    strcpy(data_users[2].phone_number, "1111111111");

    // Write the code below
    int band = 1;
    do
    {
        // system("cls");
        int opt;

        menu_principal();
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            add_new_user();
            break;
        case 2:
            deposit_own_acc();
            break;
        case 3:
            check_card();
            getch();
            break;
        case 4:
            transfer_money();
            break;
        case 5:
            recharge_airtime();
            break;
        case 6:
            change_nip();
            break;
        case 7:
            band = 0;
            break;
        case 8:
            show_users();
            break;
        default:
            break;
        }
    } while (band == 1);
    // show_users();
    getch();
    return 0;
}

void menu_principal()
{
    printf("\n");
    printf("\nÂ¿Que movimiento deseas realizar?");
    printf("\n1 - Agregar nuevo usuario");
    printf("\n2 - Depositar en mi cuenta");
    printf("\n3 - Verificar saldo de tarjeta");
    printf("\n4 - Transferir dinero");
    printf("\n5 - Recargar tiempo aire");
    printf("\n6 - Cambiar nip");
    printf("\n7 - Salir");
    printf("\nIngrese su opcion: ");
}

void add_new_user()
{
    struct Users u1; // En el caso del usuario 1, si queremos poner más, podemos hacer cases con un switch.
    printf("Ingresa tu nombre: ");
    scanf("%49s", u1.name); // se pone %49 en vez de 50 para dejar el espacio del \0.

    printf("Ingresa tu apellido: ");
    scanf("%49s", u1.lastname);

    printf("Ingresa tu número de teléfono (10 dígitos): ");
    scanf("%10s", u1.phone_number);

    printf("Ingresa tu número de tarjeta (16 dígitos): ");
    scanf("%16s", u1.number_card);

    printf("Ingresa tu NIP (4 dígitos): ");
    scanf("%4s", u1.nip);

    u1.saldo = 0;
    data_users[cont_users] = u1; // Guardar los datos ingresados en el arreglo del struct
    cont_users++;
    printf("Tu registro fue exitoso, regresando al menu...");
    printf("%c", data_users[cont_users].nip);
}

void deposit_own_acc()
{
    char verification_pnum[10], verification_nip[4];

    int i, validar = 0, validador, index_user, cant_a_depositar;
    int transferencia, verification_transfer;
    printf("Ingresa tu numero de telefono: ");
    scanf("%10s", verification_pnum);
    getchar();
    for (i = 0; i < cont_users; i++)
    {
        if (strcmp(verification_pnum, data_users[i].phone_number) == 0)
        {
            printf("\nIngresa tu NIP: ");
            scanf("%4s", verification_nip);
            getchar();

            //printf("usuario encontrado %s | nip ingresado %s | nip del usuario %s", data_users[i].name, verification_nip, data_users[i].nip);
            int result = strcmp(verification_nip, data_users[i].nip);

            if (result == 0)
            {
                index_user = i;
                validar = 1;
                printf("\nValidando datos...");
                break;
            }
        }
    }

    if (validar == 0)
    {
        printf("\nLos datos ingresados son erroneos o no existe el usuario");
    }

    if (validar == 1)
    {
        printf("\n%s", data_users[index_user].name);
        printf(" %s", data_users[index_user].lastname);
        printf("\n%i", data_users[index_user].saldo);

        printf("\nIngrese la cantidad a depositar: ");
        scanf("%i", &cant_a_depositar);

        printf("Todo esta correcto? \n1.Si 2.No: ");
        scanf("%i", &validador);
        getchar();

        if (validador == 1)
        {
            data_users[index_user].saldo += cant_a_depositar;
            printf("Se deposito a la cuenta de %s %s", data_users[index_user].name, data_users[index_user].lastname);
            printf("\nSe depositaron %i pesos", cant_a_depositar);
            printf("\nTu saldo es de %i pesos", data_users[index_user].saldo);
            printf("\nSaldo actualizado :)");
        }


    } // fin del if si puso bien sus datos
}

void check_card()
{
    char nip[4], number_phone[10], confirmate_nip[4], confirmate_number_phone[10];
    int i;

    printf("Ingresa tu numero de telefono: ");
    scanf("%10s", &number_phone);
    getchar();
    printf("%10s", &number_phone);
    for (i = 0; i < cont_users; i++)
    {
        int res = strcmp(number_phone, data_users[i].phone_number);
        if (res == 0)
        {
            printf("\nIngresa tu NIP: ");
            scanf("%4s", &nip);
            if (strcmp(nip, data_users[i].nip) == 0)
            {
                printf("%s ", data_users[i].name);
                printf("%s", data_users[i].lastname);
                printf("\nTu saldo es: %i", data_users[i].saldo);
            }
        }
    }
}

void transfer_money()
{
    // encontrar si el usuario existe con su numero y nip

    char verification_pnum[10], verification_nip[4], verification_card[16];
    int i, validador = 0, transferencia, verification_transfer, cliente;
    printf("\nIngresa tu numero de telefono: ");
    scanf("%10s", &verification_pnum);
    for (i = 0; i < cont_users; i++)
    {
        if (strcmp(verification_pnum, data_users[i].phone_number) == 0)
        {
            printf("\nIngresa tu NIP: ");
            scanf("%4s", &verification_nip);
            if (strcmp(verification_nip, data_users[i].nip) == 0)
            {
                printf("%s ", data_users[i].name);
                printf("%s \n", data_users[i].lastname);
                printf("saldo: %i\n", data_users[i].saldo);
                cliente = i;   // para si se llega a concluir, saber a quien quitarle dinero
                validador = 1; // si sus datos estan bien, seguimos con la siguiente parte
            }
        }
    }
    if (validador == 0)
    {
        printf("Los datos ingresados son erroneos");
    }

    if (validador == 1)
    { // inicio del if si puso bien sus datos
        printf("Ingresa cuanto quieres transferir: ");
        scanf("%i", &transferencia);
        if (data_users[cliente].saldo > transferencia)
        {
            printf("Ingresa su numero de tarjeta: ");
            scanf("%s", &verification_card);
            for (i = 0; i < cont_users; i++)
            {
                if (strcmp(verification_card, data_users[i].number_card) == 0)
                {
                    printf("El numero de cuenta %s pertenece a %s %s", verification_card, data_users[i].name, data_users[i].lastname);
                    printf("\nEstas seguro de que quieres transferirle %i pesos? \n1.Si 2.No: ", transferencia);
                    scanf("%i", &verification_transfer);
                    if (verification_transfer == 1)
                    {
                        data_users[i].saldo += transferencia;
                        data_users[cliente].saldo -= transferencia;
                        printf("Transferencia exitosa :)");
                    }
                    if (verification_transfer == 0)
                    {
                        printf("Vuelve a ingresar tus datos, regresando al menu...");
                    }
                }
                else
                {
                    printf("No hay ninguna tarjeta con ese numero");
                }
            }
        }
        if (data_users[cliente].saldo < transferencia)
        {
            printf("No tienes los suficientes fondos, vuelve a intentarlo con un monto menor");
        }
    } // fin del if si puso bien sus datos
}

void change_nip()
{
    char verification_pnum[10], verification_nip[4];
    int i, validar = 0, phone_number, nip, validador, index_user;
    printf("Ingresa tu numero de telefono");
    scanf("%10s", verification_pnum);
    for (i = 0; i < cont_users; i++)
    {
        if (strcmp(verification_pnum, data_users[i].phone_number) == 0)
        {
            printf("\nIngresa tu NIP: ");
            scanf("%4s", verification_nip);
            if (strcmp(verification_nip, data_users[i].nip) == 0)
            {
                index_user = i;
                printf("Ingresa tu NIP");
                scanf("%4s", nip);
            }
        }
    }
    if (validador == 0)
    {

        printf("Los datos ingresados son erroneos");
    }
    else
    {
        printf("%s", data_users[index_user].name);
        printf("%s", data_users[index_user].lastname);
        printf("%s", data_users[index_user].nip);
    }

    char new_nip_confirm[4], new_nip[4];
    printf("\nIngrese su nuevo NIP");
    scanf("%4s", new_nip);

    printf("Ingrese de nuevo su nuevo NIP");
    scanf("%4s", new_nip_confirm);
    if (strcmp(new_nip_confirm, new_nip) == 0)
    {
        printf("El NIP ha sido cambiado exitosamente");
    }
    else
    {
        printf("Los datos no coinciden");
    }
}

void recharge_airtime()
{
    char verification_pnum[10], verification_nip[4], verification_card[16], pnum_to_transfer[10];
    int i, new_try, validador = 0, cliente, compania, cantidad_transferencia;
    printf("\nIngresa tu numero de telefono: ");
    scanf("%10s", &verification_pnum);
    for (i = 0; i < cont_users; i++)
    {
        if (strcmp(verification_pnum, data_users[i].phone_number) == 0)
        {
            printf("\nIngresa tu NIP: ");
            scanf("%4s", &verification_nip);
            if (strcmp(verification_nip, data_users[i].nip) == 0)
            {
                printf("%s ", data_users[i].name);
                printf("%s \n", data_users[i].lastname);
                printf("saldo: %i\n", data_users[i].saldo);
                cliente = i;   // para si se llega a concluir, saber a quien quitarle dinero
                validador = 1; // si sus datos estan bien, seguimos con la siguiente parte
                printf("A quÃ© compaÃ±Ã­a quiere hacer la recarga de tiempo aire?\n 1. AT%cT 2. Telcel 3. Movistar: ", 38);
                scanf("%i", &compania);
                printf("Ingresa la cantidad que quieres recargar: ");
                scanf("%i", &cantidad_transferencia);
                printf("A que numero quieres transferirlo?: ");
                scanf("%s", &pnum_to_transfer[0]);

                if (data_users[cliente].saldo < cantidad_transferencia)
                {
                    printf("No tienes los fondos suficientes para hacer la transferencia, vuelve a registrar tus datos...");
                }

                if (data_users[cliente].saldo > cantidad_transferencia)
                {
                    printf("Todo esta bien?, quieres concluir la transferencia?\n 1.Si 2.No: ");
                    scanf("%i", &validador);

                    if (validador == 1)
                    {
                        printf("Recarga exitosa\n La recarga se hizo al numero: %s\n El monto de la recarga es: %i\n ", pnum_to_transfer, cantidad_transferencia);
                    }
                    if (validador == 2)
                    {
                        system("cls");
                        printf("Vuelve a ingresar tus datos");
                    }
                }
            }
        }
    }

    // cuando sus datos ingresados al inicio son erroneos
    if (validador == 0)
    {
        printf("Los datos ingresados son erroneos... \n Â¿Quieres intentarlo de nuevo? 1.Si 2.No: ");
        scanf("%i", &new_try);
        if (new_try == 1)
        {
            // recharge_airtime();
        }
        else
        {
            printf("Regresando al menu...");
        }
    }
}

void show_users()
{
    int i, j;
    printf("MOSTRAR USUARIOS");
    for (i = 0; i < cont_users; i++)
    {
        printf("\n--------------------------");
        printf("\nNombre: %s", data_users[i].name);
        printf("\nApellido: %s", data_users[i].lastname);
        printf("\nNumber phone: %s", data_users[i].phone_number);
        printf("\nSaldo: %i", data_users[i].saldo);
        printf("\nNumber card: ");
        for (j = 0; j < 16; j++)
        {
            printf("%c", data_users[i].number_card[j]);
        }

        printf("\nNIP: ");
        for (j = 0; j < 4; j++)
        {
            printf("%d", data_users[i].nip[j]);
        }

    }
}
