#include <iostream>
#include <queue>
#include <map>

using namespace std;

void check_insert(long int n, map<long int, bool> &hash, priority_queue<long int, vector<long int>, greater<long int> > &heap){
  if(!hash.count(n)){
	hash[n] = true;
	heap.push(n);
  }
}

int main(void){
  long int ugly_order = 0;
  long int ugly_number, aux;
  map<long int, bool> ugly_hash;
  priority_queue<long int, vector<long int>, greater<long int> > ugly_heap;

  ugly_hash[1] = true;
  ugly_heap.push(1);
  
  for(long int i=0; ugly_order < 1500; i++){
	ugly_order++;

	ugly_number = ugly_heap.top();
	ugly_heap.pop();
	
	aux = ugly_number * 2;
	check_insert(aux, ugly_hash, ugly_heap);

	aux = ugly_number * 3;
	check_insert(aux, ugly_hash, ugly_heap);

	aux = ugly_number * 5;
	check_insert(aux, ugly_hash, ugly_heap);
  }

  cout << "The 1500'th ugly number is " << ugly_number << "." << endl;
}

