/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */

import java.util.List;;
import java.util.ArrayList;
import java.util.Iterator;

public class NestedIterator implements Iterator<Integer> {
    public List<Integer> list;
    public Iterator<Integer> iterator;
    
    
    public NestedIterator(List<NestedInteger> nestedList) {
        // Build result list
        list = new ArrayList<Integer>();
        build(nestedList);
         
        
        System.out.println(list);
        
        iterator = list.iterator();
    }
    
    // Build list
    public void build(List<NestedInteger> nestedList) {
        for (NestedInteger ni : nestedList) {         
            if (ni.isInteger())    list.add(ni.getInteger());
            else    build(ni.getList());
        }
    }
    

    @Override
    public Integer next() {
        return iterator.next();
    }

    @Override
    public boolean hasNext() {
        if (iterator.hasNext())    return true;
        else    return false;
    }
}

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i = new NestedIterator(nestedList);
 * while (i.hasNext()) v[f()] = i.next();
 */