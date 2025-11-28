class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int min{-1};
        const size_t len{nums.size()};
        unordered_map<int, array<int, 3>> datas{};

        for (size_t i{0}; i < len; ++i) {
            auto& num_data = datas[nums[i]];
            if (num_data[0] == 0 && num_data[1] == 0 && num_data[2] == 0) {
                num_data[0] = -1;
                num_data[1] = -1;
                num_data[2] = -1;
            }

            if (num_data[0] == -1) {
                num_data[0] = static_cast<int>(i);
            } else if (num_data[1] == -1) {
                num_data[1] = static_cast<int>(i);
            } else {
                if (num_data[2] == -1) {
                    num_data[2] = static_cast<int>(i);
                } else {
                    num_data[0] = num_data[1];
                    num_data[1] = num_data[2];
                    num_data[2] = static_cast<int>(i);
                }

                int curr_distance = (num_data[2] - num_data[0]) * 2;

                if (min == -1 || min > curr_distance) {
                    min = curr_distance;
                }
            }
        }

        return min;
    }
};
