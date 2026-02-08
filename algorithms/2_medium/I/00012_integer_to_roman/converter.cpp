class Solution {
public:
    static string intToRoman(int num) {
        size_t steps{ 0 };
        string res{};

        array<array<char, 3>, 4> map_steps {
            array<char, 3>{'I','V','X'},
            {'X','L','C'},
            {'C','D','M'},
            {'M','_','_'}
        };

        while (num > 0) {
            const int rem { num % 10 };
            num /= 10;

            switch (rem) {
                case 1:
                    res.push_back(map_steps[steps][0]);
                    break;
                case 2:
                    res.push_back(map_steps[steps][0]);
                    res.push_back(map_steps[steps][0]);
                    break;
                case 3:
                    res.push_back(map_steps[steps][0]);
                    res.push_back(map_steps[steps][0]);
                    res.push_back(map_steps[steps][0]);
                    break;
                case 4:
                    res.push_back(map_steps[steps][1]);
                    res.push_back(map_steps[steps][0]);
                    break;
                case 5:
                    res.push_back(map_steps[steps][1]);
                    break;
                case 6:
                    res.push_back(map_steps[steps][0]);
                    res.push_back(map_steps[steps][1]);
                    break;
                case 7:
                    res.push_back(map_steps[steps][0]);
                    res.push_back(map_steps[steps][0]);
                    res.push_back(map_steps[steps][1]);
                    break;
                case 8:
                    res.push_back(map_steps[steps][0]);
                    res.push_back(map_steps[steps][0]);
                    res.push_back(map_steps[steps][0]);
                    res.push_back(map_steps[steps][1]);
                    break;
                case 9:
                    res.push_back(map_steps[steps][2]);
                    res.push_back(map_steps[steps][0]);
                    break;
                default:
                    break;
            };

            steps += 1;
        }

        ranges::reverse(res);

        return res;
    }
};
