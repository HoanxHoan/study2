#include <stdio.h>
int findMaxSum(int arr[], int n, int k) { 
    if (n < k || k == 0) {
        return 0;
		}
		int excludingLast = findMaxSum(arr, n - 1, k);
		int includingLast = arr[n - 1] + findMaxSum(arr, n - 1, k - 1);
		return (excludingLast > includingLast) ? excludingLast : includingLast;
}
int main()
{
  int n,k;
  scanf("%d %d",&k,&n);
  int list[n];
  for(int i=0;i<n;i++)
  {scanf("%d",&list[i]);}
  int result = findMaxSum(list, n, k);
  printf("%d",result);
  return 0;
  
}	
