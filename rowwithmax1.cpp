//approach1-brute force
//tc-O(m*n)

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	   int maxi=-1;
	    int max1=0;
	   for(int i=0;i<n;i++){
	        int count=0;
	       for(int j=0;j<m;j++){
	           if(arr[i][j]==1)
	             count++;
	       }
	        if(max1 < count){
	            max1=count;
	            maxi=i;
	        }
	   }
	   return maxi;
	}

};

//approach2->apply binary search in each row
//tc-O(mlogn)

