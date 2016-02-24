#include <iostream>
#include <vector>
#include <limits>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

class Puzzles
{
public:
    int solve(int n, int m, vector<int> f)
    {
        std::sort(f.begin(), f.end());

        int minVal = std::numeric_limits<int>::max();
        int diff = 0;

        for(int i=0; i <= m - n; i++)
        {
            diff = f[i+n-1] - f[i];

            if (minVal > diff)
            {
                minVal = diff;
            }
        }

        return minVal;
    }
};

int main()
{
    Puzzles p;

    string buf;
    string nm;
    string fstr;
    vector<string> bufs;
    vector<int> f;

    std::getline(cin, nm);
    stringstream ss(nm);

    while (ss >> buf)
    {
        bufs.push_back(buf);
    }

    int n = atoi(bufs[0].c_str());
    int m = atoi(bufs[1].c_str());

    bufs.clear();

    std::getline(cin, fstr);
    stringstream fss(fstr);

    while (fss >> buf)
    {
        f.push_back(atoi(buf.c_str()));
    }

    cout << p.solve(n, m, f);
}
