class Solution {
    func isSubsequence(_ s: String, _ t: String) -> Bool {
        let arr_s = Array(s)
        let arr_t = Array(t)
        
        var ps = 0, pt = 0
        
        while (pt < arr_t.count && ps < arr_s.count) {
            let cs = arr_s[ps]
            let ct = arr_t[pt]
            
            if (cs == ct) {
                ps += 1
                pt += 1
            } else {
                pt += 1
            }
        }
        
        return (ps >= s.count) ? true : false
    }
}

