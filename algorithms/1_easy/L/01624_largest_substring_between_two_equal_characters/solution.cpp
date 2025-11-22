class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        array<pair<int, int>, 26> chars_pos;
        for (auto& p : chars_pos) {
            p.first = -1;
            p.second = -1;
        }

        int max_dis{-1};
        const size_t len{s.size()};

        for (size_t i{0}; i < len; ++i) {
            const size_t chars_pos_index{static_cast<size_t>(s[i] - 'a')};

            if (chars_pos[chars_pos_index].first == -1) {
                chars_pos[chars_pos_index].first = static_cast<int>(i);
            } else {
                chars_pos[chars_pos_index].second = static_cast<int>(i);
                max_dis = std::max(max_dis, chars_pos[chars_pos_index].second - chars_pos[chars_pos_index].first - 1);
            }
        }

        return max_dis;
    }
};
