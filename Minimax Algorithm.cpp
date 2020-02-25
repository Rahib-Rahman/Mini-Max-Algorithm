#include<bits/stdc++.h>
using namespace std;

int minimax(int depth, int nodeIndex, bool isMax, int arr[], int h)
{
    if (depth == h) return arr[nodeIndex];

    if
    (isMax) return max(minimax(depth+1, nodeIndex*2, false, arr, h),minimax(depth+1, nodeIndex*2 + 1, false, arr, h));

    else
        return min(minimax(depth+1, nodeIndex*2, true, arr, h), minimax(depth+1, nodeIndex*2 + 1, true, arr, h));
}

int log2(int n)
{
    return (n==1)? 0 : 1 + log2(n/2);
}

int main()
{
    int n, i, h, ans, arr[1024];

    cout<<"n = number of elements & n must be power of 2.\nn = ";
    cin>>n;
    cout<<"The elements are: ";

    for(i=0; i<n; i++) cin>>arr[i];

    h = log2(n);

    ans = minimax(0, 0, true, arr, h);
    cout << "The optimal value is : " << ans << endl;
    return 0;
}

