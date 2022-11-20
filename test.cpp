#include<bits/stdc++.h>
using namespace std;


class worker //Base class declaration
{
    int age;
    char name [10] ;
    public:
        void get ( ) ;
        void show ( ) ;
};

void worker :: get ()
{
    cout << "your name please" ; 
    cin >> name;
    cout << "your age please"; 
    cin >>age;
}
void worker :: show ()
{
    cout<< "name is "<< name <<" and "<<"age is"<<age<<endl;
}

class manager : private worker //Derived class (privately by default)
{
    int now;
    public:
    void get () ;
    void show () ; 
}; 
void manager :: get ( )
{
    worker :: get ( ); //calling the get function of base
    cout << "number of worker under you";
    cin >> now;
} 
void manager :: show ( ) 
{
    worker :: show ( ) ;
    cout << "no. of worker under me are : " <<now;
}

int main()
{
    worker w1;
    manager m1;
    m1.get();
    m1.show();
}
