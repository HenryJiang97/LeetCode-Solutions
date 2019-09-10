// Heap
// Time: O(nlog(n))

class KthLargest {
    public PriorityQueue<Integer> pq = new PriorityQueue<>();
    public int k;
    
    public KthLargest(int k, int[] nums) {
        this.k = k;
        Arrays.sort(nums);
        for (int i = 0; i < k && i < nums.length; i++)    pq.offer(nums[nums.length - i - 1]);
    }
    
    public int add(int val) {
        pq.offer(val);    if (pq.size() > k)    pq.poll();
        return pq.peek();
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */