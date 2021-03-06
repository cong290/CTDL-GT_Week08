#include <iostream>
#include<stack>

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
    cout << endl;
}

// Bài 2: câu a
void Graph::Deep_first_search(int vertex_start)
{
    stack<int> q;
    bool* visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        visited[i] = false;
    }
    //đưa đỉnh đầu tiên vào stack
    q.push(vertex_start);
    // đặt đỉnh đã truy cập bằng true
    visited[vertex_start] = true;
    
    int vis = NULL;
    while (!q.empty())
    {
        do {
            if (q.empty())
                break;

            // lấy một đỉnh ra khỏi stack q để xét
            vis = q.top();
            // xóa đỉnh vừa lấy ra khỏi stack q
            q.pop();
        } while (visited[vis] == true);

        // in ra đỉnh đang xét
        cout << vis << " ";
        
        // đánh dấu vis đã duyệt qua
        visited[vis] = true;

        // duyệt các đỉnh kề với vis
        for (int i = 0; i < numVertices; i++)
        {
            if (adjMatrix[vis][i] == 1 && !visited[i])
            {
                q.push(i);  // đưa đỉnh chưa được duyệt vào stack
            }
        }
    }
    cout << endl;

    delete[] visited;
}
// Bài 2: câu b
// Độ phức tạp về không gian: O(V*V)  (biểu diễn bằng ma trận kề)
// Độ phức tạp về thời gian: O(V+E)

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
    
    cout << "DFS: ";
    graph.Deep_first_search(0);

    return 0;
}