class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freqs{};

        for (const int &num: arr) {
            freqs[num] += 1;
        }

        unordered_set<int> freqs_vals_set{};

        for (const auto &it: freqs) {
            if (!freqs_vals_set.insert(it.second).second) {
                return false;
            }
        }

       return true;
    }
};
