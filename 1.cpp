#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

std::string* spaceDelimit(std::string,int);
int hexToDec(std::string);
std::string decToBin(int);
int numOfElements(std::string);
int numOfDigits(int);
std::string decToBinWidth(int,int);

int main()
{
	//18 3C 7E 7E 18 18 18 18
	std::string pic = "18 3C 7E 7E 18 18 18 18";
	int picSize = numOfElements(pic);
	std::string* strArr = new std::string[picSize];
	

	strArr=spaceDelimit(pic,picSize);
	std::string picArr[picSize];
	//output array converted to base 16, 24,61,127 ...	
	for(int i=0; i<picSize; i++)
	{
		picArr[i]=decToBinWidth(hexToDec(strArr[i]),8);
		std::cout << picArr[i] << std::endl;
	}
	//std::cout <<  decToBinWidth(147,8) << std::endl;
	delete[] strArr;
}

int numOfElements(std::string input)
{
	int count = 1;
	for(int i=0; i<input.length(); i++)
	{
		if(input[i]==' ')
		{
			count++;
		}
	}
	return count;
}

std::string* spaceDelimit(std::string input, int size)
{
	std::string* delimited= new std::string[size];
	for(int i=0,j=0; i<input.length(); i++)
	{
		if(input[i]==' ')
		{
			j++;
		}else
		{
			delimited[j] += input[i];
		}
	}
	return delimited;
}

int hexToDec(std::string hex)
{
	int num=0;
	for(int i=0, j; i<2; i++)
	{
		if((j=hex[i]-'0')>9)
		{
			j = j%16+9;	
		}
		num += j*std::pow(16,(1-i));
	}
	return num;
}

std::string decToBin(int dec)
{
	std::string bin;
	while(dec!=1/2)
	{
		if(dec%2==0)
		{
			bin += "0";
		}else
		{
			bin +="1";
		}
		dec/=2;
	}
	return bin;
}

std::string decToBinWidth(int dec, int width)
{
	std::string bin;
	width--;
	while(width>=0)
	{
		if(dec<std::pow(2,width))
		{
			bin +="0";
		}else
		{
			bin +="1";
			dec -=std::pow(2,width);
		}
		width--;
	}
	return bin;
}

int numOfDigits(int num)
{
	return std::floor(std::log10(std::abs(num))) + 1;
}
