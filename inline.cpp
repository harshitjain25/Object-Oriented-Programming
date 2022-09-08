#include <iostream>
using namespace std;
int area(int x,int y);
int main()
{
    int l,b;
    cout<<"enter length and breadth";
    cin>>l>>b;
    cout<<"Area "<<area(l,b);
}
inline int area(int x,int y)
{
    return x*y;
}