
// Problem: https://practice.geeksforgeeks.org/problems/number-of-provinces/1
class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
    	
    	// visited is for keeping track of already visited
	// vertex to remove redunduncy and avoid permanent loop
        vector<bool> visited(V,false);
        int provinces = 0;
        
        // traverse each vertex in graph
        for(int i=0;i<V;i++){
            //if vertex is visited, skip
            if(visited[i])continue;
            provinces++;
            
            //the algroithm below is a simple dfs
            queue<int> q;
            q.push(i);
            visited[i]==true;
            while(!q.empty()){
                vector<int>& cur = adj[q.front()];
                q.pop();
                for(int v=0;v<V;v++){
                    if(cur[v] && !visited[v]){
                        q.push(v);
                        visited[v]=true;
                    }
                }
            }
        }
        
        return provinces;
    }
};
