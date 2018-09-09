#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <climits>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

#define _inline(f...) f() __attribute__((always_inline)); f
#define foreach(i, c) for( __typeof( (c).begin() ) i = (c).begin(); i != (c).end(); ++i )
#define all(x) (x).begin,(x).end
#define fori(i, n) for(int i = 0; i < (n); i++)

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

/*---------- GRAPH ---------- */

int V, E;
vector<vii> adj_list;
vi graus;


void printGraph();
void addEdge(int v, int u, int w);

int main(){
	
	int N, M;
	map<string, int> drinks;
	map<int, string> t_drinks;
	string aux, aux2;

	int count = 0;
	while(cin >> N){
		count++;
		adj_list = vector<vii> (N);
		graus = vi (N, 0);

		fori(i, N){
			cin >> aux;
			drinks[aux] = i;
			t_drinks[i] = aux;
		}

		cin >> M;

		fori(i, M){
			cin >> aux >> aux2;
			addEdge(drinks[aux], drinks[aux2], 1);
			graus[drinks[aux2]]++;
		}

		priority_queue<int, vector<int>, greater<int> > pqueue;

		fori(i, N){
			if(graus[i] == 0) pqueue.push(i);
		}

		vi order;

		int actual;
		cout << "Case #" << count << ": Dilbert should drink beverages in this order:";
		while(!pqueue.empty()){
			actual = pqueue.top();
			pqueue.pop();

			foreach(it, adj_list[actual]){
				graus[it->first]--;
				if(graus[it->first] == 0)
					pqueue.push(it->first);
			}

			cout << " " << t_drinks[actual];
		}
		cout << "." << endl << endl;
	}
}
	
void addEdge(int v, int u, int w) {
   adj_list[v].push_back(make_pair(u, w));
   E++;
}
