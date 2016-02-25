#include <iostream>
#include <vector>
#include <limits>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class FlippingGame
{
public:
    int solve(size_t n, vector<size_t> a)
    {
        size_t ret[n][n];
        size_t ret1[n][n];

        for (size_t i=0; i < n; i++)
        {
            for (size_t j=0; j < n; j++)
            {
                ret[i][j] = 0;
                ret1[i][j] = 0;
            }
        }


        for (size_t i=0; i<n; i++)
        {
            for (size_t j=i; j<n; j++)
            {
                if (i == 0 && j == 0)
                {
                    if (a[j] == 0)
                    {
                        ret[i][j] = 1;
                        ret1[i][j] = 0;
                    }
                    else
                    {
                        ret[i][j] = 0;
                        ret1[i][j] = 1;
                    }
                }
                else
                {
                    if (a[j] == 0)
                    {
                        ret[i][j] = 1 + ret[i][j-1];
                        ret1[i][j] = ret1[i][j-1];
                    }
                    else
                    {
                        ret[i][j] = ret[i][j-1];
                        ret1[i][j] = ret1[i][j-1] + 1;
                    }
                }
            }
        }

        size_t maxSum = 0;
        size_t sum = 0;

        for (int i=0; i<n; i++)
        {
            for (int j=i; j<n; j++)
            {
                sum = 0;
                if (i - 1 >= 0)
                    sum += ret1[0][i - 1];

                if (j + 1 < n)
                    sum += ret1[j + 1][n - 1];

                if (maxSum < sum + ret[i][j])
                {
                    maxSum = sum + ret[i][j];
                }
            }
        }

        return maxSum;
    }
};

int main()
{

   size_t buf;
    string nm;
    string fstr;
    size_t n;
    vector<size_t> f;

    std::getline(cin, nm);
    stringstream ss(nm);

    ss >> n;

    std::getline(cin, fstr);
    stringstream fss(fstr);

    while (fss >> buf)
    {
        f.push_back(buf);
    }

/*
    size_t n = 5;
    vector<size_t> f;

    f.push_back(1);
    f.push_back(0);
    f.push_back(0);
    f.push_back(1);
    f.push_back(0); */

    FlippingGame prog;
    size_t b = prog.solve(n, f);
    cout << b;
}
