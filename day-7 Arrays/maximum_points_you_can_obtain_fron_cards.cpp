/*
There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.
*/

METHOD - 1:

class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int n = cardPoints.length;
        int[] prefix = new int[n];
        prefix[0] = cardPoints[0];
        for(int i=1;i<n;i++) {
            prefix[i] = prefix[i-1]+cardPoints[i];
        }
        int[] suffix = new int[n];
        suffix[n-1] = cardPoints[n-1];
        for(int i=n-2;i>=0;i--) {
            suffix[i] = suffix[i+1]+cardPoints[i];
        }
        int maxSum = Integer.MIN_VALUE;
        maxSum = Math.max(prefix[k-1], suffix[n-k]);
        for(int i=1;i<k;i++) {
            int x = prefix[i-1]+suffix[n-k+i];
            maxSum = Math.max(maxSum, x);
        }
        return maxSum;
    }
}

METHOD - 2:


class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int n = cardPoints.length;
        int prefix = 0;
        for(int i=1;i<=k;i++) prefix+=cardPoints[i-1];
        int suffix = 0;
        for(int i=1;i<=k;i++){
            suffix += cardPoints[n-i];
        }
        int maxSum = Math.max(prefix, suffix);
        int pre=0;
        for(int i=1;i<=k;i++){
            pre += cardPoints[i-1];
            suffix -= cardPoints[n-k+i-1];
            maxSum = Math.max(maxSum, pre+suffix);
        }

        return maxSum;
    }
}
