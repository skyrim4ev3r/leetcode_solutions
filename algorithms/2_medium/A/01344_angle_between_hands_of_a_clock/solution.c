double angleClock(int hour, int minutes)
{
    const double m_degree = (double)(minutes * 6);
    const double h_degree = (double)(hour * 30) + (m_degree / 12.0);
    const double diff = fabs(h_degree - m_degree);

    return fmin(diff, 360.0 - diff);
}
