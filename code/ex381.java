import java.util.ArrayList;
import java.util.Random;

class RandomizedCollection {
    ArrayList<Integer> list; 

    /** Initialize your data structure here. */
    public RandomizedCollection() {
        list = new ArrayList<Integer>();
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    public boolean insert(int val) {
        if (!list.contains(val))    {list.add(val);    return true;}
        else    {list.add(val);    return false;}
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    public boolean remove(int val) {
        if (list.contains(val))    {list.remove(list.indexOf(val));    return true;}
        else    return false;
    }
    
    /** Get a random element from the collection. */
    public int getRandom() {
        Random rand = new Random();
        int randNum = rand.nextInt(list.size());

        return list.get(randNum);
    }
}

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */