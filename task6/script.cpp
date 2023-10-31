#include <numeric>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int Levenshtein(const string& s, const string& t) {

    const int m = s.size();
    const int n = t.size();

    if (m == 0) return n;
    if (n == 0) return m;

    vector<int> answer(n + 1);
    iota(answer.begin(), answer.end(), 0);
    int i = 0;

    for (auto c1 : s) {
        answer[0] = i + 1;

        int bord = i;
        int j = 0;

        for (auto c2 : t) {
            int upper = answer[j + 1];
            answer[j + 1] = (c1 == c2) ? bord
                : 1 + min(min(upper, bord), answer[j]);
            bord = upper;
            ++j;
        }
        ++i;
    }
    return answer[n];
}

int main() {

    string s;
    string t;

    cin >> s;
    cin >> t;

    cout << Levenshtein(s, t);
    return 0;
}