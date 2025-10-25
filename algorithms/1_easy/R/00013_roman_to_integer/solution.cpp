class Solution {
public:
    int romanToInt(string s) {

        int sum{0};
        int curr_max{0};

        for (auto it{s.rbegin()}; it != s.rend(); ++it) {

            int curr_num = 0;

            switch (*it) {
                case 'I':
                    curr_num = 1;
                    break;
                case 'V':
                    curr_num = 5;
                    break;
                case 'X':
                    curr_num = 10;
                    break;
                case 'L':
                    curr_num = 50;
                    break;
                case 'C':
                    curr_num = 100;
                    break;
                case 'D':
                    curr_num = 500;
                    break;
                case 'M':
                    curr_num = 1000;
                    break;
                default:
                    break;
            };

            if (curr_num >= curr_max) {
                sum += curr_num;
                curr_max = curr_num;
            } else {
                sum -= curr_num;
            }
        }

        return sum;
    }
};
