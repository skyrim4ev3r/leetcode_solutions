/**
 * @param {number[]} nums
 * @return {number[]}
 */
const majorityElement = (nums) => {
    const min_target_freq = 1 + Math.floor(nums.length / 3);
    let freqs = {};
    let res = [];

    for (const num of nums) {
        freqs[num] = (freqs[num] || 0) + 1;
    }

    Object.entries(freqs).forEach(([val, freq])=> {
        if (freq >= min_target_freq) {
            res.push(parseInt(val, 10));
        }
    });

    return res;
};
