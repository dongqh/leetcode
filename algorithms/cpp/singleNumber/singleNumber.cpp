// Date   : 2025-03-13

/**
 * Solution 1: 
 * Time complexity : O(n)
 * Space complexity: O(1)
 * 
*/

int singleNumber(vector<int>& nums) {
    unordered_set<int> res;
    for (int num : nums) {

        if (res.contains(num)) {
            res.erase(num);
        } else {
            res.insert(num);
        }
    }

    return *res.begin();
}

/** 
 * Solution 2:
 * 
 * Time complexity : O(n)
 * Space complexity: O(1)
**/

int singleNumber(vector<int>& nums) {
    int res = 0;
    for (int num : nums) {
        res ^= num;
    }
    return res;
}