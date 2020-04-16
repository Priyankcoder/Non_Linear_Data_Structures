//This is a class based approach to create graph but It is always better to implement graph by declaring visited arr and adjacency list globally in coding question that 
//way you don't need to pass visited arr and adjacency list explicitly in each function to make changes in the graph.

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{
  int v;
  bool *visited;
  vector<int> *adj;  //Vector for maintaining adjacency list explained above
  public:
  Graph(int p){
      v = p;
      adj = new vector<int>[v];
      visited = new bool[v];
  }
  void addedge(int v, int w)
  {
    adj[v].push_back(w); // take both statements for undirected graph and take first statement for directed graph 
    adj[w].push_back(v);
  
  }
  void bfs(int s){
        
		int level[v]; //To determine the level of each node  //Mark the node if visited  
        queue <int> q;
        q.push(s);
        initialize(); // setting all elements of visited bool array = False
        level[ s ] = 0 ;  //Setting the level of the source node as 0
        visited[ s ] = true;
        while(!q.empty())
        {
            int p = q.front();
            q.pop();
            cout<<p<<"\n";  //print the node
            for(int i = 0;i < adj[ p ].size() ; i++)
            {
                if(visited[ adj[ p ][ i ] ] == false)
                {
            //Setting the level of each node with an increment in the level of parent node
                    level[ adj[ p ][ i ] ] = level[ p ]+1;                 
                     q.push(adj[ p ][ i ]);
                     visited[ adj[ p ][ i ] ] = true;
				}
			
      
			}
			
		}
		for(int i = 0; i<v; ++i)
				cout<<level[i]<<"\n";
    }
    
   void dfs(int s){
	   
	   visited[s] = true;
	   //cout<<s<<"\n";      // print the traversed vertex 
	   for(int i = 0; i < adj[s].size(); i++)
	   {
		   if (visited[adj[s][i]] == false)
		   {
                dfs(adj[s][i]);	    
		    }
		}
     }
  
  void initialize() {
         for(int i = 0;i < v;++i)
            visited[i] = false;
    }
  void connectedcomponents()
  {
	int connectedComponents;for(int i = 1; i<=v; ++i)
	// {
	// 	if (visited[i] == false)
	// 	   total += 1;
		   
	// }
	initialize(); 
	for(int i = 0;i < v;++i) {
         if(visited[i] == false)     {
             dfs(i);
             connectedComponents++;
         }
        }
        cout << "Number of connected components: " << connectedComponents << endl;  
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
    g.dfs(2); 
    g.connectedcomponents();
  
    return 0; 
} 
