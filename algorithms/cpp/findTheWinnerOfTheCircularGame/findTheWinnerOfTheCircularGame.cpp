// Date   : 2025-05-27

/**
 * @Solution 1: Simulation with List
 * @Time complexity: O(n^2)
 * @Space complexity: O(n)
 * @Date: 2025-05-27 09:18:54
 */

int findTheWinner(int n, int k) {
    vector<int> vec;
    for (int i = 1; i <= n; ++i) {
        vec.push_back(i);
    }
    int start = 0;
    while (vec.size() > 1) {
        int removeIndex = (start + k - 1) % vec.size();
        vec.erase(vec.begin() + removeIndex);
        start = removeIndex;
    }
    return vec.front();
}

/**
 * @Solution 2: Simulation with Queue
 * @Time complexity:
 * @Space complexity:
 * @Date: 2025-05-27 09:27:47
 */

//  Todo...

/**
 * @Solution 3: Recursion
 * @Time complexity: O(n)
 * @Space complexity: O(n)
 * @Date: 2025-05-27 09:25:06
 */

int findTheWinner(int n, int k) { return helper(n, k) + 1; }

int helper(int n, int k) {
    if (n == 1)
        return 0;
    return (helper(n - 1, k) + k) % n;
}

/**
 * @Solution 4: Iterative
 * @Time complexity: O(n)
 * @Space complexity: O(1)
 * @Date: 2025-05-27 09:28:34
 */

int findTheWinner(int n, int k) {
    int res = 0;
    for (int i = 2; i <= n; ++i) {
        res = (res + k) % i;
    }
    return res + 1;
}
