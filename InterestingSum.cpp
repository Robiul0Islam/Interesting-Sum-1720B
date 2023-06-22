/*
You are given an array 𝑎
 that contains 𝑛
 integers. You can choose any proper subsegment 𝑎𝑙,𝑎𝑙+1,…,𝑎𝑟
 of this array, meaning you can choose any two integers 1≤𝑙≤𝑟≤𝑛
, where 𝑟−𝑙+1<𝑛
. We define the beauty of a given subsegment as the value of the following expression:

max(𝑎1,𝑎2,…,𝑎𝑙−1,𝑎𝑟+1,𝑎𝑟+2,…,𝑎𝑛)−min(𝑎1,𝑎2,…,𝑎𝑙−1,𝑎𝑟+1,𝑎𝑟+2,…,𝑎𝑛)+max(𝑎𝑙,…,𝑎𝑟)−min(𝑎𝑙,…,𝑎𝑟).
Please find the maximum beauty among all proper subsegments.

Input
The first line contains one integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases. Then follow the descriptions of each test case.

The first line of each test case contains a single integer 𝑛
 (4≤𝑛≤105)
 — the length of the array.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the elements of the given array.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 105
.

Output
For each testcase print a single integer — the maximum beauty of a proper subsegment.

Example
inputCopy
4
8
1 2 2 3 1 5 6 1
5
1 2 3 100 200
4
3 3 3 3
6
7 8 3 1 1 8
outputCopy
9
297
0
14
Note
In the first test case, the optimal segment is 𝑙=7
, 𝑟=8
. The beauty of this segment equals to (6−1)+(5−1)=9
.

In the second test case, the optimal segment is 𝑙=2
, 𝑟=4
. The beauty of this segment equals (100−2)+(200−1)=297
.


*/

#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    int ans[t+1];
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int arr[n];
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }

        int max=arr[0];
        int min=arr[0];
        
        int maxIndex=0;
        int minIndex=0;
        

        for(int j=0;j<n;j++){
            if(arr[j]>max){
                max=arr[j];
                maxIndex=j;   
            }
            if(arr[j]<min){
                min=arr[j];
                minIndex=j;
               
            }
        }

        int temp=arr[n-1];
        arr[n-1]=max;
        arr[maxIndex]=temp;

        temp=arr[0];
        arr[0]=min;
        arr[minIndex]=temp;

        int max2=arr[1];
        int min2=arr[1];
    

        for(int j=1;j<n-1;j++){
            if(arr[j]>max2){
                max2=arr[j];
            }
            if(arr[j]<min2){
                min2=arr[j];
            }
        }

        int result=(max-min)+(max2-min2);
       

        ans[i+1]=result;

        
        
    }
    
    for(int i=1;i<=t;i++){
        cout<<ans[i]<<"\n";
    }
}