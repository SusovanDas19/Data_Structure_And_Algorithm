#include<iostream>
#include<limits.h>
#include <algorithm> // to use swap function
#include<vector>
using namespace std;

void print(int arr[][4], int r, int c){
    cout<<"Element of 2D array is: "<<endl;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
// we have to initialize at least column when passing the 2d array in the function
void column_wise_print(int arr[][4], int r, int c){
    cout<<"Column wise printing: "<<endl;
    for(int i=0; i<c; i++){
        for(int j=0; j<r; j++){
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }
}

void searching(int arr[][4], int row, int column, int target){
     for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            if(arr[i][j] == target){
                cout<<"Traget element"<<target<<"found at index "<<i<<","<<j;
                return;
            }
        }
    }
    cout<<"Target"<<target<<"is not present";
}

void find_max_min(int arr[][4], int row, int column){
    int max=INT_MIN, min= INT_MAX;
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            if(arr[i][j] < min) min= arr[i][j];
            if(arr[i][j] > max) max= arr[i][j];
        }
    }

    cout<<"Maximum element is: "<<max<<"\nMinimum element is: "<<min;

}

void row_wise_sum(int arr[][4], int row, int column){
    
    for(int i=0; i<row; i++){
        int sum=0;
        
        for(int j=0; j<column; j++){
           sum +=arr[i][j];
          
        }
        cout<<"Row "<<i<<" Sum: "<<sum<<endl;
        
    }
}
void column_wise_sum(int arr[][4], int row, int column){
    
    for(int i=0; i<column; i++){
        int sum=0;
        
        for(int j=0; j<row; j++){
           sum +=arr[j][i];
          
        }
        cout<<"Column "<<i<<" Sum: "<<sum<<endl;
        
    }
}

void diagonal_sum(int arr[][4],int r, int c){
    int sum=0;
    for(int i=0; i<r; i++){
       sum +=arr[i][i];
    }
    cout<<"DIagonal sum of the 2d array : "<<sum;
}

void reverse_diagonal_sum(int arr[][4], int row, int column){
    int i=row-1, j=0, sum=0;
    while(i>=0 && j<column){
        sum += arr[i][j];
        i--;
        j++;
    }
    cout<<"Sum of reverse diagonal sum is: "<<sum;
}

void transpose(int arr[][4], int row, int column){ 
    for(int i=0; i<row; i++){
        for(int j=i; j<column; j++){       // <--- here we can do j=i+1 also 
            swap(arr[i][j],arr[j][i]);
        }
    }
    print(arr, row, column);
}

void vector_Print(vector<vector<int>>array){
    for(int i=0; i<array.size(); i++){          // array.size() = row size
        for(int j=0; j<array[i].size(); j++){  // array[i].size() = column sizze ,  here i means a row 
           cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    
    // int arr[4][4], row=4, column=4, target;

    // cout<<"Enter the element of the 2D array: "<<endl;
    // for(int i=0; i<row; i++){
    //     for(int j=0; j<column; j++){
    //         cin>>arr[i][j];
    //     }
        
    // }
    //print(arr, row, column);
    //column_wise_print(arr, row, column);
    // cout<<"Enter target element: "; cin>>target;
    // searching(arr, row, column, target);
    //find_max_min(arr, row, column);
    //row_wise_sum(arr, row, column);
    //column_wise_sum(arr, row, column);
    //diagonal_sum(arr, row, column);
    //reverse_diagonal_sum(arr, row, column);
    //transpose(arr, row, column);
    

    //2D Array using vector
    vector<vector<int>>array(5,vector<int>(5,0));
    //2D vector printing 
    vector_Print(array);


    // creating a 2D array
    vector<vector<int>> brr;

    //creating some 1D array
    vector<int>vec1(5,0);
    vector<int>vec2(6,-1);
    vector<int>vec3(7,-2);
    //inserting all the 1D array into the 2D array
    brr.push_back(vec1);
    brr.push_back(vec2);
    brr.push_back(vec3);
    //printing 2D array
    vector_Print(brr);

    return 0;
}
