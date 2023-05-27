#include "sever.c"



int main() {
     printf("Enter the password: \n");
     scanf("%s",password);
     struct CwebSever *sever = newCwebSever(3000,main_sever);
     sever->start(sever);
     sever->free(sever);
return 0;
}
