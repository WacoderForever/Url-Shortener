

#include "dependencies/CWebStudio.h"
#include "dependencies/doTheWorld.h"
#include "url_functions.c"

#include "interface/render_main_interface.c"
#include "public_routes/main_route.c"
#include "public_routes/create_url.c"

struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){

    request->read_content(request,2000);

    char *route = request->route;

    if(strcmp(route,"/create_url") == 0) {
        return create_url(request);
    }


    return main_route();
}

int main(){
    /*
    for(int i=3000;i< 4000;i++){
        cweb_run_server(i,main_sever,CWEB_DEFAULT_TIMEOUT,CWEB_SAFTY_MODE);
    }
     */
    char *route = create_randon_url_token("aaaaaaaaaaaaaaaa");
    free(route);

    return 0;
}
