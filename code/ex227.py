class Solution:
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """

        stack_num = []
        stack_sign = []
        n = ''
        r = 0


        # Save num and sign to stacks
        i = 0
        while i < len(s):
            # Skip blanks
            if s[i] == ' ':
                i += 1
                continue

            if (ord(s[i]) >= 48) & (ord(s[i]) <= 57):
                n += s[i]
                i += 1

            else:
                if n != '':
                    stack_num.append(int(n))
                    n = ''

                if (s[i] == '+') | (s[i] == '-'):
                    stack_sign.append(s[i])
                    i += 1

                if (s[i] == '*') | (s[i] == '/'):
                    sign = s[i]

                    i += 1
                    # Get the next integer
                    while i < len(s):
                        # Skip blanks
                        if s[i] == ' ':
                            i += 1
                            continue

                        if (ord(s[i]) >= 48) & (ord(s[i]) <= 57):
                            n += s[i]
                            
                            i += 1
                        else:
                            
                            first = stack_num.pop(-1)

                            if sign == '*':
                                stack_num.append(first * int(n))
                            if sign == '/':
                                stack_num.append(int(first / int(n)))

                            n = ''
                        
                            break
                    
                    if n != '':
                        first = stack_num.pop(-1)

                        if sign == '*':
                            stack_num.append(first * int(n))
                        if sign == '/':
                            stack_num.append(int(first / int(n)))

                        n = ''
                        
                        break

        if n != '':
            stack_num.append(int(n))



        # Do the + and - calculation
        if stack_num == []:
            return 0
        else:
            r += stack_num.pop(0)

            for i in range(len(stack_num)):
                if stack_sign[i] == '+':
                    r += stack_num[i]
                if stack_sign[i] == '-':
                    r -= stack_num[i]


        return int(r)
        


sol = Solution()
print(sol.calculate("14/3*2"))