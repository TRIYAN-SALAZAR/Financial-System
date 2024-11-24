#ifndef DATA_OF_USERS_H_INCLUDED
#define DATA_OF_USERS_H_INCLUDED

struct Users {
    char name[50];
    char lastname[50];
    char phone_number[11];
    char number_card[17];
    char nip[5];
    int saldo;
};

extern struct Users data_users[50];

#endif // DATA_OF_USERS_H_INCLUDED
