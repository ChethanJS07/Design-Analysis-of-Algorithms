#include<stdio.h>
#include<stdlib.h>

int main()
{
  int w,n;
  scanf("%d %d",&w.&n);
  int size[n];
  int p[n];
  for(int i=0;i<n;i++)
  {
    scanf("%d",&size[i]);
  }
  for(int i=0;i<n;i++)
  {
    scanf("%d",&p[i]);
  }
  quicksort()
}

int partition(int arr[],int left,int right)
{
  int x=arr[left];
  int i=left;
  for(int j=left+1;j<=right;j++)
  {
    if(arr[j]<x)
    {
      i+=1;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i],arr[left]);
  return i;
}

void quicksort(int arr[],int left,int right)
{
  if(left>=right)
  {
    return;
  }
  else
  {
    int mid = partition(arr,left,right);
    quicksort(arr,left,mid-1);
    quicksort(arr,mid+1,right);
  }
}