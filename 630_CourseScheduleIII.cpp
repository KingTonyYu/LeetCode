class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](auto& v1, auto& v2) {
            return v1[1] < v2[1];
        });

        priority_queue<int> max_heap;
        int cur_time = 0;
        for (const auto& course : courses) {
            int duration = course[0];
            int deadline = course[1];
            cur_time += duration;
            max_heap.push(duration);
            if (cur_time <= deadline)
                continue;
            cur_time -= max_heap.top();
            max_heap.pop();
        }
        return max_heap.size();
    }
};