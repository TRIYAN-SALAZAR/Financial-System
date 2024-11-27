#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "librerias/data_of_users.h"

void menu_principal();
void menu_chiquito();
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
    strcpy(data_users[0].phone_number, "3333333333");
    strcpy(data_users[0].number_card, "2222333344445555");
    strcpy(data_users[0].nip, "3333");
    data_users[0].saldo = 103300;

    strcpy(data_users[1].name, "Emma");
    strcpy(data_users[1].lastname, "Myers");
    strcpy(data_users[1].phone_number, "9999999999");
    strcpy(data_users[1].number_card, "4444888899991111");
    strcpy(data_users[1].nip, "1234");
    data_users[1].saldo = 8999000;

    strcpy(data_users[2].name, "Rogelio");
    strcpy(data_users[2].lastname, "Zoro");
    strcpy(data_users[2].phone_number, "1111111111");
    strcpy(data_users[2].number_card, "9999222211110000");
    strcpy(data_users[2].nip, "1234");
    data_users[2].saldo = 1000;

    // Write the code below
    int band = 1;
    do
    {
        int opt;

        menu_principal();
        scanf("%d", &opt);

        getchar();
        system("cls");

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
            printf("\nPorfavor ingrese una opcion valida");
            break;
        }
    } while (band == 1);
    // show_users();
    getch();
    return 0;
}

void menu_principal()
{
    printf("\n------------------------------------");
    printf("\n%cQue movimiento deseas realizar?", 168);
    printf("\n1 - Agregar nuevo usuario");
    printf("\n2 - Depositar en mi cuenta");
    printf("\n3 - Verificar saldo de tarjeta");
    printf("\n4 - Transferir dinero");
    printf("\n5 - Recargar tiempo aire");
    printf("\n6 - Cambiar nip");
    printf("\n7 - Salir");
    printf("\nIngrese su opcion: ");
}

void menu_chiquito()
{
    printf("\n1 - Si");
    printf("\n2 - No");
    printf("\nIngrese su opcion: ");
}
void add_new_user()
{
    struct Users u1; // En el caso del usuario 1, si queremos poner más, podemos hacer cases con un switch.
    printf("\n------------------------------------");
    printf("\nIngresa tu nombre: ");
    scanf("%49s", u1.name); // se pone %49 en vez de 50 para dejar el espacio del \0.

    printf("\nIngresa tu apellido: ");
    scanf("%49s", u1.lastname);

    printf("\nIngresa tu número de teléfono (10 dígitos): ");
    scanf("%10s", u1.phone_number);

    printf("\nIngresa tu número de tarjeta (16 dígitos): ");
    scanf("%16s", u1.number_card);

    printf("\nIngresa tu NIP (4 dígitos): ");
    scanf("%4s", u1.nip);
    printf("\n------------------------------------");

    u1.saldo = 0;
    data_users[cont_users] = u1; // Guardar los datos ingresados en el arreglo del struct
    cont_users++;
    printf("\n\nTu registro fue exitoso, regresando al menu...\n");

}

void deposit_own_acc()
{
    do
    {
        char verification_pnum[10], verification_nip[4];

        int i, validador, index_user, cant_a_depositar;
        int transferencia, verification_transfer;
        int validar = 0, new_try = 0;

    printf("\n------------------------------------");
        printf("\nIngresa tu numero de telefono: ");
        scanf("%10s", verification_pnum);
        getchar();
        for (i = 0; i < cont_users; i++)
        {
            // printf("\n------------------------------------------------------");
            // printf("\nusuario encontrado %s | nip del usuario %s\n", data_users[i].name, data_users[i].nip);
            // printf("\n------------------------------------------------------");

            if (strcmp(verification_pnum, data_users[i].phone_number) == 0)
            {
                printf("\n------------------------------------");
                printf("\nIngresa tu NIP: ");
                scanf("%4s", verification_nip);
                getchar();

                // printf("usuario encontrado %s | nip ingresado %s | nip del usuario %s", data_users[i].name, verification_nip, data_users[i].nip);
                int result = strcmp(verification_nip, data_users[i].nip);

                if (result == 0)
                {
                    index_user = i;
                    validar = 1;
                    // printf("\n\nValidando datos...");
                    break;
                }
                else
                {
                    break;
                }
            }
        }

        if (validar == 0)
        {
            printf("\n------------------------------------");
            printf("\nLos datos ingresados son erroneos o no existe el usuario");
            printf("\nDesea volver a intentarlo?");

            printf("\n------------------------------------");
            menu_chiquito();

            scanf("%i", &new_try);
            getchar();

            if (new_try == 1)
            {
                system("cls");
                continue;
            }
            else
            {
                printf("\nRegresando al menu principal...");
                break;
            }
        }

        if (validar == 1)
        {
            do
            {

                printf("\n------------------------------------");
                printf("\n%s", data_users[index_user].name);
                printf(" %s", data_users[index_user].lastname);
                printf("\nSaldo actual: %i", data_users[index_user].saldo);
                printf("\n------------------------------------\n");

                printf("\nIngrese la cantidad a depositar: ");
                scanf("%i", &cant_a_depositar);

                printf("\nTodo esta correcto? \n1.Si 2.No 3.Salir: ");
                scanf("%i", &validador);
                getchar();
                if (validador == 2)
                {
                    system("cls");
                    continue;
                }

                if (validador == 1)
                {
                    break;
                }

                if (validador == 3)
                {
                    break;
                }

            } while (1);

            if (validador == 1)
            {
                data_users[index_user].saldo += cant_a_depositar;
                printf("\n------------------------------------");
                printf("\nEl deposito de hizo con exito!");
                printf("\nSe deposito a la cuenta de %s %s", data_users[index_user].name, data_users[index_user].lastname);
                printf("\nSe depositaron %i pesos", cant_a_depositar);
                printf("\nTu saldo es de %i pesos", data_users[index_user].saldo);
                printf("\nRegresando al menu principal...");
                getch();
                system("cls");
                break;
            }

            if (validador == 3)
            {
                printf("\nRegresando al menu principal...");
                break;
            }
        } // fin del if si puso bien sus datos
    } while (1);
}

void check_card()
{
    do
    {
        char nip[4], number_phone[10], confirmate_nip[4], confirmate_number_phone[10];
        int i, correct_number_phone = 0, leave = 0;

        printf("\nIngresa tu numero de telefono: ");
        scanf("%10s", &number_phone);
        getchar();

        // printf("%10s", &number_phone);
        for (i = 0; i < cont_users; i++)
        {
            int res = strcmp(number_phone, data_users[i].phone_number);
            if (res == 0)
            {
                correct_number_phone = 1;

                printf("\nIngresa tu NIP: ");
                scanf("%4s", &nip);

                if (strcmp(nip, data_users[i].nip) == 0)
                {

                    printf("%s ", data_users[i].name);
                    printf("%s", data_users[i].lastname);
                    printf("\nTu saldo es: %i", data_users[i].saldo);

                    leave = 1;
                    break;
                }
                else
                {
                    printf("\nEl nip ingresado es incorrecto");
                    printf("\nVuelve a introducir los datos");
                    break;
                }
            }
        }

        if (correct_number_phone == 0)
        {
            printf("\nEl numero de telefono ingresado no existe");
            printf("\nIntroduzca los datos nuevamente");
        }

        if (leave == 1)
        {
            break;
        }
    } while (1);
}

void transfer_money()
{
    // encontrar si el usuario existe con su numero y nip
    do
    {
        char verification_pnum[10], verification_nip[4], verification_card[16];
        int i, transferencia, verification_transfer, cliente, new_try;
        int validador = 0, is_num_card_found = 0;

        printf("\nIngresa tu numero de telefono: ");
        scanf("%10s", &verification_pnum);
        getchar();

        for (i = 0; i < cont_users; i++)
        {
            if (strcmp(verification_pnum, data_users[i].phone_number) == 0)
            {
                printf("\nIngresa tu NIP: ");
                scanf("%4s", &verification_nip);
                getchar();

                if (strcmp(verification_nip, data_users[i].nip) == 0)
                {
                    printf("%s ", data_users[i].name);
                    printf("%s \n", data_users[i].lastname);
                    printf("saldo: %i\n", data_users[i].saldo);
                    cliente = i;   // para si se llega a concluir, saber a quien quitarle dinero
                    validador = 1; // si sus datos estan bien, seguimos con la siguiente parte
                }
                else
                {
                    printf("\nLa clave ingresada es incorrecta");
                }
            }
        }

        if (validador == 0)
        {
            printf("\nLos datos ingresados son erroneos o no existe el usuario");
            printf("\nDesea volver a intentarlo?");

            menu_chiquito();

            scanf("%i", &new_try);
            getchar();

            if (new_try == 1)
            {
                system("cls");
                continue;
            }
            else
            {
                printf("\nRegresando al menu principal...");
                break;
            }
        }

        if (validador == 1)
        { // inicio del if si puso bien sus datos
            do
            {
                printf("Ingresa cuanto quieres transferir: ");
                scanf("%i", &transferencia);
                getchar();

                if (data_users[cliente].saldo >= transferencia)
                {
                    printf("Ingresa el numero de tarjeta a la que deseas transferir: ");
                    scanf("%s", &verification_card);
                    getchar();

                    for (i = 0; i < cont_users; i++)
                    {
                        if (strcmp(verification_card, data_users[i].number_card) == 0)
                        {
                            printf("\nEl numero de cuenta %s pertenece a %s %s", verification_card, data_users[i].name, data_users[i].lastname);
                            printf("\nEstas seguro de que quieres transferirle %i pesos? \n1.Si 2.No: ", transferencia);
                            scanf("%i", &verification_transfer);
                            getchar();

                            if (verification_transfer == 1)
                            {
                                is_num_card_found = 1;

                                data_users[i].saldo += transferencia;
                                data_users[cliente].saldo -= transferencia;

                                printf("\nSe transfirio %i pesos a %s %s", transferencia, data_users[i].name, data_users[i].lastname);
                                printf("\nCon numero de cuenta %s", verification_card);
                                printf("\nTransferencia exitosa :)");

                                break;
                            }
                            if (verification_transfer == 0)
                            {
                                printf("Vuelve a ingresar los datos de la transferencia");
                                break;
                            }
                        }
                    }

                    if (is_num_card_found == 0)
                    {
                        printf("\nEl numero de tarjeta ingresado no pertenece a ningun usuario");
                        printf("\nVuelve a intentarlo con un numero de tarjeta diferente");
                    }
                }
                else
                {
                    printf("\nNo tienes los suficientes fondos, vuelve a intentarlo con un monto menor\n");
                }

                if (verification_transfer == 1)
                {
                    break;
                }
            } while (1);
        } // fin del if si puso bien sus datos

        if (verification_transfer == 1)
        {
            break;
        }
    } while (1);
}

void change_nip()
{
    do
    {
        char verification_pnum[10], verification_nip[4];
        int i, phone_number, nip, validador, index_user, res;
        int confirm_change_nip = 0, validar = 0;

        printf("\nIngresa tu numero de telefono: ");
        scanf("%10s", verification_pnum);
        getchar();

        for (i = 0; i < cont_users; i++)
        {
            if (strcmp(verification_pnum, data_users[i].phone_number) == 0)
            {
                printf("\nIngresa tu NIP: ");
                scanf("%4s", verification_nip);
                getchar();

                res = strcmp(verification_nip, data_users[i].nip);

                if (res == 0)
                {
                    index_user = i;
                    validador = 1;
                }
            }
        }

        if (validador == 0)
        {
            printf("\nLos datos ingresados son erroneos");
            printf("\nPorfavor, vuelva a ingresar los datos");
        }

        if (validador == 1)
        {
            do
            {
                printf("\nSus datos actuales son\n");
                printf("-----------------------------------------\n");
                printf("%s", data_users[index_user].name);
                printf(" %s", data_users[index_user].lastname);
                printf("\n%s", data_users[index_user].nip);
                printf("\n-----------------------------------------");

                char new_nip_confirm[5], new_nip[5];
                printf("\nIngrese su nuevo NIP: ");
                scanf("%4s", new_nip);
                getchar();

                printf("\nIngrese de nuevo su nuevo NIP: ");
                scanf("%4s", new_nip_confirm);
                getchar();

                printf("\nLos datos ingresados son coorrectos? \n1 - Si\n 2 - No\nIngrese su opcion: ");
                scanf("%i", &confirm_change_nip);
                getchar();

                if (confirm_change_nip == 1)
                {
                    res = strcmp(new_nip, new_nip_confirm);
                    if (res == 0)
                    {
                        strcpy(data_users[index_user].nip, new_nip);
                        printf("\nEl NIP ha sido cambiado exitosamente");
                        break;
                    }
                    else
                    {
                        printf("\nLos NIP ingresados no son iguales");
                        printf("\nVuelve a intentarlo\n");
                        break;
                    }
                }
                if (confirm_change_nip == 2)
                {
                    printf("\nIngrese los datos nuevamente\n");
                    continue;
                    ;
                }
            } while (1);
        }

        if (confirm_change_nip == 1 || confirm_change_nip == 2)
        {
            break;
        }
    } while (1);
}

void recharge_airtime()
{
    do
    {
        char verification_pnum[10], verification_nip[4], verification_card[16], pnum_to_transfer[10];
        int i, new_try, cliente, compania, cantidad_transferencia;
        int correct_number_phone = 0, leave = 0, validador = 0;

        printf("\nIngresa tu numero de telefono: ");
        scanf("%10s", &verification_pnum);
        getchar();

        for (i = 0; i < cont_users; i++)
        {
            if (strcmp(verification_pnum, data_users[i].phone_number) == 0)
            {
                printf("\nIngresa tu NIP: ");
                scanf("%s", &verification_nip);
                getchar();

                if (strcmp(verification_nip, data_users[i].nip) == 0)
                {
                    cliente = i;   // para si se llega a concluir, saber a quien quitarle dinero
                    validador = 1; // si sus datos estan bien, seguimos con la siguiente parte
                    correct_number_phone = 1;
                    break;
                }
                else
                {
                    printf("\nEl NIP ingresado es incorrecto, vuelve a ingresarlos ota vez");
                    correct_number_phone = 1;
                    break;
                }
            }
        }
        // cuando sus datos ingresados al inicio son erroneos
        if (correct_number_phone == 0)
        {
            printf("\nEse numero de telefono no existe, vuelve a intentarlo\n");
        }

        if (validador == 1)
        {
            do
            {
                printf("%s ", data_users[i].name);
                printf("%s \n", data_users[i].lastname);
                printf("saldo: %i\n", data_users[i].saldo);

                printf("A que compania quiere hacer la recarga de tiempo aire?\n 1. AT%cT 2. Telcel 3. Movistar: ", 38);
                scanf("%i", &compania);
                getchar();

                printf("Ingresa la cantidad que quieres recargar: ");
                scanf("%i", &cantidad_transferencia);
                getchar();

                printf("A que numero quieres transferirlo?: ");
                scanf("%s", &pnum_to_transfer[0]);
                getchar();

                if (data_users[cliente].saldo < cantidad_transferencia)
                {
                    printf("\nNo tienes los fondos suficientes para hacer la recarga de saldo");
                    printf("\nVuelve a intentarlo\n");
                }

                if (data_users[cliente].saldo >= cantidad_transferencia)
                {
                    printf("\nEstas seguro de realizar la recarga?\n 1.Si 2.No: ");
                    scanf("%i", &validador);

                    if (validador == 1)
                    {
                        data_users[cliente].saldo = data_users[cliente].saldo - cantidad_transferencia;
                        printf("Recarga exitosa\n La recarga se hizo al numero: %s\n El monto de la recarga es: %i\n ", pnum_to_transfer, cantidad_transferencia);

                        leave = 1;
                        break;
                    }
                    if (validador == 2)
                    {
                        system("cls");
                        printf("Vuelve a ingresar tus datos");
                        break;
                    }
                }

            } while (1);
        }

        if (leave == 1)
        {
            break;
        }

    } while (1);
}

void show_users()
{
    int i;
    printf("+-----------------+-----------------+--------------+------------------+------+------------+\n");
    printf("| %-15s | %-15s | %-12s | %-16s | %-4s | %-10s |\n", 
            "First Name", "Last Name", "Phone", "Card Number", "NIP", "Saldo");

    for (i = 0; i < cont_users; i++) {
    printf("+-----------------+-----------------+--------------+------------------+------+------------+\n");
        printf("| %-15s | %-15s | %-12s | %-16s | %-4s | %10d |\n",
            data_users[i].name,
            data_users[i].lastname,
            data_users[i].phone_number,
            data_users[i].number_card,
            data_users[i].nip,
            data_users[i].saldo);
    }
    printf("+-----------------+-----------------+--------------+------------------+------+------------+\n");

}
