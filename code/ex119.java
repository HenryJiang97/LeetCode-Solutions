class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> list = new ArrayList<>();
        list.add(1);
        
        for (int i = 1; i <= rowIndex; i++) {
            int temp = list.get(0);
            for (int j = 1; j < i; j++) {
                int newItem = temp + list.get(j);
                temp = list.get(j);
                list.set(j, newItem);
            }
            list.add(1);
        }
        
        return list;
    }
}