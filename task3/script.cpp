#include <iostream>
#include <vector> 
#include <string>
#include <algorithm> 
#include <sstream>

using namespace std; 

void sort_asc(std::vector<long long>& vec)
{
    unsigned int i = 1;
    bool flag = false;
    while (i < vec.size() && !flag)
    {
        flag = true;
        for (unsigned int j = 0; j < vec.size() - i; ++j)
        {

            if (vec[j] > vec[j+1])
            {
                swap(vec[j], vec[j+1]);
                flag = false;
            }
        }
    }
}

void sort_dsc(std::vector<long long>& vec)
{
    unsigned int i = 1;
    bool flag = false;
    while (i < vec.size() && !flag)
    {
        flag = true;
        for (unsigned int j = 0; j < vec.size() - i; ++j)
        {

            if (vec[j] < vec[j+1])
            {
                swap(vec[j], vec[j+1]);
                flag = false;
            }
        }
    }
}

int main() { 

    string str_lenght;
    getline(cin, str_lenght);

    string str_costs;
    getline(cin, str_costs);

    stringstream in(str_lenght);
    vector<long long> lenght;
    long long temp;
    while (in >> temp) {
        lenght.push_back(temp);
    }

    stringstream in2(str_costs);
    vector<long long> costs; 
    long long temp2;
    while (in2 >> temp2) {
        costs.push_back(temp2);
    }

    sort_asc(lenght);
    sort_dsc(costs);

    long long n = lenght.size();
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        sum += lenght[i] * costs[i];
    }

    cout << sum;

    return 0;
}
