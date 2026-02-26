class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        const size_t len{ instructions.size() };
        size_t curr_index{ 0 };
        long long curr_score{ 0 };
        vector<bool> seen(len, false);

        while (curr_index < len && !seen[curr_index]) {
            seen[curr_index] = true;

            if (instructions[curr_index] == "jump") {
                    curr_index = static_cast<size_t>(static_cast<int>(curr_index) + values[curr_index]);
            } else {
                curr_score += static_cast<long long>(values[curr_index]);
                curr_index += 1;
            }
        }

        return curr_score;
    }
};
