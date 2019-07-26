class Solution:
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """

        # Record the char appeared more than once and their position
        app1 = {}
        app2 = {}

        # Record the char and their times of appearence
        record1 = {}
        record2 = {}

        for i in range(len(s)):
            if s[i] not in record1:
                record1.update({s[i]:1})
                app1.update({s[i]:[i]})
            else:
                record1[s[i]] += 1
                app1[s[i]].append(i)


            if t[i] not in record2:
                record2.update({t[i]:1})
                app2.update({t[i]:[i]})
            else:
                record2[t[i]] += 1
                app2[t[i]].append(i)


        print(app1)
        print(app2)

        l1 = []
        l2 = []
        
        for k, v in app1.items():
            l1.append(v)

        for k, v in app2.items():
            l2.append(v)

        print(l1)
        print(l2)

        return l1 == l2



sol = Solution()
print(sol.isIsomorphic("egg", "add"))
