#include <iostream>
using namespace std;
void PrintN(int N){
    if(N){
        PrintN(N-1);
        cout << N << endl;     
    }
}

void PrintN2(int N){
    for(int i=1; i<=N; i++){
        cout << i << endl;
    }
}

int main() {
    
    PrintN2(100000);
    
    return 0;
}