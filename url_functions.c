//
// Created by jurandi on 13-05-2023.
//

char *gemerate_random_token(int size) {
    static const char chars[] =
            "abcdefghijklmnopqrstuvwxyz"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "0123456789";

    int total_size = sizeof(chars) - 1;
    char *token = malloc(sizeof(char) * (size + 1));

    srand(time(NULL));



    for (int i = 0; i < size; ++i) {
        int index = rand() % total_size;
        token[i] = chars[index];
    }

    token[size] = '\0';
    return token;
}

char * return_content_of_token(char *token){
    char formated_path[30];
    sprintf(formated_path,"data/tokens/%s",token);
    return dtw_load_string_file_content(formated_path);
}


char *create_randon_url_token(char *url){
    char *token;
    //ensure its not equal to other token

    char *formated_url[2000];

    if(dtw_starts_with(url,"http://") || dtw_starts_with(url,"https://")){
        sprintf(formated_url,"%s",url);
    }else{
        sprintf(formated_url,"http://%s",url);
    }


    while(true){
        token = gemerate_random_token(6);

        char *content = return_content_of_token(token);

        if(content == NULL){
            char formated_path[30];
            sprintf(formated_path,"data/tokens/%s",token);
            dtw_write_string_file_content(formated_path,formated_url);
            return token;
        }
        free(token);
        free(content);
    }
}


