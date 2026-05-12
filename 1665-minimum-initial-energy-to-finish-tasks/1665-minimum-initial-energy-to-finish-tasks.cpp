class Solution {
public:
    bool doable(vector<vector<int>>& tasks, int mid) {
        for(auto &task: tasks) {
            int min = task[1];
            int act = task[0];

            if(mid<min) return false;
            mid-=act;
        }
        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();

        int l = 0;
        int r = 1e9;
        int result = INT_MAX;

        auto lambda = [](auto &task1, auto &task2) {
            int diff1 = task1[1]-task1[0];
            int diff2 = task2[1]-task2[0];
            return diff1 > diff2;
        };

        sort(tasks.begin(), tasks.end(), lambda);

        while(l <= r) {
           int mid = l + (r-l)/2;

            if(doable(tasks,mid)) {
                result = mid;
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return result;
    }
};