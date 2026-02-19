const VALID_BITS_COUNT = 31;

const get_digits_freqs = (n) => {
    const res = new Array(10).fill(0);

    while (n > 0) {
        res[n % 10] += 1;
        n = Math.floor(n / 10);
    }

    return res;
}

/**
 * @param {number} n
 * @return {boolean}
 */
const reorderedPowerOf2 = (n) => {
    const digits_freqs_n = get_digits_freqs(n);

    for (let i = 0; i < VALID_BITS_COUNT; ++i) {
        const digits_freqs_power_of_two = get_digits_freqs(1 << i);

        if (digits_freqs_power_of_two.every((value, index) => value === digits_freqs_n[index])) {
            return true;
        }
    }

    return false;
};
