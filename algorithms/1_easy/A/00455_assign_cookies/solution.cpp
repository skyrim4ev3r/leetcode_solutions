class Solution {
public:
    static int findContentChildren(vector<int>& g, vector<int>& s) {
        ranges::sort(g);
        ranges::sort(s);

        const size_t len_g{ g.size() };
        const size_t len_s{ s.size() };
        int32_t count{ 0 };
        size_t index_g{ 0 };
        size_t index_s{ 0 };

        while (index_s < len_s && index_g < len_g) {
            if (g[index_g] <= s[index_s]) {
                count += 1;
                index_g += 1;
            }

            index_s += 1;
        }

        return count;
    }
};
