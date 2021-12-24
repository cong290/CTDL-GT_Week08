#include <iostream>
#include<queue>

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
    void Breadth_first_search(int vertex_start);

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

// Bài 3: câu a
void Graph::Breadth_first_search(int vertex_start)
{
    queue<int> q;
    bool* visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        visited[i] = false;
    }
    //đưa đỉnh đầu tiên vào queue
    q.push(vertex_start);
    // đặt đỉnh đã truy cập bằng true
    visited[vertex_start] = true;

    int vis = NULL;
    while (!q.empty())
    {
        do {
            if (q.empty())
                break;

            // lấy một đỉnh ra khỏi queue q để xét
            vis = q.front();
            // xóa đỉnh vừa lấy ra khỏi queue q
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
                q.push(i);  // đưa đỉnh chưa được duyệt vào queue
            }
        }
    }
    cout << endl;

    delete[] visited;
}
// Bài 3: câu b
// Độ phức tạp về không gian: O(V*V)  (biểu diễn bằng ma trận kề)
// Độ phức tạp về thời gian: O(V+E)

int main()
{
    Graph graph(8);
    graph.add_edge(0, 1);
    graph.add_edge(0, 2);
    graph.add_edge(1, 2);
    graph.add_edge(1, 3);
    graph.add_edge(2, 3);
    graph.add_edge(2, 5);
    graph.add_edge(3, 4);
    graph.add_edge(7, 6);

    graph.Print_matrix();
    cout <<"BFS: ";
    graph.Breadth_first_search(0);

    return 0;
}