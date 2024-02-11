#include <vector>
#include <functional>

using namespace std;
// best time: 3 ms (95th percentile)
// time complexity: O(mn)
// space complexity: O(1)

/* explanation:
 * depth-first search: we'll count every X and set its neighbours (which are part of its batttleship if they're not equal to '.') to '.'. this will prevent us from looping through them again
 * for max optimisation we can also use a hash to prevent checking all bits of a char when we only need one bit to tell the difference between X and '.'
*/

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ret = 0;

        size_t r_max = board.size() - 1,
               c_max = board[0].size() - 1;

        function<void(size_t, size_t)> remove_neighbours;
        remove_neighbours = [&board, &remove_neighbours, &r_max, &c_max](size_t r, size_t c) {
            if ((board[r][c] & 2) == 2) // i.e. board[r][c] == '.'. 'X' & 2 is 0 and '.' & 2 is 2 - since they are the only two values in the board we can hash them by their 1 bit
                return;

            board[r][c] = '.';

            if (r != 0)
                remove_neighbours(r-1, c);
            if (r != r_max)
                remove_neighbours(r+1, c);

            if (c != 0)
                remove_neighbours(r, c-1);
            if (c != c_max)
                remove_neighbours(r, c+1);
        };

        for (size_t r = 0; r <= r_max; ++r)
            for (size_t c = 0; c <= c_max; ++c)
                if (!(board[r][c] & 2)) // board[r][c] == 'X' - recall the hash described earlier
                    ++ret,
                    remove_neighbours(r, c);

        return ret;
    }
};
