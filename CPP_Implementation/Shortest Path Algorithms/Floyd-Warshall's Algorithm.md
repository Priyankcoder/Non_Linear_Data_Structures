# Floyd–Warshall's Algorithm
Floyd–Warshall's Algorithm is used to find the shortest paths between all pairs of vertices in a graph, where each edge in the graph has a weight which is positive or negative. It can be implemented by **DP**.The biggest advantage of using this algorithm is that all the shortest distances between any 2 vertices could be calculated in **O(V<sup>3</sup>)**, where **V** is the number of vertices in a graph.
## Advantages
* It is **better than Bellman's Ford Algorithm** because it calculates distance between all pairs of nodes in a graph in the same time as Bellman's Ford Algorithm takes to calculate distance from a source node to every other node.

## Implementation
```c++
#include<bits/stdc++.h>
using namespace std;
const int NODES = 1e5;
const int MAX = 2e5;
int main(){

int nodes, edges, start_node, end_node, dist;

cin >> nodes >> edges;                 //Take Input
int dis[nodes+2][nodes+2];            //stores distance b/w two nodes
for(int i = 1; i <= nodes; i++){     //Initialize distances by infinity(large value)
    for(int j = 1; j <= nodes; j++){
        dis[i][j] = MAX;
    }
}
for(int i = 0; i < edges; i++){

    cin >> start_node >> end_node >> dist;
    
    dis[start_node][end_node] = dist;

    
}

for(int k = 1; k <= nodes; k++){
    for(int i = 1; i <= nodes; i++){
        for(int j = 1; j <= nodes; j++){
            dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
        }
    }
}
for(int k = 1; k <= nodes; k++){
    for(int i = 1; i <= nodes; i++){
        if ( k == i)
        continue;
    cout<<"Shortest distance between "<< k << " and "<< i <<" is "<< dis[k][i] << "\n";
    }
}

return 0;
}

```
## Time Complexity
Time Complexity of Floyd–Warshall's Algorithm is **O(V<sup>3</sup>)**, where **V** is the number of vertices in a graph.

