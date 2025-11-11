class Solution {
public:
    string removeOccurrences(string s, string part) {
        const size_t part_len{part.size()};

        size_t pos{s.find(part)};
        while (pos != std::string::npos) {
            s = s.substr(0, pos) + s.substr(pos + part_len);
            pos = s.find(part);
        }

        return s;
    }
};
