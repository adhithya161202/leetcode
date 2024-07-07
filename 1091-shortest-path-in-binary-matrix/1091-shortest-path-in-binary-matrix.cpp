class Solution {
public:
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1)return -1;

        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>dist(n,vector<int>(m,1e9));
        queue<pair<int,pair<int,int>>>q;
        dist[0][0]=1;
        q.push({1,{0,0}});
        
        vector<pair<int,int>>dir={{-1,1},{0,1},{1,1},{-1,0},{1,0},{-1,-1},{0,-1},{1,-1}};
        while(!q.empty()){
            auto k=q.front();
            q.pop();
            
            int distance=k.first;
            int r=k.second.first;
            int c=k.second.second;
            if(r==n-1 && c ==m-1){
               return dist[r][c];}
            
            for(auto it:dir){
                int nrow= r+ it.first;
                int ncol= c+ it.second;
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0){
                    if(distance +1<dist[nrow][ncol]){
                    dist[nrow][ncol]=1+distance;     
                    q.push({distance+1,{nrow,ncol}});
                    } 
                }
            }     
            
        }
        return -1;
        
        
    }
};
