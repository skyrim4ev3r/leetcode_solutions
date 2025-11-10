class Solution {
public:
    vector<int> decimalRepresentation(int n) {

        int p{1};
        while (n / p >= 10) {
            p *= 10;
        }

        vector<int> res{};

        while (p > 0) {
            const int temp{((n / p) % 10) * p};

            if (temp != 0) {
                res.push_back(temp);
            }

            p /= 10;
        }

        return res;
    }
};
