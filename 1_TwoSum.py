class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        my_set = {}
        for i in range(len(nums)):
            sec_num = target - nums[i]
            if sec_num in my_set:
                return [i, my_set[sec_num]]
            my_set[nums[i]] = i
