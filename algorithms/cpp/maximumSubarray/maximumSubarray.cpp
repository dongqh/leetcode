// Date   : 2025-03-09

/*
 * Solution 1: 
 * Time complexity : O(n)
 * Space complexity: O(1)
 * 
 * Kadane's algorithm
 * https://en.wikipedia.org/wiki/Maximum_subarray_problem
*/
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int res = INT_MIN, curSum = 0;
    for (int num : nums) {
        curSum = max(curSum + num, num);
        res = max(curSum, res);
    }
    return res;
}

/*
 * Solution 2: divide and conquer approach
 * Time complexity : O()
 * Space complexity: O()
 * 
 * 
*/

// To do