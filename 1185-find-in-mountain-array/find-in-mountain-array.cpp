/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
int binarysearch1(int target, MountainArray& mountainArr, int l, int h) {
    int low = l;
    int high = h;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (mountainArr.get(mid) == target) {
            return mid;
        } else if (mountainArr.get(mid) > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}
int binarysearch2(int target, MountainArray& mountainArr, int l, int h) {
    int low = l;
    int high = h;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (mountainArr.get(mid) == target) {
            return mid;
        } else if (mountainArr.get(mid) > target) {
            low = mid+1;
        } else {
            high=mid-1;
        }
    }
    return -1;
}
class Solution {
public:
    int findInMountainArray(int target, MountainArray& mountainArr) {
        int low = 0;
        int high = mountainArr.length() - 1;
        int answer = 0;
        while (low < high) {
            int mid = (low + high) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        int peak = high;
        int a = binarysearch1(target, mountainArr, 0, peak);
        int b = binarysearch2(target, mountainArr, peak + 1,
                             mountainArr.length() - 1);
        if (a == -1 && b != -1) {
            return b;
        }
        if (b == -1 && a != -1) {
            return a;
        }
        return min(a, b);
    }
};