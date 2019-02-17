class Solution:
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """

        head = 0
        end = len(s) - 1

        while head <= end:
            if not (((ord(s[head]) >= 65) and (ord(s[head]) <= 90)) or ((ord(s[head]) >= 97) and (ord(s[head]) <= 122)) or ((ord(s[head]) >= 48) and (ord(s[head]) <= 57))):
                head += 1
                continue
            if not (((ord(s[end]) >= 65) and (ord(s[end]) <= 90)) or ((ord(s[end]) >= 97) and (ord(s[end]) <= 122)) or ((ord(s[end]) >= 48) and (ord(s[end]) <= 57))):
                end -= 1
                continue

            #When head and end are not numbers
            if not (((ord(s[head]) >= 48) and (ord(s[head]) <= 57)) or ((ord(s[end]) >= 48) and (ord(s[end]) <= 57))):
                if (s[head] == s[end]) or (abs(ord(s[head]) - ord(s[end])) == 32):
                    head += 1
                    end -= 1
                else:
                    return False
            else:
                #When head or end is number
                if (s[head] == s[end]):
                    head += 1
                    end -= 1
                else:
                    return False

        return True

sol = Solution()
print(sol.isPalindrome("0P"))
