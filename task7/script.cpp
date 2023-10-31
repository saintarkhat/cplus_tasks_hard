#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int move_x[8] = { 1, 1, -1, -1, 2, 2, -2, -2 };
int move_y[8] = { 2, -2, 2, -2, 1, -1, 1, -1 };



int main() { 

    int n;
    cin >> n;
    
    pair<int,int> begin   = make_pair(-1, -1);
    pair<int,int> finish  = make_pair(-1, -1);
    pair<int,int> tt      = make_pair(-1, -1);
    pair<int,int> nan     = make_pair(-1, -1);

    vector<vector<pair<int,int>>> graph(n, vector <pair<int, int> >(n, nan));

    cin >> begin.first >> begin.second >> finish.first >> finish.second;
    --begin.first;
    --begin.second;
    --finish.first;
    --finish.second;

    queue<pair<int, int>> que;
    que.push(begin); 

    graph[begin.first][begin.second] = begin;

    while (!que.empty()) {

        tt = que.front();
        que.pop();

        if (tt == finish) { 

            vector <pair <int, int> > steps;

            while (tt != begin) {
                steps.push_back(tt);
                tt = graph[tt.first][tt.second];
            }
            cout << steps.size() << endl;
            steps.push_back(begin);
            for (int i = steps.size() - 1; i >= 0; i--) {
                cout << steps[i].first +1 << " " << steps[i].second+1 << endl;
            }
            return 0;
        }

        for (int i = 0; i < 8; i++) {

            int xi = tt.first + move_x[i];
            int yi = tt.second + move_y[i];

            if (xi >= 0 && yi >= 0 && xi < n && yi < n && graph[xi][yi] == nan) {
                graph[xi][yi] = tt;
                que.push(make_pair(xi, yi)); 
            }
        }
    } 
    return 0;
}
