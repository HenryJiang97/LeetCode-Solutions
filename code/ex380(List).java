import java.util.ArrayList;
import java.util.Random;

class RandomizedSet {
    ArrayList<Integer> list;    
    
    /** Initialize your data structure here. */
    public RandomizedSet() {
        list = new ArrayList<Integer>();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    public boolean insert(int val) {
        if (!list.contains(val))    {list.add(val);    return true;}
        else    return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    public boolean remove(int val) {
        if (list.contains(val))    {list.remove(list.indexOf(val));    return true;}
        else    return false;
    }
    
    /** Get a random element from the set. */
    public int getRandom() {
        Random rand = new Random();
        int randNum = rand.nextInt(list.size());

        return list.get(randNum);
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */