import java.util.*;
class Solution {
    public List<Integer> addToArrayForm(int[] num, int k) {
        List<Integer> result = new ArrayList<>();
        int p = num.length - 1;

        while (p >= 0 || k > 0) {
            if (p >= 0) {
                k += num[p]; 
                p--;
            }
            
            result.add(k % 10); 
            k /= 10; 
        }

        Collections.reverse(result);
        return result;
    }
}