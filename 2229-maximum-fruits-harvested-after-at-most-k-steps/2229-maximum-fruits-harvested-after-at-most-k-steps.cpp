class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size(),ans=0,x=0,y=0,z=0,w=0;
        unordered_map<int,int> mpp;
        for(int i=0; i<n; i++) mpp[fruits[i][0]] = fruits[i][1];
        for(int i=max(0,(startPos-k)); i<=startPos; i++) x+=mpp[i];
        for(int i=startPos; i<=startPos+k; i++) y+=mpp[i];
        ans = max(x,y);
        if(ans==0) return 0;
        else {
            int l = max(0,startPos-(k/2));
            int h = l+ k-abs(startPos-l);
            for(int i=l; i<=h; i++) z+=mpp[i];
            ans = max(ans,z);
            while(l<startPos) {
                z-=mpp[l];
                l++;
                int temp=h;
                h = l+ k-abs(startPos-l);
                for(int i=temp+1; i<=h; i++) z+=mpp[i];
                ans = max(ans,z);
            }

            int b = startPos+k/2;
            int a = b - (k-abs(startPos-b));
            for(int i=a; i<=b; i++) w+=mpp[i];
            ans = max(ans,w);
            while(b>startPos) {
                w-=mpp[b];
                b--;
                int s = a;
                a = b - (k-abs(startPos-b));
                for(int i=a; i<s; i++) w+=mpp[i];
                ans = max(ans,w);
            } 
        }
        return ans;
    }
};