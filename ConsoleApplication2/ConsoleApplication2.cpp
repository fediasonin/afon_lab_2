#include <iostream>
using namespace std;

int schet(int r)
{
    int summa = 0, decyat = 10;
    _asm
    {
            metka1:
            mov edx, 0
            mov eax, r
            div decyat
            add summa, edx
            mov r, eax
            cmp r, 0
            jne metka1
            
    }
    //cout << summa << endl << r;
    return summa;
}

int main() {
    int arr[] = { -3, -2, -2343, -2521, -423, -91111, -12359 , -5, -875};
    int arr2[sizeof(arr)];
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i <= n; i++) {
        if (arr[i] < 0) {
            arr2[i] = arr[i] * (-1);
        }
        else
            arr2[i] = arr[i];
    }
    int max_num = INT_MIN;
    int chislo, d = 0;
    for (int i = 0; i < n; i++) {
        d = schet(arr2[i]);
        if (d > max_num) {
            max_num = d;
            chislo = arr2[i];
        }
    }
    cout << max_num << ", " << chislo;
}
