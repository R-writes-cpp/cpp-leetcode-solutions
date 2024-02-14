#include <string>
#include <array>
#include <numeric>

using namespace std;
// time: 0 ms
// time complexity: O(n log n)

/* explanation:
 * in this solution we'll be using a disjoint set / union find to find the lexicographically smallest character that we can use for each character in our base string
 * the representative for each set will be set to its lexicographically smallest character (e.g. if 'a', 'b' and 'c' are equivalent to each other then 'a' will be the representative for the set {'a', 'b', 'c'})
 * our disjoint set will be able to handle transitivity since the unioning process will include all the children of the trees which we union (e.g. if 'a' is equivalent to 'c', then 'a' will become the parent of 'c', including all of its children)
 * once we've finished setting up our trees, we'll loop through the base string and replace each character with its representative, which is guaranteed to be lexicographically smaller or equal to the original character
*/

class Solution {
public:
    string smallestEquivalentString(string& s1, string& s2, string& baseStr) {
        array<int, 26> parent; // using an array because the upper bound of unique characters is 26 and 26 isn't very large when it comes to integer types
        iota (parent.begin(), parent.end(), 0); // i.e. parent[0] = 0, parent[1] = 1, etc.

        auto find = [&parent](int i) {
            while (parent[i] != i)
                i = parent[i];

            return i;
        };

        for (size_t i = 0, size = s1.size(); i < size; ++i)
            if (auto find_s1 = find(s1[i] - 'a'), find_s2 = find(s2[i] - 'a'); find_s1 < find_s2) // union the two characters' sets, with the new parent being the smaller representative of the two sets
                parent[find_s2] = find_s1;
            else
                parent[find_s1] = find_s2;

        for (char& c : baseStr)
            c = 'a' + find(c - 'a');

        return baseStr;
    }
};
