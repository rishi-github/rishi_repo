
#include<iostream>
#include<list>
#include<cmath>
using namespace std;

class person
{
    string name;
    list<person> friendlist;
    float location;
    list<person>::iterator it;
    void isclose();
    public:
        person(string name,float loc);

        void addfriend(person per);

        bool setnewlocation(float loc);
        void showfriendlist();

};

void person::showfriendlist()
{
    cout<<"friends of "<<this->name<<" are :"<<endl;
    for(it = friendlist.begin(); it != friendlist.end(); ++it)
        {
            cout<<it->name<<endl;
        }
        cout<<endl;


}
void person::isclose()
    {
        for(it = friendlist.begin(); it != friendlist.end(); ++it)
        {
            if(abs((this->location)-(it->location))<=50)
            cout<<" hi  "<<it->name<<",  your friend "<<name<<"  is closer to you"<<endl;

        }

    }

person::person(string name,float loc)
     {
            this->name=name;

            this->location=loc;

    }
void person::addfriend(person per)
    {
            friendlist.push_front(per);
            per.friendlist.push_front(*this);
    }

bool person::setnewlocation(float loc)
    {
            this->location=loc;
            isclose();

    }

int main()
{
person a("a",100);
person b("b",150);
person c("c",200);
person d("d",300);
person e("e",500);
a.addfriend(b);
a.addfriend(c);
a.addfriend(d);
//a.setnewlocation(200);
a.showfriendlist();
a.setnewlocation(250);

}
