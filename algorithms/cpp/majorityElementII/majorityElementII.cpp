// Date   : 2025-03-13

/*
 * Solution 1: 
 * Time complexity : O(n)
 * Space complexity: O(1)
 * 
*/

vector<int> majorityElement(vector<int>& nums) {
    unordered_map<int, int> counts;
    vector<int> res;
    for (auto num : nums) {
        ++counts[num];
    }

    int flag = nums.size() / 3;

    for (const auto& [key, val] : counts) {
        if (val > flag) {
            res.push_back(key);
        }
    }

    return res;
}

/** 
 * Solution 2: Boyer–Moore majority vote algorithm
 * https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm
 * Time complexity : O(n)
 * Space complexity: O(1)
**/

vector<int> majorityElement(vector<int>& nums) {
    vector<int> res;
    int count1 = 0, count2 = 0, num1 = 0, num2 = 0;

    for (int num : nums) {
        if (num1 == num) {
            ++count1;
        } else if (num2 == num) {
            ++count2;
        } else if (count1 == 0) {
            num1 = num;
            ++count1;
        } else if (count2 == 0) {
            num2 = num;
            ++count2;
        } else {
            --count1;
            --count2;
        }
    }

    count1 = count2 = 0;
    for (int num : nums) {
        if (num1 == num) {
            ++count1;
        } else if (num2 == num) {
            ++count2;
        }
    }
    // Verify
    if (count1 > nums.size() / 3) {
        res.push_back(num1);
    }
    if (count2 > nums.size() / 3) {
        res.push_back(num2);
    }
    return res;
}