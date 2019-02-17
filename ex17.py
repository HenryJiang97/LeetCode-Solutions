class Solution:
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        #Dictionary to hold all values
        d = {'2':['a', 'b', 'c'], '3':['d', 'e', 'f'], '4':['g', 'h', 'i'], '5':['j', 'k', 'l'], '6':['m', 'n', 'o'], '7':['p', 'q', 'r', 's'], '8':['t', 'u', 'v'], '9':['w', 'x', 'y', 'z']}
        result = []

        #When digits is blank, return ''
        if len(digits) == 0:
            return []

        #Enqueue the first digit
        result = list(d.get(digits[0]))

        #FIFO
        List_pos = 1    #Postition of the next list to enter the queue
        for loop in range(0, len(digits) - 1):
            for Dequeue in range(0, len(result)):
                #Dequeue
                item_out = result.pop(0)
                #Enqueue
                List_len = len(d.get(digits[List_pos]))
                i = 0   #The position of the item the list under operation
                while i < List_len: 
                    result.append(item_out + d.get(digits[List_pos])[i])
                    i += 1

            List_pos += 1

        return result

sol = Solution()
print(sol.letterCombinations('789'))