class Solution {
private:
    int targetLength;

    long long int findMinSteps(long long int currentLength, long long int clipboardLength) {
        if (currentLength == targetLength) return 0;
        if (currentLength > targetLength) return INT_MAX ;

        long long  copyAndPaste = 2 + findMinSteps(currentLength * 2, currentLength);
        long long  pasteOnly = 1 + findMinSteps(currentLength + clipboardLength, clipboardLength);

        return std::min(copyAndPaste, pasteOnly);
    }

public:
    int minSteps(int n) {
        if (n == 1) return 0;
        targetLength = n;
        return 1 + findMinSteps(1, 1);
    }
};