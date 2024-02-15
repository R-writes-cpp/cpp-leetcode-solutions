#include <vector>

using namespace std;
// best time: 6 ms (98th percentile)

/* explanation:
 * we'll use a depth-first search to traverse the grid and keep track of our current island's area
 * every 4-directionally adjacent land cell will add to our current counter, which we will compare with the return value at the end of the depth-first search
*/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ret = 0, current = 0;
        for (size_t r_max = grid.size() - 1, c_max = grid[0].size() - 1, r = 0; r <= r_max; ++r)
            for (size_t c = 0; c <= c_max; ++c)
                if (grid[r][c])
                    erase_island(grid, r_max, c_max, r, c, current),
                    ret = max (ret, current),
                    current = 0;

        return ret;
    }

    void erase_island (vector<vector<int>>& grid, size_t& r_max, size_t& c_max, size_t r, size_t c, int& current) {
        if (grid[r][c] == 0)
            return;

        ++current,
        grid[r][c] = 0;

        if (r != 0)
            erase_island(grid, r_max, c_max, r - 1, c, current);
        if (r != r_max)
            erase_island(grid, r_max, c_max, r + 1, c, current);
        if (c != 0)
            erase_island(grid, r_max, c_max, r, c - 1, current);
        if (c != c_max)
            erase_island(grid, r_max, c_max, r, c + 1, current);
    }
};
