/**
 * @param {number[]} nums
 * @param {number} threshold
 * @return {number}
 */

const isPossible = (nums, divisor, threshold) => {
    let sum = 0;

    for (const num of nums) {
        sum += Math.ceil(num / divisor);

        if (sum > threshold) {
            return false;
        }
    }

    return true;
}

const smallestDivisor = (nums, threshold) => {
    let low  = 1;
    let high = Math.max(...nums) + 1;

    while (low <= high) {
        const mid = low + Math.floor( (high - low) / 2 );

        if (isPossible(nums, mid, threshold)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return low;
};
