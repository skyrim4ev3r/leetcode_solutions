class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        m_degree = minutes * 6.0
        h_degree = (hour * 30.0) + (m_degree / 12.0)
        diff = abs(h_degree - m_degree)

        return min(diff, 360.0 - diff)
