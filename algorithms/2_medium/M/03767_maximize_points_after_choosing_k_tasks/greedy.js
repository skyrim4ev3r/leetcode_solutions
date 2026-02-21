/**
 * @param {number[]} technique1
 * @param {number[]} technique2
 * @param {number} k
 * @return {number}
 */
const maxPoints = (technique1, technique2, k) => {
    const sum_tech2 = technique2.reduce((acc, x) => acc + x, 0);
    const diff = technique1.map((t1, index) => t1 - technique2[index]);
    diff.sort((a, b) => b - a);
    const forced_to_pick = diff.slice(0, k).reduce((acc, x) => acc + x, 0);
    const pick_if_good = diff.slice(k).reduce((acc, x) => acc + Math.max(x, 0), 0);

    return sum_tech2 + forced_to_pick + pick_if_good;
};
