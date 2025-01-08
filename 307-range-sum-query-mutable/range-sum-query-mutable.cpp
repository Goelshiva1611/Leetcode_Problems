class NumArray {
    int n;
    vector<int> input;
    vector<int>segment;

public:
    
    void buildSegment(int ind , int l , int r){
        if(l == r){
            segment[ind] = input[l];
            return;
        }

        int mid = (l+r)/2;
        buildSegment(2*ind+1 , l , mid);
        buildSegment(2*ind+2 , mid+1 , r);

        segment[ind] = segment[2*ind+1] + segment[2*ind+2];
    }

    void updateSegment(int ind , int val , int i , int l , int r){
        if(l == r){
            segment[i] = val;
            return;
        }

        int mid = (l+r)/2;
        if(ind <= mid){
            updateSegment(ind , val , 2*i+1 , l , mid);
        }else{
            updateSegment(ind , val , 2*i+2 , mid+1 , r);
        }
        segment[i] = segment[2*i+1] + segment[2*i+2];
    }

    int sumSegment(int start , int end , int i , int l , int r){

        if(l>end or r<start){
            return 0;
        }
        if(l>=start and r <= end){
            return segment[i];
        }
        int mid = (l+r)/2;
        return sumSegment(start , end , 2*i+1 , l , mid) + sumSegment(start , end , 2*i+2 , mid +1 , r);
    }


    NumArray(vector<int>& nums) {
        n = nums.size();
        input = nums;
        segment.resize(4*n , 0);
        buildSegment(0 , 0 , n-1);
    }
    
    void update(int index, int val) {
        updateSegment(index , val , 0 , 0 , n-1);
    }
    
    int sumRange(int left, int right) {
        return sumSegment(left , right , 0 , 0 , n-1);
    }
};