class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if (tokens.empty()) {
            return 0;
        }

        int curr_score{ 0 };
        int max_score{ 0 };
        ranges::sort(tokens);
        size_t left{ 0 };
        size_t right{ tokens.size() - 1 };

        while (left <= right) {
            if (power >= tokens[left]) {
                power -= tokens[left];
                curr_score += 1;
                max_score = std::max(max_score, curr_score);
                left += 1;
            } else if (left < right && curr_score > 0) {
                power += tokens[right];
                curr_score -= 1;
                right -= 1;
            } else {
                break;
            }
        }

        return max_score;
    }
};
