#include <iostream>
using namespace std;

void merging(int nums1[], int n, int nums2[], int m)
{
    int i = 0 ;
        while(nums1[i] != 0){
            i++;
        }
        if(nums1[i] == 0)
        {
            int j = 0 ;
            while(j < n){
            cout << " Ind=s== ";
            nums1[i] = nums2[j];
            i++;
            j++;
            }
        }
}

int main()
{
    int arr1[6] = {1, 3, 5, 0, 0 , 0};
    int arr2[3] = {2, 4, 6};

    merging(arr1, 3 , arr2, 3);

    for (auto x : arr1)
    {
        cout << x << " ";
    }

    return 0;
}