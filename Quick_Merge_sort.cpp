#include<bits/stdc++.h>
const int N = 1e5 + 10;
int p[N];

// 快速排序 O(n logn)
void quick_sort(int s[], int l, int r){
    if(l >= r)return ;
    
    int i = l - 1, j= r + 1, t = s[l + r >> 1];// 以区间中间的数为基准
    while(i < j){
        while(s[++ i] < t);
        while(s[-- j] > t);
        if(i < j)std::swap(s[i], s[j]);
    }
    
    quick_sort(s, l, j), quick_sort(s, j + 1, r);
}

// 归并排序 O(n logn)

void merge_sort(int s[], int l, int r){
    if(l >= r)return ;
    
    int mid = l + r >> 1;
    merge_sort(s, l, mid), merge_sort(s, mid + 1, r);
    
    int i = l,j = mid + 1, k = 0;
    while(i <= mid && j <= r){
        if(s[i] < s[j])p[++ k] =  s[i ++];
        else p[++ k] = s[j ++];
    }
    while(i <= mid )p[++ k] = s[i ++];
    while(j <= r)p[++ k] = s[j ++];
    
    for(i = l,j = 1;i <= r; i ++, j ++)s[i] = p[j];
}