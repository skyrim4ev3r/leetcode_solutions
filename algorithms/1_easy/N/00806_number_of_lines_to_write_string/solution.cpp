const int MAX_WIDTH{100};

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines_count{1};
        int curr_width{0};

        for (const char& ch : s) {
            int char_width{widths[static_cast<size_t>(ch - 'a')]};

            if (curr_width + char_width <= MAX_WIDTH) {
                curr_width += char_width;
            } else {
                lines_count += 1;
                curr_width = char_width;
            }
        }

        return vector<int>{lines_count, curr_width};
    }
};
