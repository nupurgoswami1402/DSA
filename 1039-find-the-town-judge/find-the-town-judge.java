class Solution {
    public int findJudge(int N, int[][] trust) {
        int[] trustScores = new int[N + 1];

        for (int[] relationship : trust) {
            int a = relationship[0];
            int b = relationship[1];

            trustScores[a]--;
            trustScores[b]++;
        }

        for (int i = 1; i <= N; i++) {
            if (trustScores[i] == N - 1) {
                return i;
            }
        }

        return -1;
    }
}