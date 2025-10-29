class Solution {
public:
    int maxBottlesDrunk(int num_bottles, int num_exchange) {
        int total_drunk = 0;

        while (num_bottles >= num_exchange) {
            total_drunk += num_exchange;
            num_bottles =  num_bottles - num_exchange + 1;
            num_exchange += 1;
        }

        return total_drunk + num_bottles;
    }
};
