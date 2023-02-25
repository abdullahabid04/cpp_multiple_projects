#include<iostream>
using namespace std;

int main()
{
	float f,m,a;
	int x;
	
	while(1)
	{	
		cout<<endl<<"------------------------------"<<endl<<"Referance"<<endl<<endl;
		cout<<"x=1 for force"<<endl;
		cout<<"x=2 for mass"<<endl;
		cout<<"x=3 for acceleration"<<endl;
		cout<<endl<<"------------------------------"<<endl<<"QUESTION"<<endl<<endl;
		cout<<"What do you want to find"<<endl;
		cin>>x;
		switch(x)
		{
			case 1:
				{
					cout<<endl<<endl<<"----------"<<endl<<endl;	
					cout<<"Enter value of mass"<<endl<<endl;
					cin>>m;
					cout<<endl;
					cout<<"Enter value of acceleration"<<endl<<endl;
					cin>>a;
					cout<<endl;
					cout<<endl<<"formula for finding force"<<endl<<"------------------------------"<<endl<<endl;
					cout<<"f=m*a"<<endl<<endl;
					f=m*a;
					cout<<"value of force"<<endl<<"------------------------------"<<endl<<endl;
					cout<<"force ="<<f<<"N"<<endl;
					cout<<endl<<"------------------------------"<<endl<<endl;
					break;
    			}
			case 2:
				{
					cout<<endl<<endl<<"----------"<<endl<<endl;	
					cout<<"Enter value of force"<<endl<<endl;
					cin>>f;
					cout<<endl;
					cout<<"Enter value of acceleration"<<endl<<endl;
					cin>>a;
					cout<<endl;
					cout<<endl<<"formula for finding mass"<<endl<<"------------------------------"<<endl<<endl;
					cout<<"m=f/a"<<endl<<endl;
					m=f/a;
					cout<<"value of mass"<<endl<<"------------------------------"<<endl<<endl;
					cout<<"mass ="<<m<<"kg"<<endl;
					cout<<endl<<"------------------------------"<<endl<<endl;
					break;
				}
			case 3:
				{
					cout<<endl<<endl<<"----------"<<endl<<endl;	
					cout<<"Enter value of force"<<endl<<endl;
					cin>>f;
					cout<<endl;
					cout<<"Enter value of mass"<<endl<<endl;
					cin>>m;
					cout<<endl;
					cout<<endl<<"formula for finding acceleration"<<endl<<"------------------------------"<<endl<<endl;
					cout<<"a=f/m"<<endl<<endl;
					a=f/m;
					cout<<"value of acceleration"<<endl<<"------------------------------"<<endl<<endl;
					cout<<"acceleration ="<<a<<"m/s*s"<<endl;
					cout<<endl<<"------------------------------"<<endl<<endl;
					break;
				}		
		}
		system("pause");
		system("cls");
	}
	return 0;
}
