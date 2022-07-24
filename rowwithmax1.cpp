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

class Solution{
public:
    int binarysearch(vector<int> arr,int s,int e){
        
        while(s <= e){
        
        int mid = s+(e-s)/2;
        
        if((mid==0 || arr[mid-1]==0) && arr[mid]==1){
           return mid;
        }
            
        else if(arr[mid]==0)
            s=mid+1;  
        
        else
            e=mid-1;
        } 
        return -1;

    }

	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	   int max=-1;
	   int maxi=-1;
	   for(int i=0;i<n;i++){
	       int index=binarysearch(arr[i],0,m-1);
	       
	       if(index!=-1 && m-index > max){
	           max=m-index;
	           maxi=i;
	       }
	   }
	   return maxi;
	}

};

//approach3-
//tc-O(m+n)

