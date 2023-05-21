#include "sever.c"



int main() {
     struct CwebSever *sever = newCwebSever(80,main_sever);
     sever->start(sever);
     sever->free(sever);
return 0;
}
