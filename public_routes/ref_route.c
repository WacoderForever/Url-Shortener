//
// Created by jurandi on 13-05-2023.
//



struct CwebHttpResponse * ref_route(struct CwebHttpRequest *request){


    char *token = request->get_param(request,"t");
    char *url_redirect = return_content_of_token(token);

    if(url_redirect == NULL){
        return cweb_send_text("page not found",404);
    }

    struct CwebHttpResponse *response = create_http_response();
    response->add_header(response, "Location", url_redirect);
    response->status_code = 301;
    free(url_redirect);


    return response;

}
