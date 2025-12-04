class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int last_p{0};
        int last_g{0};
        int last_m{0};

        int curr_possible_p{0};
        int curr_possible_g{0};
        int curr_possible_m{0};

        const size_t len{garbage.size()};

        for (size_t i{0}; i < len; ++i) {
            int count_p{0};
            int count_g{0};
            int count_m{0};

            if (i > 0) {
                curr_possible_p += travel[i - 1];
                curr_possible_g += travel[i - 1];
                curr_possible_m += travel[i - 1];
            }

            for (const char& ch : garbage[i]) {
                switch (ch) {
                    case 'P':
                        count_p += 1;
                        break;
                    case 'G':
                        count_g += 1;
                        break;
                    default:
                        count_m += 1;
                        break;
                }
            }

            if (count_p > 0) {
                curr_possible_p += count_p;
                last_p = curr_possible_p;
            }

            if (count_g > 0) {
                curr_possible_g += count_g;
                last_g = curr_possible_g;
            }

            if (count_m > 0) {
                curr_possible_m += count_m;
                last_m = curr_possible_m;
            }
        }

        return last_p + last_g + last_m;
    }
};
