#include<iostream>
using namespace std;
void FibonacciSeries(int num)
{
static int first_num = 0, second_num = 1, third_num;
if(num > 0)
{
third_num = first_num + second_num;
first_num = second_num;
second_num = third_num;
cout << third_num << endl;
FibonacciSeries(num - 1);
}
}
int main()
{
int num;
cout << "Enter random number to print fibonacci series:";
cin >> num;
cout << "Fibonacci Series for a given number: \n" << endl;
cout << "0" << endl;
cout << "1" << endl;
FibonacciSeries (num - 2); //number-2 is used because we have already print 2 numbers
return 0;
}