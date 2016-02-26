#include <iostream>
#include <vector>
#include <limits>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class CutRibbon
{
public:
    size_t solve(size_t n, vector<size_t> lens)
    {
        size_t ret[n + 1];

        for(size_t i=0; i< n+1; i++)
        {
            ret[i] = 0;
        }

        ret[0] = 1;

        std::sort(lens.begin(), lens.end());

        size_t maxVal = 0;
        for(size_t i=1; i<= n; i++)
        {
            maxVal = 0;
            for(size_t j=0; j<lens.size(); j++)
            {
                if (lens[j] > i)
                {
                    break;
                }

                if (ret[i - lens[j]] != 0 && (ret[lens[j]] != 0 || lens[j] == i) &&  ret[i - lens[j]] + ret[lens[j]] > maxVal)
                {
                    maxVal = ret[i - lens[j]] + ret[lens[j]];
                }
            }

            ret[i] = maxVal;
        }

        return ret[n];
    }
};

int main()
{
    size_t buf;
    string fstr;
    vector<size_t> f;

    std::getline(cin, fstr);
    stringstream fss(fstr);

    bool isFirst = true;
    size_t n;
    while (fss >> buf)
    {
        if (isFirst)
        {
            n = buf;
            isFirst = false;
        }
        else
        {
            f.push_back(buf);
        }
    }

    CutRibbon prog;
    size_t b = prog.solve(n, f);
    cout << b;
}
