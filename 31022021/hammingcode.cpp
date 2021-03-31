#include <bits/stdc++.h>
using namespace std;
  
vector<int> make(vector<int> msgBits, int m, int r)
{
    vector<int> hammingCode(r + m);

    for (int i = 0; i < r; ++i)
    hammingCode[pow(2, i) - 1] = -1;
 
  
    int j = 0;

    for (int i = 0; i < (r + m); i++) 
    {
         if (hammingCode[i] != -1) 
         {
            hammingCode[i] = msgBits[j];
            j++;
         }
    }
  
    for (int i = 0; i < (r + m); i++)
    {
        if (hammingCode[i] != -1)
        continue;
  
        int x = log2(i + 1);
        int one_count = 0;
  
        for (int j = i + 2;
             j <= (r + m); ++j) {
  
            if (j & (1 << x)) {
                if (hammingCode[j - 1] == 1) {
                    one_count++;
                }
            }
        }
  

        if (one_count % 2 == 0) {
            hammingCode[i] = 0;
        }
        else {
            hammingCode[i] = 1;
        }
    }

    return hammingCode;
}

void HammingCode(vector<int>& msgBit)
{

    int m = msgBit.size();

    int r = 1;

    while (pow(2, r) < (m + r + 1)) {
        r++;
    }

    vector<int> ans
        = make(msgBit, m, r);
  

    cout << "Message is: ";
    for (int i = 0; i < msgBit.size(); i++)
        cout << msgBit[i] << " ";
  
    cout << "\nHamming code is: ";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}

int main()
{
    string S;
    cin>>S;

    vector<int> M;
    for(int i=0;i<S.length();i++)
    M.push_back(S[i]-'0');
  
    HammingCode(M);
  
    return 0;
}