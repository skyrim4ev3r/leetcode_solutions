class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        const size_t len{events.size()};
        int max_duration{events[0][1]};
        int pressed_btn{events[0][0]};

        for (size_t i{1}; i < len; ++i) {
            int curr_duration{events[i][1] - events[i - 1][1]};
            int curr_btn{events[i][0]};

            if (curr_duration > max_duration) {
                max_duration = curr_duration;
                pressed_btn = curr_btn;
            } else if (curr_duration == max_duration) {
                pressed_btn = std::min(pressed_btn, curr_btn);
            }
        }

        return pressed_btn;
    }
};
