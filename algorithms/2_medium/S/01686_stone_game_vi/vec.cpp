class Solution {
public:
    int stoneGameVI(vector<int>& alice_values, vector<int>& bob_values) {
        const size_t n{ alice_values.size() };
        vector<tuple<int, int, int>> vec;
        vec.reserve(n);

        for (size_t i{ 0 }; i < n; ++i) {
            const int priority{ alice_values[i] + bob_values[i] };
            vec.push_back({priority, alice_values[i], bob_values[i]});
        }

        ranges::sort(vec, [](const auto& a, const auto& b) {
            return std::get<0>(a) > std::get<0>(b);
        });

        bool alice_turn{ true };
        int alice_score{ 0 };
        int bob_score{ 0 };

        for (const auto&[_, alice_value, bob_value] : vec) {
            if (alice_turn) {
                alice_score += alice_value;
            } else {
                bob_score += bob_value;
            }

            alice_turn = !alice_turn;
        }

        if (bob_score > alice_score) {
            return -1;
        } else if (bob_score == alice_score) {
            return 0;
        } else {
            return 1;
        }
    }
};
