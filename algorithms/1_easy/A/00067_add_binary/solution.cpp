class Solution {
public:
    string addBinary(string a, string b) {
        char carry{0};

        if (a.size() < b.size()) {
            std::swap(a, b);
        }

        size_t a_len{a.size()};

        for (size_t i{a_len - 1}; i < a_len; --i) {
            char b_char{'0'};

            if (!b.empty()) {
                b_char = b.back();
                b.pop_back();
            }

            char bit_sum = (a[i] - '0') + (b_char - '0') + carry;
            carry = 0;
            if (bit_sum > 1) {
                bit_sum -= 2;
                carry = 1;
            }

            a[i] = bit_sum + '0';

            if (carry == 0 && b.empty()) {
                break;
            }
        }

        if (carry == 1) {
            a.insert(a.begin(), '1');
        }

        return a;
    }
};
