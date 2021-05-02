#include <iostream>
using namespace std;

int main()
{
    int K;
    cin >> K;
    int list[K]  = {0};
    for (int i = 0; i<K; i++)
    {
        cin >> list[i];
    }

    int MaxSum = 0;
    int tmpSum = 0;
    int first_index = 0;
    int last_index = 0;
    for( int i=0; i<K; i++ )
    {
        tmpSum += list[i];

        if(tmpSum<0)
        {
            tmpSum = 0;
            if(MaxSum<=0)
            {
                first_index = i+1;
                last_index = i+1;
            }
        }
        if(tmpSum>MaxSum)
        {
            MaxSum = tmpSum;
            last_index = i;
        }
    }

    if(MaxSum==0)
    {
        MaxSum = 0;
        first_index = 0;
        last_index = K-1;
    }
    if(list[first_index]<0 || list[last_index]<0)
    {
        cout << 0 << " " << 0 << " " << 0;
    }
    else{
        cout << MaxSum << " " << list[first_index] << " " << list[last_index];
    }
    return 0;
}