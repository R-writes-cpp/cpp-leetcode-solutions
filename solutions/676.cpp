#include <vector>
#include <string>
#include <array>

using namespace std;
// best time: 20 ms (99th percentile), 2.75 MB (73rd percentile)
// time complexity: O(n)

/* explanation:
 * for a string to satisfy the search query, it must at least have the same number of characters as some other string in the dictionary
 * one constraint of the problem is that every string added to the dictionary is at most 100 characters long
 * we can use an std::array to organise strings by this!
 * now we'll just compare all strings of a matching length with the searchWord string
*/

class MagicDictionary {
public:
    MagicDictionary() {

    }

    void buildDict(vector<string> dictionary) {
        for (auto s : dictionary)
            dict[s.size() - 1].push_back(s);
    }

    bool search(string searchWord) {
        auto size_max = searchWord.size() - 1;
        bool one_diff = false;
        for (auto& s : dict[size_max]) {
            for (size_t i = 0; i <= size_max; ++i)
                if (s[i] != searchWord[i]) {
                    if (one_diff) {
                        one_diff = false;
                        break;
                    }
                    one_diff = true;
                }

            if (one_diff)
                return true;
            one_diff = false;
        }

        return false;
    }

private:
    array<vector<string>, 100> dict;
};
