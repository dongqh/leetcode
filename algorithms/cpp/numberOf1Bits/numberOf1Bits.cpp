// Date   : 2025-03-11

/******************************************************************************************************
 * Given a positive integer n, write a function that returns the number of in its binary representation
 * (also known as the Hamming weight).
 *
 * 
 * Example 1:
 * Input: n = 11
 * Output: 3
 * 
 * Explanation:
 * The input binary string 1011 has a total of three set bits.
 * 
 * 
 * Example 2:
 * Input: n = 128
 * Output: 1
 * 
 * Explanation:
 * The input binary string 10000000 has a total of one set bit.
 *
******************************************************************************************************/

/*
 * Solution 1:
 * Time complexity : O(k)
 * The time complexity of this function is O(k), where k is the number of digits in the integer n.
 * 
 * Space complexity: O(1)
 * 
*/

int hammingWeight(int n) {
    int res = 0;
    while (n) {
        if (n & 1) {
            ++res;
        }
        n = n >> 1;
    }
    return res;
}


/*
 * Solution 2: Brian Kernighan algorithm
 * Time complexity : O(logn)
 * Space complexity: O(1)
 * 
*/

int hammingWeight(int n) {
    int res = 0;
    while (n) {
        // Directly skip the 0 positions, and only process the 1 positions.
        // n &= (n - 1)
        n = n & (n - 1);
        ++res;
    }
    return res;
}