class Solution {
public:
    double angleClock(int hour, int minutes) {
        const double m_degree = static_cast<double>(minutes * 6);
        const double h_degree = static_cast<double>(hour * 30) + (m_degree / 12.0);
        const double diff = abs(h_degree - m_degree);

        return std::min(diff, 360.0 - diff);
    }
};
