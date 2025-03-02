#include<iostream>
using namespace std;

int passes = 0;
int steps = 0;

void QuickSort(int arr[], int l, int r);
int partition(int arr[], int l, int r);
void swap_elements(int &a1, int &a2);

void QuickSort(int arr[], int l, int r){
    if (l < r){
    	passes++;
        int p = partition(arr, l, r);
        QuickSort(arr, l, p - 1);
        QuickSort(arr, p + 1, r);
    }
}

int partition(int arr[], int l, int r){
    int x = l + 1, y = r;//condition is x= l + 1 
    int P = arr[l];  // pivot element
    
    while(x <= y){
        while(x <= y && arr[x] <= P){//changed
            x++;
            steps++;
        }
        
        while(x <= y && arr[y] > P){//changed
            y--;
            steps++;
        }

        if(x < y){
            swap_elements(arr[x], arr[y]);
            steps++;
        }
    }

    swap_elements(arr[l], arr[y]);
    steps++;
    return y;
}

void swap_elements(int &a1, int &a2){
    int temp = a1;
    a1 = a2;
    a2 = temp;
}

int main() {
//    int arr[] = {7, 2, 1, 6, 8, 5, 3, 4};
	int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
    }
    
    cout << "The elements before the sorting: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    QuickSort(arr, 0, n - 1);
    cout<<"\nThe elements after sorting: "<<endl;
    
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
	cout<<"Total passes: "<<passes<<endl;
	cout<<"Total steps: "<<steps<<endl;
    return 0;
}

