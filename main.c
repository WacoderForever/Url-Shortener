

#include "dependencies/CWebStudio.h"
#include "dependencies/doTheWorld.h"

#include "interface/render_main_interface.c"
#include "public_routes/main_route.c"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    request->read_content(request,2000);

    char *route = request->route;

    return main_route();
}

int main(){
    for(int i=3000;i< 4000;i++){
        cweb_run_server(i,main_sever,CWEB_DEFAULT_TIMEOUT,CWEB_SAFTY_MODE);
    }
    return 0;
}
