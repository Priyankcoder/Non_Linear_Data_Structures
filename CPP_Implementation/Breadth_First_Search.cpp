#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{
  int v;
  vector<int> *adj;  //Vector for maintaining adjacency list explained above
  public:
  Graph(int p){
      v = p;
      adj = new vector<int>[v];
  }
  void addedge(int v, int w)
  {
    adj[v].push_back(w);
  
  }
  void bfs(int s){
    
		int level[v]; //To determine the level of each node
		bool vis[v];  //Mark the node if visited  
        queue <int> q;
        q.push(s);
        level[ s ] = 0 ;  //Setting the level of the source node as 0
        vis[ s ] = true;
        while(!q.empty())
        {
            int p = q.front();
            q.pop();
            cout<<p<<"\n";  //print the node
            for(int i = 0;i < adj[ p ].size() ; i++)
            {
                if(vis[ adj[ p ][ i ] ] == false)
                {
            //Setting the level of each node with an increment in the level of parent node
                    level[ adj[ p ][ i ] ] = level[ p ]+1;                 
                     q.push(adj[ p ][ i ]);
                     vis[ adj[ p ][ i ] ] = true;
				}
			
      
			}
			
		}
		for(int i = 0; i<v; ++i)
				cout<<level[i]<<"\n";
    }

};

int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(4); 
    g.addedge(0, 1); 
    g.addedge(0, 2); 
    g.addedge(1, 2); 
    g.addedge(2, 0); 
    g.addedge(2, 3); 
    g.addedge(3, 3); 
  
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 
    g.bfs(2); 
  
    return 0; 
} 
