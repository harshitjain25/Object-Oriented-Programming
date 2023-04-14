#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    
    int t = 1;
    cin >> t;
    while (t--)
    {
        vector<int> v;
        int n, x = 0, y = 0;
        int k;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> k;
            v.push_back(k);
        }
        sort(v.begin(), v.end());

        for (int i = 0; i < n; i++)
        {
            if (v[i] > i + 1)
            {
                y = -1;
                break;
            }
            else 
            {
                x = x + i + 1 - v[i];
                
            }
        }
       
        if (y == -1)
            cout << -1;
        else
            cout << x;

        cout << "\n";
    }

    return 0;
}