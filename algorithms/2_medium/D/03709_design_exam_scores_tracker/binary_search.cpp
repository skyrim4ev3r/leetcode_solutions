bool compare_pairs(const pair<int, long>& a, const pair<int, long>& b) {
    return a.first < b.first;
}

class ExamTracker {
    vector<pair<int, long>> time_score;
public:
    ExamTracker() : time_score{vector<pair<int, long>>{make_pair(0, 0L)}} {}

    void record(int time, int score) {
        long sum = time_score.back().second + static_cast<long>(score);
        time_score.push_back(make_pair(time, sum));
    }

    long long totalScore(int startTime, int endTime) {
        auto lower = lower_bound(time_score.begin(), time_score.end(), make_pair(startTime, 0L), compare_pairs);
        auto upper = upper_bound(time_score.begin(), time_score.end(), make_pair(endTime, 0L), compare_pairs);

        return (*(upper - 1)).second - (*(lower - 1)).second;
    }
};
