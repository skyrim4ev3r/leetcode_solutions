/**
 * @param {number[]} p1
 * @param {number[]} p2
 * @param {number[]} p3
 * @param {number[]} p4
 * @return {boolean}
 */

const manhattan_dist = (p1, p2) => {
    return Math.abs(p1[0] - p2[0]) + Math.abs(p1[1] - p2[1]);
}

const is_square = (sides, diags) => {
    return sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3] && diags[0] == diags[1];
}

const validSquare = (p1, p2, p3, p4) => {
    const d12 = manhattan_dist(p1, p2);
    const d13 = manhattan_dist(p1, p3);
    const d14 = manhattan_dist(p1, p4);
    const d23 = manhattan_dist(p2, p3);
    const d24 = manhattan_dist(p2, p4);
    const d34 = manhattan_dist(p3, p4);

    if (d12 == 0 || d13 == 0 || d14 == 0 || d23 == 0 || d24 == 0 || d34 == 0) {
        return false;
    }

    const sides1 = [d12, d13, d24, d34];
    const diags1 = [d14, d23];

    const sides2 = [d12, d14, d23, d34];
    const diags2 = [d13, d24];

    const sides3 = [d13, d14, d23, d24];
    const diags3 = [d13, d24];

    return (
        is_square(sides1, diags1) ||
        is_square(sides2, diags2) ||
        is_square(sides3, diags3)
    )
};
