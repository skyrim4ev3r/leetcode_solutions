class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        const size_t len{nums.size()};

        if (len <= 3 || nums[0] >= nums[1] || nums[len - 2] >= nums[len - 1]) {
            return false;
        }

        int change_count{0};
        bool is_increasing{true};

        for (auto it{nums.cbegin() + 1}; it != nums.cend(); ++it) {
            if (change_count > 2 || *it == *(it - 1)) {
                return false;
            }

            if ((*it > *(it - 1)) != is_increasing) {
                is_increasing = !is_increasing;
                change_count += 1;
            }
        }

        return change_count == 2;
    }
};
