#include <iostream>
#include<cstring>

using namespace std;
void menu();
int verificaNumeros(char cadena[10]);
int verificaLetras(char cadena[10]);


int main()
{
    int n=0, l=0, op;
    char rfc[10];
    //int matriz[3][3];
    int len=0;
    do{
        menu();
        cin>>op;
        switch(op){
            case 1:
                do {
                    cout<<"C representa cualquier letra."<<endl;
                    cout<<"N representa cualquier numero."<<endl<<endl;
                    cout<<"Ingresa tu RFC de la forma CCCCNNNNNN."<<endl;
                    cin>>rfc;
                    len = strlen(rfc);
                    if (len<10){
                        cout<<"ingresa por lo menos 10 caracteres"<<endl;
                    }
                    if(len > 10){
                        cout<<"escribe 10 caracteres como maximo. "<<endl;
                    }
                    if(len == 10){
                            cout<<endl;
                        cout<<rfc<<endl;
                        n=verificaNumeros(rfc);
                        l=verificaLetras(rfc);
                        if(l==4 && n==6){
                            cout<<"TEST PASS!!"<<endl;
                        }
                        else if(l== 9){
                            cout<<"FAIL Formato incorrecto"<<endl;
                        }
                        else if (n<6){
                            cout<<"FAIL Excediste letras"<<endl;
                        }
                        else if(l<4){
                            cout<<"FAIL letras Insuficientes"<<endl;
                        }
                        else{
                            cout<<"FAIL Formato incorrecto"<<endl;
                        }
                    }

                }while(len !=10);
            break;
            case 2:
                    cout<<"opcion 2"<<endl;
                break;
            case 3:{

            }break;
            default:{
                cout<<"Elige una opcion valida!!"<<endl<<endl;
            }break;
        }
    }while(op !=3);

    return 0;
}

//metodos
void menu(){
    cout<<endl;
    cout<<"   **************************************************"<<endl;
    cout<<"   *    Elige una opcion:                           *"<<endl;
    cout<<"   *                                                *"<<endl;
    cout<<"   *    1.- Ingresar RFC                            *"<<endl;
    cout<<"   *    2.- Ingresar matriz 3x3                     *"<<endl;
    cout<<"   *    3.- Salir                                   *"<<endl;
    cout<<"   **************************************************"<<endl<<endl;
}
int verificaNumeros(char cadena[10]){
    int i, cod, n=0;
// verifico que los ultimos 6 caracteres sean numeros segun ascii
    for (i=4; i<10; i++){
        cod = cadena[i];
        if(cod >47 && cod<=57){
            n++;
        }
    }
    return n;
}

int verificaLetras(char cadena[10]){
    int i, cod, n=0, aux=0;
    // verifico que los primeros 4 caracteres segun ascii
    // esten dentro de a-z A-Z
    for(i=0;i<4;i++){
        cod=cadena[i];
        if((cod>64 && cod<=90) || (cod>96 && cod<=122)){
            n++;
        }
    // verifico que los primer 4 caracteres
    // no empiecen con numeros segun ascii
        if(cod >47 && cod<=57){
            aux++;
        }
    }
    if(aux>0){
        n = 9;
    }
    return n;
}
