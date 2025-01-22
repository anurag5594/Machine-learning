#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <limits>

using namespace std;


class Graph 
{
  map<string, vector<pair<string, int>>> adjList;
public:
    
    void addEdge(const string& cityA, const string& cityB, int cost) 
    {
        adjList[cityA].push_back({cityB, cost});
        adjList[cityB].push_back({cityA, cost});  
    }
    void DFS(const string& city, set<string>& visited) 
    { 
        visited.insert(city);
        for (auto neighbor : adjList[city]) 
        {
            if (visited.find(neighbor.first) == visited.end()) 
            {
                DFS(neighbor.first, visited);
            }
        }
    }


    bool isConnected() 
    {
        if (adjList.empty()) return true; 

        set<string> visited;
        string startCity = adjList.begin()->first;
        DFS(startCity, visited);

    
        return visited.size() == adjList.size();
    }

    void displayGraph() 
    {
        if (adjList.empty()) 
        {
            cout << "No flights available." << endl;
            return;
        }
        for (auto city : adjList) 
        {
            cout << city.first << " -> ";
            for (auto neighbor : city.second) 
            {
                cout << "(" << neighbor.first << ", cost: " << neighbor.second << ") ";
            }
            cout << endl;
        }
    }
};

bool isValidCityName(const string& city) 
{
    return !city.empty();
}
bool isValidCost(int cost) 
{
    return cost >= 0;
}
string readCityName() 
{
    string city;
    do 
    {
        cout << "Enter city name: ";
        cin >> ws;
        getline(cin, city);
        if (!isValidCityName(city)) 
        {
            cout << "Invalid input. City name cannot be empty. Please try again." << endl;
        }
    } 
    while (!isValidCityName(city));
    return city;
}

int readCost() 
{
    int cost;
    while (true) 
    {
        cout << "Enter cost (time or fuel): ";
        cin >> cost;
        if (cin.fail() || !isValidCost(cost)) 
        {
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Cost must be a non-negative integer. Please try again." << endl;
        } else 
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break; 
        }
    }
    return cost;
}

int main() 
{
    Graph flightGraph;
    int choice;
    
    do 
    {
        cout << "\n--- Flight Path Management ---\n";
        cout << "1. Add Flight\n";
        cout << "2. Display Flights\n";
        cout << "3. Check Connectivity\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1: 
            {
                string cityA = readCityName();
                string cityB = readCityName();
                int cost = readCost();
                flightGraph.addEdge(cityA, cityB, cost);
                cout << "Flight from " << cityA << " to " << cityB << " added successfully!" << endl;
                break;
            }
            case 2:
                cout << "\nFlight Paths Graph (Adjacency List Representation):\n";
                flightGraph.displayGraph();
                break;
            case 3:
                if (flightGraph.isConnected()) 
                {
                    cout << "The graph is connected, i.e., all cities are reachable from each other." << endl;
                } 
                else 
                {
                    cout << "The graph is not connected, i.e., there are isolated cities." << endl;
                }
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return ; 
    
}
                                                                                                                                                                                                                                                                                                                   