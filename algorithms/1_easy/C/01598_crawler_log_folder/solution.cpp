class Solution {
public:
    int minOperations(vector<string>& logs) {
        int curr{ 0 };

        for (const auto& log : logs) {
            if (log == "../") {
                curr = curr > 0 ? curr - 1 : 0;
            } else if (log == "./") {
                continue;
            } else {
                curr += 1;
            }
        }

        return curr;
    }
};
