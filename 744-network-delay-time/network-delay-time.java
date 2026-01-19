import java.util.*;

class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        // Adjacency list: node -> {neighbor, weight}
        List<int[]>[] graph = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int[] t : times) {
            graph[t[0]].add(new int[]{t[1], t[2]});
        }

        // Distance array
        int[] dist = new int[n + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[k] = 0;

        // Min-heap: {currentTime, node}
        PriorityQueue<int[]> pq = new PriorityQueue<>(
            (a, b) -> a[0] - b[0]
        );
        pq.offer(new int[]{0, k});

        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int time = curr[0];
            int node = curr[1];

            if (time > dist[node]) continue;

            for (int[] nei : graph[node]) {
                int nextNode = nei[0];
                int weight = nei[1];

                if (dist[nextNode] > time + weight) {
                    dist[nextNode] = time + weight;
                    pq.offer(new int[]{dist[nextNode], nextNode});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == Integer.MAX_VALUE) return -1;
            ans = Math.max(ans, dist[i]);
        }

        return ans;
    }
}
