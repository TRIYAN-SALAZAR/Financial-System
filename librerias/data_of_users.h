#ifndef DATA_OF_USERS_H_INCLUDED
#define DATA_OF_USERS_H_INCLUDED

struct Users {
    char name[50];
    char lastname[50];
    long long int phone_number;
    long long int number_card;
    long long int nip;
};

extern struct Users data_users[];

#endif // DATA_OF_USERS_H_INCLUDED
