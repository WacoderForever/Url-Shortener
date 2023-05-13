//
// Created by jurandi on 13-05-2023.
//



struct CwebHttpResponse * create_url(struct CwebHttpRequest *request){


    char *url = request->get_param(request,"url");






    struct CTextStack *stack = render_main_interface();
    return cweb_send_rendered_CTextStack_cleaning_memory(
            stack,
            200
    );
}
