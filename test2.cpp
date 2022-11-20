#include<bits/stdc++.h>
using namespace std;

class student 
{ 
    protected:
        int r_no;
    public:
        void get_n (int a) 
        { 
            r_no = a; 
        } 
        void put_n () 
        { 
            cout << "Roll No. "<< r_no<<endl;
        }
};

class test : virtual public student
{ 
    protected:
        int part1;
        int part2;
    public:
    void get_m (int x, int y)
    { 
        part1= x; 
        part2=y;
    } 
    void put_m ()
    {   
        cout << "marks obtained: " << endl;
        cout << "part1 = " << part1 << endl;
        cout << "part2 = "<< part2 << endl;
    }
};

class sports : virtual public student // Virtually declared common
{ 
    protected:
        int score;
    public:
        void get_s (int x)
        { 
            score= x; 
        } 
        void put_s ()
        {
            cout << "sports = "<< score << endl;
        }
};

class result: public test, public sports //derived class
{
    private : 
        int total ; 
    public:
        void show (void) ;
};
void result :: show ()
{ 
    total = part1 + part2 + score ;
    put_n();
    put_m();
    put_s() ; 
    cout << "\n total score= " <<total<< endl ;
}

int main ( )
{
    result S1 ; 
    S1.get_n (345); 
    S1.get_m (30, 35) ;
    S1.get_s (7) ;
    S1. show ( ) ;
}
