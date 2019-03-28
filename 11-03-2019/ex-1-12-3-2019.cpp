#include<iostream>
using namespace std;

int main()
{
    //PRE=(cin contiene 60 interi, seguiti o dalla coppia "H" x o dalla coppia 'V' y dove x
    //sarà tra 0 e 3 e y tra 0 e 4)
    int A[3][4][5];
    int N = 60;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            for(int k = 0; k < 5; k++)
            {
                cin >> A[i][j][k];
            }
        }
    }
    char mode;
    cin >> mode;
    bool isH = mode == 'H';
    int pos;
    cin >> pos;
    cout << "start" << endl;
    if(isH)
    {
        for(int i = 0; i < 3; i++)
        {
            for(int k = 0; k < 5; k++)
            {
                cout << A[i][pos][k] << ' ';
            }
            cout << endl;
        }
    }
    else
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                cout << A[i][j][pos] << ' ';
            }
            cout << endl;
        }
    }
    cout << "end" << endl;
    //POST=(cout deve contenere gli elementi della fetta specificata dalla coppia letta)
}
