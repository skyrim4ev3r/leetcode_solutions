class Solution {
public:
    static int openLock(const vector<string>& deadends, const string& target) {
        unordered_set invalids(deadends.cbegin(), deadends.cend());
        queue<string> q;
        string first_str{ "0000" };

        if (!invalids.insert(first_str).second) {
            return -1;
        }

        q.push(first_str);
        int turns{ 0 };

        while (!q.empty()) {
            const size_t len{ q.size() };
            for (size_t c{ 0 }; c < len; ++c) {
                const string curr{ q.front() };
                q.pop();

                if (curr == target) {
                    return turns;
                }

                string temp{ curr };

                for (size_t i{ 0 }; i < curr.size(); ++i) {
                    temp[i] = curr[i] == '9' ? '0' : curr[i] + 1;

                    if (invalids.insert(temp).second) {
                        q.push(temp);
                    }

                    temp[i] = curr[i] == '0' ? '9' : curr[i] - 1;

                    if (invalids.insert(temp).second) {
                        q.push(temp);
                    }

                    temp[i] = curr[i];
                }
            }
            turns += 1;
        }

        return -1;
    }
};
