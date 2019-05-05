

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <string.h>
using namespace std;

string deck[52] = {"S-A","S-2","S-3","S-4","S-5","S-6","S-7","S-8","S-9","S-X","S-J","S-Q","S-K","H-A","H-2","H-3","H-4","H-5","H-6","H-7","H-8","H-9","H-X","H-J","H-Q","H-K","D-A","D-2","D-3","D-4","D-5","D-6","D-7","D-8","D-9","D-X","D-J","D-Q","D-K","C-A","C-2","C-3","C-4","C-5","C-6","C-7","C-8","C-9","C-X","C-J","C-Q","C-K"};

int GenRandom()
{
    return rand()%52;
}

void implement(int row, int mid, int remaining)
{
    string **ar = new string*[row];
    for (int i=0; i<row; i++)
        ar[i] = new string[53];
    
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<53; j++)
        {
            ar[i][j] = "NULL";
        }
    }
    
    
    for (int i=0; i<mid; i++)
    {
        for (int j=0; j<row; j++)
        {
            int iChoose = GenRandom();
            while(deck[iChoose]=="NULL"){
                iChoose = GenRandom();
            }
            ar[j][i] = deck[iChoose];
            deck[iChoose] = "NULL";
        }
    }
    
    for (int i=0; i<remaining; i++)
    {
        int iChoose = GenRandom();
        while(deck[iChoose]=="NULL"){
            iChoose = GenRandom();
        }
        ar[i][mid] = deck[iChoose];
        deck[iChoose]  = "NULL";
    }
    
    
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<=mid; j++)
        {
            if(ar[i][j]!="NULL")
            {
                cout << ar[i][j] << ",";
            }
        }
        cout << endl;
    }
    
    for (int i=0; i<row; i++)
        delete []ar[i];
    delete []ar;
}

int main(int argc, const char * argv[])
{
    string n1; //number of player
    srand((unsigned)time(NULL));
    cout << "人数を入力してください" << endl;
    getline(cin,n1);
    int n = atoi(n1.c_str());
    if(n<=0 || n1.empty())
    {
        cout << "入力値が無いか、値が不正です。";
        return EXIT_FAILURE;
    }
    
    int mid = (int) 52/n;
    int remaining = 52 - mid*n;
    
    implement(n,mid,remaining);
    
    return EXIT_SUCCESS;
}
