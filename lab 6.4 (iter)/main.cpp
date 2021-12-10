#include <iostream>
#include <iomanip>
#include <time.h>

void initialization(int* n, const int length, const int low, const int high);
void print(int* n, const int length);
int multiplication(int* n, const int length);
int sum(int* n, const int length);
void sort(int* n, const int length);

using namespace std;
int main(){
    
    int n;
    srand((unsigned)time(NULL));
    int Low = -3;
    int High = 3;
    cout << "n = "; cin >> n;
    int* a = new int[n];
    initialization(a, n , Low, High);
    print(a, n);
    
    cout << "Добуток: " << multiplication(a, n) << endl;
    cout << "Сума: " << sum(a, n) << endl;
    sort(a, n);
    print(a, n);
    delete[] a;
    return 0;
}
void initialization(int* n, const int length, const int low, const int high)
{
    for (int i = 0; i < length; i++)
    {
        n[i] = low + rand() % (high - low + 1);
    }
}
void print(int* n, const int length)
{
    for (int i = 0; i < length; i++)
        cout << setw(4) << n[i];
    cout << endl;
}
int multiplication(int* n, const int length)
{
    int P = 1;
    for(int i = 0; i < length; i+=2)
        P*=n[i];
    return P;
}
int sum(int* n, const int length)
{
    int Sum = 0, start, finish;
    for(int i = 0; i < length; i++)
    {
        if(n[i]==0)
        {
            start = i;
            break;
        }
    }
    for(int i = length - 1; i > start; i--)
    {
        if(n[i]==0)
        {
            finish = i;
            break;
        }
    }
    for(int i = start; i < finish; i++)
    {
        Sum += n[i];
    }
        
    return Sum;
}
void sort(int* n, const int length)
{
    for (int i=1; i<length; i++)
       {
           int k=0;
           for (int j=0; j<length-i; j++)
               if (n[j]<n[j+1])
               {
                   int tmp = n[j];
                   n[j] = n[j+1];
                   n[j+1] = tmp;
                   k=1;
               }
           if (k==0)
               return;
           
       }
}
