class Solution {
    inline int lower_bound(const vector<int>& arr, const int &target) {
        return static_cast<int>(std::lower_bound(arr.begin(), arr.end(), target) - arr.begin());
    }

public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());

        const size_t potions_len{potions.size()};
        vector<int> res;

        for (const int &spell : spells) {
            const long long spell_i64{static_cast<long long>(spell)};
            const long long minSuccessNum{(success + spell_i64 - 1) / spell_i64}; // Its ceiling of success / spell

            if (minSuccessNum > INT32_MAX) {
                res.push_back(0);
            } else {
                const int index{lower_bound(potions, static_cast<int>(minSuccessNum))};
                res.push_back(static_cast<int>(potions_len) - index);
            }
        }

        return res;
    }
};
