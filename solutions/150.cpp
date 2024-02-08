#include <vector>
#include <string>

using namespace std;
// best time: 0 ms, 11.81 MB (84th percentile)

/* explanation:
 * use a stack to keep track of all the numbers
 * every operation in RPN represents popping back the top two numbers and pushing their result to the top of the stack
*/

int evalRPN(vector<string>& tokens) {
    vector<int> stack {};
    int ret = 0;

    for (auto& t : tokens)
        if (auto t0 = t[0]; t0 >= '0' && t0 <= '9' || (t0 == '-' && t[1]))
            stack.push_back (stoi(t));
        else {
            auto& n1 = *(stack.end() - 2), n2 = *(stack.end() - 1);
            n1 =
                t0 == '+' ? n1 + n2 :
                t0 == '*' ? n1 * n2 :
                t0 == '-' ? n1 - n2 :
                n1 / n2,
            stack.pop_back();
        }

    return stack[0];
}
