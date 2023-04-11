#include <iostream>

using namespace std;
class Point{
private:
int x,y;
public:
Point(int _x, int _y){x = _x; y = _y;}
Point(const Point &p){
x = p.x;
y = p.y;
 //p.x = 0; // Don’t want to allow this
}
void ShowData(){ cout<<"("<<x<<", "<<y<<")"<<endl;}
void SetData(int _x, int _y){x=x+_x;y=y+_y;}
};
int main(){
Point p1(10,20);
Point p2(p1);
p1.ShowData();
p2.ShowData();
p1.SetData(2,3);
p1.ShowData();
p2.ShowData();
}