//approach-
//matrix--transpose--reverse by column
#include<iostream>
#include<algorithm>
using namespace std;

void rotatematrix(int arr[3][3],int n){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }

    for(int i=0;i<n;i++){
        int start=0;
        int end=n-1;
        while(start < end){
            swap(arr[i][start],arr[i][end]);
            start++;
            end--;
        }
    }
   
}

void printarray(int arr[3][3],int n){
    for(int i=0 ; i < n ; i++){
        for(int j=0;j<n;j++){
             cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main(){
    int n;
    
    cout<<"enter size of array";
    cin>>n;
    
    int arr[3][3];
    cout<<"enter array";
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
              cin>>arr[i][j];
        }
    }

    rotatematrix(arr,n);
    printarray(arr,n);
}