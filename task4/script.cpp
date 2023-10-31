#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct report {
    int id;
    int cost;
};

void sort_dsc(std::vector<report>& vec)
{
    unsigned int i = 1;
    bool flag = false;
    while (i < vec.size() && !flag)
    {
        flag = true;
        for (unsigned int j = 0; j < vec.size() - i; ++j)
        {
            if (vec[j].cost < vec[j + 1].cost)
            {
                swap(vec[j], vec[j + 1]);
                flag = false;
            }
        }
    }
}

int main() {
    int amount;
    cin >> amount;

    vector <report> matrix(amount);

    for (int i = 0; i < amount; i++) {
        int temp;
        int s_temp;
        cin >> temp >> s_temp;
        report struct_temp;
        struct_temp.id = temp;
        struct_temp.cost = s_temp;
        matrix[i] = struct_temp;
    }

    sort_dsc(matrix); 

    for (auto step : matrix) { 
        cout << step.id << " " << step.cost << endl;
    }
    return 0;
}