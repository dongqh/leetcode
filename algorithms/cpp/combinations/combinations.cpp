// Date   : 2025-04-25

/**
 * @Solution 1:
 * @Time complexity: ...
 * @Space complexity: ...
 * @Date: 2025-04-25 10:16:09
 */

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> oneline;
    dfs(n, k, 1, oneline, res);
    return res;
}

void dfs(int n, int k, int level, vector<int> &line, vector<vector<int>> &res) {
    if (line.size() == k) {
        res.push_back(line);
        return;
    }
    for (int i = level; i <= n; ++i) {
        line.push_back(i);
        dfs(n, k, i + 1, line, res);
        line.pop_back();
    }
}

// Todo more solution