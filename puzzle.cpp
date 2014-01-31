// Puzzle Game
// According to the rrquirements, we know the range of numbers is 100 to 999

// For the errors shown in VS, it runs well on my CodeRunner, OS X.

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool is_3primes(int num);
bool is_Triangular(int num);
bool is_Cube(int num);
bool is_1p2p(int num);
bool is_3InIt(int num);
bool is_2p1p(int num);
bool isPrime(int num);

int main(){

	cout<<"The program is searching the numbers ..."<<endl<<endl;
	
// codes for removing numbers that donot have 3 (only one 3)
	int temp1size=0;
	int one3InIt[temp1size]; // array to store numbers that have only one 3
	int one3=0;
	// loop to find number that has one 3
	for(int i=100; i<=999; i++){
		string check=to_string(i); // int to string
		char checkarray[3];
		// string to array
		for(int a=0; a<check.length(); a++){
			checkarray[a]=check[a];
			// check for 3
			if(checkarray[a]=='3'){
				one3=one3+1;
			}
		}
		// one3 = 3, then only one 3 in the number, store it to array one3InIt
		if(one3==1){
			one3InIt[temp1size]=i;
			temp1size++;
		}
	}
	
// codes for removing numbers that have repeat digits
	int temp2size=0;
	int NoRepeats[temp2size]; // array to store numbers that donot have repeat digits
	// loop to check whether the number in array one3InIt has repeat digits
	for(int i=0; i<temp1size; i++){
		string check=to_string(one3InIt[i]);
		char checkarray[3];
		for(int a=0; a<check.length(); a++){
			checkarray[a]=check[a];
		}
		// if no repeat digits, store the number to array NoRepeats
		if((checkarray[0]!=checkarray[1]) && (checkarray[1]!=checkarray[2]) && (checkarray[0]!=checkarray[2])){
			NoRepeats[temp2size]=one3InIt[i];
			temp2size++;
		}
	}
	
// codes for removing numbers that cannot be divided by 3
	int temp3size=0;
	int DividedBy3[temp3size]; // array to store numbers that can be divided by 3
	// loop to check whether the number in array NoRepeats can be divided by 3
	for(int i=0; i<temp2size; i++){
		if(NoRepeats[i]%3==0){
			DividedBy3[temp3size]=NoRepeats[i];
			temp3size++;
		}
	}

// codes for comparing number with the six conditions
	int valid=0;
	//loop to check the six conditions
	for(int i=0; i<temp3size; i++){
		valid=is_3primes(DividedBy3[i])+is_Triangular(DividedBy3[i])+is_Cube(DividedBy3[i])+is_1p2p(DividedBy3[i])+is_3InIt(DividedBy3[i])+is_2p1p(DividedBy3[i]);
		if(valid==3){

			cout<<"The number is "<<DividedBy3[i]<<", and"<<endl;

			// loops to show the number passed which conditions and failed which conditions
			if(is_3primes(DividedBy3[i]))
				cout<<"It passed condition 1: The number is product of three distinct primes"<<endl;
			else
				cout<<"It failed condition 1: The number is product of three distinct primes"<<endl;

			if(is_Triangular(DividedBy3[i]))
				cout<<"It passed condition 2: The number is triangular"<<endl;
			else
				cout<<"It failed condition 2: The number is triangular"<<endl;

			if(is_Cube(DividedBy3[i]))
				cout<<"It passed condition 3: The number is a cube, or a cube+3"<<endl;
			else
				cout<<"It failed condition 3: The number is a cube, or a cube+3"<<endl;

			if(is_1p2p(DividedBy3[i]))
				cout<<"It passed condition 4: The number is written as a single digit prime followed by a 2-digit prime"<<endl;
			else
				cout<<"It failed condition 4: The number is written as a single digit prime followed by a 2-digit prime"<<endl;

			if(is_3InIt(DividedBy3[i]))
				cout<<"It passed condition 5: The number has a 3, and the 3 is the first or last digit"<<endl;
			else
				cout<<"It failed condition 5: The number has a 3, and the 3 is the first or last digit"<<endl;

			if(is_2p1p(DividedBy3[i]))
				cout<<"It passed condition 6: The number is written as a 2-digit prime followed by a single digit prime"<<endl;
			else
				cout<<"It failed condition 6: The number is written as a 2-digit prime followed by a single digit prime"<<endl;

			cout<<endl;
		}
	}
	
	return 0;
}

// condition 1: product of 3 distinct primes
bool is_3primes(int num){
	for(int a=0; a<999; a++){
		for(int b=0; b<999; b++){
			for(int c=0; c<999;c++){
				// repeat digits check
				if((a!=b && b!=c && c!=a)){
					// product check
					if(num==a*b*c){
						// check the primes
						if(isPrime(a) && isPrime(b) && isPrime(c))
							return true;
					}
				}
			}
		}
	}
};

// condition 2: the number is triangular
bool is_Triangular(int num){
	int temp;
	temp=sqrt(num*8+1);
	if((temp*temp)==(num*8+1))
		return true;
};

// condition 3: the number is a cube, or a cube + 3
bool is_Cube(int num){
	int temp1,temp2;
	temp1=cbrt(num);
	temp2=cbrt(num-3);
	if((temp1*temp1*temp1 == num) || (temp2*temp2*temp2 == (num-3)))
		return true;
};

// condition 4: the number is a single prime followed by a 2-digit prime
bool is_1p2p(int num){
	int p1,p2;
	p1=num/10; // get the first digit
	p2=num%100; // get the last two digits
	if(isPrime(p1) && isPrime(p2))
		return true;
};

// condition 5: the 3 is the first or last digit
bool is_3InIt(int num){
	int first,last;
	first=num/100; // get the first digit
	last=num%10; // get last digit
	if((first==3) || (last==3))
		return true;
};

// condition 6: the number is a 2-digit prime followed by a single prime
bool is_2p1p(int num){
	int p1,p2;
	p1=num/10; // get first 2 digits
	p2=num%10; // get last digit
	if(isPrime(p1) && isPrime(p2))
		return true;
};

// prime number check, from http://www.cplusplus.com/forum/general/1125/#msg3850
bool isPrime (int num)
{
    if (num <=1)
        return false;
    else if (num == 2)         
        return true;
    else if (num % 2 == 0)
        return false;
    else
    {
        bool prime = true;
        int divisor = 3;
        double num_d = static_cast<double>(num);
        int upperLimit = static_cast<int>(sqrt(num_d) +1);
        
        while (divisor <= upperLimit)
        {
            if (num % divisor == 0)
                prime = false;
            divisor +=2;
        }
        return prime;
    }
};
