class Solution {
public:

    const int N = 1e3+10;
    const int INF = 1e9+10;

    int dijkstra(int src, int n, vector<pair<int,int>> g[]) {
        
        vector<int> vis(N, 0);
        vector<int> dist(N, INF);

        set<pair<int,int>> st;
        st.insert({0, src});
        dist[src] = 0;

        while(!st.empty()) {

            auto node = *st.begin();
            int v = node.second;
            st.erase(st.begin());

            if(vis[v]) continue; // if the node is already visited then continue
            vis[v] = 1; // mark the node as visited before processing its children

            for(auto child : g[v]) {

                int child_v = child.first;
                int wt = child.second;

                if(dist[v] + wt < dist[child_v]) {

                    dist[child_v] = dist[v] + wt;
                    st.insert({dist[child_v], child_v});
                }
            }
        }
        
        int ans = 0;
        for(int i = 1; i <= n; i++){

            if(dist[i] == INF) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<pair<int,int>> g[N]; //make a graph from the vector array

        for(auto vec : times){

            g[vec[0]].push_back({vec[1], vec[2]});
        }

        return dijkstra(k, n, g);
    }
};