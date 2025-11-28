class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> res{};

        for (const string& word : words) {
            istringstream ss{word};
            string part;

            while (std::getline(ss, part, separator)) {
                if (!part.empty()) {
                    res.emplace_back(part);
                }
            }
        }

        return res;
    }
};
