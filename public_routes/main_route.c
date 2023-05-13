//
// Created by jurandi on 13-05-2023.
//



struct CwebHttpResponse * main_route(){

    struct CTextStack *stack = render_main_interface(NULL,NULL);
    return cweb_send_rendered_CTextStack_cleaning_memory(
            stack,
            200
    );
}
