class Solution {
public:
    static int bestClosingTime(const string& customers) {
        const size_t len {customers.size()};
        int curr_penalty {0};
        int min_penalty {0};
        size_t min_penalty_index {0};

        for (size_t i {1}; i <= len; ++i) {
            if (customers[i - 1] == 'N') {
                curr_penalty += 1;
            } else {
                curr_penalty -= 1;
            }

            if (curr_penalty < min_penalty) {
                min_penalty = curr_penalty;
                min_penalty_index = i;
            }
        }

        return static_cast<int>(min_penalty_index);
    }
};
