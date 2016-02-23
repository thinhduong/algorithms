/*
You are going on a long trip. Y ou start on the road at mile post 0. Along the way there are n
hotels, at mile posts a1 < a2 < ... < an, where each ai
is measured from the starting point. The only places you are allowed to stop are at these hotels, but you can choose which of the hotels
you stop at. You must stop at the final hotel (at distance an), which is your destination.
You'd ideally like to travel 200 miles a day , but this may not be possible (depending on the spacing
of the hotels). If you travel x miles during a day , the penalty for that day is (200 - x)^2. You want
to plan your trip so as to minimize the total penalty - that is, the sum, over all travel days, of the daily penalties.
Give an efficient algorithm that determines the optimal sequence of hotels at which to stop.

Solution:
Lj = min( Li + (200 - aj + ai)^2; i < j and aj - ai <= 200)
*/
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

vector<int *> findHotels(int n, int* hotels)
{
    int* sum = new int[n];
    int* path = new int[n];

    for(int i=0; i<n; i++)
    {
        int minValue = std::numeric_limits<int>::max();
        // compare to the starting point at 0.
        if (hotels[i] <= 200)
        {
            minValue = (200 - hotels[i]) * (200 - hotels[i]);
            path[i] = -1;
        }
        for(int j=0; j<i; j++)
        {
            if (hotels[i] - hotels[j] <= 200)
            {
                int temp = (200 - hotels[i] + hotels[j]) * (200 - hotels[i] + hotels[j]) + sum[j];

                if (minValue >= temp)
                {
                    minValue = temp;
                    path[i] = j;
                }
            }
        }
        sum[i] = minValue;
    }

    vector<int *> ret;
    ret.push_back(sum);
    ret.push_back(path);

    return ret;
}

int main()
{
    int test[] = {100, 300, 450, 480, 670, 720, 800};
    int n = 7;

    vector<int *> ret = findHotels(n, test);
    cout << "minValue " << ret[0][n - 1] << endl;

    int idx = n - 1;
    while (idx > -1)
    {
        cout << idx;
        idx = ret[1][idx];
    }

    return 1;
}
