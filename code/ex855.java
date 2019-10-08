// Ordered Set

class ExamRoom {
    private TreeSet<Integer> tset;
    private int n;
    
    public ExamRoom(int N) {
        tset = new TreeSet<Integer>();    
        n = N;
    }
    
    public int seat() {
        if (tset.isEmpty()) {
            tset.add(0);
            return 0;
        }
        
        int pos = 0;
        int lo = -1, max = 0;
        for (Integer i : tset) {
            if (lo == -1) {
                if (i > max) {
                    max = i;
                    pos = 0;
                }
                lo = i;
                continue;
            }
            
            int mid = (lo + i) / 2;
            int dis = mid - lo;
            if (dis > max) {
                max = dis;
                pos = mid;
            }
            lo = i;
        }
        
        // Get distance to the last pos
        int dis = n - 1 - lo;
        if (dis > max)    pos = n - 1;
        
        tset.add(pos);
        return pos;
    }
    
    public void leave(int p) {
        tset.remove(p);
    }
}

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */