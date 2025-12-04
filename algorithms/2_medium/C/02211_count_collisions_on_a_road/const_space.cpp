class Solution {
public:
    int countCollisions(string directions) {
        int count{0};
        int curr_r{0};
        int curr_s{0};

        for (const char& ch : directions) {
            switch (ch) {
                case 'L':
                    if (curr_r > 0) {
                        count += curr_r + 1;
                        curr_r = 0;
                        curr_s = 1;
                    } else if (curr_s != 0) {
                            count += 1;
                    }
                    break;
                case 'R':
                    curr_r += 1;
                    break;
                case 'S':
                    count += curr_r;
                    curr_r = 0;
                    curr_s = 1;
                    break;
                default:
                    break;
            }
        }

        return count;
    }
};
