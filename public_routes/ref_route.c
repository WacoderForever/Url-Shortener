//
// Created by jurandi on 13-05-2023.
//



struct CwebHttpResponse * ref_route(struct CwebHttpRequest *request){


    char *token = request->get_param(request,"t");
    char *url_redirect = return_content_of_token(token);



    if(url_redirect == NULL){
        return cweb_send_text("page not found",404);
    }

    char formated_json_path[30];
    sprintf(formated_json_path,"data/statistc/%s.json",token);

 
    char *json_content = dtw_load_string_file_content(formated_json_path);
    //loadss json file

    cJSON *json = cJSON_Parse(json_content);
    //increases the number of visits
    cJSON *visits = cJSON_GetObjectItem(json,"clicks");
    
    int visits_int = visits->valueint;
    visits_int++;

    cJSON_DeleteItemFromObject(json,"clicks");
    cJSON_AddNumberToObject(json,"clicks",visits_int);
    

    char *generated_json = cJSON_Print(json);
    

    dtw_write_string_file_content(formated_json_path,generated_json);


    free(generated_json);
    free(json_content);
    cJSON_Delete(json);


    struct CwebHttpResponse *response = create_http_response();
    response->add_header(response, "Location", url_redirect);
    response->status_code = 302;
    free(url_redirect);


    return response;

}
