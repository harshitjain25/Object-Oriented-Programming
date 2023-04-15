#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main()
{
    vector<int> v;
    int k, n;
    cout << "Enter size of vector: ";
    cin >> n;
    int max = INT_MIN, start, end, s = 0, x = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        v.push_back(k);
    }
    for (int i = 0; i < n; i++)
    {
        x = x + v[i];
        if (max < x)
        {
            max = x;
            start = s;
            end = i;
        }
        if (x < 0)
        {
            x = 0;
            s = i + 1;
        }
        
        
    }
    cout << max << "\n";
    for (int i = start; i <= end; i++)
        {
            cout << v[i] << "  ";
        }

    return 0;
}