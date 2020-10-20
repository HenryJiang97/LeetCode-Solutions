class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        name += ' ';    typed += ' ';
        int n1 = name.size(), n2 = typed.size();
        int p2 = 0;
        for (int i = 0; i < n1; i++) {
            while (p2 < n2 && name[i] != typed[p2] && i > 0 && typed[p2] == name[i - 1]) {
                p2++;
            }
            if (p2 >= n2 || name[i] != typed[p2])    return 0;
            p2++;
        }
        return p2 >= n2;
    }
};