#include <vector>

using namespace std;
// best time: 0 ms, 7.27 MB (23rd percentile)
// time complexity: O(mn)
// memory complexity: O(n)

/* explanation:
 * sol (m, n) = sol (m, n-1) + sol (m-1, n)
 * USE DYNAMIC PROGRAMMING!
 * we only need 2 vector rows for this recursion - the current vector and the one before
 * if the grid is only 1 unit thick then there's only one path from the top-left corner to the bottom-right corner
*/

int uniquePaths(int m, int n) {
    if (m == 1 || n == 1)
        return 1;

    vector<int> top = vector<int>(n, 1), bottom = vector<int>(n);
    bottom[0] = 1;

    for (int i = 1; i < m; ++i) {
        for (size_t j = 1; j < n; ++j)
            bottom[j] = bottom[j-1] + top[j];
        swap (top, bottom);
    }

    return top[n-1];
}
