class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int zeros{static_cast<int>(count(students.begin(), students.end(), 0))};
        int ones{static_cast<int>(students.size()) - zeros};

        for (const int& sandwich : sandwiches) {
            if (sandwich == 1) {
                if (ones > 0) {
                    ones -= 1;
                } else {
                    break;
                }
            } else if (sandwich == 0) {
                if (zeros > 0) {
                    zeros -= 1;
                } else {
                    break;
                }
            }
        }

        return ones + zeros;
    }
};
