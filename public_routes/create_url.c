//
// Created by jurandi on 13-05-2023.
//



struct CwebHttpResponse * create_url(struct CwebHttpRequest *request){
    request->read_content(request,3000);

    char *url = request->get_param(request,"url");

    char *token = create_randon_url_token(url);

    char *host =request->get_header(request,"Host");



    char full_link[30];
    sprintf(full_link,"%s/ref?t=%s",host,token);


    char internal_link[30];
    sprintf(internal_link,"/ref?t=%s",token);

    struct CTextStack *stack = render_main_interface(full_link,internal_link);

    return cweb_send_rendered_CTextStack_cleaning_memory(
            stack,
            200
    );
}
