#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int minimums[150001];
int t[300001];

void tree(int i, int left, int right) {
    if (left == right)
        t[i] = minimums[left];
    else {
        int medium = (left + right) / 2;

        tree(i * 2, left, medium);
        tree(i * 2 + 1, medium + 1, right);
        t[i] = min(t[i * 2], t[i * 2 + 1]);
    }
}

int min(int i, int left, int right, int l, int r) {
    if (l > r)
        return INT_MAX;
    if (l == left && r == right)
        return t[i];
    int medium = (left + right) / 2;
    return min(min(i * 2, left, medium, l, min(r, medium))
        ,min(i * 2 + 1, medium + 1, right, max(l, medium + 1), r));
}
int main()
{
    int Nums;
    int Window;
    cin >> Nums >> Window;

    for (int i = 1; i <= Nums; ++i) cin >> minimums[i];

    tree(1, 1, Nums);

    for (int i = 0; i <= Nums - Window; ++i) cout << min(1, 0, Nums - 1, i, i + Window - 1) << endl;

    return 0;
}