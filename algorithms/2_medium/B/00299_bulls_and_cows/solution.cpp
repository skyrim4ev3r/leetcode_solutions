class Solution {
public:
    string getHint(string secret, string guess) {
        //wg stands for "wrong guess"
        array<int, 10> wg_digit_counts_secret{};
        array<int, 10> wg_digit_counts_guess{};

        int correct_guess_count{0};
        int correct_digit_wrong_pos_count{0};
        const size_t len{secret.size()};

        for (size_t i{0}; i < len; ++i) {
            if (secret[i] == guess[i]) {
                correct_guess_count += 1;
            } else {
                wg_digit_counts_secret[static_cast<size_t>(secret[i] - '0')] += 1;
                wg_digit_counts_guess[static_cast<size_t>(guess[i] - '0')] += 1;
            }
        }

        for (size_t i{0}; i < 10; ++i) {
            correct_digit_wrong_pos_count += min(wg_digit_counts_guess[i],wg_digit_counts_secret[i]);
        }
        
        return  to_string(correct_guess_count) + "A" + to_string(correct_digit_wrong_pos_count) + "B";
    }
};
