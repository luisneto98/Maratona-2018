#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
vector<vii> adjList;

void dfs(int u, bool state, vi* visited, vi* loop) {
   vi cost(adjList.size(), 0);
   int min_cost = 0;
   if(visited->at(u)) loop->at(u) = true;
   for(int i = 0; i < adjList[u].size(); i++) {
      ii node = adjList[u][i];
      if(!visited[node.first])
         cost[i] = dfs(node.first, !state, visited, loop);
      else if(visited[node.first] && loop[u])
         cost[i] = dfs(node.first, !state, visited, loop);
   }
   if(u == c) {
      if (state)
         return 0;
      else
         return min_cost;
   }
}

int main() {
   long int c;
   int v, i, j, k;
   int n1, n2, w;

   scanf("%d %d", &c, &v);

   while(v--) {
      scanf("%d %d %d", &n1, &n2, &w);
      adjList[n1].push_back(make_pair(n2, w));
   }
}
