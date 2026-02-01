class Solution {
    static bool match_result(const string& q, const string& p) {
        const size_t len_q{ q.size() };
        const size_t len_p{ p.size() };
        size_t i_q{ 0 };
        size_t i_p{ 0 };

        while (i_q < len_q && i_p < len_p) {
            if (q[i_q] == p[i_p]) {
                i_p += 1;
            } else if (q[i_q] >= 'A' && q[i_q] <= 'Z') {
                return false;
            }

            i_q += 1;
        }

        if (i_p != len_p) {
            return false;
        }

        while (i_q < len_q) {
            if (q[i_q] >= 'A' && q[i_q] <= 'Z') {
                return false;
            }

            i_q += 1;
        }

        return true;
    }
public:
    static vector<bool> camelMatch(vector<string>& queries, const string& pattern) {
        const size_t len{ queries.size() };
        vector<bool> res;
        res.reserve(len);

        for (const auto& q : queries) {
            res.push_back(match_result(q, pattern));
        }

        return res;
    }
};
