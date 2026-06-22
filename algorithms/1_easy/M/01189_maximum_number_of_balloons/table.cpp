typedef ptrdiff_t isize;
static constexpr isize table_size = 256;

[[nodiscard]] static int max_formations_of(const std::string_view source, const std::string_view target) {
    if (target.empty()) { return 0; }

    isize freqs_source[table_size] = { 0 };
    isize freqs_target[table_size] = { 0 };

    for (const unsigned char ch : source) { freqs_source[ch] += 1; }
    for (const unsigned char ch : target) { freqs_target[ch] += 1; }

    isize result = std::numeric_limits<isize>::max();

    for (isize i = 0; i < table_size; i += 1) {
        if (freqs_target[i] > 0) {
            result = std::min(result, freqs_source[i] / freqs_target[i]);
        }
    }

    assert(result <= std::numeric_limits<int>::max());
    return static_cast<int>(result);
}

class Solution {
public:
    static int maxNumberOfBalloons(const string& text) {
        return max_formations_of(text, "balloon");
    }
};
