class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long m = mass;
        sort(asteroids.begin(), asteroids.end());
        for(int i=0; i<asteroids.size(); i++) {
            if(asteroids[i] > m) return false;
            m+=asteroids[i];
        }
        return true;
    }
};