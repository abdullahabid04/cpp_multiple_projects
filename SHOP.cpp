#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<ctime>
#include<cstdlib>
#include<windows.h>

#define pause system("pause")
#define clear system("cls")
#define delay Sleep(1000)

using namespace std;

class shop
{
	private:
		const string items[10] = {"biscuits","chocolates","candies","pizzas","burgers","cakes","icecreams","colddrinks","hotdrinks"};
		const int prices[10] = {5,3,1,20,10,15,10,5,5};
		vector<string>order_item;
		vector<int>order_price;
		int cash;
		int income;
		int costumer_count = 0;
		static const int x=100;
		void clear_data_order_item()
		{
			for(int l=0;l<order_item.size();l++)
			{
				order_item.pop_back();
			}
		}
		void clear_data_order_price()
		{
			for(int m=0;m<order_price.size();m++)
			{
				order_price.pop_back();
			}
		}
	public:
		int money;
		void available_items()
		{
			int i;
			cout<<"Available Items\n";
			cout<<"Serial\tItems\t\tPrice\n";
			cout<<"-------------------------------------------\n";
			for(i=0;i<9;i++)
			{
				cout<<"|"<<i+1<<"\t|"<<right<<setw(10)<<items[i]<<"\t|"<<left<<prices[i]<<'$'<<"\t|"<<"\n";
			}
			cout<<"-------------------------------------------\n";
			cout<<"\n\n\n";
			delay;
			clear;
			cout<<"Processing your order and bill\nPlease Wait";
			delay;
			clear;
		}
		void buyer()
		{
			int count=0;
			available_items();
			cout<<"Total costumers : "<<costumer_count<<'\n';
			cout<<"Shop income     :"<<income<<'$'<<'\n';
			srand(time(0));
			while(count < numberofitems())
			{
				int choice = rand()%9;
				order_item.push_back(items[choice]);
				order_price.push_back(prices[choice]);
				count++;
			}
			costumer_count++;
			display_order();
			clear_data_order_item();
			clear_data_order_price();
		}
		void display_order()
		{
			cout<<"-------------------------------------------\n";
			cout<<"\n\n\tCOSTUMER RECIEPT\n\n\n";
			cout<<"-------------------------------------------\n";		
			cout<<"Your Items and Bill\n";
			if(order_item.size()>1)
			{
				cout<<"Serial\tItems\t\tPrice\n";
				cout<<"-------------------------------------------\n";

				for(int k=0;k<order_item.size();k++)
				{
				cout<<"|"<<k+1<<"\t|"<<right<<setw(10)<<order_item[k]<<"\t|"<<left<<order_price[k]<<'$'<<"\t|"<<"\n";
				}
				cout<<"-------------------------------------------\n";
			}
			if(order_price.size()>1)
			{
				Bill();
			}			
		}
		int numberofitems()
		{
			int number_of_items;
			number_of_items=2+rand()%8;
		}
		int Bill()
		{
			int bill;
			for(int j=0;j<order_price.size();j++)
			{
				bill = bill + order_price[j];	
			}
			cout<<"-------------------------------------------\n";
			cout<<"Total bill    : "<<bill<<"$";
			get_cash();
			cout<<"\n";
			cout<<"-------------------------------------------\n";
			money = bill;
			income = income + bill;
		}
		void get_cash()
		{
			srand(time(0));
			cash=x+rand()%100+x;
			return_cash();
		}
		void return_cash()
		{
			if(cash>money)
			{
				cout<<"\nRecieved cash : "<<cash<<'$';	
				cout<<"\nChange        : "<<cash-money<<'$';
			}
			else if(cash == money)
			{
				cout<<"\nRecieved cash : "<<cash<<'$';	
				cout<<"\nChange        : "<<cash-money<<'$';
			}
			else
			{
				cout<<"\nYour given amount is less than your bill\n";
				cout<<"Need more cash\n";
				cash=x+rand()%100+x;
			}
		}		 
};
class clock
{
	private:
		int h = 10;
		int m = 0;
		int s = 0;
		const int open_hour = 10;
		const int open_minute = 0;
		const int open_second = 0; 		
		const int close_hour = 10;
		const int close_minute = 5;
		const int close_second = 0; 		
	public:
		int get_time()
		{
			clear;
			cout<<"-------------------------------------------\n";
			cout<<"\n\n\tTIME\n\n\n";
			cout<<"\t"<<h<<":"<<m<<":"<<s;
			cout<<"\n";
			cout<<"Shop timings are from "<<open_hour<<":"<<open_minute<<":"<<open_second<<" to "<<close_hour<<":"<<close_minute<<":"<<close_second<<endl;
			s = s + 30;
			if(s == 60)
			{
				m++;
				s=0;
				if(m == 60)
				{
					h++;
					m=0;
					if(h == 24)
					{
						h = 0; 
						m = 0;
						s = 0;
					}
				}
			}
			if(h == close_hour && m == close_minute && s == close_second)
			{
				cout<<"\tTime to close shop\n\tEveryone get out\n\tCome next day";
				clear;
				cout<<"\tCostumers leaving\n\tShutting down systems\n\tMaking preparations for closing shop\n\tPlease wait";
				delay;
				delay;
				delay;
				clear;
				cout<<"\n\n\n\t\t\tSHOP IS CLOSED";
				exit(1);
			}
		}
};
class Seller : public shop,public clock
{
	private:
		clock time;
	public:
		void run()
		{
			while(1)
			{
				time.get_time();
				buyer();
				delay;
				delay;
			}
		}
};

int main()
{
	Seller seller;
	Seller *SellerPtr = 0;
	SellerPtr = &seller;
	SellerPtr->run();
	return 0;
}
