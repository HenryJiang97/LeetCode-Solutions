/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char[] buf);
 */
public class Solution extends Reader4 {
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    public int read(char[] buf, int n) {
        char[] bf = new char[4];
        int i = 0;
        while (i < n) {
            int cnt = read4(bf);
            if (cnt == 0)    break;
            cnt = Math.min(cnt, n - i);
            for (int j = 0; j < cnt; j++)
                buf[i + j] = bf[j];
            i += cnt;
        }
        return i;
    }
}