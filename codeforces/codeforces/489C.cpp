#include <iostream>
#include <vector>
#include <limits>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;

class GivenLengthAndSumOfDigits
{
public:
    string solve(size_t m, size_t s)
    {
        std::set<vector<size_t>> rets[m][s + 1];

        for(size_t i=0; i < s+1; i++)
        {
            vector<size_t> ret;
            if (i < 10)
            {
                ret.push_back(i);
            }
            else
            {
                ret.push_back(0);
            }

            rets[0][i].insert(ret);
        }

        for(size_t i=1; i < m; i++)
        {
            vector<size_t> ret;
            ret.push_back(0);

            rets[i][0].insert(ret);
        }

        for(size_t i=1; i < m; i++)
        {
            for(size_t j=1; j < s+1; j++)
            {
                size_t mid = j / 2;

                for(size_t k=0; k <= mid; k++)
                {
                    std::set<vector<size_t>> temps = merge(rets[i-1][k], rets[i-1][j-k], i + 1);

                    set<vector<size_t>>::iterator iter;

                    for(iter = temps.begin(); iter != temps.end(); iter++)
                    {
                        rets[i][j].insert(*iter);
                    }
                }
            }
        }

        std::set<vector<size_t>> ret = rets[m-1][s];
        size_t a = 0
    }

    std::set<vector<size_t>> merge(std::set<vector<size_t>> l, std::set<vector<size_t>> r, size_t n)
    {
        std::set<vector<size_t>> ret;

        set<vector<size_t>>::iterator liter;
        set<vector<size_t>>::iterator riter;

        for(liter = l.begin(); liter != l.end(); ++liter)
        {
            for(riter = r.begin(); riter != r.end(); ++riter)
            {
                ret.insert(merge(*liter, *riter, n));
            }
        }

        return ret;
    }

    std::vector<size_t> merge(vector<size_t> l, vector<size_t> r, size_t n)
    {
        vector<size_t> temp;
        size_t i = 0;
        size_t j = 0;

        size_t total = l.size() + r.size();

        for(size_t k=0; k < total; k++)
        {
            if (l[i] <= r[j])
            {
                temp.push_back(l[i]);
                i++;
            }
            else
            {
                temp.push_back(r[j]);
                j++;
            }
        }

        vector<size_t> newVec(temp.begin() + temp.size() - n, temp.end());
        return newVec;
    }
};

int main()
{
    GivenLengthAndSumOfDigits prog;
    prog.solve(2, 15);
}