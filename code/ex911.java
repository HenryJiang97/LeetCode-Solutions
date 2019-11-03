class TopVotedCandidate {
    public int[] leadingPerson;
    public int[] time;

    public TopVotedCandidate(int[] persons, int[] times) {
        int n = persons.length;
        leadingPerson = new int[n];
        time = Arrays.copyOf(times, n);
        Map<Integer, Integer> cnt = new HashMap<>();
        int max = 1, leading = persons[0];
        for (int i = 0; i < n; i++) {
            cnt.put(persons[i], cnt.getOrDefault(persons[i], 0) + 1);
            if (cnt.get(persons[i]) >= max) {
                leading = persons[i];
                max = cnt.get(persons[i]);
            }
            leadingPerson[i] = leading;
        }
    }
    
    public int q(int t) {
        int n = time.length;
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (time[mid] > t) {
                hi = mid - 1;
            } else {
                if (mid + 1 >= n || time[mid + 1] > t)    return leadingPerson[mid];
                else    lo = mid + 1;
            }
        }
        return -1;
    }
}

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */