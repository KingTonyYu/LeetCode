class Solution {
public:
  bool canReach(vector<int>& arr, int start) {
    int length = static_cast<int>(arr.size());
    vector<int> directions = {-1, 1};
    deque<int> queue;
    queue.push_back(start);
    arr[start] = -arr[start];
    while (!queue.empty())
    {
      int idx = queue.front();
      queue.pop_front();
      int step_size = arr[idx];
      for (int direct : directions)
      {
        int new_idx = idx + direct * step_size;
        if (new_idx < 0 || new_idx > length - 1)
          continue;
        if (arr[new_idx] == 0)
          return true;
        if (arr[new_idx] < 0)
          continue;
        arr[new_idx] = -arr[new_idx];
        queue.push_back(new_idx);
      }
    }
    return false;

  }
};