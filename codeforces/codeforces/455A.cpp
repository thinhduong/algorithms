#include <iostream>
#include <vector>
#include <limits>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Boredom
{
public:
    long long solve(size_t n, vector<size_t> a)
    {
        size_t maxElem = 0;

        for(size_t i=0; i<n; i++)
        {
            if (maxElem < a[i])
            {
                maxElem = a[i];
            }
        }

        size_t cost[maxElem];

        for(size_t i=0; i<maxElem + 1; i++)
        {
            cost[i] = 0;
        }

        for(size_t i=0; i<n; i++)
        {
            cost[a[i]] += 1;
        }

        long long subMax = 0;
        long long maxVal = 0;
        long long curVal = 0;
        long long pre1Val = 0;
        long long pre2Val = 0;

        for(long long i=1; i < maxElem + 1; i++)
        {
            if (i >= 2)
            {
                if (subMax < pre2Val)
                {
                    subMax = pre2Val;
                }
            }

            curVal = subMax + i * cost[i];
            pre2Val = pre1Val;
            pre1Val = curVal;

            if (maxVal < curVal)
            {
                maxVal = curVal;
            }
        }

        return maxVal;
    }
};

/*
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

    Boredom prog;
    long long b = prog.solve(n, f);
    cout << b;
}
*/
