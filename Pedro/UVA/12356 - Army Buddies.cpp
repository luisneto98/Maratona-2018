#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

int main(){
  int B, S;
  int l, r;
  int left[100001], right[100001];
  
  while(true){
	cin >> S >> B;

	if(!S && !B) break;
	
	for(int i = 1; i <= S; i++){
	  left[i] = i - 1;
	  right[i] = i + 1;
	}

	left[1] = -1;
	right[S] = -1;
	
	while(B--){

	  cin >> l >> r;
	  
	  left[right[r]] = left[l];
	  right[left[l]] = right[r];

	  if(left[l] == -1) cout << "* ";
	  else cout << left[l] << " ";

	  if(right[r] == -1) cout << "*";
	  else cout << right[r];

	  cout << endl;
	  
	}
	cout << "-" << endl;
	
	
  }
  
}
