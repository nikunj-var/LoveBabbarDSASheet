// QUESTION-MEDIAN OF TWO SORTED ARRAYS OF EQUAL SIZE.


//APPROACH1-
//using merge sort approach
//keep track of count while comparing elements of two equal arrays if count becomes n we have reached the median.
//take the average of the elements at indixes n-1 and n.
//TC-O(n)


// #include<iostream>
// #include<algorithm>
// using namespace std;

// int getmedian(int arr1[],int arr2[],int n){
//     int m1=-1,m2=-1;
//     int i=0,j=0;
//     for(int count=0;count<=n;count++){
//         if(i==n){
//             m1=m2;
//             m2=arr2[0];
//             break;
//         }
//         if(j==n){
//             m1=m2;
//             m2=arr1[0];
//             break;
//         }
//         if(arr1[i] <= arr2[j]){
//             m1=m2;
//             m2=arr1[i];
//             i++;
//         }
//         else{
//             m1=m2;
//             m2=arr2[j];
//             j++;
//         }
//     }
//     return (m1+m2)/2;
// }

// int main(){
//     int n;
    
//     cout<<"enter size of array";
//     cin>>n;
    
//     int arr1[n],arr2[n];
//     cout<<"enter first array";
    
//     for(int i=0;i<n;i++){
//         cin>>arr1[i];
//     }

//     cout<<"enter second first array";
    
//     for(int i=0;i<n;i++){
//         cin>>arr2[i];
//     }

//     cout<<"the median is "<<getmedian(arr1,arr2,n);
// }

//approach2-by comparing the median of two arrays
//TC-O(logn)

#include<iostream>
#include<algorithm>
using namespace std;

//finds the median of the arrays
int median(int arr[],int n){
    if(n % 2==0){
        return (arr[n/2]+arr[n/2-1])/2;
    }
    return arr[n/2];
}


int getmedian(int arr1[],int arr2[],int n){
    if(n <= 0)
        return 0;
    if(n==1)
        return (arr1[0]+arr2[0])/2;
    if(n==2){
        return (max(arr1[0], arr2[0]) + min(arr1[1], arr2[1])) / 2;
    }


    //get median of first array
    int m1=median(arr1,n);
    //get median of second array
    int m2=median(arr2,n);

    //if both are equal return one of them
    if(m1==m2)
        return m1;

    //if m1 < m2 then  then median must exist in ar1[m1....] and
        //ar2[....m2]
    if(m1 < m2){
        if(n % 2 ==0){
            return getmedian(arr1+n/2-1,arr2,n-n/2+1);
        }
        return getmedian(arr1+n/2,arr2,n-n/2);
    }    

     /* if m1 > m2 then median must exist in ar1[....m1] and
        ar2[m2...] */
    else{
         if(n % 2 ==0){
            return getmedian(arr2+n/2-1,arr1,n-n/2+1);
        }
        return getmedian(arr2+n/2,arr1,n-n/2);
    }

}

int main(){
    int n;
    
    cout<<"enter size of array";
    cin>>n;
    
    int arr1[n],arr2[n];
    cout<<"enter first array";
    
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }

    cout<<"enter second first array";
    
    for(int i=0;i<n;i++){
        cin>>arr2[i];
    }

    cout<<"the median is "<<getmedian(arr1,arr2,n);
}
