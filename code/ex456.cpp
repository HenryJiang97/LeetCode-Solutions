// Stack
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() <= 2)    return false;
        
        // Get the min number array before position i
        vector<int> minimum(nums.size());
        minimum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
            minimum[i] = min(minimum[i - 1], nums[i]);
        
        // Maintain the stack
        stack<int> stack;
        for (int i = nums.size() - 1; i >= 1; i--) {
            if (nums[i] > minimum[i]) {
                if (stack.empty() || stack.top() > nums[i])    stack.push(nums[i]);
                while (!stack.empty() && minimum[i] >= stack.top())    stack.pop();
                if (!stack.empty() && stack.top() > minimum[i] && stack.top() < nums[i])
                    return true;
            }
        }
        
        return false;
    }
};