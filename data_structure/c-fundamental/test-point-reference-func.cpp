#include <iostream>
#include <vector>

using namespace std;
void change_to_3_point(int* a)
{
    *a = 3;
}
void change_to_3_ref(int &a)
{
    a = 3;
}
int main()
{
    int a = 1;
    int* p =&a;
    //change_to_3_point(p);
    change_to_3_ref(a);
    cout << a;
    return 0;
}