#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
   int a, b;
   vector<bool> memo(14, false);

   scanf("%d %d", &a, &b);
   int maior = max(a, b);

   cout << maior << endl;
}
