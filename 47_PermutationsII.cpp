class Solution {
private:
  int length;
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
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
        if (i > 0 && nums[i] == nums[i - 1] && !hash[i - 1])
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
};
