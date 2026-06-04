#include <iostream>
using namespace std;

int a[5];      
int usado[5]; 
int p[5];       
bool posible;   

void operar(int pos,int resultado){ 
    if(pos==5){ 
        if(resultado==23)
            posible=true; 
        return;
    }
    operar(pos+1,resultado+p[pos]);
    operar(pos+1,resultado-p[pos]);
    operar(pos+1,resultado*p[pos]);
}

void permutar(int pos){ 
    if(pos==5){ 
        operar(1,p[0]); 
        return;
    }

    for(int i=0;i<5;i++){
        if(!usado[i]){ 
            usado[i]=1; 
            p[pos]=a[i]; 
            permutar(pos+1); 
            usado[i]=0;
        }
    }
}

int main(){
    while(true){
        int suma=0;

        for(int i=0;i<5;i++){
            cin>>a[i];
            suma+=a[i];
        }

        if(suma==0)
            break;

        posible=false;

        for (int i=0;i<5;i++)
            usado[i]=0; 

        permutar(0);

        if(posible)
            cout<<"Possible"<<endl;
        else
            cout<<"Impossible"<<endl;
    }

    return 0;
}