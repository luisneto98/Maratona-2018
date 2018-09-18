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

#define ABS(a, b) (a) > (b) ? (a) - (b) : (b) - (a)
#define MAXSIZE 100000

typedef pair<long long int, long long int> ll;
typedef vector<ll> vll;

bool cmp(const ll &a, const ll &b) 
{
  if(a.first == b.first){
	return (a.second < b.second);
  }

  return (a.first < b.first);
} 

int main(){
  long long X, Y;
  long long cut_s, cut_f;
  int H, V;
  vll H_U, H_D, V_L, V_R;
  int map_pos_V[MAXSIZE], map_pos_H[MAXSIZE];
  int count = 1;
  
  scanf("%Ld %Ld", &X, &Y);
  scanf("%d %d", &H, &V);

  count += H * V;
  
  fori(i, H){
	scanf("%Ld %Ld", &cut_s, &cut_f);
	H_U.push_back(make_pair(cut_s, (long long) i));
	H_D.push_back(make_pair(cut_f, (long long) i));
  }

  sort(H_U.begin(), H_U.end(), cmp);  
  sort(H_D.begin(), H_D.end(), cmp);

  fori(i, V){
	scanf("%Ld %Ld", &cut_s, &cut_f);
	V_L.push_back(make_pair(cut_s, (long long) i));
	V_R.push_back(make_pair(cut_f, (long long) i));
  }

  sort(V_L.begin(), V_L.end(), cmp);  
  sort(V_R.begin(), V_R.end(), cmp);

  fori(i, H_D.size()) map_pos_H[H_D[i].second] = i;
  
  fori(i, V_R.size()) map_pos_V[V_R[i].second] = i;

  int intersecs = 0;

  fori(i, H_U.size()){
	intersecs += ABS(i, map_pos_H[H_U[i].second]);
	count++;
  }

  intersecs = intersecs/2;
  count += intersecs;


  intersecs = 0;
  fori(i, V_L.size()){
	intersecs += ABS(i, map_pos_V[V_L[i].second]);
	count++;
  }

  intersecs = intersecs/2;
  count += intersecs;
  
  printf("%d\n", count);

  return 0;
}
