#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge 
{
    int u, v, weight;
    bool operator<(Edge const& other) 
    {
        return weight < other.weight;
    }
};

int find_set(int v, vector<int>& parent) 
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v], parent);
}

void union_sets(int a, int b, vector<int>& parent, vector<int>& rank) 
{
    a = find_set(a, parent);
    b = find_set(b, parent);
    if (a != b) 
    { 
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    } 
}

void kruskalMST(vector<Edge>& edges, int max_vertex) 
{
    sort(edges.begin(), edges.end());
    vector<int> parent(max_vertex + 1); // Adjusting size for 1-based indexing
    vector<int> rank(max_vertex + 1, 0); 
    for (int i = 0; i <= max_vertex; i++)
        parent[i] = i;

    int total_weight = 0;  
    vector<Edge> result;

    for (Edge e : edges) 
    {
        if (find_set(e.u, parent) != find_set(e.v, parent)) 
        {
            total_weight += e.weight;
            result.push_back(e);
            union_sets(e.u, e.v, parent, rank);
        }
    }

    cout << "Total weight of the MST: " << total_weight << endl;
    cout << "Edges in the MST:" << endl;
    for (Edge e : result) 
    {
        cout << e.u << " - " << e.v << " : " << e.weight << endl;
    }
}

void displayGraph(vector<Edge>& edges) 
{
    cout << "Graph edges (u, v, weight):" << endl;
    for (Edge e : edges) 
    {
        cout << e.u << " - " << e.v << " : " << e.weight << endl;
    }
}

int main() 
{
    int choice;
    vector<Edge> edges;
    int n, m, max_vertex = 0;

    do 
    {
        cout << "\nMenu:\n";
        cout << "1. Input Graph\n";
        cout << "2. Display Graph\n";
        cout << "3. Find MST using Kruskal's Algorithm\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1: 
            {
                cout << "Enter number of edges: ";
                cin >> m;
                edges.clear();
                cout << "Enter the edges (u v weight):" << endl;
                for (int i = 0; i < m; i++) 
                {
                    Edge edge;
                    cin >> edge.u >> edge.v >> edge.weight;
                    edges.push_back(edge);
                    max_vertex = max(max_vertex, max(edge.u, edge.v));  
                }
                break;
            }
            case 2: 
            {
                if (edges.empty()) 
                {
                    cout << "Graph is empty. Please input the graph first." << endl;
                } 
                else 
                {
                    displayGraph(edges);
                }
                break;
            }
            case 3: 
            {
                if (edges.empty()) 
                {
                    cout << "Graph is empty. Please input the graph first." << endl;
                } 
                else 
                {
                    kruskalMST(edges, max_vertex);
                }
                break;
            }
            case 4: 
            {
                cout << "Exiting program." << endl;
                break;
            }
            default: 
            {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    } while (choice != 4);

    return 0;
}
 

                