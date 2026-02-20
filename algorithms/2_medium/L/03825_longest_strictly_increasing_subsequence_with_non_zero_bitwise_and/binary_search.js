const lowerBound = (arr, value) => {
    let left = 0;
    let right = arr.length;

    while (left <= right) {
        const mid = Math.floor((left + right) / 2);
        if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left;
}

const calc_lis_with_mask = (nums, mask) => {
    const sub = [];

    for (const num of nums) {
        if ((num & mask) == 0) {
            continue;
        }

        const pos = lowerBound(sub, num);
        sub[pos] = num;
    }

    return sub.length;
}

/**
 * @param {number[]} nums
 * @return {number}
 */
const longestSubsequence = (nums) => {
    let longest = 0;
    const MAX_VALID_BIT = 31;

    for (let i = 0; i < MAX_VALID_BIT; ++i) {
        const mask = 1 << i;

        longest = Math.max(longest, calc_lis_with_mask(nums, mask));
    }

    return longest;
};
