//lab12_2.cpp
//Buy and sell Gold program

#include <iostream>
 void trading_gold(int start, int end);


int main()
 {
 	int start_day=0, end_day=0;
 	std::cout<<"***Welcome to forecast gold price system***\n";
 	std::cout<<"Please enter start trading day: ";
 	std::cin >> start_day;
 	std::cout<<"Please enter end trading day : ";
 	std::cin>> end_day;
 	
 	trading_gold(start_day, end_day);
 	
 	return 0;
 }
 
 void trading_gold(int start, int end)
 {
 	int max_price=0, min_price=0;
	int price[6] = {100, 200, 500, 1000, 100, 888};
	
 	if(start==end){std::cout<<"Bye~~~";return;}
 	else if(start>=end){std::cout<<"Bye~~~";return;}
 	//else if(start==4){std::cout<<"Get 0 dollar!!!\n";}
 	
 	start--;
 	end--;
 	
 	min_price = price[start];
 	for(int i=start; i<=end; i++)
 	{
 		if(price[i]>max_price)max_price = price[i];
 		if(price[i]<=min_price)min_price = price[i];
	}
	std::cout<<"Get "<< (max_price - min_price) <<" dollar!!!"<< std::endl;
	
	 
}
 
 /* lab 12_2.txt */
 /* Day 	Price
 	1		100
 	2		200
 	3		500
 	4		1000
 	5		100
 	6		888
*/
