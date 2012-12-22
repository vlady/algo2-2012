#include <cstdio>

using namespace std;
int num_nodes, num_bits, num_clusters;
int leader[1<<24];

void read_input() {
  freopen("clustering2.txt", "r", stdin);
  scanf("%d %d", &num_nodes, &num_bits);
  num_clusters = num_nodes;

  for (int i = 0; i < num_nodes; ++i) {
    int mask = 0;
    for (int j = 0; j < num_bits; ++j) {
      int bit;
      scanf("%d", &bit);
      if (bit) mask |= (1 << j);
    }
    // Nodes with same label.
    if (leader[mask] == mask) num_clusters--;
    leader[mask] = mask;
  }
  fclose(stdin);
}
int dep = 0;
int FIND(int x) {
  if (leader[x] == x) return x;
  return leader[x] = FIND(leader[x]);
}
void UNION(int a, int b) {
  a = FIND(a);
  b = FIND(b);
  leader[a] = b;
}
int main() {
  read_input();
  // Assume input does not have 0 0 0 0 0 0 0 0 ...
  for (int i = 1; i < 1 << num_bits; ++i) if (leader[i]) {
    for (int b1 = 0; b1 < num_bits; ++b1)
      for (int b2 = b1; b2 < num_bits; ++b2) {
        // Find a possible node.
        int mask = i;
        mask ^= (1 << b1);
        if (b1 != b2) mask ^= (1 << b2);
        if (leader[mask] && FIND(i) != FIND(mask))
          --num_clusters, UNION(i, mask);
      }
  }
  printf("Final k: %d\n", num_clusters);
  return 0;
}
