class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> queue;
        for (const auto& stone : stones)
            queue.push(stone);
        while (queue.size() > 1) {
            int first = queue.top();
            queue.pop();
            int second = queue.top();
            queue.pop();
            int tmp = first - second;
            if (tmp > 0)
                queue.push(tmp);
        }
        return queue.empty() ? 0 : queue.top();
    }
};