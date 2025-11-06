class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        const int min_bulky_len{10'000};
        const long long min_bulky_volume{1'000'000'000};
        const int min_heavy_mass{100};

        bool is_bulky{false};
        bool is_heavy{false};

        long long volume{(static_cast<long long>(length)) * (static_cast<long long>(width)) * (static_cast<long long>(height))};

        if  (length >= min_bulky_len || width >= min_bulky_len 
            || height >= min_bulky_len || volume >= min_bulky_volume)
        {
            is_bulky = true;
        }

        if (mass >= min_heavy_mass) {
            is_heavy = true;
        }

        if (is_bulky && is_heavy) {
            return "Both";
        } else if (is_bulky) {
            return "Bulky";
        } else if (is_heavy) {
            return "Heavy";
        } else {
            return "Neither";
        }
    }
};
