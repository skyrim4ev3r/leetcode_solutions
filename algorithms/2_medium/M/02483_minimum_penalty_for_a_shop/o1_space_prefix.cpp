class Solution {
public:
    static int bestClosingTime(const string& customers) {
        const size_t len {customers.size()};
        int curr_y {static_cast<int>(count(customers.begin(), customers.end(), 'Y'))};
        int curr_n {0};
        int min_penalty {curr_y};
        size_t min_penalty_index {0};

        for (size_t i {1}; i <= len; ++i) {
            if (customers[i - 1] == 'N') {
                curr_n += 1;
            } else {
                curr_y -= 1;
            }

            const int total {curr_y + curr_n};

            if (total < min_penalty) {
                min_penalty = total;
                min_penalty_index = i;
            }
        }

        return static_cast<int>(min_penalty_index);
    }
};
