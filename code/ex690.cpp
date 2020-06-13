/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, pair<int, vector<int>>> map;
        for (Employee* em : employees)    map[em->id] = {em->importance, em->subordinates};
        return backtracking(map, id);
    }
    
private:
    int backtracking(unordered_map<int, pair<int, vector<int>>>& map, int id) {
        int cnt = map[id].first;
        for (int subid : map[id].second)
            cnt += backtracking(map, subid);
        return cnt;
    }
};