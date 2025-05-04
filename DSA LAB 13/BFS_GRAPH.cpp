#include <iostream>
using namespace std;

const int MAX = 10;

class GraphBFS {
    int matrix[MAX][MAX];
    int size;
    
public:
    GraphBFS() {
        size = 0;
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                matrix[i][j] = 0;
            }
        }
    }
    
    void addEdge(int u, int v) {
        matrix[u][v] = 1;
        matrix[v][u] = 1;
        if (u >= size) size = u + 1;
        if (v >= size) size = v + 1;
    }
    
    void bfs(int start) {
        int visited[MAX] = {0};
        int queue[MAX];
        int front = 0;
        int rear = 0;
        
        cout << start << " ";
        visited[start] = 1;
        queue[rear++] = start;
        
        while (front < rear) {
            int current = queue[front++];
            
            for (int i = 0; i < size; i++) {
                if (matrix[current][i] == 1 && visited[i] == 0) {
                    cout << i << " ";
                    visited[i] = 1;
                    queue[rear++] = i;
                }
            }
        }
    }
};

int main() {
    GraphBFS g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    
    g.bfs(0);
    return 0;
}