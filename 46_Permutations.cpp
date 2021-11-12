class Solution {
private:
  int length;
public:
  vector<vector<int>> permute(vector<int>& nums) {
    length = nums.size();
    vector<vector<int>> result;
    vector<bool> hash(length);
    vector<int> current;
    
    function<void()> dfs = [&]() {
      if (current.size() == length) {
        result.push_back(current);
        return;
      }

      for (int i = 0; i < length; i++) {
        if (hash[i])
          continue;
        current.push_back(nums[i]);
        hash[i] = true;
        dfs();
        hash[i] = false;
        current.pop_back();
      }
    };
      
    dfs();
    return result;
  }
  
//   void backTracking(vector<int>& current, vector<bool>& hash, vector<vector<int>>& result, const vector<int>& nums)
//   {
//     if (current.size() == length) {
//       result.push_back(current);
//       return;
//     }
    
//     for (int i = 0; i < length; i++) {
//       if (hash[i])
//         continue;
//       current.push_back(nums[i]);
//       hash[i] = true;
//       backTracking(current, hash, result, nums);
//       hash[i] = false;
//       current.pop_back();
//     }
//   }
};