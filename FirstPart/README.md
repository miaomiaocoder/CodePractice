# 常用代码模板

快速排序算法模板 —— 模板题 [AcWing 785. 快速排序](https://www.acwing.com/problem/content/787/)

```cpp
void quick_sort(int q[], int l, int r)
{
    if(l >= r)return;

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
