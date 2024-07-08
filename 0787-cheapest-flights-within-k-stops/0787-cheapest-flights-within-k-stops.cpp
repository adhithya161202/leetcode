class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto i :flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector<int>dis(n,1e9);
        dis[src]=0;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});

        while(!q.empty()){
            auto it =q.front();
            int stop=it.first;
            int node=it.second.first;
            int wt=it.second.second;
            q.pop();

            if(stop>k)continue;
            for(auto s:adj[node]){
                int adjnode=s.first;
                int adjwt=s.second;

                if(adjwt + wt < dis[adjnode] && stop<=k){
                    dis[adjnode]=wt+adjwt;

                    q.push({stop+1,{adjnode,wt+adjwt}});
                }
            }
        }
        if(dis[dst]==1e9)return -1;

        return dis[dst];

    }
};