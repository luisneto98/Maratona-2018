#include <cstdio>
#include <climits>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define fori(i, N) for(int i = 0; i < (N); i++)
#define foreach(it, v) for(__typeof( (v).begin() ) it = (v).begin(); it != (v).end(); it++)

//#define __DEBUG__

typedef pair<long long int, long long int> ll;
typedef vector<ll> vll;

bool cmp(const ll &a, const ll &b) 
{
  if(a.first == b.first){
	return (a.second < b.second);
  }

  return (a.first < b.first);
} 

int bin_search(vll &v, long long val, long long line_id, int c_pos=-1){
  int middle;
  int left = 0;
  int right = v.size() - 1;

  if(c_pos != -1){
	if(v[c_pos].first == val) return c_pos;
  }
  
  while(left <= right){
	middle = (left + right) / 2;
	
	if(v[middle].first == val){
	  int aux = middle;
	  while(aux >= 0 && v[aux].first == val){
		aux--;
	  }

	  return aux + 1;
	}

	if(v[middle].first > val) right = middle-1;
	else left = middle + 1;
	
  }

  return -1;
}

int main(){
  long long X, Y;
  long long cut_s, cut_f;
  int H, V;
  vll H_ID, V_ID;
  vll H_U, H_D, V_L, V_R;
  int count = 1;
  
  scanf("%Ld %Ld", &X, &Y);
  
  scanf("%d %d", &H, &V);

  count += H * V;
  
  fori(i, H){
	scanf("%Ld %Ld", &cut_s, &cut_f);

	H_ID.push_back(make_pair(cut_s, cut_f));
	H_U.push_back(make_pair(cut_s, (long long) i));
	H_D.push_back(make_pair(cut_f, (long long) i));

	sort(H_U.begin(), H_U.end(), cmp);  
	sort(H_D.begin(), H_D.end(), cmp);

	int p_u = bin_search(H_U, cut_s, i);
	int p_d = bin_search(H_D, cut_f, i, p_u);

	count += abs(p_u - p_d) + 1;

#ifdef __DEBUG__
	printf("Reta Horizontal [%d]:\n Intersecções: %d + %d\n", i, abs(p_u - p_d), V);
#endif
  }

  fori(i, V){
	scanf("%Ld %Ld", &cut_s, &cut_f);

	V_ID.push_back(make_pair(cut_s, cut_f));
	V_L.push_back(make_pair(cut_s, (long long) i));
	V_R.push_back(make_pair(cut_f, (long long) i));

	sort(V_L.begin(), V_L.end(), cmp);  
	sort(V_R.begin(), V_R.end(), cmp);

	int p_l = bin_search(V_L, cut_s, i);
	int p_r = bin_search(V_R, cut_f, i);

	count += abs(p_l - p_r) + 1;

#ifdef __DEBUG__
	printf("Reta Vertical [%d]:\n Intersecções: %d + %d\n", i, abs(p_l - p_r), H);
#endif
  }
  
  printf("%d\n", count);

  return 0;
}
