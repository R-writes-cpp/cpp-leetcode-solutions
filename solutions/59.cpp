#include <vector>

using namespace std;
// best time: 0 ms, 6.84 MB (89th percentile)
/* explanation:
 * there's 4 different states that we go through as we hit the spiral matrix
 * when we start, we go to the right until we hit the final column
 * after that, we'll start going downward till we reach the bottom
 * once we hit the bottom, we go to the left until we reach the first column
 * then we finally go up till we hit a row we've already reached before - at this point we repeat the process
 * we can use a integer modulo 4 to keep track of these states and act accordingly
*/

vector<vector<int>> generateMatrix(int& n) {
    size_t r = 0, c = 0;
    int mod = 0, cycles = 1;

    vector<vector<int>> ret (n, vector<int> (n));

    for (int i = 1, end = n*n; i <= end; ++i) {
        ret[r][c] = i;

        if (mod == 0 && c + cycles == n)
            mod = 1;
        else if (mod == 1 && r + cycles == n)
            mod = 2;
        else if (mod == 2 && c == cycles - 1)
            mod = 3;
        else if (mod == 3 && r == cycles)
            ++cycles,
            mod = 0;

        if (mod == 0)
            ++c;
        else if (mod == 1)
            ++r;
        else if (mod == 2)
            --c;
        else
            --r;
    }

    return ret;
}
