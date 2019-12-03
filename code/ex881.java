class Solution {
    public int numRescueBoats(int[] people, int limit) {
        int n = people.length;
        Arrays.sort(people);
        int lo = 0, hi = n - 1, cnt = 0;
        while (lo < hi) {
            if (people[lo] + people[hi] <= limit) {
                lo++;    hi--;
            } else
                hi--;
            cnt++;
        }
        return lo == hi ? cnt + 1 : cnt;
    }
}