#include<iostream>
#include<limits.h>
using namespace std;

 
void double_each_element(int arr[]){
    for(int i=0; i<=sizeof(arr[0]); i++){
        arr[i]=2*arr[i];
    }
    //array printing
    for(int i=0;i<=sizeof(arr[0]);i++){
        cout<<arr[i]<<" | ";
    }
}

void sum_printing(int arr[]){
    int n=sizeof(arr[1]);
    int sum=0;
    for(int i=0; i<=n; i++){
        sum += arr[i];
    }
    cout<<"Sum of each eleemnt is: "<<sum;
}

void linear_search(int arr[], int target){
    int n=sizeof(arr[1]);
    for(int i=0; i<=n; i++){
        if(arr[i] == target) 
        cout<<target<<" Found at index: "<<i;
        break;
    }
}

void count_0_1(int arr[],int s){
    int zero=0,one=0;
    for(int i=0; i<s; i++){
        if(arr[i] == 0) zero++;
        if(arr[i] == 1) one++;
    }

    cout<<"Num of '0': "<<zero<<"\nNum of '1': "<<one;
}

void max_min(int arr[], int s){
    int min=INT_MAX;
    int max=INT_MIN;
    for(int i=0; i<s; i++){
        if(arr[i] < min) min=arr[i];
        if(arr[i] > max) max=arr[i];
    }
    cout<<"Minimum number is: "<<min<<endl;
    cout<<"Maximum number is: "<<max<<endl;
}

void print_array(int arr[], int s){
    for(int i=0; i<s; i++){
        cout<<arr[i]<<" | ";
    }
    cout<<endl;
}

void reverse_array(int arr[], int s){
    
    int i=0,j=s-1,temp=0;
    cout<<"Original array: ";
    print_array(arr,s);
    while(i<j){
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
    cout<<"Reversed array: ";
    print_array(arr,s);

}

void extreme_print(int arr[], int s){
    int i=0,j=s-1;
    while(i<j){
        cout<<arr[i]<<"|"<<arr[j]<<"|";
        i++;
        j--;
    }
    cout<<arr[i];
}


int main(){
    int arr[5];
    cout<<"Enter the element of the array: ";
    for(int i=0; i<=sizeof(arr[0]); i++){
        cin>>arr[i];
    }
    //double_each_element(arr);
    //sum_printing(arr);
    //linear_search(arr,2);
    //count_0_1(arr,5);
    //max_min(arr,5);
    //reverse_array(arr,5);
    extreme_print(arr,5);
    return 0;
}