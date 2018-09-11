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

char S[100000000];
char SS[102];
map<char, vector<int> > maps;

int binary_search(char l, int pos){
  int left = 0;
  int right = maps[l].size()-1;
  int middle;
  
  while(left <= right){
	middle = (left + right)/2;

	if(middle==0 && maps[l][middle] >= pos) return maps[l][middle];
	else if(middle==0) left = 1;

	if(maps[l][middle] >= pos && maps[l][middle-1] < pos) return maps[l][middle];
	
	if(maps[l][middle] >= pos) right = middle-1;
	else left = middle+1;

  }

  return -1;
}

int main(){
  int Q;

  scanf("%s", S);
  
  int i = 0;
  
  while(S[i] != '\0'){
	maps[S[i]].push_back(i);
	i++;
  }

  scanf("%d", &Q);

  while(Q--){
	scanf("%s", SS);

	int first = -1, last = -1;
	int pos = 0;
	for(i = 0; SS[i] != '\0'; i++){
	  pos = binary_search(SS[i], pos);
	  
	  if(pos == -1){
		first = last = -1;
		break;
	  } else {
		if(first == -1) first = last = pos;
		else last = pos;
	  }
	  pos = pos + 1;
	}

	if(first == -1) printf("Not matched\n");
	else printf("Matched %d %d\n", first, last);
  }
  
}
