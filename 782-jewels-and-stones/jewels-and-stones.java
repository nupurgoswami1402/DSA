import java.util.HashSet;
import java.util.Set;

class Solution {
    public int numJewelsInStones(String jewels, String stones) {
        Set<Character> jewelSet = new HashSet<>();
        for (char j : jewels.toCharArray()) {
            jewelSet.add(j);
        }
        
        int jewelCount = 0;
        
        for (char s : stones.toCharArray()) {
            if (jewelSet.contains(s)) {
                jewelCount++;
            }
        }
        
        return jewelCount;
    }
}