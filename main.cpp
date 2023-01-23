#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;
namespace sdds
{

	void display(char B_stuff[], string A_stuff, string A_framing)
	{
		cout << "Before stuffing: " << B_stuff << " -- " << strlen(B_stuff) << " characters" << endl;
		cout << "After stuffing: " << A_stuff << " -- " << A_stuff.length() << " characters" << endl;
		cout << "After framing: " << A_framing << " -- " << A_framing.length() << " characters" << endl;
	}

	void convert(char input[])
	{
		string flag = "01111110";
		char* beforeStuf = nullptr;
		string afterStuf;
		string afterFrame;
		int count = 0;
		beforeStuf = new char[strlen(input)];
		strcpy(beforeStuf, input);
		for (int i = 0; i < strlen(input); i++)
		{
			if (beforeStuf[i] == '1')
			{
				afterStuf += beforeStuf[i];
				count++;
			}
			else
			{
				afterStuf += beforeStuf[i];
				count = 0;
			}
			if (count == 5 && beforeStuf[i + 1] == '1')
			{
				afterStuf += '0';
				count = 0;
			}
		}
		afterFrame = (flag + afterStuf + flag);
		display(beforeStuf, afterStuf, afterFrame);
		delete[] beforeStuf;
		beforeStuf = nullptr;
		flag.clear();
		afterStuf.clear();
		afterFrame.clear();
	}
}

using namespace sdds;
int main(void)
{
	char input[16] = {'0', '1', '1','1', '1', '1', '1', '0' ,'1' ,'1', '1', '1', '1', '1', '0'};
	convert(input);
	return 0;
}