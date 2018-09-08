#include<iostream>
#include<string>
#include<queue>

using namespace std;

int main(){
	int n,l,c;
	while(cin>>n>>l>>c){
		queue<string> palavras;
		string aux;
		for(int i = 0 ; i < n ; i++){
			cin>>aux;
			palavras.push(aux);
		}
		int totalLinha = 0;
		int linhas = 1;
		int paginas = 1;
		bool newLine = true;

		while(!palavras.empty()){
			if(!newLine && totalLinha+1 <= c){
				
				totalLinha++;
			}else
				newLine =false;


			if(palavras.front().length()+totalLinha <= c){
				totalLinha += palavras.front().length();//cout<<palavras.front();
				palavras.pop();
			}else{
				linhas++;
				//out<<endl;
				if(linhas > l){
					linhas = 1;
					paginas++;
				}
				totalLinha = 0;
				newLine = true;
			}

		}
		//cout<<linhas<<endl;	
		cout<<paginas<<endl;

	}


}