class Vector2D {
    private int[][] arr;
    private int i, j;

    public Vector2D(int[][] v) {
        i = 0;    j = 0;
        this.arr = v;
        while (i < arr.length && j >= arr[i].length) {
            i++;
            j = 0;
        }
    }
    
    public int next() {
        int val = arr[i][j++];
        while (i < arr.length && j >= arr[i].length) {
            i++;
            j = 0;
        }
        return val;
    }
    
    public boolean hasNext() {
        return i < arr.length;
    }
}

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D obj = new Vector2D(v);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */