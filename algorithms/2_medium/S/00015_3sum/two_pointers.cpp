class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        const size_t len{nums.size()};

        if (nums[len - 1] < 0) {
            return res;
        }

        for (size_t left{0}; left < len - 2; ++left) {
            if (nums[left] > 0) {
                break;
            }

            if (left > 0 && (nums[left] == nums[left - 1] || abs(nums[left]) > nums[len - 1] * 2)) {
                continue;
            }

            size_t right{len - 1};
            size_t mid{left + 1};

            while (mid < right) {
                int sum{nums[left] + nums[mid] + nums[right]};

                if (sum < 0) {
                    mid += 1;
                } else if (sum > 0) {
                    right -= 1;
                } else {
                    res.push_back(vector<int>{nums[left], nums[mid], nums[right]});

                    while (true) {
                        mid += 1;

                        if (mid >= right || nums[mid] != nums[mid - 1]) {
                            break;
                        }
                    }
                }
            }
        }

        return res;
    }
};
