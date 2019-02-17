public class Solution extends VersionControl {
    private static boolean isBadVersion(int version) {

    }

    public int firstBadVersion(int n) {
        int lo = 0, hi = n, mid = 0;

        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;

            if (isBadVersion(mid))  hi = mid - 1;
            else                    lo = mid + 1;
        }

        return isBadVersion(mid) ? mid : mid + 1;
    }
}