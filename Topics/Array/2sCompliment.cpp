#include <iostream>
#include <vector>
using namespace std;

vector<int> find_compliment(vector<int> binary)
{
    int n = binary.size();

    // creating a secondary vector to store answer (2s compliment) and initialise with 0
    vector<int> twocomp(n, 0);

    // Step 1. Flip the bits make 0->1 and 1->0
    for (int i = 0; i < n; i++)
    {
        twocomp[i] = binary[i] == 0 ? 1 : 0;
        // if (binary[i] == 0)
        // {
        //     twocomp[i] = 1;
        // }
        // else if (binary[i] == 1)
        // {
        //     twocomp[i] = 0;
        // }
    }

    // step 2 add 1 to the flipped bits
    int carry = 1;

    for (int i = twocomp.size() - 1; i >= 0; i--)
    {
        int sum = twocomp[i] + carry;
        twocomp[i] = sum % 2;
        carry = sum / 2;

        if (carry == 0)
        {
            break;
        }
    }

    return twocomp;
}

// Two's Compliment
vector<int> twoscompliment(vector<int> binary)
{
    // Step 1 : Flip the bits
    // Step 2 : Add 1 to the Fliped number
    // Optimization : if carry is 0 break

    // Step 1
    int n = binary.size();
    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++)
    {
        ans[i] = binary[i] == 0 ? 1 : 0;
    }

    // Step 2 : Add 1 to it ans move carry forward
    int carry = 1;

    for (int i = ans.size() - 1; i >= 0; i--)
    {
        int sum = ans[i] + carry;
        ans[i] = sum % 2;
        carry = sum / 2;

        if (carry == 0)
        {
            break;
        }
    }

    return ans;
}

int main()
{
    vector<int> binary = {0, 1, 0, 1, 1, 0};

    vector<int> twoscompli = twoscompliment(binary);

    for (int i = 0; i < twoscompli.size(); i++)
    {
        cout << twoscompli[i] << " ";
    }

    return 0;
}