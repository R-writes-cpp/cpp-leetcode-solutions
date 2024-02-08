#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;
// best time: 6 ms (99th percentile), 8.4 MB (67th percentile)
// time complexity: linearithmic

/* explanation:
 * we'll use a hash table to keep track of the frequencies of different characters in the string
 * once we iterate through the string and record all the frequencies, we'll add the pairs of chars (characters) and ints (their frequencies) to a new vector
 * we'll sort by the integer to sort by frequency
 * then, we'll create a new string and push back each character however many times it appeared
*/

string frequencySort(string s) {
    vector<pair<char, int>> sort_vec {};

    {
        unordered_map<char, int> map {};
        for (char c : s)
            ++map[c];

        for (auto& p : map)
            sort_vec.push_back(p);
    }

    sort(sort_vec.begin(), sort_vec.end(), [](pair<char, int> a, pair<char, int> b) {
        return a.second > b.second;
    });

    string ret;
    for (auto& p : sort_vec)
        for (int i = p.second; i; --i)
            ret += p.first;

    return ret;
}
