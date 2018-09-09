#include <stdio.h>

double graus(double a, double b){
  if(a > b) return a - b;
  return b - a;
}

double menorAngulo(float a, float b){
  double h = (double) (a + b/60)*30;
  double m = (double) b*6;

  double menorAngulo = graus(h, m);

  if(menorAngulo > 180) return 360 - menorAngulo;

  return menorAngulo;
  
}

int main(void){
  float m, h;
  int aux;
  double angulo;
  
  while(true){
	scanf("%f:%f", &h, &m);

	if(h == 0 && m == 0) break;
	
	printf("%.3f\n", menorAngulo(h, m));	
  }
  
}
