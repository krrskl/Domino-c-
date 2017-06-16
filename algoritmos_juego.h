ficha *principal;
int sentido = 0, op;
void voltear_imagen(img *m, ficha *q, BITMAP *l);
void crear_fichas(){
    srand(time(NULL));
    int random = rand() % 21 + 1;
    int cont = 0;
    for(int i=0;i<=6;i++){
        for(int j=0;j<=i;j++){
            if( i != j){
                ficha *r = new ficha;
                r->pintaDerecha = i;
                r->pintaIzquierda = j;

                if(cont == random){
                    principal = r;
                }else{
                    insertar_por_cola(r, ptr);
                }
                cont = cont +1;
            }
        }
    }
    principal->sig = NULL;
}

int ultima_pinta(){
    ficha *p = principal;

    while(p->sig != NULL){
        p = p->sig;
    }

    return p->pintaDerecha;
}

void cambiar_sentido(){

    cout<<"INGRESE: "<<endl;
    cout<<"0. JUGAR POR LA DERECHA "<<endl;
    cout<<"1. JUGAR POR LA IZQUIERDA "<<endl;
    cout<<"> ";
    sentido = validar_entero(true);

    if(sentido == 1){

        int aux = principal->pintaDerecha;

        principal->pintaDerecha = principal->pintaIzquierda;
        principal->pintaIzquierda = aux;

    }
}

img* imprimir_imagenes(ficha *x){
    img *s = imagenes;
    while(s != NULL){
        if(x->pintaIzquierda == s->pintaIzq && x->pintaDerecha == s->pintaDer){
            break;
        }else if(x->pintaIzquierda == s->pintaDer && x->pintaDerecha == s->pintaIzq){
                    break;
        }
        s = s->sig;
    }
    //cout<<"imagen: "<<s<<endl;
    return s;
}
int i=0, j=0;
void voltear_imagen_izq(img *m, ficha *q, BITMAP *l){
    if(q->pintaDerecha == m->pintaDer){
        rotate_sprite(screen,l,i,j,itofix(128));
        i = i+70;
    }else{
            draw_sprite(screen, l, i,j);
            i = i+70;
    }
}

void imprimir_por_izquierda(ficha *puntero){
    if(puntero != NULL){

        imprimir_por_izquierda(puntero->sig);
        cout<<"->[ "<<puntero->pintaDerecha<<" | "<<puntero->pintaIzquierda<<" ]";
        img *l = imprimir_imagenes(puntero);
        BITMAP *S;
        S = load_bitmap(l->url,NULL);
        voltear_imagen_izq(l,puntero,S);
    }else{
        cout<<endl;
    }
}

void imprimir(){
    if(sentido == 1){
        imprimir_por_izquierda(principal);
    }else{
        ficha *p = principal;
        int i=0, j=0;
        while(p != NULL){
            cout<<"[ "<<p->pintaIzquierda<<" | "<<p->pintaDerecha<<" ] ->";
            img *l = imprimir_imagenes(p);
            BITMAP *S;
            S = load_bitmap(l->url,NULL);
            voltear_imagen(l,p,S);
            p = p->sig;
        }
        cout<<endl;
    }
}

void voltear(int pinta, ficha *ficha){
    if(ficha->pintaDerecha == pinta){
        int aux = ficha->pintaDerecha;

        ficha->pintaDerecha = ficha->pintaIzquierda;
        ficha->pintaIzquierda = aux;
    }
}

void voltear_imagen(img *m, ficha *q, BITMAP *l){
    if(q->pintaDerecha == m->pintaDer){
        draw_sprite(screen, l, i,j);
        i = i+70;
    }else{
        rotate_sprite(screen,l,i,j,itofix(128));
            i = i+70;
    }
}

void leer_Imagenes(){
    fstream s("imagenes.txt", ios::in);
    char i[10];
    if(!s){
        cout<<"archivo no encontrado"<<endl;
    }else{
        cout<<"Encontrado"<<endl;

        while(s.getline(i,10)){
            img *r = new img;
            strcpy(r->url,i);
            s.getline(i,10);
            r->pintaIzq = atoi(i);
            s.getline(i,10);
            r->pintaDer = atoi(i);
            insertar_img(r);
            //cout<<r->url<<"<---"<<endl;
            //cout<<"[ "<<r->pintaIzq<<"|"<<r->pintaDer<<" ]"<<endl;
        }
    }
    s.close();
}

ficha *buscar_ficha(int pinta){
    ficha *p = ptr;

    while(p != NULL){
        if(p->estado == false){
            if(p->pintaIzquierda == pinta || p->pintaDerecha == pinta){
                p->estado = true;
                break;
            }
        }
        p = p->sig;
    }
    return p;
}

void insertar_en_principal(ficha *f){
    ficha *nf = new ficha;

    nf->sig = NULL;
    nf->pintaDerecha = f->pintaDerecha;
    nf->pintaIzquierda = f->pintaIzquierda;
    nf->estado = f->estado;

    insertar_por_cola(nf, principal);

}

void jugar(){
    while(true){
        int up = ultima_pinta();
        ficha *f = buscar_ficha(up);
        if(f != NULL){
            voltear(up, f);
            insertar_en_principal(f);
        }else{
            break;
        }
    }
}

void verificar_partida(){
    if(sentido == 1){
        ficha *m = principal;
        while(m->sig != NULL){
            m = m->sig;
        }
        if(principal->pintaIzquierda == m->pintaDerecha){
            cout<<endl<<"********JUEGO PERFECTO********"<<endl;
        }else{
            cout<<endl<<"********JUEGO SEMI PERFECTO********"<<endl;
        }
    }else{
        ficha *m =principal;
        while(m->sig != NULL){
            m = m->sig;
        }
        if(principal->pintaIzquierda == m->pintaDerecha){
            cout<<endl<<"********JUEGO PERFECTO********"<<endl;
        }else{
            cout<<endl<<"********JUEGO SEMI PERFECTO********"<<endl;
        }
    }
}

void mostrar_fichas(){
    ficha *x = ptr;
    int n=1;

    cout<<endl<<"FICHAS DISPONIBLES PARA JUGAR: "<<endl;

    while(x != NULL){
        if(x->estado == false){
            cout<<"(" <<n<< ") "<<"[ "<< x->pintaIzquierda<< "|" <<x->pintaDerecha<<" ]"<<endl;
        }
        x = x->sig;
        n++;
    }
    cout<<"INGRESE EL NUMERO CORRESPONDIENTE A LA FICHA: "<<endl;
    cout<<"> ";
    cin>>op;
}

void cambiar_estado(){
    ficha *p =ptr;
    while(p != NULL){
        p->estado = false;
        p = p->sig;
    }
}

ficha* buscar_ficha_persona(){
    int x = 1;
    ficha *s = ptr;
    while(x != op && s != NULL){
        x++;
        s = s->sig;
    }
    return s;
}

int verificar_ficha(int p){
    ficha *n = ptr;
    int cont = 0;
    while(n != NULL){

            if (n->estado == false){
                if (n->pintaIzquierda == p || n->pintaDerecha == p){
                    cont ++;
                }
            }
        n = n->sig;
    }
    return cont;
}

void jugar_persona(){
    principal->sig = NULL;
    while(true){
        mostrar_fichas();
        clear(screen);
        i=0;j=0;
        int up = ultima_pinta();
        ficha *m = buscar_ficha_persona();
        int r=1;
        if(m != NULL){

            if(m->estado == false ){

                if(m->pintaIzquierda == up || m->pintaDerecha == up){

                    m->estado = true;
                    voltear(up,m);
                    insertar_en_principal(m);

                }else{
                    cout<<endl<<"------------------------------------"<<endl;
                    cout<<"ESTA FICHA NO COINCIDE"<<endl;
                    r = verificar_ficha(up);
                    cout<<endl<<"------------------------------------"<<endl;
                    cout<<"NUMERO DE MOVIDAS QUE PUEDES HACER:   "<<r;
                    cout<<endl<<"------------------------------------"<<endl;
                }

            }else{

                cout<<"FICHA YA JUGADA..!"<<endl;
                r = verificar_ficha(up);
            }
            imprimir();
        } if(r==0){
           break;
        }
    }
        //cout<<"-->"<<m->pintaIzquierda<<" | "<<m->pintaDerecha<<endl;

}
