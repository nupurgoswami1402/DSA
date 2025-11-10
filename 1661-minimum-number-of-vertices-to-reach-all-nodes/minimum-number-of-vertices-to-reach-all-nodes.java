import java.util.*;

class Solution {
    public List<Integer> findSmallestSetOfVertices(int n, List<List<Integer>> edges) {
        boolean[] hasIncoming = new boolean[n];
        
        // Mark all nodes that have incoming edges
        for (List<Integer> edge : edges) {
            int to = edge.get(1);
            hasIncoming[to] = true;
        }

        List<Integer> result = new ArrayList<>();
        
        // Nodes with no incoming edges are the starting vertices
        for (int i = 0; i < n; i++) {
            if (!hasIncoming[i]) {
                result.add(i);
            }
        }
        
        return result;
    }
}
