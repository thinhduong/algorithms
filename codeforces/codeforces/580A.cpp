#include <iostream>
#include <vector>
#include <limits>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class KefaAndFirstSteps
{
public:
    int solve(size_t n, vector<size_t> a)
    {
        size_t maxVal = 1;
        size_t curVal = 1;

        for (size_t i=1; i<n; i++)
        {
            if (a[i - 1] <= a[i])
            {
                curVal += 1;
            }
            else
            {
                curVal = 1;
            }

            if (curVal > maxVal)
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

    KefaAndFirstSteps prog;
    cout << prog.solve(n, f);

    //return 1;
}
*/
