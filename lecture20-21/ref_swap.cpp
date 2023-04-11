#include <iostream>

using namespace std;

void swap(int &a, int &b){
int temp = a;
a = b;
b = temp;
}

int main()
{
 int val1, val2;
val1 = 10, val2 = 20;

cout<<val1<<" "<<val2 <<endl;

swap(val1, val2);
cout<<val1<<" "<<val2 <<endl;

return 0;

}