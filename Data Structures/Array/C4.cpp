#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print(vector<int>arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
}

void sort_positive_negative(vector<int> arr){

    // int i=0, j=arr.size()-1;
    // while(i<j){
    //     while(i<j && arr[i] < 0){
    //         i++;
    //     }
    //     while(i<j && arr[j] > 0){    // approch 1
    //         j--;
    //     }
    //     if(i<j){
    //         swap(arr[i],arr[j]);
    //     }
    // }

    int index=0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] < 0){
            swap(arr[i],arr[index]);   //approch 2
            index++;
        }
    }


    cout<<endl;
    print(arr);
}

int main(){

    vector<int>arr;
    int ele;
    cout<<"Enter thge elemt of the array: ";
    for(int i=0; i<5; i++){
        cin>>ele;
        arr.push_back(ele);
    }

    sort_positive_negative(arr);
    return 0;
}