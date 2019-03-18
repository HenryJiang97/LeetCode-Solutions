import java.util.*;

class Solution {
    // New data structure to store building information,
    // including the start point, height and the event type (up or down)
    class building {
        int x;    // X-corrdinate
        int h;    // Height
        boolean type;    // True => in;    False => out
        int id;
        public building(int x, int h, boolean type, int id) {
            this.x = x;    this.h = h;    this.type = type;    this.id = id;
        }
    }
    
    
    public List<int[]> getSkyline(int[][] buildings) {       
        // Build the list to store events of height change
        List<building> events = new ArrayList<>();
        for (int i = 0; i < buildings.length; i++) {
            events.add(new building(buildings[i][0], buildings[i][2], true, i));
            events.add(new building(buildings[i][1], buildings[i][2], false, i));
        }
        
        // Sort the list
        Collections.sort(events, new Comparator<building>() {
            @Override
            public int compare(building a, building b) {
                if (a.x != b.x)
                    return a.x - b.x;
                else
                    // Consider the situation if two events have the same x-cor
                    return b.h - a.h;
            }
        });

        
        // Find the answer
        List<int[]> res = new ArrayList<>();
        
        MaxHeap heap = new MaxHeap(buildings.length);
        
        for (building event : events) {
            if (event.type) {
                if (event.h > heap.max())    res.add(new int[]{event.x, event.h});
                heap.add(event.h, event.id);
            }
            else {
                System.out.println(event.id);
                heap.remove(event.id);
                if (event.h > heap.max())    res.add(new int[]{event.x, heap.max()});
            }
        }
    
        
        return res;
    }
    
    
    // Class MaxHeap
    private class MaxHeap {
        // (key, id)
        private List<int[]> nodes;
        
        // idx[i] = index of building[i] in nodes
        private int[] idx;
        
        public MaxHeap(int size) {
            idx = new int[size];
            nodes = new ArrayList<int[]>();
        }
        
        public void add(int key, int id) {
            idx[id] = nodes.size();
            nodes.add(new int[]{key, id});
            heapifyUp(idx[id]);
        }
        
        public void remove(int id) {
            int idx_to_evict = idx[id];
            swapNode(idx_to_evict, nodes.size() - 1);
            idx[id] = -1;
            nodes.remove(nodes.size() - 1);
            heapifyUp(idx_to_evict);
            heapifyDown(idx_to_evict);
        }
        
        public Boolean empty() {
            return nodes.isEmpty();
        }
        
        public int max() {
            return empty() ? 0 : nodes.get(0)[0];
        }
        
        private void heapifyUp(int i) {            
            while (i != 0) {            
                int p = (i - 1) / 2;
                if (nodes.get(i)[0] <= nodes.get(p)[0])
                    return;
                
                swapNode(i, p);
                i = p;
            }
        }
        
        private void swapNode(int i, int j) {
            int tmpIdx = idx[nodes.get(i)[1]];
            idx[nodes.get(i)[1]] = idx[nodes.get(j)[1]];
            idx[nodes.get(j)[1]] = tmpIdx;
 
            int[] tmpNode = nodes.get(i);
            nodes.set(i, nodes.get(j));
            nodes.set(j, tmpNode);
        }
        
        private void heapifyDown(int i) {
            while (true) {
                int c1 = i*2 + 1;
                int c2 = i*2 + 2;
 
                if (c1 >= nodes.size()) return;
 
                int c = (c2 < nodes.size() 
                      && nodes.get(c2)[0] > nodes.get(c1)[0]) ? c2 : c1;
                
                if (nodes.get(c)[0] <= nodes.get(i)[0])
                    return;
                
                swapNode(c, i);
                i = c;
            }
        }
        
    }
}