/**
 * @param {number[]} nums
 * @return {number}
 */

const BITS_COUNT = 32;

const totalHammingDistance = (nums) => {
    const len = nums.length;
    let res = 0;

    for (let shift = 0; shift < BITS_COUNT; shift += 1) {
        const mask = 1 << shift;
        let count = 0;

        for (const num of nums) {
            if ((num & mask) != 0) {
                count += 1;
            }
        }

        res += ((len - count) * count);
    }

    return res;
};
