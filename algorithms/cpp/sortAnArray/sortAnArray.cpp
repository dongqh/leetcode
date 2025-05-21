// Date   : 2025-05-21

/**
 * @Solution 1: Quick sort
 * @Time complexity: O(n log n)
 * @Space complexity: O(log n)
 * @Date: 2025-05-21 15:28:34
 */

vector<int> sortArray(vector<int> &nums) {
    if (std::is_sorted(nums.begin(), nums.end())) {
        return nums;
    }
    if (std::is_sorted(nums.begin(), nums.end(), std::greater<int>())) {
        std::reverse(nums.begin(), nums.end());
        cout << "test" << endl;
        return nums;
    }
    quickSort(nums, 0, nums.size() - 1);
    return nums;
}

void quickSort(vector<int> &nums, int begin, int end) {
    if (begin >= end) {
        return;
    }
    int pivot = nums[begin], i = begin + 1, j = end;
    while (i <= j) {
        if (nums[i] > pivot && nums[j] < pivot) {
            swap(nums[i++], nums[j--]);
        }
        if (nums[i] <= pivot) {
            ++i;
        }
        if (nums[j] >= pivot) {
            --j;
        }
    }
    swap(nums[begin], nums[j]);
    quickSort(nums, begin, j - 1);
    quickSort(nums, j + 1, end);
}

// Todo more solutions