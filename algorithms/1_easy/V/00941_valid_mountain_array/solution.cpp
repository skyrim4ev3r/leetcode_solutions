class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        bool is_increasing{true};
        const size_t arr_len{arr.size()};

        if (arr_len < 3 || arr[1] <= arr[0] || arr[arr_len - 1] >= arr[arr_len - 2]) {
            return false;
        }

        for (size_t i{1}; i < arr_len; ++i) {
            if (is_increasing) {
                if (arr[i] == arr[i - 1]) {
                    return false;
                }

                if (arr[i] < arr[i - 1]) {
                    is_increasing = false;
                }
            } else {
                if (arr[i] >= arr[i - 1]) {
                    return false;
                }
            }
        }

        return true;
    }
};
