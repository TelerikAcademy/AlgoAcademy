#include <stdio.h>
#include <string>
#include <deque>
#include <ctime>

#define MAX_NODES 20000

using namespace std;

struct Node {
    int u;
    int dist;
    int next;
    Node(){}
    Node(int u, int dist, int next):u(u), dist(dist), next(next){}
} nodes[300000];

int N, M;
int n_cnt = 0;

int table[MAX_NODES];

void add_edge(int a, int b, int d) {
    // printf("adding %d %d %d\n", a, b, d);
    nodes[n_cnt] = Node(b, d, table[a]);
    table[a] = n_cnt++;
}
bool used[MAX_NODES];

void BFS() {
    int D[MAX_NODES];

    // memset(D, -1, sizeof(D));
    for(int ij = 0; ij < MAX_NODES; ij++){
        D[ij] = -1;
    }
    D[0] = 0;
    
    deque<int> q;
    q.push_back(0);

    while (!q.empty()) {
        int t = q.front();
        q.pop_front();
        
        if (used[t]) continue;
        used[t] = 1;
        
        for (int i = table[t]; i != -1; i = nodes[i].next) {
            
            int u = nodes[i].u;
            int dist = nodes[i].dist;
            if (D[u] == -1 || D[t] + dist < D[u]) {
                D[u] = D[t] + dist;
                if (dist == 0) {
                    q.push_front(u);
                } else {
                    q.push_back(u);
                }
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        printf("%d\n", D[i]);
    }
}
int main() {
    // memset(table, -1, sizeof(table));

    for(int ij = 0; ij < MAX_NODES; ij++){
        table[ij] = -1;
    }
    
    scanf("%d %d", &N, &M);
    
    clock_t begin = clock();
    for (int i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        add_edge(a, b, c);
        add_edge(b, a, c);
    }
    

    BFS();
    
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    //printf("%f\n", elapsed_secs);    
}
