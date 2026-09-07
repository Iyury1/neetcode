#include <vector>
using namespace std;

class MinStack {
private:
    vector<int> data;
    vector<int> mins;

public:
    MinStack() {
    }
    
    void push(const int val) {
        mins.push_back(mins.empty() ? val : min(mins.back(), val));
        data.push_back(val);
    }
    
    void pop() {
        data.pop_back();
        mins.pop_back();
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        return mins.back();
    }
};