class Solution {
public:
    int compareVersion(std::string version1, std::string version2) {
        stringstream parts1(version1), parts2(version2);
        string part1, part2;

        while (parts1.good() || parts2.good()) {
            int num1{0};
            int num2{0};

            if (parts1.good()) {
                getline(parts1, part1, '.');
                num1 = stoi(part1);
            }

            if (parts2.good()) {
                getline(parts2, part2, '.');
                num2 = stoi(part2);
            }

            if (num1 > num2) {
                return 1;
            } else if (num1 < num2) {
                return -1;
            }
        }

        return 0;
    }
};
