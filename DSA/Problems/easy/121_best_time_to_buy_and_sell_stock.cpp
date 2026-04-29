#include <bits/stdc++.h>
using namespace std;

/**
 * Calculates the maximum profit from buying and selling a stock once.
 *
 * Given an array where each element represents the stock price on a given day,
 * find the maximum profit you can achieve by buying on one day and selling on
 * a later day. You must buy before you sell. If no profit is possible, return 0.
 *
 * Strategy: Track the minimum price seen so far (best buying opportunity) and
 * calculate profit at each position by comparing current price with minimum.
 * Update maximum profit whenever a better profit is found.
 *
 * Example:
 * Input: prices = [7, 1, 5, 3, 6, 4]
 * Output: 5 (Buy at 1, sell at 6)
 *
 * Example:
 * Input: prices = [7, 6, 4, 3, 1]
 * Output: 0 (No profit possible, prices only decrease)
 *
 * Time Complexity: O(n) - Single pass through the array
 * Space Complexity: O(1) - Only uses constant extra space
 *
 * @param prices Vector of integers representing daily stock prices
 * @return Maximum profit possible from a single buy-sell transaction, or 0 if no profit
 */
int maxProfitStock(const vector<int>& prices) {
    int minPrice = INT_MAX;
    int profit = 0;

    for (int i = 0; i < prices.size(); i++) {
        int currentPrice = prices[i];

        // if (minPrice >= currentPrice) {
        //     minPrice = currentPrice;
        // } else {
        //     profit = max(profit, (currentPrice - minPrice));
        // }

        minPrice = min(minPrice, currentPrice);
        profit = max(profit, (currentPrice - minPrice));
    }

    return profit;
}

int main() {
    vector<int> stock1 = {7, 1, 5, 3, 6, 4};
    cout << "Maximum profit from stock1 is: " << maxProfitStock(stock1) << endl;

    vector<int> stock2 = {7, 6, 4, 3, 1};
    cout << "Maximum profit from stock1 is: " << maxProfitStock(stock2) << endl;

    vector<int> stock3 = {};
    cout << "Maximum profit from stock3 is: " << maxProfitStock(stock3) << endl;

    return 0;
}