class Solution {
public:
    int m,n;
    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {1,-1,0,0};

    bool isValid(int x, int y, int m, int n) {
        return x>=0 && x<m && y>=0 && y<n;
    }

    void dfs(int x, int y, int oc, int color, vector<vector<bool>>& visited, vector<vector<int>>& image) {
        visited[x][y] = true;
        image[x][y] = color;

        for(int i=0; i<4; i++) {
            int u = x + dx[i];
            int v = y + dy[i];

            if(isValid(u,v,m,n) && image[u][v] == oc && !visited[u][v]) {
                dfs(u,v,oc,color,visited,image);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        int oc = image[sr][sc];
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        dfs(sr,sc,oc,color,visited,image);

        return image;
    }
};