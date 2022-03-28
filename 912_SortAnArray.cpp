class Solution {
private:
    vector<int> nums;

public:
    // Quick Sort
    vector<int> sortArray(vector<int>& nums) {
        this->nums = nums;
        int start = 0;
        int end = static_cast<int>(nums.size()) - 1;
        quickSort(start, end);
        return this->nums;
    };

    void quickSort(int start, int end) {

        if (start >= end) {
            return;
        }
        int tmp = rand() % (end - start + 1) + start;
        swap(nums[tmp], nums[end]);

        int small_last = start - 1;
        int ref = nums[end];
        for (int cur = start; cur < end; cur++) {
            if (nums[cur] >= ref) {
                continue;
            }
            small_last++;
            swap(nums[small_last], nums[cur]);
        }
        swap(nums[small_last + 1], nums[end]);
        quickSort(start, small_last);
        quickSort(small_last + 2, end);
    }

    // Merge Sort
    vector<int> sortArray(vector<int>& nums) {
        this->nums = nums;
        int start = 0;
        int end = static_cast<int>(nums.size()) - 1;
        return sort_helper(start, end);
    }

    vector<int> sort_helper(int start, int end) {
        if (start > end)
            return vector<int>({});
        if (start == end)
            return vector<int>({nums[start]});
        int mid = start + (end - start) / 2;
        vector<int> first_part = sort_helper(start, mid);
        vector<int> second_part = sort_helper(mid + 1, end);
        vector<int> result = merge_helper(first_part, second_part);
        return result;            
    }
    
    vector<int> merge_helper(vector<int>& first_part, vector<int>& second_part) {
        vector<int> result;
        auto first_it = first_part.begin();
        auto second_it = second_part.begin();
        
        while (first_it != first_part.end() && second_it != second_part.end()) {
            if (*first_it < *second_it) {
                result.push_back(*first_it);
                first_it++;
            }
            else {
                result.push_back(*second_it);
                second_it++;                    
            }
        }
        if (first_it == first_part.end()) {
            swap(first_it, second_it);
            swap(first_part, second_part);
        }
        while (first_it != first_part.end()) {
            result.push_back(*first_it);
            first_it++;
        }
        return result;
    }

};