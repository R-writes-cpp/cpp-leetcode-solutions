#include <vector>
#include <algorithm>

using namespace std;

/* explanation:
 * we can only reach a point from either the left or right
 * min path sum to get to (r, c) = min (min path sum (r-1, c), min path sum (r, c-1)) + grid[r][c]
 * use dynamic programming to implement this in O(mn) time
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        size_t cols = grid[0].size();
        vector<int> top (cols);
        top[0] = grid[0][0];

        for (size_t i = 1; i < cols; ++i)
            top[i] += top[i-1] + grid[0][i];

        size_t rows = grid.size();
        if (rows == 1)
            return top[cols - 1];

        vector<int> bottom (cols);
        bottom[0] = top[0] + grid[1][0];

        for (size_t r = 1; r < rows; ++r) {
            bottom[0] = top[0] + grid[r][0];
            for (size_t c = 1; c < cols; ++c)
                bottom[c] = min (bottom[c-1], top[c]) + grid[r][c];
            swap (top, bottom);
        }

        return top[cols - 1];
    }
};
