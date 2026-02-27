const is_valid = (nums, max_valid_sum, k) => {
    let curr_sum = 0;
    let count = 0;

    for (const num of nums) {
        if (curr_sum + num <= max_valid_sum) {
            curr_sum += num;
        } else {
            curr_sum = num;
            count += 1;

            if (count === k) {
                return false;
            }
        }
    }

    return true;
}

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
const splitArray = (nums, k) => {
    let high = nums.reduce((acc, n) => acc + n, 0);
    let low = Math.max(...nums);

    while (low <= high) {
        const mid = low + Math.floor((high - low) / 2);

        if (is_valid(nums, mid, k)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return low;
};
