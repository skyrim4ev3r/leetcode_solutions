class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        array<bool, 128> jewels_map{};

        for (const char &jewel: jewels) {
            jewels_map[static_cast<size_t>(jewel)] = true;
        }

        int count{0};

        for (const char &stone: stones) {
            if (jewels_map[static_cast<size_t>(stone)]) {
                count += 1;
            }
        }

        return count;
    }
};
