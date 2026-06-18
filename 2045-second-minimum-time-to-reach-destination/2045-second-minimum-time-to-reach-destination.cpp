class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        int e = edges.size();
        vector<vector<int>> adj(n+1);
        for(int i=0; i<e; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> time1(n+1,INT_MAX), time2(n+1,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        time1[1] = 0;
        pq.push({0,1});

        while(!pq.empty()) {
            pair<int,int> p = pq.top();
            pq.pop();
            int t = p.first;
            int u = p.second;
            int s = ((t/change)%2) ? 1 : 0;
            int wait = (s==1) ? (change-(t%change)) : 0;

            if(t > time1[u] && t < time2[u]) time2[u] = t;
              

            for(int& v : adj[u]) {
                int nt = t+wait+time;
                if(nt < time1[v]) {
                    time2[v] = time1[v];
                    time1[v] = t+wait+time;
                    pq.push({time1[v],v});
                }
                else if(nt > time1[v] && nt < time2[v]) {
                    time2[v] = nt;
                    pq.push({nt,v});
                }
            }
        }

        return time2[n];
    }
};