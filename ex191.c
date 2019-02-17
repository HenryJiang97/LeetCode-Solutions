int hammingWeight(uint32_t n) {
    int counter;
    
    while (n > 0){
        if(n % 2 == 1){
            counter ++;
        }
        
        n /= 2;
    }
    
    return counter;
}