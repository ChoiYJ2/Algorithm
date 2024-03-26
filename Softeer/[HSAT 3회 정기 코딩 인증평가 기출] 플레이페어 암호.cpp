#include <iostream>
#include <string>

using namespace std;

int alphabet[26];
string message, key, encryptionMessage;
char table[5][5];

void MakeTable()
{
    int kSize = key.size();
    int y = 0, x = 0;
    for(int i  = 0; i < kSize; i++)
    {
        int now = key[i] - 'A';
        if(alphabet[now])
            continue;
        alphabet[now] = 1;
        //cout << key[i] << "*";
        table[y][x] = key[i];
        x = (x + 1) % 5;
        if(x == 0)
            y = (y + 1) % 5;
    }

    for(int i = 0; i < 26; i++)
    {
        if(alphabet[i] || i == 9)
            continue;
        table[y][x] = 'A' + i;
        x = (x + 1) % 5;
        if(x == 0)
            y = (y + 1) % 5;
    }
}

void Encryption(int y1, int x1, int y2, int x2)
{
    if(y1 == y2)
    {
        encryptionMessage += table[y1][(x1 + 1) % 5];
        encryptionMessage += table[y2][(x2 + 1) % 5];
    }
    else if(x1 == x2)
    {
        encryptionMessage += table[(y1 + 1) % 5][x1];
        encryptionMessage += table[(y2 + 1) % 5][x2];
    }
    else
    {
        encryptionMessage += table[y1][x2];
        encryptionMessage += table[y2][x1];
    }
    //cout << encryptionMessage << "***\n";
}

void CutInTwo()
{
    int mSize = message.size();
    int i = 0;
    while(i < mSize)
    {
        string tmpEnc = "";
        tmpEnc += message[i];
        if(i + 1 >= mSize)
        {
            tmpEnc += 'X';
            i++;
        }
        else if(message[i] == message[i + 1])
        { 
            if(message[i] == 'X')
                tmpEnc += 'Q';
            else
                tmpEnc += 'X';
            i++;
        }
        else
        {
            tmpEnc += message[i + 1];
            i += 2;
        }
        //cout << tmpEnc << "\n";

        int y1 = -1, y2 = -1, x1 = -1, x2 = -1;
        for(int i = 0; i < 5; i++)
        {
            int flag = 0;
            for(int j = 0; j < 5; j++)
            {
                //cout << table[i][j] << "*";
                //cout << tmpEnc[0] << tmpEnc[1] << "\n";
                if(table[i][j] == tmpEnc[0])
                {
                    y1 = i;
                    x1 = j;
                }
                if(table[i][j] == tmpEnc[1])
                {
                    y2 = i;
                    x2 = j;
                }
                if(y1 != -1 && y2 != -1 && x1 != -1 && x2 != -1)
                {
                    Encryption(y1, x1, y2, x2);
                    flag = 1;
                    break;
                }
                //cout << "(" << y1 << "," << x1 << ")" << "(" << y2 << "," << x2 << ")\n";
            }
            //cout << "\n";
            if(flag)
                break;
        }
    }
}

int main()
{
    cin >> message >> key;
    MakeTable();
    // cout << "\n";
    // for(int i = 0; i < 5; i++)
    // {
    //     for(int j = 0; j < 5; j++)
    //         cout << table[i][j] << " ";
    //     cout << "\n";
    // }
    CutInTwo();
    cout << encryptionMessage;
    return 0;
}