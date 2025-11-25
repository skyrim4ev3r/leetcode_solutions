class Solution {
public:
    static string simplifyPath(const string& path) {
        istringstream ss{path};
        vector<string> stack{};
        string part;

        while (std::getline(ss, part, '/')) {
            if (part.empty() || part == ".") {
                continue;
            }

            if (part == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else {
                stack.push_back(move(part));
            }
        }

        string res{"/"};
        const size_t len{stack.size()};

        for (size_t i = 0; i < len; ++i) {
            res += stack[i];

            if (i != len - 1) {
                res.push_back('/');
            }
        }

        return res;
    }
};
