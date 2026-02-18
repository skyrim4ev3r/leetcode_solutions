/**
 * @param {number[]} nums
 * @return {number}
 */
const singleNumber = (nums) => {
    let res = 0;
    const INPUT_BITS = 32;
    const freqs_bits = new Array(INPUT_BITS).fill(0);

    for (const num of nums) {
        for (let i = 0; i < INPUT_BITS; ++i) {
            if ((num & (1 << i)) != 0) {
                freqs_bits[i] += 1;
            }
        }
    }

    for (let i = 0; i < INPUT_BITS; ++i) {
        if (freqs_bits[i] % 3 != 0) {
            res |= (1 << i);
        }
    }

    return res;
};
