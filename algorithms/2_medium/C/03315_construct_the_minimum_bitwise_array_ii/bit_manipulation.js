/**
 * @param {number[]} nums
 * @return {number[]}
 */
const minBitwiseArray = (nums) => {
    const len = nums.length;
    const res = new Array(len).fill(0);

    for (let i = 0; i < len; ++i) {
        const num = nums[i];

        if (num == 2) {
            res[i] = -1; // Special case for prime number 2
        } else {
            let mask = 1;
            // Find the lowest bit that is 0
            while ((num & mask) != 0) {
                mask = mask << 1;
            }
            mask = mask >> 1; // Move back to the last bit that was 1
            res[i] = (num ^ mask); // Toggle that bit
        }
    }

    return res;
};
