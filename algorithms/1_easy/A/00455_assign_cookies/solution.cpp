class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count{0};
        const size_t g_len{g.size()};
        const size_t s_len{s.size()};

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        for(size_t i{0}, j{0}; i < s_len && j < g_len; ++i) { 
            if(g[j] <= s[i]) {
                ++count;
                ++j;
            }
        }

        return count;
    }
};
