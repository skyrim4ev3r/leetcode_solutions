class Solution {
public:
    string defangIPaddr(string address) {
        string res = "";

        for (const char &ch: address) {
            if (ch == '.') {
                res += "[.]";
            } else {
                res.push_back(ch);
            }
        }

        return res;
    }
};
