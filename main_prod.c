
#include "sever.c"



int main() {

     //retrive the furst argument
    
    
     printf("Enter the password: \n");
     scanf("%s",password);
     struct CwebSever *sever = newCwebSever(80,main_sever);
     sever->start(sever);
     sever->free(sever);
return 0;
}
