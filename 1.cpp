#include <iostream>

using namespace std;

class Graph {
private:
    bool** adjMatrix;
    int numVertices;

public:
    // khởi tạo ma trận có tất cả phần tử bằng 0
    Graph(int numVertices) {
        this->numVertices = numVertices;
        adjMatrix = new bool* [numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjMatrix[i] = new bool[numVertices];
            for (int j = 0; j < numVertices; j++)
                adjMatrix[i][j] = false;
        }
    }
    // thêm đỉnh
    void add_edge(int u, int v);
    // in ra ma trận 
    void Print_matrix();

    //DFS
    void Deep_first_search(int vertex_start);

    ~Graph() {
        for (int i = 0; i < numVertices; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }
};

void Graph::add_edge(int u, int v) {
    adjMatrix[u][v] = true;
}

void Graph::Print_matrix() {
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++)
            cout << adjMatrix[i][j] << " ";
        cout << "\n";
    }
}

int main()
{
    Graph graph(5);

    graph.add_edge(0, 1);
    graph.add_edge(0, 2);
    graph.add_edge(0, 3);
    graph.add_edge(1, 3);
    graph.add_edge(1, 4);
    graph.add_edge(2, 4);

    graph.Print_matrix();

    return 0;
}