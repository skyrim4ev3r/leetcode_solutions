\/**
 * @param {number[]} nums
 * @return {number}
 */
const maximumPossibleSize = (nums) => {
    const total_count = nums.length;
    let curr_max = Number.MIN_SAFE_INTEGER;
    let remove_count = 0;

    for (const num of nums) {
        curr_max = Math.max(curr_max, num);

        if (num < curr_max) {
            remove_count += 1;
        }
    }

    return total_count - remove_count;
};
