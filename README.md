# Campus Route Finder Using Graph Algorithms

## Project Overview
Campus Route Finder is a C++ application that helps users explore campus locations and find routes between them using Graph Data Structures and Algorithms.

The project represents campus locations as vertices and paths between locations as edges using an Adjacency List.

## Features
- Represents 8 campus locations using a graph.
- Uses an adjacency list for graph representation.
- Implements Breadth-First Search (BFS).
- Finds the shortest route between two locations in an unweighted graph.
- Implements Depth-First Search (DFS).
- Displays all reachable locations.
- Identifies disconnected locations.
- Provides an interactive, menu-driven interface.

## Technologies Used
- C++
- Data Structures and Algorithms
- Graph
- Adjacency List
- BFS (Breadth-First Search)
- DFS (Depth-First Search)
- Queue and Vector

## Campus Locations
1. Main Gate
2. Library
3. Block 1
4. Block 2
5. Cafeteria
6. Auditorium
7. Parking
8. Lab

## Algorithms and Complexity

| Algorithm | Time Complexity | Space Complexity |
|---|---|---|
| BFS | O(V + E) | O(V) |
| DFS | O(V + E) | O(V) |

Where:
- V = Number of vertices
- E = Number of edges

## How to Run

1. Clone this repository.
2. Open the project folder in VS Code.
3. Compile the C++ source file:

```bash
g++ main.cpp -o campus
```

4. Run the program:

```bash
./campus
```

On Windows PowerShell:

```powershell
.\campus.exe
```

## Test Cases
- Direct route: Main Gate to Library.
- Multi-stop route: Main Gate to Auditorium.
- Unreachable destination: Main Gate to Parking.

## Learning Outcomes
- Understanding graph representation.
- Implementing BFS and DFS.
- Finding shortest paths in unweighted graphs.
- Understanding connected and disconnected components.
- Analyzing time and space complexity.

## Author
Developed as a Data Structures and Algorithms mini-project.

