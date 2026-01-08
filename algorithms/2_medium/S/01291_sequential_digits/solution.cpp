class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res {};

        for (int i {1}; i < 10; ++i) {
            int curr_num {0};
            int curr_dig {i};

            while (curr_num <= high) {
                if (curr_num >= low) {
                    res.push_back(curr_num);
                }

                if (curr_dig > 9) {
                    break;
                }

                curr_num = curr_num * 10 + curr_dig;
                curr_dig += 1;
            }
        }

        ranges::sort(res);

        return res;
    }
};
