class Solution {
public:
    int titleToNumber(string columnTitle) {
        long count{0}, mul{1};//using long to prevent overflow during multiplication and avoid extra conditions or casts.
        char ch_before_A{'A' - 1};

        for(auto it{columnTitle.rbegin()}; it != columnTitle.rend(); ++it) {
            count += static_cast<long>(*it- ch_before_A) * mul;
            mul *= 26;
        }

        return static_cast<int> (count);
    }
};
