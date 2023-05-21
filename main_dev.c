
#include "sever.c"

int main() {

     printf("Enter the password: \n");
     scanf("%s",password);
 
     #define PASSWORD password
     for (int i=3000; i < 4000; i++){
     struct CwebSever *sever = newCwebSever(i,main_sever);
     sever->start(sever);
     sever->free(sever);
     }   

return 0;
}
