#include <vector>

using namespace std;
// best time: 7 ms (99.87th percentile), 19.69 MB (27th percentile)

/*
 * explanation: in order to return the minimum value in O(1) time complexity, we need to keep track of the minimum value of the stack as we push values.
 * in order to keep track of whether the minimum value has been popped or not, we can create a second stack with the "history" of the minimum values
 * when the current minimum value has been popped, we'll pop it from our min stack and the element that was behind it will be the new minimum.
 * on line 20 we check if the new val we've pushed is less than or equal to the current minimum value because if they're equal and one of them gets popped, we still have the other one in the stack.
 * if we didn't do this then we could end up returning a minimum value which isn't actually the minimum
 * example: say we have a min stack of {1, 0, 0}. pop back the last 0 and we get {1, 0} - thus 0 is still the min val; it's just a different element in the stack.
 * if we didn't account for duplicates, and only use a strictly less than check, we'd end up with  {1, 0} as our starting min stack and {1} after popping the 0.
*/

class MinStack {
public:
    MinStack() {

    }

    void push(int val) {
        stack.push_back(val);
        if (min_hist.size() == 0 || *(min_hist.end() - 1) >= val)
            min_hist.push_back(val);
    }

    void pop() {
        if (*(min_hist.end() - 1) == *(stack.end() - 1))
            min_hist.pop_back();
        stack.pop_back();
    }

    int& top() {
        return *(stack.end() - 1);
    }

    int& getMin() {
        return *(min_hist.end() - 1);
    }

private:
    vector<int> stack {};
    vector<int> min_hist {};
};
