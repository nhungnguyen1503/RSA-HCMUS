#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <cstdint>
#include <vector>
#include <bitset>
#include <ctime>

using namespace std;

vector<char> readFile(const string &fileName)
{
    ifstream fin;
    char hexChar;
    vector<char> hexNum;
    fin.open(fileName);

    if (fin.is_open())
    {
        while (!fin.eof())
        {
            fin >> hexChar;
            hexNum.push_back(hexChar);
        }

        fin.close();
        hexNum.pop_back();
    }
    else
    {
        cout << "Can't open file.";
    }
    return hexNum;
}

vector<char> hexToBinary(const vector<char> &hexNum)
{
    vector<char> binNum;
    binNum.reserve(hexNum.size() * 4);

    for (int i = 0; i < hexNum.size(); i++)
    {
        if (isxdigit(hexNum[i]))
        {
            int hexValue;
            if (isdigit(hexNum[i]))
            {
                hexValue = hexNum[i] - '0';
            }
            else
            {
                hexValue = tolower(hexNum[i]) - 'a' + 10;
            }
            bitset<4> bits(hexValue);
            for (int i = 0; i < 4; i++)
            {
                binNum.push_back(bits[3 - i] ? '1' : '0');
            }
        }
    }
    return binNum;
}

bool isOdd(vector<char> &binNum)
{
    if (binNum.back() == '0')
    {
        return false;
    }
    return true;
}

void printNum(vector<char> &num)
{
    for (int i = 0; i < num.size(); i++)
    {
        cout << num[i];
    }
}

// n-1 = 2^r*m, k=2^r

void findKandM(vector<char> binNum, vector<char> &kNum, vector<char> &mNum, int &r)
{
    binNum.pop_back();
    kNum.push_back('0');
    for (int i = binNum.size() - 1; i >= 0; i--)
    {
        if (binNum[i] == '0')
        {
            kNum.push_back('0');
            binNum.pop_back();
        }
        if (binNum[i] == '1')
        {
            kNum.insert(kNum.begin(), '1');
            i = -1;
        }
    }
    r = kNum.size() + 1;
    mNum = binNum;
}

vector<char> addNum(vector<char> binNum1, vector<char> binNum2)
{
    vector<char> res;
    int len1 = binNum1.size();
    int len2 = binNum2.size();
    int sto = 0;
    if (len1 > len2)
    {
        for (int i = 0; i < len1 - len2; i++)
        {
            binNum2.insert(binNum2.begin(), '0');
        }
    }
    if (len1 < len2)
    {
        for (int i = 0; i < len2 - len1; i++)
        {
            binNum1.insert(binNum1.begin(), '0');
        }
    }

    for (int i = binNum1.size() - 1; i >= 0; i--)
    {
        char temp = binNum1[i];
        if (binNum1[i] == '0' && binNum2[i] == '0')
        {
            if (sto == 1)
            {
                res.insert(res.begin(), '1');
                sto = 0;
            }
            else
            {
                res.insert(res.begin(), '0');
            }
        }
        else if (binNum1[i] == '1' && binNum2[i] == '0')
        {
            if (sto == 1)
            {
                res.insert(res.begin(), '0');
            }
            else
            {
                res.insert(res.begin(), '1');
            }
        }
        else if (binNum1[i] == '0' && binNum2[i] == '1')
        {
            if (sto == 1)
            {
                res.insert(res.begin(), '0');
            }
            else
            {
                res.insert(res.begin(), '1');
            }
        }
        else if (binNum1[i] == '1' && binNum2[i] == '1')
        {
            if (sto == 1)
            {
                res.insert(res.begin(), '1');
            }
            else
            {
                res.insert(res.begin(), '0');
                sto = 1;
            }
        }
    }
    if (sto == 1)
    {
        res.insert(res.begin(), '1');
        sto = 0;
    }
    return res;
}

vector<char> notBin(vector<char> bin)
{
    vector<char> one;
    vector<char> res;
    one.push_back('1');
    for (int i = 0; i < bin.size(); i++)
    {
        bin[i] == '0' ? bin[i] = '1' : bin[i] = '0';
    }
    res = addNum(bin, one);
    return res;
}

vector<char> subNum(vector<char> binNum1, vector<char> binNum2)
{
    vector<char> res;
    int len1 = binNum1.size();
    int len2 = binNum2.size();
    int sto = 0;
    if (len1 > len2)
    {
        for (int i = 0; i < len1 - len2; i++)
        {
            binNum2.insert(binNum2.begin(), '0');
        }
    }
    if (len1 < len2)
    {
        for (int i = 0; i < len2 - len1; i++)
        {
            binNum1.insert(binNum1.begin(), '0');
        }
    }
    vector<char> bin2temp;
    bin2temp = notBin(binNum2);
    res = addNum(binNum1, bin2temp);
    res.erase(res.begin());
    return res;
}

void shiftLeft(vector<char> &A, vector<char> &Q)
{
    char temp = Q[0];
    for (int i = 0; i < A.size(); i++)
    {
        i == A.size() - 1 ? A[i] = temp : A[i] = A[i + 1];
    }
    for (int i = 0; i < A.size(); i++)
    {
        i == A.size() - 1 ? Q[i] = '0' : Q[i] = Q[i + 1];
    }
}

void shiftRight(vector<char> &A, vector<char> &Q1)
{
    char temp = A[A.size() - 1], temp1 = A[0];
    for (int i = A.size() - 1; i >= 0; i--)
    {
        i == 0 ? A[i] = '0' : A[i] = A[i - 1];
    }
    for (int i = Q1.size() - 1; i >= 0; i--)
    {
        i == 0 ? Q1[i] = temp : Q1[i] = Q1[i - 1];
    }
    A[0] = temp1;
}

vector<char> createBinZero(int n)
{
    vector<char> res;
    for (int i = 0; i < n; i++)
    {
        res.push_back('0');
    }
    return res;
}

vector<char> mulNum(vector<char> binNum1, vector<char> binNum2)
{
    vector<char> res;
    int len1 = binNum1.size();
    int len2 = binNum2.size();
    if (len1 == 1 && binNum1.back() == '1')
    {
        return binNum2;
    }
    if (len2 == 1 && binNum2.back() == '1')
    {
        return binNum1;
    }
    if (len1 == 1 && binNum1.back() == '0')
    {
        res.push_back('0');
        return res;
    }
    if (len2 == 1 && binNum2.back() == '0')
    {
        res.push_back('0');
        return res;
    }

    for (int i = 0; i < len1; i++)
    {
        binNum2.insert(binNum2.begin(), '0');
    }
    for (int i = 0; i < len2; i++)
    {
        binNum1.insert(binNum1.begin(), '0');
    }
    vector<char> A;
    A = createBinZero(binNum1.size());

    int k = binNum1.size();

    vector<char> Q1;
    Q1 = binNum1;
    Q1.push_back('0');

    vector<char> M;
    M = binNum2;

    while (k > 0)
    {
        if (Q1[Q1.size() - 2] == '1' && Q1[Q1.size() - 1] == '0')
        {
            A = subNum(A, M);
        }
        else if (Q1[Q1.size() - 2] == '0' && Q1[Q1.size() - 1] == '1')
        {
            A = addNum(A, M);
        }
        shiftRight(A, Q1);
        k--;
    }
    for (int i = 0; i < Q1.size(); i++)
    {
        if (Q1[i] == '0')
        {
            Q1.erase(Q1.begin());
        }
        if (Q1[i] == '1')
        {
            i = Q1.size();
        }
    }
    Q1.pop_back();
    return Q1;
}

void divNum(vector<char> binNum1, vector<char> binNum2, vector<char> &res, vector<char> &mod)
{
    int len1 = binNum1.size();
    int len2 = binNum2.size();
    int length;
    if (len1 > len2)
    {
        if (len1 <= 64)
            length = 64;
        if (len1 > 64 && len1 <= 128)
            length = 128;
        if (len1 > 128 && len1 <= 256)
            length = 256;
        if (len1 > 256 && len1 <= 512)
            length = 512;
    }
    if (len2 > len1)
    {
        if (len2 <= 64)
            length = 64;
        if (len2 > 64 && len2 <= 128)
            length = 128;
        if (len2 > 128 && len2 <= 256)
            length = 256;
        if (len2 > 256 && len2 <= 512)
            length = 512;
    }

    for (int i = 0; i < length - len2; i++)
    {
        binNum2.insert(binNum2.begin(), '0');
    }
    for (int i = 0; i < length - len1; i++)
    {
        binNum1.insert(binNum1.begin(), '0');
    }

    vector<char> A;
    A = createBinZero(binNum1.size());

    int k = binNum1.size();

    vector<char> Q;
    Q = binNum1;

    vector<char> M;
    M = binNum2;

    if (Q[0] == '1')
    {
        Q = notBin(Q);
    }
    if (M[0] == '1')
    {
        M = notBin(M);
    }
    while (k > 0)
    {
        shiftLeft(A, Q);
        A = subNum(A, M);
        if (A[0] == '1')
        {
            Q[Q.size() - 1] = '0';
            A = addNum(A, M);
        }
        else
        {
            Q[Q.size() - 1] = '1';
        }
        k--;
    }
    if (binNum1[0] ^ binNum2[0])
    {
        Q = notBin(Q);
        A = notBin(A);
    }
    A[0] = '0';
    res = Q;
    mod = A;
}

vector<char> powNum(vector<char> binNum, vector<char> binPow)
{
    vector<char> res;
    vector<char> tempNum;
    tempNum = binNum;
    res.push_back('1');
    for (int i = binPow.size() - 2; i >= 0; i--)
    {
        binNum = mulNum(binNum, binNum);
        if (binPow[i] == '1')
        {
            res = mulNum(res, binNum);
        }
    }
    if (binPow.back() == '1')
    {
        res = mulNum(res, tempNum);
    }
    return res;
}

bool isOne(vector<char> binNum)
{
    if (binNum.back() != '1')
        return false;
    if (binNum.back() == '1')
    {
        for (int i = 0; i < binNum.size() - 1; i++)
        {
            if (binNum[i] == '1')
                return false;
        }
    }
    return true;
}

vector<char> intToBinary(int num)
{
    vector<char> bin;
    for (int i = 3; i >= 0; i--)
    {
        char bit = (num & (1 << i)) ? '1' : '0';
        bin.push_back(bit);
    }
    return bin;
}

vector<char> randomNum()
{
    vector<char> res;

    int ran[1] = {2};
    srand(time(NULL));
    // int ranIndex = (rand() % 4) + 1;
    int ranIndex = 0;

    res = intToBinary(ran[ranIndex]);
    return res;
}

bool millerRabin(vector<char> binNum)
{
    int r;
    if (!isOdd(binNum))
        return false;
    if (binNum.size() == 2)
        return true;

    vector<char> kNum;
    vector<char> mNum;

    findKandM(binNum, kNum, mNum, r);

    vector<char> a;
    a = randomNum();
    cout << endl;
    cout << "random: ";
    printNum(a);
    cout << endl;

    vector<char> index;
    vector<char> y;
    vector<char> yPowIndex;
    index.push_back('1');
    y = powNum(a, mNum);
    for (int i = 0; i < r; i++)
    {
        vector<char> divY;
        vector<char> modY;
        yPowIndex = powNum(y, index);
        divNum(yPowIndex, binNum, divY, modY);
        if (isOne(modY))
        {
            return true;
        }
        index.push_back('0');
    }
    return false;
}

bool isPrime(vector<char> binNum)
{
    if (!isOdd(binNum))
    {
        return false;
    }
    if (!millerRabin(binNum))
        return false;
    return true;
}

int main(int argc, char **argv)
{
    const char *fileIn = argv[1];
    const char *fileOut = argv[2];
    vector<char> a;
    a.push_back('1');
    a.push_back('0');
    a.push_back('1');

    vector<char> hexNum = readFile(fileIn);
    vector<char> binNum = hexToBinary(hexNum);
    cout << "cui cung: ";
    cout << binNum.back();

    if (isPrime(binNum) == true)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    ofstream fout;
    fout.open(fileOut);
    fout.close();

    return 0;
}
