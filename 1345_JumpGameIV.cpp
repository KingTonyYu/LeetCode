class Solution {
public:
    int minJumps(vector<int>& arr) {
      int length = static_cast<int>(arr.size());
      unordered_map<int, vector<int>> hash_table;
      vector<bool> visited(length);
      deque<int> queue;
      
      for (int i = 0; i < length; i++) {
        hash_table[arr[i]].push_back(i);
      }
      int counter= 0;
      queue.push_front(0);
      visited[0] = true;

      while (!queue.empty()) {
        int cur_length = static_cast<int>(queue.size());
        for (int i = 0; i < cur_length; i++) {
          int index = queue.front();
          queue.pop_front();

          if (index == length - 1)
            return counter;

          if (index - 1 > -1 && !visited[index - 1]) {
            queue.push_back(index - 1);
            visited[index - 1] = true;
          }

          if (index + 1 < length && !visited[index + 1]) {
            queue.push_back(index + 1);
            visited[index + 1] = true;
          }
          if (hash_table.count(arr[index])) {
            for (const int& j : hash_table[arr[index]]) {
              if (!visited[j]) {
                queue.push_back(j);
                visited[j] = true;
              }
            }
            hash_table.erase(arr[index]);
          }
        }
        counter++;
      }
      return -1;
    }
};