#include <stdio.h>
#include <string.h>

typedef struct {
    char loginname[64];
    char password[64];
} account;

typedef struct {
    char stdID[20];
    char nameSurname[25];
    account stdACC;
} hoststd;

int checkLogin(char *login, char *passwd, hoststd cs[], int size);

int main() {

    hoststd cs[5] = {
        {"66-040626-2686-9","MR.A",{"user1","passwd1"}},
        {"66-040626-2686-8","MR.B",{"user2","passwd2"}},
        {"66-040626-2686-7","MR.C",{"user3","passwd3"}},
        {"66-040626-2686-6","MR.D",{"user4","passwd4"}},
        {"66-040626-2686-5","MR.E",{"user5","passwd5"}}
    };

    char login[64], password[64];

    printf("Enter login : ");
    scanf("%s", login);

    printf("Enter password : ");
    scanf("%s", password);

    if(checkLogin(login, password, cs, 5)) {
        printf("Welcome\n");
    } else {
        printf("Incorrect login or password\n");
    }

    return 0;
}

int checkLogin(char *login, char *passwd, hoststd cs[], int size) {
    int i;

    for(i = 0; i < size; i++) {
        if(strcmp(login, cs[i].stdACC.loginname) == 0 &&
           strcmp(passwd, cs[i].stdACC.password) == 0) {
            return 1;
        }
    }

    return 0;
}
