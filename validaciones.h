string pedir_dato(){

    int j = 0;
    string a ;
    int x;
    string b;
    getline(cin,b);
    while(b[j]){
        b[j] = tolower(b[j]);
        x = b[j];
        if(x !=32){a=a+b[j];}
        j++;
    }

    return a;
}

bool validar_dato2(string a){
    bool x = true;
    if(a.length() == 0){
        x=false;
    }
    for(int i=0;i<a.length();i++){
        int b = a[i];
        if(48<=b and b<=58){
        }else{x = false;}
    }
    return x;
}
bool validar_entero2(int a){
    if(a<=5){
        return true;
    }
    return false;
}
int validar_entero(bool p){
    string a;
    bool g = false;
    while(!g){
        a = pedir_dato();
        //cin.ignore(1024,'\n');
        g = validar_dato2(a);
        if(g==false){
            cout<<"---------------------------------"<<endl;
            cout<<"INGRESE UN CARACTER VALIDO!!"<<endl;
            cout<<"---------------------------------"<<endl;
            if(p){
                cout<<"---------------------------------"<<endl;
                cout<<"INGRESE: "<<endl;
                cout<<"0. JUGAR POR LA DERECHA "<<endl;
                cout<<"1. JUGAR POR LA IZQUIERDA "<<endl;
            }
        }
    }
    double b = atoi(a.c_str());

    if (p){
        while(b < 0 || b > 1){
            cout<<"---------------------------------"<<endl;
            cout<<"INGRESE UN CARACTER VALIDO!!"<<endl;
            cout<<"---------------------------------"<<endl;
            if(p){
                cout<<"---------------------------------"<<endl;
                cout<<"INGRESE: "<<endl;
                cout<<"0. JUGAR POR LA DERECHA "<<endl;
                cout<<"1. JUGAR POR LA IZQUIERDA "<<endl;
            }
            b = validar_entero(p);
        }
    }else{
        while(b > 20 || b < 1) {
            cout<<"---------------------------------"<<endl;
            cout<<"INGRESE UN NUMERO ENTRE 1 Y 20!!"<<endl;
            cout<<"> "<<endl;
            b = validar_entero(p);
        }
    }


    return b;
}
