#include<iostream>
#include<vector>
#include<cmath>
#include<cstdlib>

using namespace std;

int main(){

	int n;
	while(cin>>n){
		vector<int> integrantes;
		int aux;
		double totalNotas = 0;
		for(int i = 0 ; i < n ; i++){
			cin>> aux;
			integrantes.push_back(aux);
			totalNotas += aux; 
		}
		double mediaNotas = totalNotas/n;
		if(mediaNotas !=  floor(mediaNotas)){
			cout<<-1<<endl;
			continue;

		}
		int totalDiff = 0;
		for(int i = 0 ; i < n ; i++){
			if(integrantes[i] < mediaNotas)
				totalDiff += abs(mediaNotas - integrantes[i]);
		}
		cout<<totalDiff+1<<endl;
	}
}