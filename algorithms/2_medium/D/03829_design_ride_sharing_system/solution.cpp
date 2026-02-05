class RideSharingSystem {
    queue<int> riders;
    queue<int> drivers;
    unordered_set<int> is_rider_valid;
public:
    RideSharingSystem():
        riders{},
        drivers{},
        is_rider_valid{}
    {}

    void addRider(const int rider_id) {
        riders.push(rider_id);
        is_rider_valid.insert(rider_id);
    }

    void addDriver(const int driver_id) {
        drivers.push(driver_id);
    }

    vector<int> matchDriverWithRider() {
        while (!riders.empty() && !is_rider_valid.contains(riders.front())) {
            riders.pop();
        }

        if (drivers.empty() || riders.empty()) {
            return vector<int>{-1, -1};
        }

        const int rider_id{ riders.front() };
        riders.pop();
        const int driver_id{ drivers.front() };
        drivers.pop();
        is_rider_valid.erase(rider_id);

        return vector<int>{ driver_id, rider_id };
    }

    void cancelRider(const int rider_id) {
        if (is_rider_valid.contains(rider_id)) {
            is_rider_valid.erase(rider_id);
        }
    }
};
