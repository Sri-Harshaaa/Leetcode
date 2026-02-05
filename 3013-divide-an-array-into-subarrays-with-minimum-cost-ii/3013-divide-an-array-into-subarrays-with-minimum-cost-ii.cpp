class Solution {
public:
    priority_queue<long long> left;
    priority_queue<long long, vector<long long>, greater<long long>> right;
    unordered_map<long long,int> mpp;
    long long curr_sum = 0, left_size = 0,K;

    void remove(long long x) {
        clean();
        mpp[x]++;
        if(x <= left.top()) {
            left_size--;
            curr_sum-=x;
        }
        clean();
    }

    void add(long long y) {
        if(y <= left.top()) {
            curr_sum+=y;
            left_size++;
            left.push(y);
        }
        else right.push(y);
    }

    void balance() {
        while(left_size > K) {
            clean();
            long long a = left.top();
            left_size--;
            curr_sum-=a;
            left.pop();
            right.push(a);
        }
        while(left_size < K && right.size()>0) {
            clean();
            long long b = right.top();
            right.pop();
            left_size++;
            curr_sum+=b;
            left.push(b);
        }
    }

    void clean() {
        while(!left.empty() && mpp[left.top()] != 0) {
            long long u = left.top();
            left.pop();
            mpp[u]--;
        }

        while(!right.empty() && mpp[right.top()] != 0) {
            long long v = right.top();
            right.pop();
            mpp[v]--;
        }
    }

    long long minimumCost(vector<int>& nums, int k, int dist) {
        K = k-1;
        int n = nums.size();

        for(int i=1; i<=dist+1; i++) {
            long long a = nums[i];
            if(left.empty() || a<= left.top()) {
                left.push(a);
                left_size++;
                curr_sum+=a;
            }
            else {
                right.push(a);
            }

            if(left.size() > k-1) {
                long long b = left.top();
                left.pop();
                left_size--;
                curr_sum-=b;
                right.push(b);
            }
            else if(left.size() < k-1 && right.size() > 0) {
                long long c = right.top();
                right.pop();
                curr_sum+=c;
                left.push(c);
                left_size++;
            }
        }

        int i = 1, j = i+dist+1;
        long long ans = curr_sum;
        while(j<n) {
            long long x = nums[i], y = nums[j];
            remove(x);
            add(y);
            balance();
            ans = min(ans,curr_sum);
            i++;
            j++;
        }
        return ans+nums[0];
    }
};