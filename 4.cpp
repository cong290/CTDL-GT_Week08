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
    // kiểm tra có đường đi giữa 2 đỉnh không??
    bool isReachable(int vertex_start, int vertex_end);
    // tìm và in ra đường đi giữa 2 đỉnh
    void path_two_vertex(int vertex_start, int vertex_end);

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

// kiểm tra có đường đi giữa 2 đỉnh không??
bool Graph::isReachable(int vertex_start, int vertex_end)
{
    if (vertex_start == vertex_end)
        return true;

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

        // đánh dấu vis đã duyệt qua
        visited[vis] = true;

        // tìm thấy điểm cuối đường đi
        if (vis == vertex_end)
            return true;
          
        // duyệt các đỉnh kề với vis
        for (int i = 0; i < numVertices; i++)
        {
            if (adjMatrix[vis][i] == 1 && !visited[i])
            {
                q.push(i);  // đưa đỉnh chưa được duyệt vào stack
            }
        }
    }

    delete[] visited;

    return false;
}

// tìm và in ra đường đi giữa 2 đỉnh
void Graph::path_two_vertex(int vertex_start, int vertex_end)
{
    if (vertex_start == vertex_end)
    {
        cout << vertex_start << " " << vertex_end;
        return ;
    }
        
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

        // tìm thấy điểm cuối đường đi
        if (vis == vertex_end)
            return ;

        // duyệt các đỉnh kề với vis
        for (int i = 0; i < numVertices; i++)
        {
            if (adjMatrix[vis][i] == 1 && !visited[i])
            {
                q.push(i);  // đưa đỉnh chưa được duyệt vào stack
            }
        }
    }

    delete[] visited;
}

int main()
{
    Graph graph(5);

    graph.add_edge(0, 1);
    graph.add_edge(0, 2);
    graph.add_edge(1, 2);
    graph.add_edge(1, 4);
    graph.add_edge(2, 3);
    graph.add_edge(3, 4);

    graph.Print_matrix();

    if (graph.isReachable(0, 4))
    {
        cout << "Duong di giua 2 dinh la: ";
        graph.path_two_vertex(0, 4);
    }
    else
        cout << "Khong co duong di";

    return 0;
}