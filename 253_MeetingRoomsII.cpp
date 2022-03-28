class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<vector<int>> time_list;
        for (const auto& interval : intervals) {
            time_list.push_back({interval[0], 1});
            time_list.push_back({interval[1], -1});
        }
        sort(time_list.begin(), time_list.end(), [](const auto& t1, const auto& t2) {
            if (t1[0] == t2[0])
                return t1[1] < t2[1];
            return t1[0] < t2[0];
        });
        int max_rooms = 0;
        int cur_rooms = 0;
        for (const auto& time : time_list) {
            cur_rooms += time[1];
            max_rooms = max(cur_rooms, max_rooms);
        }
        return max_rooms;
    }
};