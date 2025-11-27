#include<iostream>
using namespace std;

void Hanoi(int n,char From,char To,char Aux){
    if(n==1){
        cout << "Move Disk 1 From " << From << " To " << To << endl;
        return;
    }
    Hanoi(n - 1, From, Aux, To);
    cout << "Move Disk " << n << " From " << From << " To " << To << endl;
    Hanoi(n - 1, Aux, To, From);
}

int main(){
    int n;
    cout << "Enter the Number : " << endl;
    cin >> n;

    cout << "n, 'A', 'C', 'b'" << endl;

    Hanoi(n, 'A', 'C', 'B');

    return 0;
}