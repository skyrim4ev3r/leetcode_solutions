class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> freqs;

        for (const char &ch: s) {
            freqs[ch] += 1;
        }

        for (const char ch : t) {
            auto it = freqs.find(ch);
            if (it != freqs.end()) {
                it->second -= 1;
                if (it->second < 0) {
                    return false;
                }
            } else {
                return false;
            }
        }

        return true;
    }
};
