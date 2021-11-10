class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        auto rit = nums.rbegin() + 1;
        while (rit != nums.rend() && *rit >= *(rit - 1)) {
            rit++;
        }
        if (rit == nums.rend()) {
            reverse(nums.rbegin(), nums.rend());
            return;
        }
        
        auto tmp_it = rit--;
        
        while (rit != nums.rbegin() && *rit > *tmp_it) {
            rit--;
        }
        if (rit == nums.rbegin() && *rit > *tmp_it)
            iter_swap(rit, tmp_it);
        else
            iter_swap(++rit, tmp_it);
        reverse(nums.rbegin(), tmp_it);
    }
};