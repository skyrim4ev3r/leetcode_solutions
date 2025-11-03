class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {

        const size_t len{code.size()};

        if (k == 0) {
            return vector<int>(len, 0);
        }

        vector<int> res{};
        res.reserve(len);

        size_t left{0};
        size_t right{0};

        if (k < 0) {
            right = len - 1;
            left = len - static_cast<size_t>(abs(k));
        } else {
            right = static_cast<size_t>(k);
            left = 1;
        }

        int curr_sum = accumulate(code.begin() + left, code.begin() + right + 1, 0);

        for (size_t i{0}; i < len; ++i) {
            res.push_back(curr_sum);

            curr_sum -= code[left];
            left += 1;
            if (left == len) {
                left = 0;
            }

            right += 1;
            if (right == len) {
                right = 0;
            }
            curr_sum += code[right];
        }

        return res;
    }
};
