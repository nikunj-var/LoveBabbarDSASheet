//approach1-using binary search

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int key) {
        int n = mat.size();
        int m = mat[0].size();
        if(n == 0 || m == 0)
            return false;
        int low = 0;
        int high = n*m -1;
        
        while(low <= high)
        {
            int mid = low+(high-low)/2;
            int val =  mat[mid/m][mid%m];
            if(val == key)
                return true;
            if(val>key)
                high = mid-1;
            else 
                low = mid+1;
        }
        return false;
    }
};

//approach2-using binarysearch int count=0;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int key) {
        int m=mat.size();
        int n=mat[0].size();
       
        if(m==0 && n==0)
            return false;
        
        int row=0,col=n-1;
        
        while(row < m && col >= 0){
            int val=mat[row][col];
            if(val == key)
                return true;
            else if( val > key){
                col--;
            }
            else{
                row++;
            }
        }
        return false;
    }
};