// 给定两个正整数

#include <iostream>
#include <vector>

using namespace std;

bool cmp(vector<int>& A, vector<int> &B)
{
    if(A.size() != B.size()) return A.size() > B.size();  //直接ruturn 了就不用else

    for(int i = A.size() - 1; i >= 0; i--)
        if(A[i] != B[i])
            return A[i] > B[i];

    return true;
}

vector <int> sub(vector<int>& A, vector<int> &B)
{
    vector<int> C;
    int t = 0;
    for(int i = 0; i < A.size(); i++)
    {
        t = A[i] - t;
        if(i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10 ); // 合而为1
        if(t < 0)  t = 1;
        else t = 0;

    }

    while(C.size() > 1 && C.back() == 0) C.pop_back();  //去掉前导0

    return C;
}

int main()
{
    string a ,b;
    vector<int> A, B;

    cin >> a >> b ;

    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

    if (cmp(A,B)) 
    {
        auto C = sub(A, B);
        for(int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
        return 0;
    }
    else
    {
        auto C = sub(B, A);
        printf("-");
        for(int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
        return 0;
    }


}

