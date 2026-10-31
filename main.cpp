#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <limits>

using namespace std;

class CampusRouteFinder {
private:

    // Names of campus locations
    vector<string> locations;

    // Adjacency list representation
    vector<vector<int>> adj;

    int V;

public:

    // Constructor
    CampusRouteFinder() {

        locations = {
            "Main Gate",
            "Library",
            "Block 1",
            "Block 2",
            "Cafeteria",
            "Auditorium",
            "Parking",
            "Lab"
        };

        V = locations.size();

        adj.resize(V);

        // Creating campus connections
        addEdge(0, 1);
        addEdge(0, 2);
        addEdge(1, 2);
        addEdge(1, 4);
        addEdge(2, 3);
        addEdge(3, 4);
        addEdge(3, 5);
        addEdge(4, 5);

        // Disconnected component
        addEdge(6, 7);
    }

    // Function to add an undirected edge
    void addEdge(int u, int v) {

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Display all campus locations
    void displayLocations() {

        cout << "\n===== CAMPUS LOCATIONS =====\n";

        for (int i = 0; i < V; i++) {

            cout << i + 1 << ". "
                 << locations[i] << endl;
        }
    }

    // Find index of a location
    int getLocationIndex(string name) {

        for (int i = 0; i < V; i++) {

            if (locations[i] == name) {
                return i;
            }
        }

        return -1;
    }

    // Display graph using adjacency list
    void displayGraph() {

        cout << "\n===== ADJACENCY LIST =====\n";

        for (int i = 0; i < V; i++) {

            cout << locations[i] << " -> ";

            for (int neighbour : adj[i]) {

                cout << locations[neighbour] << " -> ";
            }

            cout << "NULL\n";
        }
    }

    // BFS to find shortest route
    void BFS(int source, int destination) {

        vector<bool> visited(V, false);

        vector<int> parent(V, -1);

        queue<int> q;

        visited[source] = true;

        q.push(source);

        while (!q.empty()) {

            int current = q.front();

            q.pop();

            if (current == destination) {
                break;
            }

            for (int neighbour : adj[current]) {

                if (!visited[neighbour]) {

                    visited[neighbour] = true;

                    parent[neighbour] = current;

                    q.push(neighbour);
                }
            }
        }

        // Check whether destination is reachable
        if (!visited[destination]) {

            cout << "\nNo route exists between "
                 << locations[source] << " and "
                 << locations[destination] << ".\n";

            return;
        }

        // Reconstruct shortest path
        vector<int> path;

        for (int v = destination;
             v != -1;
             v = parent[v]) {

            path.push_back(v);
        }

        reverse(path.begin(), path.end());

        cout << "\n===== SHORTEST ROUTE USING BFS =====\n";

        for (int i = 0; i < path.size(); i++) {

            cout << locations[path[i]];

            if (i != path.size() - 1) {
                cout << " -> ";
            }
        }

        cout << "\nMinimum number of edges: "
             << path.size() - 1 << endl;
    }

    // Recursive DFS function
    void DFSUtil(int current, vector<bool>& visited) {

        visited[current] = true;

        cout << locations[current] << endl;

        for (int neighbour : adj[current]) {

            if (!visited[neighbour]) {

                DFSUtil(neighbour, visited);
            }
        }
    }

    // DFS traversal and disconnected locations
    void DFS(int source) {

        vector<bool> visited(V, false);

        cout << "\n===== DFS TRAVERSAL =====\n";

        DFSUtil(source, visited);

        cout << "\n===== DISCONNECTED LOCATIONS =====\n";

        bool found = false;

        for (int i = 0; i < V; i++) {

            if (!visited[i]) {

                cout << locations[i] << endl;

                found = true;
            }
        }

        if (!found) {

            cout << "No disconnected locations.\n";
        }
    }

    // Display all reachable locations using BFS
    void displayReachable(int source) {

        vector<bool> visited(V, false);

        queue<int> q;

        q.push(source);

        visited[source] = true;

        cout << "\n===== REACHABLE LOCATIONS =====\n";

        while (!q.empty()) {

            int current = q.front();

            q.pop();

            cout << locations[current] << endl;

            for (int neighbour : adj[current]) {

                if (!visited[neighbour]) {

                    visited[neighbour] = true;

                    q.push(neighbour);
                }
            }
        }
    }
};

// Main function
int main() {

    CampusRouteFinder campus;

    int choice;

    string sourceName, destinationName;

    int source, destination;

    do {

        cout << "\n====================================\n";

        cout << "        CAMPUS ROUTE FINDER          \n";

        cout << "====================================\n";

        cout << "1. Display Campus Locations\n";

        cout << "2. Display Graph (Adjacency List)\n";

        cout << "3. Find Shortest Route (BFS)\n";

        cout << "4. Display Reachable Locations\n";

        cout << "5. Display DFS Traversal\n";

        cout << "6. Exit\n";

        cout << "\nEnter your choice: ";

        if (!(cin >> choice)) {

            cout << "Invalid input. Please enter a number.\n";

            return 0;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {

            case 1:

                campus.displayLocations();

                break;

            case 2:

                campus.displayGraph();

                break;

            case 3:

                campus.displayLocations();

                cout << "\nEnter source location: ";

                getline(cin, sourceName);

                cout << "Enter destination location: ";

                getline(cin, destinationName);

                source = campus.getLocationIndex(sourceName);

                destination = campus.getLocationIndex(destinationName);

                if (source == -1 || destination == -1) {

                    cout << "Invalid location name!\n";
                }

                else {

                    campus.BFS(source, destination);
                }

                break;

            case 4:

                campus.displayLocations();

                cout << "\nEnter starting location: ";

                getline(cin, sourceName);

                source = campus.getLocationIndex(sourceName);

                if (source == -1) {

                    cout << "Invalid location name!\n";
                }

                else {

                    campus.displayReachable(source);
                }

                break;

            case 5:

                campus.displayLocations();

                cout << "\nEnter starting location: ";

                getline(cin, sourceName);

                source = campus.getLocationIndex(sourceName);

                if (source == -1) {

                    cout << "Invalid location name!\n";
                }

                else {

                    campus.DFS(source);
                }

                break;

            case 6:

                cout << "\nThank you for using Campus Route Finder!\n";

                break;

            default:

                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}
