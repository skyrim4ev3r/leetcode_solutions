class AmountColor {
    constructor(amount, color) {
        this.amount = amount;
        this.color = color;
    }
};

/**
 * @param {number[]} nums
 * @param {number[]} colors
 * @return {number}
 */
const rob = (nums, colors) => {
    const len = nums.length;
    let prev = new AmountColor(0, 0);
    let prev_prev = new AmountColor(0, 0);

    for (let i = 0; i < len; ++i) {
        const amount_to_add = (
            colors[i] == prev.color ? prev_prev.amount : Math.max(prev_prev.amount, prev.amount)
        );

        const curr = new AmountColor(nums[i] + amount_to_add, colors[i]);

        if (prev_prev.amount < prev.amount) {
            prev_prev = prev;
        }

        prev = curr;
    }

    return Math.max(prev.amount, prev_prev.amount);
};
