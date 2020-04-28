# Dijkstra's Algorithm
Dijkstra's algorithm has many variants but the most common one is to find the shortest paths from the source vertex to all other vertices in the graph.

## Pros:
* It is faster than Bellman's ford Algorithm.

## Cons:
* It gives wrong answer for the graph having **negative weight** edge/edges.

## Algorithm Steps:

* Set all vertices distances = infinity except for the source vertex, set the source distance = 0.
* Push the source vertex in a min-priority queue in the form (distance , vertex), as the comparison in the min-priority queue will be according to vertices distances.
* Pop the vertex with the minimum distance from the priority queue (at first the popped vertex = source).
* Update the distances of the connected vertices to the popped vertex in case of **"current vertex distance + edge weight < next vertex distance"**, then push the vertex
with the new distance to the priority queue.
* If the popped vertex is visited before, just continue without using it.
* Apply the same algorithm again until the priority queue is empty.

## Implementation:

Assume the source vertex =  1.
```c++
#include<bits/stdc++.h>
using namespace std;
const int EDGES = 2e5;
const int NODES = 1e5;
const int MAX = 1e9;
vector<pair<int, int>> v[NODES];  //{edge, distance}
int dis[NODES];

void Dijkstra(int n){
    bool vis[n+1];
    memset(vis, false, sizeof(vis));
    multiset<pair<int, int>>pq; //{distance, edge}, Utilising multiset as priority queue.
    dis[1] = 0;  // Assuming the source vertex is 1.
    pq.insert({0, 1}); //insert the source node with value 0.
    while(pq.size()!=0){
        pair<int, int> p = *pq.begin();
        pq.erase(pq.begin());
        int ver = p.second;
        int d = p.first;
        if (vis[ver]) //Check if popped is visited
        continue;     //If visited than continue with next node
        vis[ver] = true; //If unvisited then mark it as visited and then proccess it.
        for( int i = 0; i < v[ver].size(); i++){
            int edge_wei = v[ver][i].second;
            if (dis[ver] + edge_wei < dis[v[ver][i].first]){
                dis[v[ver][i].first] = dis[ver] + edge_wei;
                pq.insert({dis[v[ver][i].first], v[ver][i].first }); //Inserting only those nodes whose distance get reduced.
                                                                     // So, that the Upcoming iteration will evaluate the distance of its neighbour with its updated distance.
            }
            
        } 


    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    int nodes, edges, start_edge, end_edge, distance;
    cin >> nodes >> edges;
    for(int i = 0; i < edges; i++){
        cin >> start_edge >> end_edge >> distance;
        v[start_edge].push_back({end_edge, distance});
    }
    for(int i = 1; i <= nodes; i++){
        dis[i] = MAX;
    }
    Dijkstra(nodes);
    for(int i = 1; i <= nodes; i++){
        cout <<dis[i]<<"\n";
    }

return 0;
}
```
### Time Complexity:
Time Complexity of Dijkstra's Algorithm is **O(V<sup>2</sup>)** but with min-priority queue it drops down to **O(V+ElogV)**.
