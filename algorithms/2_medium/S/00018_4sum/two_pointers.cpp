class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> res{};
        const size_t len{nums.size()};

        if (len < 4) {
            return res;
        }

        const long target_long{static_cast<long>(target)};

        sort(nums.begin(), nums.end());

        size_t first{0};
        while (first < len - 3) {
            if (first > 0 && nums[first] == nums[first - 1]) {
                first += 1;
                continue;
            }

            size_t second{first + 1};
            while (second < len - 2) {
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    second += 1;
                    continue;
                }

                size_t third{second + 1};
                size_t fourth{len - 1};

                while (third < fourth) {
                    long curr_sum{static_cast<long>(nums[first]) +
                                  static_cast<long>(nums[second]) +
                                  static_cast<long>(nums[third]) +
                                  static_cast<long>(nums[fourth])};
                    if (curr_sum == target_long) {

                        res.push_back(vector<int>{nums[first], nums[second], nums[third], nums[fourth]});

                        fourth -= 1;
                        while (third < fourth && nums[fourth] == nums[fourth + 1]) {
                            fourth -= 1;
                        }

                        third += 1;
                        while (third < fourth && nums[third] == nums[third - 1]) {
                            third += 1;
                        }
                    } else if (curr_sum < target) {
                        third += 1;
                    } else {
                        fourth -= 1;
                    }
                }

                second += 1;
            }

            first += 1;
        }

        return res;
    }
};
