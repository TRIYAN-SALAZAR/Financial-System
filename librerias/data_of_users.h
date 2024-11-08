#ifndef DATA_OF_USERS_H_INCLUDED
#define DATA_OF_USERS_H_INCLUDED

struct Users {
    char name[50];
    char lastname[50];
    char phone_number[10];
    char number_card[16];
    int nip;
};
struct Sesion {
    int is_active = 0;
    char phone_number[10];
};
extern struct Sesion sesion;
extern struct Users data_users[];

#endif // DATA_OF_USERS_H_INCLUDED
