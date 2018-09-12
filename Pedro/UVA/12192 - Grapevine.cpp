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
int pT[500][500];
vector<pair<int, int> > p_map;
vector<pair<int, int> > pT_map;

_inline(int menor)(int a, int b){
  return a < b ? a : b;
}

_inline(int maior)(int a, int b){
  return a > b ? a : b;
}

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

int binary_search_l(int v[], int size, int pos, int bound){
  int left = 0;
  int right = size-1;
  int middle;
  
  while(left <= right){
	middle = (left + right)/2;
	
	if(middle==size-1 && v[middle] <= pos && v[middle] >= bound)  return middle; 
	else if(middle==size-1) right = right-1;

	if(v[middle] <= pos && v[middle+1] > pos && v[middle] >= bound) return middle;
	
	if(v[middle] > pos) right = middle-1;
	else left = middle+1;

  }

  return -1;
}

pair<int, int> inside(pair<int, int> p1, pair<int, int> p2){
  pair<int, int> result;
  int f, s;

  f = p2.first >= p1.first ? p2.first : p1.first;
  s = p2.second <= p1.second ? p2.second : p1.second;

  if(f >= p1.first && f <= p1.second) result.first = f;
  else result.first = -1;

  if(s >= p1.first && s <= p1.second) result.second = s;
  else result.second = -1;
  
  return result;
}

int b_square_rec(int l, pair<int, int> bounds, int p, int r){
  if(p_map[l].first == -1) return -1;
  if(p_map[l].second == -1) return -1;

  if(r == 0) return p;
  
  pair<int, int> new_bounds = inside(bounds, p_map[l]);

  if(new_bounds.first == -1) return -1;
  if(new_bounds.second == -1) return -1;

  int potential = new_bounds.second - new_bounds.first + 1;
  
  if(potential < p){
	r = r - (p - potential);
	p = potential;
  }

  if(r <= 0) return -1;

  int back = b_square_rec(l+1, new_bounds, p, r-1);
  return back == -1 ? p - r + 1 : back;
}


int b_square(int l, int N){
  if(p_map[l].first == -1) return -1;
  if(p_map[l].second == -1) return -1;

  int potential = p_map[l].second - p_map[l].first + 1;
  
  if((l + potential - 1) > N - l) potential = N - l;

  int result = b_square_rec(l+1, p_map[l], potential, potential-1);

  if(result == -1) return 1;

  return result;
}

int main(){
  int M, N;
  int Q;
  int L, U;

  while(scanf("%d %d", &N, &M)){
	if(!(N && M)) break;
	
	fori(i, N)
	  fori(j, M){
		scanf("%d", &p[i][j]);
	}


	scanf("%d", &Q);
	
	while(Q--){
	  scanf("%d %d", &L, &U);

	  p_map = vector<pair<int, int> > (N);

	  int l_bound, r_bound;
	  
	  fori(i, N){
		l_bound = binary_search_b(p[i], M, L, U);
		r_bound = binary_search_l(p[i], M, U, L);
		p_map[i] = make_pair(l_bound, r_bound);
	  }

	  int size;
	  int max_size = 0;
	  
	  fori(i, N){
		size = b_square(i, N);
		max_size = maior(max_size, size);
		if(max_size > N - i + 1) break;
	  }

	  printf("%d\n", max_size);

	}
	printf("-\n");
  }
}
