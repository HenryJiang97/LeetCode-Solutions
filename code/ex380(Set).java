import java.util.HashSet;
import java.util.Random;

class RandomizedSet {
    HashSet<Integer> set;    
    
    /** Initialize your data structure here. */
    public RandomizedSet() {
        set = new HashSet<Integer>();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    public boolean insert(int val) {
        if (!set.contains(val))    {set.add(val);    return true;}
        else    return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    public boolean remove(int val) {
        return set.remove(val);
    }
    
    /** Get a random element from the set. */
    public int getRandom() {
        Random rand = new Random();
        int randNum = rand.nextInt(set.size());
        int iterator = 0;
        
        for (int num : set)
            if (iterator++ == randNum)    return num;

        return 0;
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */