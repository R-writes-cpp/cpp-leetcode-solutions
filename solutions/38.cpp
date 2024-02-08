#include <string>

using namespace std;
// best time: 0 ms, 8.66 MB (37th percentile)

/* explanation:
 * the problem is recursive in nature - in fact, we're given a recursive definition
 * we only need the previous count and say string in order to get the next one
 * we can use dynamic programming! store 2 strings and use this recursive definition n times
*/

string countAndSay(int n) {
    string last = "1";
    string next = "";

    int count = 1;
    while (--n) {
        next = "";

        {
            size_t i = 1;
            for (; last[i]; ++i)
                if (last[i] != last[i-1])
                    next += to_string(count) + last[i-1],
                    count = 1;
                else
                    ++count;

            next += to_string(count) + last[i-1];
        }

        count = 1,
        swap (last, next);
    }

    return last;
}
