#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0) return 0;

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i]; // update min price
        } else {
            int profit = prices[i] - minPrice;
            if (profit > maxProfit) maxProfit = profit; // update max profit
        }
    }

    return maxProfit;
}
