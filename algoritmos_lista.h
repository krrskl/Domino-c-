struct ficha{
    int pintaIzquierda;
    int pintaDerecha;
    bool estado = false;
    ficha *sig;
} *ptr;

struct img{
    char url[10];
    int pintaIzq;
    int pintaDer;
    bool estado=false;
    img *sig;
}*imagenes;


void insertar_por_cabeza(ficha *p, ficha *&ptr);
void recorrer(ficha *c);
void insertar_por_cola(ficha *p, ficha *&ptr);

void insertar_por_cabeza(ficha *p, ficha *&ptr){
    p->sig = ptr;
    ptr = p;
}

void recorrer(ficha *c){
    ficha *k = c;
    while(k != NULL){
        cout<<"[ "<<k->pintaIzquierda<<" | "<<k->pintaDerecha<<" ]"<<endl;
        k = k->sig;
    }
}

void insertar_img(img *p){
    if(imagenes != NULL){
        img *k = imagenes;
        while(k->sig != NULL){
            k = k->sig;
        }
        k->sig = p;
        p->sig = NULL;
    }else{
        p->sig = imagenes;
        imagenes = p;
    }
}

void insertar_por_cola(ficha *p, ficha *&ptr){
    if(ptr != NULL){

        ficha *k = ptr;
        while(k->sig != NULL){
            k = k->sig;
        }

        k->sig = p;
        p->sig = NULL;
    }else{
        insertar_por_cabeza(p, ptr);
    }
}
