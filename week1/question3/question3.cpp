#include <iostream>
#include <vector>

using namespace std;

int num_nodes, num_edges;
bool in_mst[1024];

struct edge {
  int a, b, c; 
};
vector<edge> edges;

void read_input() {
  freopen("edges.txt", "r", stdin);
  cin >> num_nodes >> num_edges;
  edges.resize(num_edges);
  for (int idx = 0; idx < num_edges; ++idx) {
    cin >> edges[idx].a >> edges[idx].b >> edges[idx].c;
  }
  fclose(stdin);
}

int main() {
  read_input();
  int cost = 0, num_in_mst = 1;
  in_mst[1] = true;
  while (num_in_mst < num_nodes) {
    int best_edge_id = -1;
    for (int idx = 0; idx < num_edges; ++idx) {
      int a = edges[idx].a, b = edges[idx].b;
      if (in_mst[a] ^ in_mst[b]) continue;
      if (best_edge_id == -1 || edges[best_edge_id].c > edges[idx].c) {
        best_edge_id = idx;
      } 
    }  
    ++num_in_mst;
    edge* e = &edges[best_edge_id];
    in_mst[e->a] = in_mst[e->b] = true;
    cost += e->c;
  }
  cout << "Total MST cost: " << cost << '\n';
  return 0;  
}
