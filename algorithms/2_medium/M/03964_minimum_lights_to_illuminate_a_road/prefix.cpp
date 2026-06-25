typedef ptrdiff_t isize;

class Solution {
public:
    static int minLights(const vector<int>& lights) {
        const isize n = std::ssize(lights);
        auto prefix = vector<int>(n + 3, 0);

        for (isize i = 0; i < n; i += 1) {
            const int light = lights[i];
            if (light > 0) {
                const isize lo = std::max(i - light, 0z);
                const isize hi = std::min(i + light + 1, n);
                prefix[lo] += 1;
                prefix[hi] -= 1;
            }
        }

        int sum = 0;
        int cnt_need = 0;
        for (isize i = 0; i < n; i += 1) {
            sum += prefix[i];
            if (sum == 0) {
                sum += 1;
                cnt_need += 1;
                prefix[i + 3] -= 1;
            }
        }

        return cnt_need;
    }
};
