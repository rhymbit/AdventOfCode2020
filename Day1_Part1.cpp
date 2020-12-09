#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int binary_search(int arr[], int s, int e, int num, int avoid_index){
    // avoid_index is index of the num, I don't want this binary search to return, 
    if (e >= s){
        int mid = (e+s)/2;
        
        if (arr[mid] == num){
            if (arr[mid] == arr[avoid_index])
                ;
            else
                return num;
        }
        
        if (arr[mid] >= num)
            return binary_search(arr, s, mid-1, num, avoid_index);
        return binary_search(arr, mid+1, e, num, avoid_index);    

    }
    return -1;
}

long solve(int arr[], int n){
    for (int i{0}; i < n; i++){
        auto num = 2020 - arr[i];
        auto num2 = binary_search(arr, 0, n, num, i);
        if (num2 != -1){
            return arr[i]*num2;
        }
    }
    return -1;
}

int main()
{
    ifstream in{"playground/input.txt"};
    ofstream op{"output.txt"};

    int n{200};
    int arr[n];

    int x, i{0};
    while (in >> x){
        arr[i] = x; i++;
    }
    sort(&arr[0], &arr[n]);

    auto ans = solve(arr, n);
    if (ans != -1)
        cout << ans;
    else
        cout << "No two such nums exists";

    cout << '\n';
    return 0;
}
