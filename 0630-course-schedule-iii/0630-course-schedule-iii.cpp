class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int start_time = 0;
        int count = 0;
        priority_queue<int> pq;
        sort(courses.begin(),courses.end(),[](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        for(int i=0; i<courses.size(); i++) {
            int duration = courses[i][0];
            int end_time = courses[i][1];

            if(start_time + duration <= end_time) {
                start_time+=duration;
                pq.push(duration);
                count++;
            }
            else {
                if(pq.size() == 0) continue;
                int old_duration = pq.top();
                if(old_duration > duration) {
                    pq.pop();
                    start_time-=old_duration;
                    start_time+=duration;
                    pq.push(duration);
                }
            }
        }
        return count;
    }
};