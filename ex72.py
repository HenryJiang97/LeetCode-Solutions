class Solution:
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """

        counter = 0

        navi_1 = 0
        navi_2 = 0

        #When two words are blank string
        if len(word1) == 0 and len(word2) == 0:
            return counter
        
        #When one of the words is blank string
        if len(word1) == 0 or len(word2) == 0:
            if len(word1) == 0:
                return len(word2)
            else:
                return len(word1)

        #Compare the front part of two strings
        while (navi_1 < len(word1) - 1) and (navi_2 < len(word2) - 1):
            print(word1[navi_1], word2[navi_2])
            #Remove
            if (word1[navi_1] != word2[navi_2]) and (word1[navi_1 + 1] == word2[navi_2]):
                counter += 1
                navi_1 += 2
                navi_2 += 1
                continue

            #Insert
            if (word1[navi_1] != word2[navi_2]) and (word1[navi_1] == word2[navi_2 + 1]):
                counter += 1
                navi_1 += 1
                navi_2 += 2
                continue

            #Replace
            if (word1[navi_1] != word2[navi_2]):
                counter += 1
                navi_1 += 1
                navi_2 += 1
                continue

            if (word1[navi_1] == word2[navi_2]):
                navi_1 += 1
                navi_2 += 1

        print(navi_1, navi_2,counter)
        #Lenth1 = Lenth2
        if (len(word1) - navi_1) == (len(word2) - navi_2): 
            if word1[-1] != word2[-1]:
                return counter + 1

        if navi_1 >= len(word1):
            navi_1 -= 1
            navi_2 -= 1
        if navi_2 >= len(word2):
            navi_2 -= 1
            navi_1 -= 1


        print(navi_1, navi_2, counter)
        #Lenth1 > Lenth2
        if len(word1) - navi_1 > len(word2) - navi_2:
            if word1[navi_1] != word2[navi_2]:
                if word1[navi_1 + 1] == word2[navi_2]:
                    counter += len(word1) - navi_1 - 1
                else:
                    counter += len(word1) - navi_1

            if word1[navi_1] == word2[navi_2]:
                counter += len(word1) - navi_1 - 1


        if len(word1) - navi_1 < len(word2) - navi_2:
            if word1[navi_1] != word2[navi_2]:
                if word1[navi_1] == word2[navi_2 + 1]:
                    counter += len(word2) - navi_2 - 1
                else:
                    counter += len(word2) - navi_2

            if word1[navi_1] == word2[navi_2]:
                counter += len(word2) - navi_2 - 1


        return counter

sol = Solution()
print(sol.minDistance("plasma",
                      "altruism"))

