// Date   : 2025-03-12

/*
 * Solution 1: 
 * Time complexity : O(n)
 * Space complexity: O(1)
 * 
*/

int majorityElement(vector<int>& nums) {
    unordered_map<int, int> count;
    for (int num : nums) {
        ++count[num];
    }

    int half = nums.size() / 2;

    for (const auto& [key, value] : count) {
        if (value > half) {
            return key;
        }
    }
    return -1;
}

/** 
 * Solution 2: Boyer–Moore majority vote algorithm
 * https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm
 * Time complexity : O(n)
 * Space complexity: O(1)
**/

int majorityElement(vector<int>& nums) {
    if (nums.empty()) {
        return -1;
    }

    int res = 0, count = 0;
    for (int num : nums) {
        if (count == 0) {
            res = num;
            ++count;
        } else {
            (res == num) ? ++count : --count;
        }
    }

    return res;
}

/**
 * More solution
 */