class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> codes{
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
            "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
            "..-","...-",".--","-..-","-.--","--.."
        };
        unordered_set<string> hashset{};

        for (const string& word : words) {
            string tmp{};

            for (const char& ch : word) {
                tmp += codes[static_cast<size_t>(ch -'a')];
            }

            hashset.emplace(tmp);
        }

        return static_cast<int>(hashset.size());
    }
};
