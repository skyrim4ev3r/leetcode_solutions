/**
 * @param {number[]} nums
 * @return {number}
 */
const maxProduct = (nums) => {
    const len = nums.length;
    let left = 0;
    let prod = 1;
    let max_prod = Number.MIN_SAFE_INTEGER;

    for (let right = 0; right < len; right += 1) {
        if (nums[right] == 0) {
            max_prod = Math.max(max_prod, 0);
            left = right + 1;
            prod = 1;
        } else {
            prod *= nums[right];
            max_prod = Math.max(max_prod, prod);

            if (right + 1 == len || nums[right + 1] == 0) {
                while (left < right) {
                    prod /= nums[left];
                    max_prod = Math.max(max_prod, prod);
                    left += 1;
                }
            }
        }
    }

    return max_prod;
};
