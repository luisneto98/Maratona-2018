#include<iostream>
#include<queue>
using namespace std;

typedef struct _Casa_{
    int pessoas;
    int consumo;
    double media;
}Casa;

bool operator>(const Casa &casa1,const Casa &casa2){
    return casa1.media<casa2.media;
}
bool operator<(const Casa &casa1,const Casa &casa2){
    return casa1.media>casa2.media;
}

int main(){
 priority_queue<Casa,vector<Casa>,less<vector<Casa>::value_type>> fila;
 Casa casa1,casa2,casa3,casa4,casa5;
 casa1.pessoas = 2;
 casa1.consumo = 20;
 casa1.media= 5.3;
casa2.pessoas = 3;
 casa2.consumo = 17;
 casa2.media= 5.6;
  casa3.pessoas = 21;
 casa3.consumo = 203;
 casa3.media= 5.31;
  casa4.pessoas = 3;
 casa4.consumo = 20;
 casa4.media= 10;
  casa5.pessoas = 23;
 casa5.consumo = 2023;
 casa5.media= 1;

 fila.push(casa1);
 casa1.pessoas = 21;
 casa1.consumo = 20;
 casa1.media= 70;
 fila.push(casa1);
 fila.push(casa2);
 fila.push(casa3);
 fila.push(casa4);
 fila.push(casa5);

 //Display container elements.
    while ( !fila.empty() ) {
    cout << fila.top().media << endl;
    fila.pop();
}

}
