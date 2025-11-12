class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {

        long long curr_time{0};
        long long total_waiting{0};
        const size_t len{customers.size()}; 

        for (const auto &customer: customers) {
            const long long arrive_time{static_cast<long long>(customer[0])};
            const long long order_time{static_cast<long long>(customer[1])};

            if (arrive_time >= curr_time) {
                total_waiting += order_time;
                curr_time = arrive_time + order_time;
            } else {
                long long waiting_time{curr_time - arrive_time};
                total_waiting +=  waiting_time + order_time;
                curr_time += order_time;
            }
        }

        return static_cast<double>(total_waiting) / static_cast<double>(len);
    }
};
