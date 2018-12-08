/*Problem
Like Uber, CNG owners want to develop a software which can communicate with customer and driver.
A customer needs to say his/her destination and nearer CNG driver will get message from the Uber company with name and mobile number of the customer.
The driver can make a direct call and if the customer confirms the ride then driver will come to spot and carry the passenger.
As a student of CSE,write OOP code for the project.
You need to pass message from one end to another end to make communications.*/

#include<iostream>
#include <windows.h>;
using namespace std;
class Cng
{
    public:
        string cngNumber;
        string location;
        int capacity;
        string status;
        double distance;
        int driverId;
        Cng() {}
        Cng(string cngNumber,string location, int capacity,string status,double distance,int driverId)
        {
            this->cngNumber = cngNumber;
            this->location = location;
            this->capacity = capacity;
            this->status = status;
            this->distance = distance;
            this->driverId = driverId;
        }
        void cngDetails()
        {
            cout<<endl<<"CNG Details "<<endl;
            cout<<"..........................."<<endl;
            cout<<"CNG Number : "<<cngNumber<<endl;
            cout<<"CNG Location : "<<location<<endl;
            cout<<"Person Capacity : "<<capacity<<endl;
            cout<<"Distance from you : "<<distance<<" Km "<<endl;
        }
};

class CngDriver
{
    public:
        int driverId;
        string dName;
        string dPhone;
        CngDriver() {}
        CngDriver(int driverId,string dName,string dPhone)
        {
            this->driverId = driverId;
            this->dPhone = dPhone;
            this->dName = dName;
        }
        void driverDetails()
        {
            cout<<endl<<"Driver Details "<<endl;
            cout<<"Driver Id :"<<driverId<<endl;
            cout<<"Name : "<<dName<<endl;
            cout<<"Phone : "<<dPhone<<endl;
            cout<<"......................"<<endl;
        }
};

class Client
{
    string name;
    string phone;
    public:
        Client () {}
        Client (string name,string phone)
        {
            this->phone = phone;
            this->name = name;
        }
        void clientDetails()
        {
            cout<<endl<<"Client Details "<<endl;
            cout<<".........................."<<endl;
            cout<<"Name : "<<name<<endl;
            cout<<"Phone : "<<phone<<endl;
        }
};

int main()
{
    const int drvSize = 3;
    string ride;
    const int cngSize = 3;

    CngDriver *drv[drvSize] =
    {
        new CngDriver(1,"ABC","017170123"),
        new CngDriver(2,"XYZ","019361256"),
        new CngDriver(3,"PQW","017328562")
    };

    Cng *cng[cngSize] =
    {
        new Cng("Dhk metro 9999","Banani",3,"free",2.00,drv[0]->driverId),
        new Cng("Dhk metro 7799","uttara",3,"off",5.00,drv[1]->driverId),
        new Cng("Dhk metro 9977","Badda",3,"free",1.00,drv[2]->driverId)
    };

    cout<<endl<<endl<<"UBER"<<endl<<"==== All rides ===="<<endl;
    for(int i = 0; i < cngSize; i++)
    {
        cng[i]->cngDetails();
        for(int j = 0; j < drvSize; j++)
        {
            if(cng[i]->driverId == drv[j]->driverId)
            {
                drv[j]->driverDetails();
            }
        }
    }

    Client client("PQR","017256458");
    Client client2("LMN","01725623");

    client.clientDetails();

    cout<<endl<<"==================="<<endl;
    cout<<endl<<"==================="<<endl;
    cout<<"Press 'S' for Find Rides ";
    cin >> ride;

    if(ride == "S" || ride == "s")
    {
        system("CLS");
        cout<<endl<<endl<<"========= UBER ========"<<endl<<"==== Available rides ===="<<endl;
        cout<<"Finding Rides";
        Sleep(10);
        cout<<".";
        Sleep(1000);
        cout<<".";
        Sleep(1000);
        cout<<".";
        Sleep(1000);
        cout<<". ";

        int myCng,myDrv,found = 0;
        double minDis = 5,myDis = 5;

        for(int i = 0; i < cngSize; i++)
        {
            if(myDis > cng[i]->distance && cng[i]->status == "free")
            {
                myCng = i;
                myDis = cng[i]->distance;
            }
        }

        for(int i = 0; i < cngSize; i++)
        {

            for(int j = 0; j < drvSize; j++)
            {
                if(cng[i]->driverId == drv[j]->driverId)
                {
                    myDrv = j;
                    if(minDis > cng[i]->distance && cng[i]->status == "free")
                    {
                        cng[i]->cngDetails();
                        drv[myDrv]->driverDetails();
                        found = 1;
                    }
                }
            }

        }

        if(found == 0)
        {
            cout<<endl<<"No Rides are available right now. please try again later"<<endl;
        }
        else
        {
            cout<<endl<<"To Confirm press 'C' or cancel press 'X' "<<endl;
            cin >> ride;
            system("CLS");
            cout<<endl<<endl<<"========= UBER ========="<<endl<<endl;

            if(ride == "c" || ride == "C")
            {
                cout<<"Confirming Rides";
                Sleep(10);
                cout<<".";
                Sleep(1000);
                cout<<".";
                Sleep(1000);
                cout<<".";
                Sleep(1000);
                cout<<". ";

                cout<<endl<<"Your ride will be in your location with in few minutes ..."<<endl;
                cng[myCng]->cngDetails();
                drv[myDrv]->driverDetails();
                cout<<endl<<"You will receive a call soon"<<endl<<"Thank You For choosing UBER."<<endl;
            }
            else
            {
                system("CLS");
                cout<<endl<<endl<<"========= UBER ========="<<endl<<endl;
                cout<<"Thank You"<<endl<<"UBER";
            }
        }
    }
    else
    {
        system("CLS");
        cout<<endl<<endl<<"========= UBER ========="<<endl<<endl;
        cout<<"Thank You"<<endl<<"UBER";
    }

    cout<<endl<<endl<<endl<<endl;
    return 0;
}


