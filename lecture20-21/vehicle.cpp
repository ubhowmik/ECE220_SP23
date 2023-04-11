#include <iostream>
using namespace std;
class Vehicle{
    protected:
        int passenger;
        double baggage;
    public:
        Vehicle(int person, double weight){
            passenger = person;
            baggage = weight;
        }
        void Ride(int person){
            passenger += person;
        }
        void Load(double weight){
            baggage += weight;
        }
		
		//void ShowData(){cout<<"Vehicle"<<endl;}
        
		//virtual void ShowData(){cout<<"Vehicle"<<endl;}
		
		virtual void ShowData()=0; //pure virtual function;
};

class Airplane : public Vehicle{
    private:
        int crew_man;
    public:
        Airplane(int person, double weight, int crew) : Vehicle(person, weight){
            crew_man = crew;
        }
        void TakeCrew(int crew){
            crew_man += crew;
        }
        void ShowData(){
            cout<<"<<Airplane>> "<<endl;
            cout<<"passenger: "<<passenger<<endl;
            cout<<"baggage: "<<baggage<<endl;
            cout<<"crew man: "<<crew_man<<endl;
        }
};

class Train : public Vehicle{
    private:
        int length;
    public:
        Train(int person, double weight, int len) : Vehicle(person, weight){
            length = len;
        }
        void AddLength(int len){
            length += len;
        }
        void ShowData(){
            cout<<"<<Train>> "<<endl;
            cout<<"passenger: "<<passenger<<endl;
            cout<<"baggage: "<<baggage<<endl;
            cout<<"length : "<<length<<endl;
        }
};


int main(){

  

    Vehicle *ptr;

    ptr = new Airplane(10,10,20);
    ptr->ShowData();

    ptr = new Train(1,1,1);
    ptr->ShowData();

    ptr = new Vehicle(3,3);
    ptr->ShowData();
}



