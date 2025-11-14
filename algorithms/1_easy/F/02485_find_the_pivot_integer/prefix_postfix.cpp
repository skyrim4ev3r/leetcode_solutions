class Solution {
public:
    int pivotInteger(int n) {
        int prefix_sum{(n * (n + 1)) / 2};
        int postfix_sum{n};
        int pivot{n};

        while (pivot > 0 && prefix_sum >= postfix_sum) {
            if (prefix_sum == postfix_sum) {
                return pivot;
            }

            prefix_sum -= pivot;
            postfix_sum += pivot - 1;
            pivot -= 1;
        }

        return -1;
    }
};
