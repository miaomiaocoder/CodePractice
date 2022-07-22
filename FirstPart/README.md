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
        q[i] = tmp[j];
}
```

整数二分算法模板 —— 模板题[AcWing 789. 数的范围](https://www.acwing.com/problem/content/791/)

```cpp
bool check(int x) {/* ... */} // 检查x是否满足某种性质

// 区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用：
int bsearch_1(int l, int r){
    while(l < r){
        int mid = l + r >> 1;
        if (check(mid)) r = mid; // check()判断mid是否满足性质
        else l = mid + 1;
    }
    return l;
}
// 区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用：
int bsearch_2(int l, int r){
    while (l < r){
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}
```

浮点数二分算法模板 —— 模板题[AcWing 790. 数的三次方根](https://www.acwing.com/problem/content/792/)
```cpp
bool check(double x) {/* ... */} // 检查x是否满足某种性质

double bsearch_3(double l, double r){
    const double eps = 1e-6; // eps 表示精度，取决于题目对精度的要求
    while (r - l > eps){
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    return l;
}
```

高精度加法 —— 模板题[AcWing 791. 高精度加法](https://www.acwing.com/problem/content/793/)
```cpp 
// C = A + B, A >= 0, B >= 0
vector<int> add(vector<int> &A, vector<int> &B){
    if (A.size() < B.size()) return add(B, A);

    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i ++ ){
        t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }

    if (t) C.push_back(t);
    return C;
}
```