# 常用代码模板

快速排序算法模板 —— 模板题 [AcWing 785. 快速排序](https://www.acwing.com/problem/content/787/)

```cpp
void quick_sort(int q[], int l, int r)
{
    if(l >= r) return;

    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while(i < j)
    {
        do i ++; while q[i] < x;
        do j --; while q[j] > x;
        if(i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}
```

归并排序算法模板 —— 模板题[AcWing 787. 归并排序](https://www.acwing.com/problem/content/789/)

```cpp
void merge_sort(int q[], int l, int r)
{
    if(l >= r) return;

    int mid = l + r >> 1;

    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while(i <= mid && j <= r)
        if (q[i] <= q[j]) tmp[k++] = q[i++];
        else tmp[k++] = q[j++];
    while(i <= mid) tmp[k++] = q[i++];
    while(j <= r) tmp[k++] = q[j++];

    for(int i = l, j = 0; i <= r; i++, j++)
        q[i++] = tmp[j++];
}
```
