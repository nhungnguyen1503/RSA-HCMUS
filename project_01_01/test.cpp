#pragma comment(linker, "/STACK:5000000")
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

const vector<int> Bit0 = {0};
const vector<int> Bit1 = {1};
const vector<int> Bit2 = {0, 1};

/*
Chuyen chuoi Hex sang chuoi Binary
Input:	1 string ( chuoi Hex ) ( strHex ).
Output: 1 vector ( chuoi Binary ).
*/
vector<int> convertHexToBinary(string strHex)
{
	vector<int> arrBit;
	for (int i = 0; i < strHex.length(); i++)
	{
		switch (strHex[i])
		{
		case '0':
		{
			arrBit.push_back(0);
			arrBit.push_back(0);
			arrBit.push_back(0);
			arrBit.push_back(0);
			break;
		}
		case '1':
		{
			arrBit.push_back(1);
			arrBit.push_back(0);
			arrBit.push_back(0);
			arrBit.push_back(0);
			break;
		}
		case '2':
		{
			arrBit.push_back(0);
			arrBit.push_back(1);
			arrBit.push_back(0);
			arrBit.push_back(0);
			break;
		}
		case '3':
		{
			arrBit.push_back(1);
			arrBit.push_back(1);
			arrBit.push_back(0);
			arrBit.push_back(0);
			break;
		}
		case '4':
		{
			arrBit.push_back(0);
			arrBit.push_back(0);
			arrBit.push_back(1);
			arrBit.push_back(0);
			break;
		}
		case '5':
		{
			arrBit.push_back(1);
			arrBit.push_back(0);
			arrBit.push_back(1);
			arrBit.push_back(0);
			break;
		}
		case '6':
		{
			arrBit.push_back(0);
			arrBit.push_back(1);
			arrBit.push_back(1);
			arrBit.push_back(0);
			break;
		}
		case '7':
		{
			arrBit.push_back(1);
			arrBit.push_back(1);
			arrBit.push_back(1);
			arrBit.push_back(0);
			break;
		}
		case '8':
		{
			arrBit.push_back(0);
			arrBit.push_back(0);
			arrBit.push_back(0);
			arrBit.push_back(1);
			break;
		}
		case '9':
		{
			arrBit.push_back(1);
			arrBit.push_back(0);
			arrBit.push_back(0);
			arrBit.push_back(1);
			break;
		}
		case 'A':
		{
			arrBit.push_back(0);
			arrBit.push_back(1);
			arrBit.push_back(0);
			arrBit.push_back(1);
			break;
		}
		case 'B':
		{
			arrBit.push_back(1);
			arrBit.push_back(1);
			arrBit.push_back(0);
			arrBit.push_back(1);
			break;
		}
		case 'C':
		{
			arrBit.push_back(0);
			arrBit.push_back(0);
			arrBit.push_back(1);
			arrBit.push_back(1);
			break;
		}
		case 'D':
		{
			arrBit.push_back(1);
			arrBit.push_back(0);
			arrBit.push_back(1);
			arrBit.push_back(1);
			break;
		}
		case 'E':
		{
			arrBit.push_back(0);
			arrBit.push_back(1);
			arrBit.push_back(1);
			arrBit.push_back(1);
			break;
		}
		case 'F':
		{
			arrBit.push_back(1);
			arrBit.push_back(1);
			arrBit.push_back(1);
			arrBit.push_back(1);
			break;
		}
		}
	}
	while (arrBit[arrBit.size() - 1] == 0 && arrBit.size() > 1)
	{
		arrBit.pop_back();
	}
	return arrBit;
}

/*
Kiem tra chuoi Hex co phai la 2 hoac la 3 khong ?
*	Mo rong:	Kiem tra co phai la 0 hoac 1 khong ?
Input:	1 string ( chuoi Hex ) ( strHex ).
Output:	1 trong 3 gia tri ( 0, 1, 2 ).
		*	1:	Chuoi Hex la 2 hoac la 3.
		*	2:	Chuoi Hex la 0 hoac la 1.
		*	0:	Chuoi Hex khong thuoc cac truong hop tren.
*/
int isNumber2or3(string strHex)
{
	if (strHex.length() != 1)
		return 0;
	if (strHex == "0" || strHex == "1")
		return 2;
	if (strHex == "2" || strHex == "3")
		return 1;
	return 0;
}

/*
Kiem tra chuoi Hex co phai la so chan khong ?
Input:	1 string ( chuoi Hex ) ( strHex ).
Output:	True hoac False.
		*	True:	Chuoi Hex la 1 so chan.
		*	False:	Chuoi Hex la 1 so le.
*/
bool isEvenNumber(string strHex)
{
	char tempStrHex = strHex[0];
	if (tempStrHex == '0' || tempStrHex == '2' || tempStrHex == '4' || tempStrHex == '6' || tempStrHex == '8' || tempStrHex == 'A' || tempStrHex == 'C' || tempStrHex == 'E')
		return true;
	return false;
}

/*
So sanh 2 so nguyen lon duoi dang Binary
Input:	1 vector ( chuoi Binary ) ( arrBit1 ), 1 vector ( chuoi Binary ) ( arrBit2 ).
Output:	1 vector ( chuoi Binary ).
Output:	1 trong 3 gia tri ( 0, 1, 2 ).
		*	1  :	a > b.
		*	-1 :	a < b.
		*	0  :	a = b.
*/
int compareBigNum(vector<int> arrBit1, vector<int> arrBit2)
{
	if (arrBit1.size() != arrBit2.size())
	{
		if (arrBit1.size() > arrBit2.size())
			return 1;
		else
			return -1;
	}
	for (int i = arrBit1.size() - 1; i >= 0; i--)
	{
		if (arrBit1[i] > arrBit2[i])
			return 1;
		if (arrBit1[i] < arrBit2[i])
			return -1;
	}
	return 0;
}

/*
Tim s va r trong:
n - 1 = ( 2 ^ s ) * r. Voi r la 1 so le.

Input:	1 vector ( chuoi Binary ) ( arrBitN ), 1 so nguyen ( s )
		, 1 vector ( chuoi Binary ) ( arrBitR ).
Output:	Ket qua khong tra truc tiep ve ma thong qua 2 bien ( s ) va ( arrBitR ).
*/
void findSandR(vector<int> arrBitN, int &s, vector<int> &arrBitR)
{
	s = 0;
	vector<int> tempArrBit = arrBitN;
	tempArrBit[0] = 0;
	while (tempArrBit[0] == 0)
	{
		s++;
		tempArrBit.erase(tempArrBit.begin());
	}
	arrBitR = tempArrBit;
}

/*
Cong 2 so nguyen lon duoi dang Binary
Input:	1 vector ( chuoi Binary ) ( arrBit1 ), 1 vector ( chuoi Binary ) ( arrBit2 ).
Output:	1 vector ( chuoi Binary ).
*/
vector<int> addBigNum(vector<int> arrBit1, vector<int> arrBit2)
{
	vector<int> arrBitResult;
	int carry = 0;
	if (arrBit1.size() == 0)
		return arrBit2;
	if (arrBit2.size() == 0)
		return arrBit1;

	while (arrBit1.size() != arrBit2.size())
	{
		if (arrBit1.size() > arrBit2.size())
			arrBit2.push_back(0);
		else
			arrBit1.push_back(0);
	}
	for (int i = 0; i < arrBit1.size(); i++)
	{
		arrBitResult.push_back((arrBit1[i] + arrBit2[i] + carry) % 2);
		if (arrBit1[i] + arrBit2[i] + carry >= 2)
			carry = 1;
		else
			carry = 0;
	}
	if (carry == 1)
		arrBitResult.push_back(1);
	while (arrBitResult[arrBitResult.size() - 1] == 0 && arrBitResult.size() > 1)
	{
		arrBitResult.pop_back();
	}
	return arrBitResult;
}

/*
Nhan 2 so nguyen lon duoi dang Binary
Input:	1 vector ( chuoi Binary ) ( arrBit1 ), 1 vector ( chuoi Binary ) ( arrBit2 ).
Output:	1 vector ( chuoi Binary ).
*/
vector<int> mulBigNum(vector<int> arrBit1, vector<int> arrBit2)
{
	vector<int> arrBitResult;
	vector<int> tempArrBit2 = arrBit2;

	if (compareBigNum(Bit2, arrBit1) == 0)
	{
		arrBit2.insert(arrBit2.begin(), 0);
		return arrBit2;
	}
	else
	{
		if (compareBigNum(Bit2, arrBit2) == 0)
		{
			arrBit1.insert(arrBit1.begin(), 0);
			return arrBit1;
		}
	}

	for (int i = 0; i < arrBit1.size(); i++)
	{
		if (i != 0)
		{
			tempArrBit2.insert(tempArrBit2.begin(), 0);
		}
		if (arrBit1[i] == 1)
		{
			arrBitResult = addBigNum(arrBitResult, tempArrBit2);
		}
	}
	return arrBitResult;
}

/*
Tru 2 so nguyen lon duoi dang Binary
Input:	1 vector ( chuoi Binary ) ( arrBit1 ), 1 vector ( chuoi Binary ) ( arrBit2 ).
Output:	1 vector ( chuoi Binary ).
*/
vector<int> subBigNum(vector<int> arrBit1, vector<int> arrBit2)
{
	vector<int> arrBitResult;
	int carry = 0;
	int tempCarry = 0;
	while (arrBit1.size() != arrBit2.size())
	{
		if (arrBit1.size() > arrBit2.size())
			arrBit2.push_back(0);
		else
			arrBit1.push_back(0);
	}
	for (int i = 0; i < arrBit1.size(); i++)
	{
		if (arrBit1[i] >= arrBit2[i] + carry)
		{
			arrBitResult.push_back(arrBit1[i] - (arrBit2[i] + carry));
			carry = 0;
		}
		else
		{
			if (arrBit1[i] - (arrBit2[i] + carry) == -1)
			{
				arrBitResult.push_back(1);
				carry = 1;
			}
			else
			{
				arrBitResult.push_back(0);
				carry = 1;
			}
		}
	}
	while (arrBitResult[arrBitResult.size() - 1] == 0 && arrBitResult.size() > 1)
	{
		arrBitResult.pop_back();
	}
	return arrBitResult;
}

/*
Chia 2 so nguyen lon duoi dang Binary
Input:	1 vector ( chuoi Binary ) ( arrBit1 ), 1 vector ( chuoi Binary ) ( arrBit2 )
		, 1 vector ( chuoi Binary ) ( arrBit3 ), 1 vector ( chuoi Binary ) ( arrBit4 ).
Output:	Ket qua khong tra truc tiep ve ma thong qua 2 bien ( arrBit3 ) va ( arrBit4 ).
		*	arrBit3: Phan nguyen.
		*	arrBit4: Phan du.
*/
void divBigNum(vector<int> arrBit1, vector<int> arrBit2, vector<int> &arrBit3, vector<int> &arrBit4)
{
	arrBit3.clear();
	arrBit4.clear();
	vector<int> tempArrBit1 = arrBit1;
	vector<int> tempArrBit2 = arrBit2;
	if (compareBigNum(tempArrBit1, tempArrBit2) == -1)
	{
		arrBit3 = Bit0;
		arrBit4 = tempArrBit1;
		return;
	}
	if (compareBigNum(arrBit2, Bit2) == 0)
	{
		if (tempArrBit1[0] == 0)
		{
			tempArrBit1.erase(tempArrBit1.begin());
			arrBit3 = tempArrBit1;
			arrBit4 = Bit0;
			return;
		}
		else
		{
			tempArrBit1.erase(tempArrBit1.begin());
			arrBit3 = tempArrBit1;
			arrBit4 = Bit1;
			return;
		}
	}

	while (compareBigNum(tempArrBit1, tempArrBit2) != -1)
	{
		tempArrBit2.insert(tempArrBit2.begin(), 0);
	}
	tempArrBit2.erase(tempArrBit2.begin());
	arrBit3.push_back(1);
	tempArrBit1 = subBigNum(tempArrBit1, tempArrBit2);

	while (tempArrBit2.size() > arrBit2.size())
	{
		tempArrBit2.erase(tempArrBit2.begin());
		if (compareBigNum(tempArrBit1, tempArrBit2) == -1)
		{
			arrBit3.insert(arrBit3.begin(), 0);
		}
		else
		{
			arrBit3.insert(arrBit3.begin(), 1);
			tempArrBit1 = subBigNum(tempArrBit1, tempArrBit2);
		}
	}
	arrBit4 = tempArrBit1;
}

/*
Tao 1 so nguyen lon tu A den B
Input:	1 vector ( chuoi Binary ) ( arrBit1 ), 1 vector ( chuoi Binary ) ( arrBit2 ).
Output:	1 vector ( chuoi Binary ).
*/
vector<int> genArrBit(vector<int> &arrBit1, vector<int> &arrBit2)
{
	vector<int> arrBitResult;
	srand(time(NULL));
	int len;
	if (arrBit2.size() - arrBit1.size() == 0)
		len = arrBit1.size();
	else
		len = (rand() % (arrBit2.size() - arrBit1.size())) + arrBit1.size();
	do
	{
		arrBitResult.clear();
		for (int j = 0; j < len; j++)
		{
			arrBitResult.push_back(rand() % 2);
		}
		while (arrBitResult[arrBitResult.size() - 1] == 0 && arrBitResult.size() > 1)
		{
			arrBitResult.pop_back();
		}
	} while (compareBigNum(arrBitResult, arrBit1) < 0 || compareBigNum(arrBitResult, arrBit2) > 0);
	return arrBitResult;
}

/*
Nhan binh phuong co lap:
	y = ( a ^ r ) mod n.
Input:	1 vector ( chuoi Binary ) ( arrBitA ), 1 vector ( chuoi Binary ) ( arrBitN )
		, 1 vector ( chuoi Binary ) ( arrBitR ), 1 vector ( chuoi Binary ) ( arrBitY ).
Output:	Ket qua khong tra truc tiep ve ma thong qua bien ( arrBitY ).
*/
void iterativeSquaring(vector<int> arrBitA, vector<int> arrBitN, vector<int> arrBitR, vector<int> &arrBitY)
{
	vector<int> tempArrBitA;
	vector<int> tempArrBitB;
	vector<int> tempArrBit;
	if (compareBigNum(arrBitA, Bit0) == 0 || compareBigNum(arrBitA, arrBitR) == 0)
	{
		arrBitY = Bit0;
		return;
	}
	if (compareBigNum(arrBitR, Bit0) == 0)
	{
		arrBitY = Bit1;
		return;
	}

	tempArrBitA = arrBitA;
	tempArrBitB.push_back(1);

	if (arrBitR[0] == 1)
		tempArrBitB = arrBitA;

	for (int i = 1; i < arrBitR.size(); i++)
	{
		divBigNum(mulBigNum(tempArrBitA, tempArrBitA), arrBitN, tempArrBit, tempArrBitA);
		if (arrBitR[i] == 1 && i != 0)
			divBigNum(mulBigNum(tempArrBitA, tempArrBitB), arrBitN, tempArrBit, tempArrBitB);
	}

	while (tempArrBitB[tempArrBitB.size() - 1] == 0 && tempArrBitB.size() > 1)
	{
		tempArrBitB.pop_back();
	}
	arrBitY = tempArrBitB;
}

/*
Kiem tra N co phai la so nguyen to khong ? ( voi so lan t nhat dinh )
Input:	1 vector ( chuoi Binary ) ( arrBit1 ),  1 so nguyen ( t ).
Output:	True hoac False.
		*	True:	La so nguyen to.
		*	False:	Khong phai so nguyen to.
*/
bool millerRabin(vector<int> arrBitN, int t)
{
	vector<int> tempArrBit;
	vector<int> tempArrBitN;
	vector<int> arrBitR;

	vector<int> tempArrBit2 = Bit2;
	vector<int> tempArrBitNSub2 = subBigNum(arrBitN, Bit2);
	int s = 0;
	tempArrBit.push_back(1);
	tempArrBitN = subBigNum(arrBitN, tempArrBit);
	findSandR(tempArrBitN, s, arrBitR);
	for (int i = 1; i <= t; i++)
	{
		vector<int> arrBitA;
		vector<int> arrBitY;
		arrBitA = genArrBit(tempArrBit2, tempArrBitNSub2);
		iterativeSquaring(arrBitA, arrBitN, arrBitR, arrBitY);
		if (compareBigNum(arrBitY, tempArrBit) != 0 && compareBigNum(arrBitY, tempArrBitN) != 0)
		{
			int j = 1;
			vector<int> tempArrBit2 = Bit2;
			while (j <= s - 1 && compareBigNum(arrBitY, tempArrBitN) != 0)
			{
				iterativeSquaring(arrBitY, arrBitN, tempArrBit2, arrBitY);
				if (compareBigNum(arrBitY, tempArrBit) == 0)
					return false;
				j++;
			}
			if (compareBigNum(arrBitY, tempArrBitN) != 0)
				return false;
		}
	}
	return true;
}

int main(int argc, char **argv)
{
	string strHex;
	vector<int> arrBit;
	int time = 1;
	const char *fileIn = argv[1];
	const char *fileOut = argv[2];

	ifstream in;
	in.open(fileIn);

	in >> strHex;
	strHex = "1DA50F8400AACA58E4D33FEE";
	cout << strHex;
	arrBit = convertHexToBinary(strHex);
	if (isNumber2or3(strHex) == 1)
	{
		cout << 1;
		return 0;
	}
	if (isNumber2or3(strHex) == 2 || isEvenNumber(strHex))
	{
		cout << 0;
		return 0;
	}
	vector<int> num;

	int s;
	vector<int> r;
	findSandR(arrBit, s, r);
	vector<int> a;
	a.push_back(1);
	a.push_back(0);
	a.push_back(1);

	cout << "bit: ";
	for (int i = 0; i < arrBit.size(); i++)
	{
		cout << arrBit[i];
	}
	cout << endl;
	cout << "r: ";
	for (int i = 0; i < r.size(); i++)
	{
		cout << r[i];
	}
	cout << endl;

	vector<int> y;
	iterativeSquaring(a, arrBit, r, y);
	cout << "y: ";
	for (int i = 0; i < y.size(); i++)
	{
		cout << y[i];
	}
	cout << endl;

	if (arrBit.size() <= 128)
		time = 10;
	else if (arrBit.size() <= 256)
		time = 10;
	else if (arrBit.size() <= 348)
		time = 3;
	else
		time = 2;

	if (millerRabin(arrBit, time))
	{
		cout << 1;
		return 0;
	}
	else
	{
		cout << 0;
		return 0;
	}

	return 0;
}