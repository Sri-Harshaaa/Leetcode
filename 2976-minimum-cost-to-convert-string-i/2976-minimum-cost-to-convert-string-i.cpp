class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> dist(26, vector<long long>(26, INT_MAX));
        for(int i=0; i<original.size(); i++) {
            int u = original[i]-'a';
            int v = changed[i]-'a';
            long long w = cost[i];
            if(w < dist[u][v]) dist[u][v] = w;
        }

        for(int k=0; k<26; k++) {
            for(int i=0; i<26; i++) {
                for(int j=0; j<26; j++) {
                    if(i==j) {
                        dist[i][j] = 0;
                        continue;
                    }
                    if(dist[i][k]+dist[k][j] < dist[i][j]) dist[i][j] = dist[i][k]+dist[k][j];
                }
            }
        }

        long long min_cost = 0;
        for(int i=0; i<source.size(); i++) {
            int u = source[i]-'a';
            int v = target[i]-'a';
            long long c = dist[u][v];
            if(c == INT_MAX) return -1;
            else min_cost+=c;
        }
        return min_cost;
    }
};