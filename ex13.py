class Solution:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = 0
        i = 0

        while i < len(s):
            if s[i] == 'M':
                result += 1000

                i += 1
                continue
            
            if s[i] == 'D':
                result += 500

                i += 1
                continue

            if s[i] == 'C':
                if (i + 1) < len(s):
                    if s[i + 1] == 'M':
                        result += 900
                        i += 2
                    elif s[i + 1] == 'D':
                        result += 400
                        i += 2
                    else:
                        result += 100
                        i += 1

                    continue

                else:
                    result += 100
                    break

            if s[i] == 'X':
                if (i + 1) < len(s):
                    if s[i + 1] == 'C':
                        result += 90
                        i += 2
                    elif s[i + 1] == 'L':
                        result += 40
                        i += 2
                    else:
                        result += 10
                        i += 1
                
                    continue

                else:
                    result += 10
                    break


            if s[i] == 'L':
                result += 50

                i += 1
                continue

            if s[i] == 'V':
                result += 5

                i += 1
                continue

            if s[i] == 'I':
                if (i + 1) < len(s):
                    if s[i + 1] == 'X':
                        result += 9
                        i += 2
                    elif s[i + 1] == 'V':
                        result += 4
                        i += 2
                    else:
                        result += 1
                        i += 1
                    continue
                
                else:
                    result += 1
                    break
                           

        return result



sol = Solution()
print(sol.romanToInt('MDLXX'))