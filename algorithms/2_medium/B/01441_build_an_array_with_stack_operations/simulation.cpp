class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        size_t target_index{0};
        const size_t target_len{target.size()};
        int num{1};
        vector<string> res{};

        while (target_index < target_len) {
            res.push_back("Push");

            if (num == target[target_index]) {
                target_index += 1;
            } else {
                res.push_back("Pop");
            }

            num += 1;
        }

        return res;
    }
};
