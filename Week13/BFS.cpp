#include <iostream>
#include <queue>
#include <stack>

using namespace std;
 
void BFS(int vtx, int A[][8], int n){
    queue<int> Q;
    int visited[8] = {0};
 
    // Initial
    cout << vtx << " " << flush;  // Visit vertex
    visited[vtx] = 1;
    Q.push(vtx);
 
    // Explore
    while (!Q.empty()){
        int u = Q.front();  // Vertex u for exploring
        Q.pop();
        for (int v=1; v<=n; v++){  // Adjacent vertices of vertex u
            if (A[u][v] == 1 && visited[v] == 0){  // Adjacent vertex and not visited
                cout << v << " ";  // Visit vertex
                visited[v] = 1;
                Q.push(v);
            }
        }
    }
    cout << endl;
}

void DFS(int A[][8], int start, int size) {
    stack<int> s;
    int visited[size] = {0};
    s.push(start);
    while (!s.empty()) {
        int current = s.top();
        s.pop();
        if (!visited[current]) {
            visited[current] = 1;
            cout << current << " ";
        }
        for (int i = 0; i < size; i++) {
            if (A[current][i] == 1 && visited[i] == 0) {
                s.push(i);
            }
        }
    }
}
 
int main (){
 
    int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
 
    cout << "Vertex: 1 -> " << flush;
    BFS(1, A, 8);
    
    cout << "Vertex: 1 -> " << flush;
    BFS(4, A, 8);
    
    cout << "Vertex: 1 -> " << flush;
    DFS(A, 1, 8);
 
 
    return 0;
}