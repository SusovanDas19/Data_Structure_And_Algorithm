#include<iostream>
using namespace std;

void find_unique_element(int arr[]){
    int uniq=0;
    for(int i=0; i<5; i++){
       uniq=uniq^arr[i];    //int ans=0^12^10^13^12^10^13^5; ---> 5
    }
    cout<<"Unique element is: "<<uniq;
    //to understand check "NOTES"
}

void print_all_pair(int arr[]){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(arr[i] != arr[j]){
                cout<<"("<<arr[i]<<","<<arr[j]<<")";
            }
            
        }
        cout<<endl;
    }
}

void sort_0_1(int arr[]) {
    int left=0, right=4;
    while(left < right){
        while(left < right && arr[left] == 0) left++;  
        while(left < right && arr[right] == 1) right--;
        if(left < right){
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
    }
    cout << "Sorted array: ";
    for (int i=0; i<5; i++)
        cout << arr[i]<<" ";
    cout << endl;
}

void element_move(int arr[]){
    int temp=arr[5];
    for( int i=5; i>=1; i--){
       arr[i]=arr[i-1];
    }
    arr[0]=temp;
    for (int i=0; i<5; i++) cout << arr[i]<<" ";
    
}
int main(){
    int arr[5];
    cout<<"Enter the element of the array: ";
    for(int i=0; i<5; i++){
        cin>>arr[i];
    }
    //find_unique_element(arr);
    //print_all_pair(arr);
    //sort_0_1(arr);
    //element_move(arr);
    return 0;
}