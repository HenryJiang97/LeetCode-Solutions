/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
    int i = 0;
public:
    NestedInteger deserialize(string s) {
        s += ',';
        NestedInteger res = NestedInteger();
        if (s[i] == '[')    {i++;    res = helper(s);}
        else    res.setInteger(stoi(s));
        return res;
    }

private:
    NestedInteger helper(string s) {
        NestedInteger ni = NestedInteger();
        
        int num = 0, sign = 1;
        while (i < s.length()) {
            char c = s[i];
            if (c == '[') {
                i++;
                ni.add(helper(s));
            } else if (isdigit(c)) {
                i++;
                num = num * 10 + (c - '0');
            } else if (c == '-') {
                i++;
                sign = -1;
            } else {
                if (i > 0 && isdigit(s[i - 1])) {
                    NestedInteger nni = NestedInteger();
                    nni.setInteger(sign * num);
                    ni.add(nni);
                }
                num = 0;    sign = 1;
                i++;
                
                if (c == ']')    return ni;
            }
        }
        
        return ni;
    }
};