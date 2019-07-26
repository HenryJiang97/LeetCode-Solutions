class Solution {
    public String complexNumberMultiply(String a, String b) {
        String[] arr_a = a.split("\\+"), arr_b = b.split("\\+");
        int aa = Integer.parseInt(arr_a[0]);
        int ab = Integer.parseInt(arr_a[1].substring(0, arr_a[1].length() - 1));
        int ba = Integer.parseInt(arr_b[0]);
        int bb = Integer.parseInt(arr_b[1].substring(0, arr_b[1].length() - 1));

        int new_a = aa * ba + (-1) * ab * bb;
        int new_b = aa * bb + ab * ba;
        
        return String.valueOf(new_a) + "+" + String.valueOf(new_b) + "i";
    }
}