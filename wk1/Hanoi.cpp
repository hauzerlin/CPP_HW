//Hanoi.cpp
//A program to show how tower of Hanoi work

#include <iostream>

//Put rings from start to end.
void Hanoi(char start, char temp, char end, int ring, int &step);

int main()
{
	int disk=0, step=1;
	char start='A', temp='B', end='C';
	std::cout<<"Please enter the number of disks: ";
	std::cin>>disk;
	
	Hanoi(start,temp,end,disk,step);
	
	return 0;	
}

//EX output: Step 5 : disk 1 moves from B to A
void Hanoi(char start, char temp, char end, int ring, int &step)
{
	if(ring<=0) exit(0);
	else if(ring==1)//put ring 1 directly from 'start' to 'end' pillar 
	{
		std::cout<<"Step "<< step <<" : ";
		std::cout<<"disk "<< ring <<" moves from "<< start <<" to "<<end<<std::endl;
	}
	else //put (ring-1) to temp pillar, then put the last ring to end pillar.
		 //put (ring-1) from temp to end pillar.
	{
		Hanoi(start, end, temp, ring-1, step);
		step++;
		std::cout<<"Step "<< step <<" : ";
		std::cout<<"disk "<< ring <<" moves from "<< start <<" to "<<end<<std::endl;
		step++;
		Hanoi(temp, start, end, ring-1, step);
	}
}
