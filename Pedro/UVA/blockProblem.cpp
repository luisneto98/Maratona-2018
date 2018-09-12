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
vector<int> stacks (25);

void addEdge(int v, int u, int w) {
  adj_list[v].push_back(make_pair(u, w));
  E++;
}

void r_unstack(int bloc){
  while(adj_list[stacks[bloc]].size()){
	int aux = adj_list[stacks[bloc]].back().first;

	if(aux == bloc) break;

	adj_list[stacks[bloc]].pop_back();
	
	stacks[aux] = aux;
  }
}


void r_stack(int bloc1, int bloc2){
  addEdge(stacks[bloc1], bloc2, 1);

  stacks[bloc2] = stacks[bloc1];
}


vector<int> pile(int bloc1){
  vector<int> pile_aux;

  while(adj_list[stacks[bloc1]].size()){
	int aux = adj_list[stacks[bloc1]].back().first;

	if(aux == bloc1) break;

	adj_list[stacks[bloc1]].pop_back();
	
	stacks[aux] = aux;

	pile_aux.insert(pile_aux.begin(), aux);
  }

  return pile_aux;
}


void pile_over(int a, int b){
  vector<int> pile_a = pile(a);

  if(stacks[a] !=  a){
	 adj_list[stacks[a]].pop_back();
	 stacks[a] = a;
  }

  r_stack(b, a);

  foreach(it, pile_a){
	r_stack(b, *it);
  }
}

void pile_onto(int a, int b){
  vector<int> pile_a = pile(a);
 
  if(stacks[a] !=  a){
	 adj_list[stacks[a]].pop_back();
	 stacks[a] = a;
  }

  pile(b);

  r_stack(b, a);
  
  foreach(it, pile_a){
	r_stack(b, *it);
  }
}

void move_onto(int a, int b){
  r_unstack(a);

  if(stacks[a] !=  a){
	 adj_list[stacks[a]].pop_back();
	 stacks[a] = a;
  }
 
  r_unstack(b);

  r_stack(b, a);
}

void move_over(int a, int b){
  r_unstack(a);

  if(stacks[a] !=  a){
	 adj_list[stacks[a]].pop_back();
	 stacks[a] = a;
  }
 
  r_stack(b, a);
}


void printGraph(int N) {
  fori(i, N) {
	cout << i << ":";// << (it - adj_list.begin()) << endl;
	if(stacks[i] == i) cout << " " << i;
	foreach(it, adj_list[i]) {
	  cout << " " << it->first;
	}
	cout << endl;
  }
}


int main(){
  int n;
  adj_list = vector<vii> (25);
  string action1, action2;
  int bloc1, bloc2;
  
  cin >> n;

  fori(i, n) stacks[i] = i;

  cin >> action1;
  while(action1 != "quit"){
	cin >> bloc1 >> action2 >> bloc2;

	if(bloc1 == bloc2 || (stacks[bloc1] == stacks[bloc2])){
	  cin >> action1;
	  continue;
	} 
	
	if(action1 == "move"){
	  if(action2 == "onto") move_onto(bloc1, bloc2);
	  else move_over(bloc1, bloc2); 
	} else {
	  if(action2 == "onto") pile_onto(bloc1, bloc2);
	  else pile_over(bloc1, bloc2);
	}

	cin >> action1;
  }

  printGraph(n);
  
  
}
