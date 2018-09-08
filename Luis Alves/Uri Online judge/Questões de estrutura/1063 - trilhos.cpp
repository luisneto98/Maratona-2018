#include<iostream>
#include<stack>
#include<queue>
#include<string>
using namespace std;

int main(){

	int n;
	while(true){
		stack<string>	pilha2;
		queue<string> pilha1;
		cin>>n;

		if(n == 0)
			break;

		string aux;
		for(int i = 0 ; i < n ; i++){
			cin>>aux;
			pilha1.push(aux);
		}
		string saida[27];
		for(int i = 0 ; i < n ; i++){
			cin>>saida[i];
			//cout<<saida[i];
		}
		int i = 0;
		while(!pilha1.empty()){
			cout<<"I";
			pilha2.push(pilha1.front());
			pilha1.pop();
			
			while(!pilha2.empty() && pilha2.top() == saida[i]){
				cout<<"R";
				pilha2.pop();
				i++;
			}

		}
		while(!pilha2.empty()){
			if(pilha2.top() == saida[i]){
				cout<<"R";
				pilha2.pop();
				i++;
			}else{
				cout<<" Impossible"<<endl;
				break;
			}

		}
		if(pilha2.empty()){
			cout<<endl;
		}


	}
}