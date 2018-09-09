#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
  int n, last;
  int actual, aux, lek;
  int i;
  
  while(scanf("%d", &n) != EOF){

	bool values[n-1] = { false };

	i = 0;
	   
	last = -1;
	
	for(i = 0; i < n; i++) {
	  scanf("%d", &actual);
	  
	  if(i == 0){
		last = actual;
		continue;
	  }

	  aux = abs(actual - last);
	  
	  if(aux >= n || aux <= 0){
		for(int j=i+1; j<n; j++) scanf("%d", &lek);
		break;
	  }

	  if(values[aux-1] == true){
		for(int j=i+1; j<n; j++) scanf("%d", &lek);
		break;
	  }

	  values[aux-1] = true;
	  
	  last = actual;
	  
	}

	for(i=0; i < n-1; i++){
	  if(values[i] == false)
		break;
	}

	if(i == n-1) printf("Jolly\n");
	else printf("Not jolly\n");	
	
  }
}
