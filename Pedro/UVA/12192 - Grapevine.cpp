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

int p[500][500];

int binary_search_b(int v[], int size, int pos, int bound){
  int left = 0;
  int right = size-1;
  int middle;
  
  while(left <= right){
	middle = (left + right)/2;

	if(middle==0 && v[middle] >= pos && v[middle] <= bound) return middle;
	else if(middle==0) left = 1;

	if(v[middle] >= pos && v[middle-1] < pos && v[middle] <= bound) return middle;
	
	if(v[middle] >= pos) right = middle-1;
	else left = middle+1;

  }
  
  return -1;
}


int main(){
  int Q, L, U, M, N;

  while(scanf("%d %d", &N, &M)){
	if(!(N && M)) break;
	
	fori(i, N)
	  fori(j, M){
		scanf("%d", &p[i][j]);
	}

	scanf("%d", &Q);
	
	while(Q--){
	  scanf("%d %d", &L, &U);
	  
	  int l_bound;
	  int max_size = 0;
	  
	  fori(i, N){
		
		l_bound = binary_search_b(p[i], M, L, U);
		
		if(l_bound == -1) continue;
		
		for(int j = max_size; j < N; j++){
		  if(i + j >= N || l_bound + j >= M || p[i + j][l_bound + j] > U) break;

		  if(j+1 > max_size) max_size = j+1;
		}
		
	  }

	  printf("%d\n", max_size);
	}
	printf("-\n");
  }
}
