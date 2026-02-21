const rev_digits = (num) => {
    let rev = 0;
    while (num > 0) {
        rev = rev * 10 + num % 10;
        num = Math.floor(num / 10);
    }
    return rev;
}

/**
 * @param {number[]} nums
 * @return {number}
 */
const minMirrorPairDistance = (nums) => {
    nums.reverse();
    const len = nums.length;
    const seen = new Map();
    let min_abs_diff = Number.MAX_SAFE_INTEGER;

    for (let i = 0; i < len; ++i) {
        const rev = rev_digits(nums[i]);
        if (seen.has(rev)) {
            min_abs_diff = Math.min(min_abs_diff, i - seen.get(rev))
        }
        seen.set(nums[i], i);
    }

    if (min_abs_diff === Number.MAX_SAFE_INTEGER) {
        return -1;
    }

    return min_abs_diff;
};
