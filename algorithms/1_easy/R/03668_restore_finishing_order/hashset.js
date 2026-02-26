/**
 * @param {number[]} order
 * @param {number[]} friends
 * @return {number[]}
 */
const recoverOrder = (order, friends) => {
    const res = [];
    const exact = new Set();

    for (const f of friends) {
        exact.add(f);
    }

    for (const o of order) {
        if (exact.has(o)) {
            res.push(o);
        }
    }

    return res;
};
