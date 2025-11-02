class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num==1) {
            return false;
        }

        int sum{1};
        int sq{static_cast<int>(sqrt(num))};

        for (int i{2}; i <= sq; ++i) {
            if (num % i == 0) {
                sum += i;

                if(i != sq){
                    sum += num / i;
                } else if(num / i != i) {
                    sum += num / i;
                }

                if(sum > num) {
                    return false;
                }
            }            
        }

        return sum == num;
    }
};
