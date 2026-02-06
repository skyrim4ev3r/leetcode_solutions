class Solution {
public:
    int hIndex(vector<int>& citations) {
        const size_t len{ citations.size() };
        size_t left{ 0 };
        size_t right{ len - 1 };
        int res{ 0 };

        while (left <= right && right < len) {
            const size_t mid{ left + (right - left) / 2 };
            const int least_valid{ static_cast<int>(len - mid) };

            if (citations[mid] >= least_valid) {
                res = least_valid;
                right = mid - 1;
            } else {
                left = mid +1;
            }
        }

        return res;
    }
};
