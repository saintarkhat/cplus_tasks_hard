#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    string chars;
    char ch;

    cin >> n;
    cin >> chars;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (chars[j] > chars[j + 1]) {
                ch = chars[j];
                chars[j] = chars[j + 1];
                chars[j + 1] = ch;
            }
        }
    }
    
    string answer;
    string m;
    bool flag = false;

    for (int i = 0; i < chars.length(); ++i)
    {
        size_t n = count(chars.begin(), chars.end(), chars[i]);

        if ((n & 1) == 1)
        {
            if (!flag)
            {
                m = chars[i];
                flag = true;
            }
        }
        answer += string(n / 2, chars[i]);
        i += n - 1;
    }

    if (flag != true) {
        m = "";
    }

    cout << answer + m + string(answer.rbegin(), answer.rend());
    return 0;
}
