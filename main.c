

#define PASSWORD "siohfuih4iufhiugu48-u844udpds"


#include "dependencies/CWebStudio.h"
#include "dependencies/doTheWorld.h"
#include "url_functions.c"

#include "interface/render_main_interface.c"
#include "public_routes/main_route.c"
#include "public_routes/create_url.c"
#include "public_routes/ref_route.c"
#include "api_routes/get_informations.c"


struct CwebHttpResponse *main_sever(struct CwebHttpRequest *request ){
    request->read_content(request,2000);

    if(actual_request > 4){
        request->free(request);
        exit(0);
    }
    char *route = request->route;
    //when short is clicked
    if(strcmp(route,"/create_url") == 0) {
        return create_url(request);
    }
    //when shorten ref link is clicked
    if(strcmp(route,"/ref") == 0){
        return ref_route(request);
    }


    if(strcmp(route,"/api/get_informations") == 0){
        return get_informations(request);
    }


    //first page of web app
    return main_route();
}

int main(){

    for(int i=3000;i< 4000;i++){
        cweb_run_server(i,main_sever,CWEB_DEFAULT_TIMEOUT,CWEB_DANGEROUS_SINGLE_PROCESS);
    }

    return 0;
}
