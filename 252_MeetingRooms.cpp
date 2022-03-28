class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int length = static_cast<int>(intervals.size());
        sort(intervals.begin(), intervals.end(), [](const auto& v1, const auto& v2) {
            return v1[0] < v2[0];
        });

        for (int i = 1; i < length; i++) {
            if (intervals[i][0] < intervals[i - 1][1])
                return false;
        }

        return true;
    }
};