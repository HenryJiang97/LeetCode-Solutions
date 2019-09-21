/*
// Definition for an Interval.
class Interval {
    public int start;
    public int end;

    public Interval() {}

    public Interval(int _start,int _end) {
        start = _start;
        end = _end;
    }
};
*/
class Solution {
    public List<Interval> employeeFreeTime(List<List<Interval>> schedule) {
        List<Interval> list = new ArrayList<>();
        
        for (List<Interval> s : schedule) {
            for (Interval i : s) {
                list.add(i);
            }
        }
        
        // Sort the interval list by start time
        Collections.sort(list, (a, b)->a.start - b.start);
        
        List<Interval> res = new ArrayList<>();
        int t = list.get(0).end;
        for (int i = 1; i < list.size(); i++) {
            if (list.get(i).start <= t) {    // Has interval
                t = Math.max(list.get(i).end, t);
            }
            else {    // No interval -> has non-overlapping intervals
                res.add(new Interval(t, list.get(i).start));
                t = list.get(i).end;
            }
        }
        
        return res;
    }
}