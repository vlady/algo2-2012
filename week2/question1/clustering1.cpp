#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
  int a, b, c;  // (a, b) with cost c.
};

int num_nodes;
vector<edge> edges;

bool desc(edge a, edge b) {
  return a.c < b.c;
}
void read_input() {
  freopen("clustering1.txt", "r", stdin);
  scanf("%d", &num_nodes);
  edges.resize(num_nodes * (num_nodes - 1) / 2);
  for (int i = 0; i < num_nodes * (num_nodes - 1) / 2; ++i) {
    scanf("%d %d %d", &edges[i].a, &edges[i].b, &edges[i].c);
  }
  fclose(stdin);
}

int leader[1024];

int FIND(int x) {
  if (x == leader[x]) return x;
  return leader[x] = FIND(leader[x]);
}

void UNION(int a, int b) {
  a = FIND(a);
  b = FIND(b);
  leader[a] = b;
}

int main() {
  read_input();
  // sort edges
  sort(edges.begin(), edges.end(), desc);
  // initialize clusters
  for (int i = 0; i < num_nodes; ++i) leader[i] = i;

  int num_clusters = num_nodes;
  int idx = 0;
  while (num_clusters > 4) {
    if (FIND(edges[idx].a) != FIND(edges[idx].b))
      UNION(edges[idx].a, edges[idx].b), --num_clusters; 
    ++idx;
  }

  for (; idx < edges.size(); ++idx) {
    if (FIND(edges[idx].a) != FIND(edges[idx].b)) {
      printf("Maximal distance: %d\n", edges[idx].c);
      break;
    }
  }

  return 0;
}
