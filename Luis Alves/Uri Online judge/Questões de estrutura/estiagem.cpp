#include<iostream>
#include<queue>
#include<stdio.h>
#include<cmath>
using namespace std;

typedef struct _Casa_{
    int pessoas;
    int consumo;
    float media;
}Casa;

bool operator>(const Casa &casa1,const Casa &casa2){
    return casa1.media<casa2.media;
}
bool operator<(const Casa &casa1,const Casa &casa2){
    return casa1.media>casa2.media;
}

int main(){

    int n;
    int ncasas = 0;

    while(true){
        cin>>n;
        priority_queue<Casa,vector<Casa>,less<vector<Casa>::value_type>> fila;
        if(n ==0 )
            break;
        if(ncasas != 0)
            cout<<endl;
        Casa aux;
        for(int i = 0 ; i < n ; i++){
            cin>>aux.pessoas>>aux.consumo;
            aux.media = (float) aux.consumo/aux.pessoas;
            fila.push(aux);
        }
        int j = 0;
        cout<<"Cidade# "<<ncasas+1<<":"<<endl;
        float total = 0;
        int totalPessoas = 0;
        while ( !fila.empty() ) {
            if(j != 0)
                cout<<" ";
            Casa aux2 = fila.top();
            fila.pop();
            int qtdPessoas = aux2.pessoas;
            while(!fila.empty() && (int)fila.top().media == (int)aux2.media){
                qtdPessoas += fila.top().pessoas;
                total += fila.top().consumo;
                totalPessoas += fila.top().pessoas;
                fila.pop();
            }

            cout<<qtdPessoas << "-"<<((int)aux2.media);
            total += aux2.consumo;
            totalPessoas += aux2.pessoas;
            //cout<<endl<<fila.size()<<endl;
            j++;
        }
        //cout<<endl<<"Consumo medio: "<<total/totalPessoas<<" m3."<<endl;
        printf("\nConsumo medio: %.2f m3.\n",floor(total/totalPessoas*100)/100);
        //cout.precision(2);

        ncasas++;

    }

 //Display container elements.


}
