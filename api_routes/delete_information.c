





struct CwebHttpResponse * delete_information(struct CwebHttpRequest *request){

  
    char *token = request->get_header(request,"password");


    if(token == NULL){
        return cweb_send_text("No password provided",403);
    }
    if(strcmp(token,PASSWORD) != 0){
        return cweb_send_text("Permission Denied to retrive informations",403);
    }
    
    char *usages = request->get_header(request,"usage");

    if(usages == NULL){
        return cweb_send_text("usages is required",408);
    }

    if(strcmp(usages,"all") ==0){}
    else  if(strcmp(usages,"used") ==0){}
    else  if(strcmp(usages,"unused") ==0){}
    else {
        return cweb_send_text("usages must be betwen (all,used,unused)",408);
    }



    char *lower= request->get_header(request,"lower_data");

    if(lower == NULL){
        return cweb_send_text("lower_data is required",408);
    }

    long lower_in_unix = convertTimestampToUnix(lower);
    if (lower_in_unix == -1){
        return cweb_send_text("lower time its not an valid data \n, pass like: 2023-05-15 10:11:44 ",408);
    }



    char *higher = request->get_header(request,"higher_data");


    if(higher == NULL){
        return cweb_send_text("higher_data is required",408);
    }


    long higher_in_unix = convertTimestampToUnix(higher);
    if(higher_in_unix == -1){
        return cweb_send_text("higher time its not an valid data \n, pass like: 2023-05-15 10:11:44 ",408);
    }


    //crete an array of jsons 
 
    const char * formated_statistic_files = "data/statistc/";

    struct DtwStringArray  *list = dtw_list_files(formated_statistic_files,true);

    
    //implementing the filtrage
    for(int i = 0; i< list->size;i++){
        char *current = list->strings[i];
        char *content = dtw_load_string_file_content(current);
        cJSON *data = cJSON_Parse(content);

        cJSON *used = cJSON_GetObjectItem(data,"used");

        bool used_in_bool = used->valueint;

        if(strcmp(usages,"used") ==0 && used_in_bool == false){
            free(content);
            cJSON_Delete(data);
            continue;
        }
        if(strcmp(usages,"unused") ==0 && used_in_bool == true){
            free(content);
            cJSON_Delete(data);
            continue;
        }

        //all its for everything

        cJSON *creationg = cJSON_GetObjectItem(data,"created_at");
        long creation_in_int = creationg->valueint;
        if(creation_in_int  < lower_in_unix){
            free(content);
            cJSON_Delete(data);
            continue;
        }

        if(creation_in_int > higher_in_unix){
            free(content);
            cJSON_Delete(data);
            continue;
        }

   
        //delete the two files
        char token_file[30];
        sprintf(token_file,"data/token/%s",cJSON_GetObjectItem(data,"token")->valuestring);
        remove(token_file);
        remove(current);

        free(content);

        cJSON_Delete(data);
    }

    list->free_string_array(list);
   
   
    return cweb_send_text("all information were deleted",200);
}