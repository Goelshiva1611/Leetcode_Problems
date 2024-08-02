class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        // Count the total number of 1s in the array
        int totalOnes = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] == 1) {
                totalOnes++;
            }
        }

        // If there are no 1s or all are 1s, no swaps are needed
        if (totalOnes == 0 || totalOnes == n) {
            return 0;
        }

        // Use a sliding window to find the maximum number of 1s in any window of size totalOnes
        int maxOnesInWindow = 0;
        int currentOnesInWindow = 0;

        // Initial window
        for (int i = 0; i < totalOnes; i++) {
            if (nums[i] == 1) {
                currentOnesInWindow++;
            }
        }
        maxOnesInWindow = currentOnesInWindow;

        // Sliding the window
        for (int i = totalOnes; i < n + totalOnes; i++) {
            if (nums[i % n] == 1) {
                currentOnesInWindow++;
            }
            if (nums[(i - totalOnes) % n] == 1) {
                currentOnesInWindow--;
            }
            maxOnesInWindow = max(maxOnesInWindow, currentOnesInWindow);
        }

        // The minimum swaps needed is the total number of 1s minus the maximum number of 1s in any window
        return totalOnes - maxOnesInWindow;
    }
};
