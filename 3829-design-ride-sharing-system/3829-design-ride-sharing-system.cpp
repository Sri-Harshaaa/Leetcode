class RideSharingSystem {
public:
    queue<int> drivers, riders;
    RideSharingSystem() {}
    
    void addRider(int riderId) {
        riders.push(riderId);
    }
    
    void addDriver(int driverId) {
        drivers.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        vector<int> result;
        if(riders.empty() || drivers.empty()) return {-1,-1};
        int a = drivers.front();
        drivers.pop();
        int b = riders.front();
        riders.pop();
        return {a,b};
    }
    
    void cancelRider(int riderId) {
        int n = riders.size();
        bool found = false;
        for(int i=0; i<n; i++) {
            int a = riders.front();
            riders.pop();
            if(a == riderId && !found) found = true;
            else riders.push(a);
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */