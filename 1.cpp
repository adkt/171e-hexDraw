//output hex string as image

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

std::string* spaceDelimit(std::string,int);
int hexToDec(std::string);
std::string decToPixel(int[]);
int numOfElements(std::string);

int main()
{
	std::string pic = "18 3C 7E 7E 18 18 18 18";
	int picSize = numOfElements(pic);
	std::string* strArr = new std::string[picSize];
	

	strArr=spaceDelimit(pic,picSize);
	int picArr[picSize];
	//output array converted to base 16, 24,61,127 ...	
	for(int i=0; i<picSize; i++)
	{
		picArr[i]=hexToDec(strArr[i]);
		std::cout << picArr[i] << std::endl;
	}
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
			j = j%16+10;	
		}
		num += j*std::pow(16,(1-i));
	}
	return num;
}
