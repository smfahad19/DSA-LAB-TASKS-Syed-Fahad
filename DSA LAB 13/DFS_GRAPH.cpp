#include <iostream>
using namespace std;

const int MAX = 10;

class GraphDFS {
    int matrix[MAX][MAX];
    int visited[MAX];
    int size;
    
public:
    GraphDFS() {
        size = 0;
        for (int i = 0; i < MAX; i++) {
            visited[i] = 0;
            for (int j = 0; j < MAX; j++) {
                matrix[i][j] = 0;
            }
        }
    }
    
    void addEdge(int u, int v) {
        matrix[u][v] = 1;
        matrix[v][u] = 1;
        if (u >= size){
            size = u + 1;
        } 
        if (v >= size){
            size = v + 1;
        } 
    }
    
    void dfs(int start) {
        cout << start << " ";
        visited[start] = 1;
        
        for (int i = 0; i < size; i++) {
            if (matrix[start][i] == 1 && visited[i] == 0) {
                dfs(i);
            }
        }
    }
};

int main() {
    GraphDFS g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    
    g.dfs(0);
    return 0;
}