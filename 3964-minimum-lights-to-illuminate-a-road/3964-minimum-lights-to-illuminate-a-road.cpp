class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int> light(n+1,0);
        for(int i=0; i<n; i++) {
            if(!lights[i]) continue;
            int l = max(0,i-lights[i]);
            int r = min(n-1,i+lights[i])+1;
            light[l]++;
            light[r]--;
        }
        for(int i=1; i<n+1; i++) {
            light[i]+=light[i-1];
        }
        
        int cnt = 0;

        for(int i=0; i<n; i++) {
            if(light[i]) continue;
            int o = 0;
            while(!light[i] && i<n) {
                light[o] = 1;
                o++;
                i++;
            }
            cnt+=ceil(o/3.0);
        }

        return cnt;
    }
};