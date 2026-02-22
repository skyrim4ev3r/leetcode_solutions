const countBits = (n) => {
    let count = 0;
    while (n > 0) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

/**
 * @param {number[]} nums
 * @return {boolean}
 */
const canSortArray = (nums) => {
    let currMax = Number.MIN_SAFE_INTEGER;
    let prevMax = Number.MIN_SAFE_INTEGER;

    for (const num of nums) {
        if (countBits(currMax) != countBits(num)) {
            prevMax = currMax;
            currMax = num;
        } else {
            currMax = Math.max(currMax, num);
        }

        if (num < prevMax) {
            return false;
        }
    }

    return true;
};
