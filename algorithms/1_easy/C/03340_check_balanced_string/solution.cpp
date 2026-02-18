class Solution {
public:
    static bool isBalanced(string num) {
        int32_t balance{ 0 };

        for (int32_t i{ 0 }; const auto& ch : num) {
            if ((i & 1) == 1) {
                balance += static_cast<int32_t>(ch - '0');
            } else {
                balance -= static_cast<int32_t>(ch - '0');
            }

            i += 1;
        }

        return balance == 0;
    }
};
