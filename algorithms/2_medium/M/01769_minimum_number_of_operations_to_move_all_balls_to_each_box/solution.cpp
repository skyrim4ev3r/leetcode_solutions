class Solution {
public:
    vector<int> minOperations(string boxes) {
        const size_t len{boxes.size()};
        vector<int> res(len, 0);
        int sum{0};
        int balls{0};
    
        for (size_t i{0}; i < len; ++i) {
            sum += balls;
            res[i] += sum;

            if (boxes[i] == '1') {
                balls += 1;
            }
        }

        sum = 0;
        balls = 0;
        for (size_t i{len - 1}; i < len; --i) {
            sum += balls;
            res[i] += sum;

            if (boxes[i] == '1') {
                balls += 1;
            }
        }

        return res;
    }
};
