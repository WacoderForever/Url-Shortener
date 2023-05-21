
#include "sever.c"



int main() {

     //retrive the furst argument
     char password[100];
     printf("Enter the password: \n");
     scanf("%s",password);
     #define PASSWORD password
     struct CwebSever *sever = newCwebSever(80,main_sever);
     sever->start(sever);
     sever->free(sever);
return 0;
}
