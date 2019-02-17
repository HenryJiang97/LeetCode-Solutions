from collections import defaultdict

class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        
        self.w = defaultdict(set)
        

        
    def addWord(self, word):
        """
        Adds a word into the data structure.
        :type word: str
        :rtype: void
        """
        
        # Add word to the set for its specific length
        self.w[len(word)].add(word)
        
        

    def search(self, word):
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        :type word: str
        :rtype: bool
        """
            
        # If the word is exactly the same as the one in the set
        if word in self.w[len(word)]:
            return True
        
        # If the word contains "."
        if "." in word:
            for l in self.w[len(word)]:
                sign = 0
                
                for i in range(len(l)):
                    if (word[i] != '.') and (word[i] != l[i]):
                        sign = 1
                        break
                    
                # If every digit in word meet item in the set, True
                if sign == 0:
                    return True
                    
        return False
                        
                    
        
        


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)