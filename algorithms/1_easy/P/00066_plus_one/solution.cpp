class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int carry{1};

        for (auto it{digits.rbegin()}; it != digits.rend(); ++it) {
            *it += carry;
            carry = 0;

            if (*it > 9) {
                *it -= 10;
                carry = 1;
            } 

            if (carry == 0){ 
                break;
            }
        }

        // This case occurs when all digits are 9 (e.g., [9,9,9,9]), 
        // resulting in [0,0,0,0]. We push a 0 and set the first digit to 1.
        if (carry == 1) {
            digits.push_back(0);
            digits[0] = 1;
        }

        return digits;
    }
};
