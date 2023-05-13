//
// Created by jurandi on 13-05-2023.
//


struct CTextStack * render_main_interface(){
    struct CTextStack *s = newCTextStack(CTEXT_LINE_BREAKER, CTEXT_SEPARATOR);
    s->$open(s,HTML,"lang=\"en\"");
    s->open(s,HEAD);
        s->auto$close(s,LINK,R"(rel="stylesheet" href="/static/style.css")");
        s->open(s,TITLE);
            s->segment_text(s,"KATTI");
        s->close(s,TITLE);

    s->close(s,HEAD);
        s->open(s,BODY);
        s->auto$close(s,BR,"");
            s->$open(s,DIV,R"(class="center")");
                s->open(s,H3);
                    s->segment_text(s,"Type The URL you want to Short");
                s->close(s,H3);
                s->$open(s,FORM,R"(action="/create_url" method="POST" )");
                s->auto$close(s,INPUT,R"( name="url" placeholder='url' )");
                s->auto$close(s,BR,"");
                s->auto$close(s,BR,"");
                s->open(s,BUTTON);
                     s->segment_text(s,"Short");
                s->close(s,BUTTON);

                s->close(s,FORM);

            s->close(s,DIV);
        s->close(s,BODY);
    s->close(s,HTML);
    return s;
}