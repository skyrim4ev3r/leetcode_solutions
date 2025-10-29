class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        const size_t len{arr.size()};
        size_t count_zeros{0};

        for (const int &num: arr) {
            if (num == 0) {
                count_zeros++;
            }
        }

        size_t new_index{len - 1 + count_zeros};
        for (size_t index{len - 1}; index < len; --index) {
            if (new_index < len) {
                arr[new_index] = arr[index];
            }

            if (arr[index] == 0) {
                new_index -= 1;
                if (new_index < len) {
                    arr[new_index] = 0;
                }
            }

            new_index -= 1;
        }
    }
};
