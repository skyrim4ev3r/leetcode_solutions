class Solution {
    static inline vector<int> get_digits(int num) {
        vector<int> digits;
        digits.reserve(9);
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
        ranges::reverse(digits);
        return digits;
    }

    static inline int construct_number_from_digits(const vector<int>& digits) {
        int res{ 0 };

        for (const auto& d : digits) {
            res = res * 10 + d;
        }

        return res;
    }
public:
    static int maximumSwap(const int num) {
        vector<int> digits{ get_digits(num) };
        auto digits_sort{ digits };
        ranges::sort(digits_sort, std::greater<>());

        const size_t len{ digits.size() };
        size_t left{ 0 };

        while (left < len && digits[left] == digits_sort[left]) {
            left += 1;
        }

        if (left == len) {
            return num;
        }

        size_t right{ len - 1};
        while (digits[right] != digits_sort[left]) {
            right -= 1;
        }

        const int temp{ digits[left] };
        digits[left] = digits[right];
        digits[right] = temp;

        return construct_number_from_digits(digits);
    }
};
