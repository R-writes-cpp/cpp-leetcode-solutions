#include <vector>

using namespace std;
// best time: 0 ms, 8.72 MB (77th percentile)

/* explanation:
 * here's a couple of steps:
 * use dynamic programming - we can define the amount of champagne passed to a glass as its parents' excess:
 * (max (p1 - 1, 0) + max (p2 - 1, 0)) / 2 where p1 and p2 are the parents of our current glass
 * if the current row is filled exclusively with zeros then everything below it will be equal to 0 as well. thus we'll return 0 early
*/

double champagneTower(int& poured, int& query_row, int& query_glass) {
    if (!poured)
        return 0;

    if (!query_row)
        return min (1, poured);

    vector<double> top (2, (static_cast<double>(poured) - 1) / 2), bottom (3);

    for (size_t i = 2; i <= query_row; ++i) {
        bottom.resize (i + 1);

        bottom[0] = top[0] > 1 ? (top[0] - 1) / 2 : 0;
        bool all_zero = true;

        for (size_t j = 1; j < i; ++j)
            if ((bottom[j] = ((top[j-1] > 1 ? top[j-1] - 1 : 0) + (top[j] > 1 ? top[j] - 1 : 0)) / 2))
                all_zero = false;

        if (all_zero)
            return 0;

        bottom[i] = top[i-1] > 1 ? (top[i-1] - 1) / 2 : 0;
        swap (top, bottom);
    }

    return top[query_glass] < 1 ? top[query_glass] : 1;
}
