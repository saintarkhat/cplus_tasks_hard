#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long binSearchLeft(const std::vector<int>& numbers, int value)
{
    long left = -1;
    long right = numbers.size();

    while (right - left > 1) {
        long middle = (left + right) / 2;
        if (numbers[middle] < value) {
            left = middle;
        }
        else {
            right = middle;
        }
    }
    return left;
}

long binSearchRight(const std::vector<int>& numbers, int value)
{
    long left = -1;
    long right = numbers.size();

    while (right - left > 1) {
        long middle = (left + right) / 2;
        if (numbers[middle] <= value) {
            left = middle;
        }
        else {
            right = middle;
        }
    }
    return right;
}

int main()
{
    int n;
    int m;

    cin >> n >> m;

    vector<int> n_arra(n);
    vector<int> m_arra(m);

    for (auto& elem : n_arra)
        cin >> elem;

    for (auto& elem : m_arra)
        cin >> elem;

    for (vector<int>::iterator i = m_arra.begin(); i != m_arra.end(); ++i) {

        long l = binSearchLeft(n_arra, *i);
        long r = binSearchRight(n_arra, *i);

        if (r - l < 2) {
            cout << 0 << endl;
        }
        else {
            cout << l+2 << " " << r << endl;
        }
    }

    return 0;
}