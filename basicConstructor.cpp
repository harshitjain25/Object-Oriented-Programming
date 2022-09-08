#include <iostream>
using namespace std;
class integer
{
    int n,m;


public:
    integer();
    integer(int x, int y);
    void putdata(void);
};
void integer::putdata(void)
{
    cout<<m<<" ";
    cout<<n<<" ";
}
integer :: integer()
{
    m=0;
    n=0;
}
integer :: integer(int x,int y)
{
    m=x;
    n=y;
}
int main()
{
    integer i1;
    integer i2(30,40);
    i1.putdata();
    i2.putdata();
    
}