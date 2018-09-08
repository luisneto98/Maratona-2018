#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAX_V 100

int n;
bool visited[MAX_V];
int mat[MAX_V][MAX_V];

#define foreach(i, c) for( __typeof( (c).begin() ) i = (c).begin(); i != (c).end(); ++i )
#define all(x) (x).begin,(x).end
#define fori(i, n) for(int i = 0; i < (n); i++)

void dfs(int node) {
   visited[node] = true;
   for (int i = 0; i < n; i++)
      if (!visited[i] && mat[node][i])
         dfs(i);
}

int main() {
   int t;
   int i, j, k;

   scanf("%d", &t);
   fori(cases, t) {
      scanf("%d", &n);
      fori(i, n) {
         fori(j, n) {
            scanf("%d", &mat[i][j]);
         }
      }
      bool dominates[MAX_V][MAX_V];
      memset(dominates, false, sizeof(dominates));
      dominates[0][0] = true; // 0 domina ele mesmo
      for(int rem_node = 1; rem_node < n; rem_node++) {
         dominates[0][rem_node] = true; // 0 domina todos os nos
         memset(visited, false, sizeof(visited));
         visited[rem_node] = true;

         dfs(0);
         fori(i, n) {
            if (!visited[i])
               dominates[rem_node][i] = true;
            dominates[rem_node][rem_node] = true;
         }

      }
      printf("Case %d:\n", cases+1);
      printf("+");
      fori(i, (n*2)-1) {
         printf("-");
      }
      printf("+\n");
      fori(i, n) {
         fori(j, n) {
            printf(dominates[i][j] && visited[j] ? "|Y" : "|N");
         }
         printf("|\n");
      }

      printf("+");
      fori(i, (n*2)-1) {
         printf("-");
      }
      printf("+\n");
   }
}


