#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    int n;
    vector<int> tree, arr;
    bool isMin;

public:
    SegmentTree(vector<int>& nums, bool modeMin) {
        n = nums.size();
        arr = nums;
        isMin = modeMin;
        tree.resize(4 * n + 1);
        build(1, 0, n - 1);
    }
    
    int combine(int left, int right) {
        return isMin ? min(left, right) : max(left, right);
    }
    
    void build(int idx, int l, int r) {
        if (l == r) {
            tree[idx] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * idx, l, mid);
        build(2 * idx + 1, mid + 1, r);
        tree[idx] = combine(tree[2 * idx], tree[2 * idx + 1]);
    }
    
    int query(int idx, int l, int r, int ql, int qr) {
        if (ql > r || qr < l)
            return isMin ? INT_MAX : INT_MIN;
        if (ql <= l && r <= qr)
            return tree[idx];
        int mid = (l + r) / 2;
        int left = query(2 * idx, l, mid, ql, qr);
        int right = query(2 * idx + 1, mid + 1, r, ql, qr);
        return combine(left, right);
    }
    
    int range_query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};
typedef long long ll;
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        SegmentTree segMax(nums, false);
        SegmentTree segMin(nums, true);
        
        priority_queue<pair<int, pair<int,int>>> maxHeap;
        set<pair<int,int>> vis;
        
        // Start with the full array
        int maxEle = segMax.range_query(0, n - 1);
        int minEle = segMin.range_query(0, n - 1);
        maxHeap.push({maxEle - minEle, {0, n - 1}});
        vis.insert({0, n - 1});
        
        long long ans = 0;
        while (!maxHeap.empty() && k > 0) {
            auto [diff, range] = maxHeap.top();
            maxHeap.pop();
            int l = range.first, r = range.second;
            ans += diff;
            k--;
            
            // Shrink the current subarray by removing first element
            if (l + 1 <= r && !vis.count({l + 1, r})) {
                int maxi = segMax.range_query(l + 1, r);
                int mini = segMin.range_query(l + 1, r);
                maxHeap.push({maxi - mini, {l + 1, r}});
                vis.insert({l + 1, r});
            }
            
            // Shrink the current subarray by removing last element
            if (l <= r - 1 && !vis.count({l, r - 1})) {
                int maxi = segMax.range_query(l, r - 1);
                int mini = segMin.range_query(l, r - 1);
                maxHeap.push({maxi - mini, {l, r - 1}});
                vis.insert({l, r - 1});
            }
        }
        return ans;
    }
};