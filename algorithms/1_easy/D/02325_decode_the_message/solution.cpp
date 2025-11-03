class Solution {
public:
    string decodeMessage(string key, string message) {
        array<char, 26> key_map{};

        char curr_char = 'a';
        for (const char &ch: key) {
            size_t index = (ch - 'a');

            if (ch != ' ' && key_map[index] == 0) {
                key_map[index] = curr_char;
                curr_char += 1;
            }
        }

        string res{};

        for (const char &ch: message) {
            if (ch == ' ') {
                res.push_back(ch);
            } else {
                res.push_back(key_map[static_cast<size_t>(ch - 'a')]);
            }
        }

        return res;
    }
};
