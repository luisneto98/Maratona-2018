#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <climits>

using namespace std;

#define _inline(f...) f() __attribute__((always_inline)); f
#define foreach(i, c) for( __typeof( (c).begin() ) i = (c).begin(); i != (c).end(); ++i )
#define all(x) (x).begin,(x).end
#define fori(i, n) for(int i = 0; i < (n); i++)

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

/*---------- GRAPH ---------- */

int V, E;
vector<vii> adj_list;
vector<bool> visited;

void printGraph() {
  foreach(it, adj_list) {
     cout << "No: " << (it - adj_list.begin()) << endl;
     foreach(it2, *it) {
        printf("   Vizinho: %d, Peso: %d\n", it2->first, it2->second);
     }
  }
}

void addEdge(int v, int u, int w) {
   adj_list[v].push_back(make_pair(u, w));
   E++;
}

void bfs(int node) {
   visited.fill(false);
   queue<int> fila;

   fila.push(node);
   visited[node] = 1;
   while(!fila.empty()) {
      int v = fila.front(); fila.pop();
#ifdef _DEBUG_
      printf("No: %d\n", v);
#endif
      foreach(it, adj_list[v]) { // Percorrer vizinhos do no
         if(!visited[it->first]) { // Se vizinho ainda n foi visitado
            visited[it->first] = 1;
            fila.push(it->first);
         }
      }
   }
}

void dfs_visit(int node) {
   visited[node] = true;
#ifdef _DEBUG_
   printf("No: %d\n", node);
#endif
   foreach(it, adj_list[node]) {
      if(!visited[(it->first)])
         dfs_visit(it->first);
   }
}
void dfs(int node) {
   visited.fill(false);
   dfs_visit(node);
}

/* Acha o numero de nos conectados */
void find_con_nodes() {
   visited.fill(false);
   fori(i, V)
      if (!visited[i])
         printf("CC %d:", ++numCC), dfs(i), printf("\n");
}

int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
/* rows, cols, replace c1 with c2;
 * retorna o numero de c1s */
int floodfill(int r, int c, char c1, char c2) {
   if (r < 0 || r >= R || c < 0 || c >= C) return 0;
   if (grid[r][c] != c1) return 0;
   int ans = 1;
   grid[r][c] = c2;
   fori(d, 8)
      ans += floodfill(r+dr[d], c+dc[d], c1, c2);
   return ans;
}

vi ts; // Guarda topsort na ordem reversa
void top_sort(int u) {
   visited[u] = true;
   fori(i, adj_list.size(); i++) {
      ii v = adj_list[u][j];
      if(!visited[v.first])
         top_sort(v.first);
   }
   ts.push_back(u);
}

bool Bipartite() {
   queue<int> q; q.push(s);
   vi color(V, INF);
   color[s] = 0;
   bool isBi = true;
   while(!q.empty() & is Bi) {
      int u = q.front(); q.pop();
      fori(i, adj_list[u].size()) {
         ii v = adj_list[u][i];
         if(color[v.first] == INF) {
            color[v.first] = 1- color[u];
            q.push(v.first);
         }else if (color[v.first] == color[u]) {
            isBi = false;
            break;
         }
      }
   }
   return isBi;
}

void articulationPointAndBridge(int u) {
}

void dijkstra(int node, vi *cost) {
   visited.fill(false);
   cost->at(node) = 0;
   priority_queue<ii, vector<ii>, greater<ii> > q;
   q.push(make_pair(0, node));

   while(!q.empty()) {
      ii p = q.top();
      q.pop();
      int u = p.second;
      if (visited[u]) continue;

      visited[u] = 1;
      foreach(it, adj_list[u]) {
         int v = it->first;
         int weight = it->second;
         if(cost->at(u) + weight < cost->at(v)) {
            cost->at(v) = cost->at(u) + weight;
            q.push(make_pair(cost->at(v), v));
         }
      }
   }
}



void prim(Graph *result) {
}

void kruskal(Graph *result) {
}

/*---------- Union Find Disjoint Set ----------*/
int root(vi* arr, int i) {
   while(arr->at(i) != i) {
      arr->at(i) = arr->at(arr->at(i));
      i = arr->at(i);
   }
   return i;
}

bool find(vi* arr, int a, int b) {
   return (root(arr, a) == root(arr, b));
}

void weighted_union(vi* arr, vi* size, int a, int b) {
   int rA = root(arr, a);
   int rB = root(arr, b);
#ifdef _DEBUG_
   printf("Adding %d to %d\n", a, b);
   printf("   Root of %d: %d\n", a, rA);
   printf("   Root of %d: %d\n", b, rB);
   printf("   Size of %d: %d\n", a, size->at(a));
   printf("   Size of %d: %d\n", b, size->at(b));
#endif

   if (size->at(a) < size->at(b)) {
#ifdef _DEBUG_
      printf("   %d < %d\n", a, b);
      printf("   Adding %d to %d\n", a, b);
#endif
      arr->at(rA) = rB;
      size->at(rB) += size->at(rA);
   } else {
#ifdef _DEBUG_
      printf("   %d > %d\n", a, b);
      printf("   Adding %d to %d\n", b, a);
#endif
      arr->at(rB) = rA;
      size->at(rA) += size->at(rB);
   }
}

/*---------- Segment Tree ----------*/
/* Responder consultas com ranges dinamicas
 * Ex: Achar o index do menor elemento na range[i,j]
 */

/*
 * p = 
 * L = 
 * R = 
 * I = 
 * J = 
 */
int aux_rmq(vi* arr, vi* seg, int p, int L, int R, int i, int j) {
#ifdef _DEBUG_
   printf("   Looking between %d and %d\n", L, R);
#endif
   if (i > R || j < L) return -1;
   if (L == R) return seg->at(p);

   int left = p << 1;
   int right = (p << 1)+1;
#ifdef _DEBUG_
   printf("   Left: %d Right: %d\n", left, right);
#endif
   int n1 = aux_rmq(arr, seg, left,  L, (L+R)/2, i, j);
   int n2 = aux_rmq(arr, seg, right, (L+R)/2+1, R, i, j);
#ifdef _DEBUG_
   printf("N1: %d  N2: %d\n", n1, n2);
#endif
   if (n1 == -1) return n2;
   if (n2 == -1) return n1;
   return (arr->at(n1) <= arr->at(n2) ? n1 : n2);
}

int aux_update(vi* arr, vi* tree, int p, int L, int R, int idx, int new_v) {
   int i = idx, j = idx;
   if (i > R || j < L)
      return tree->at(p);
   if (L == i && R == j) {
      arr->at(i) = new_v;
      return tree->at(p) = L;
   }
}

int update_value(vi* arr, vi* tree, int idx, int new_v) {
   return aux_update(arr, tree, 1, 0, arr->size()-1, idx, new_v);
}

int rmq(vi* arr, vi* seg, int L, int R) {
#ifdef _DEBUG_
   printf("Looking between %d and %d\n", L, R);
#endif
   return aux_rmq(arr, seg, 1, 0, arr->size()-1, L, R);
}

void segTree(vi* arr, vi* tree, int n, int L, int R) {
   int left = n << 1;
   int right = (n << 1)+1;
#ifdef _DEBUG_
   printf("Segment of %d: %d / %d\n", n, L, R);
   printf("   Left: %d, Right: %d\n", left, right);
#endif
   if (L == R) {
      tree->at(n) = L;
   } else {
      segTree(arr, tree, left, L, (L+R)/2);
      segTree(arr, tree, right, (L+R)/2+1, R);
      int n1 = tree->at(left), n2 = tree->at(right);
      tree->at(n) = (arr->at(n1) <= arr->at(n2)) ? n1 : n2;
   }
}


/*---------- Fenwick Tree ----------*/
/* AKA Binary Indexed Tree - Dynamic Cumulative Frequency Table */
void fenwick() {
}


int main() {
   int aux[] = {18, 17, 13, 19, 15, 11, 20};
   vi arr = vector<int>(begin(aux), end(aux));
   vi seg_tree = vi(arr.size()*4, 0);
   segTree(&arr, &seg_tree,1, 0, arr.size()-1);
   cout << rmq(&arr, &seg_tree, 1, 3) << endl;
   cout << rmq(&arr, &seg_tree, 4, 5) << endl;
   cout << rmq(&arr, &seg_tree, 3, 4) << endl;

   return 0;
}
