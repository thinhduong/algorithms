/*
L[j] = max(L[j - 1] + aj, aj)
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int*> findContiguousSubsequence(int n, int *arr)
{
    int *sum = new int[n];
	int *path = new int[n];

	for(int i=0; i < n; i++)
	{
		sum[i] = 0;
	}

	sum[0] = *arr;
	path[0] = -1;

	for (int i=1; i < n; i++)
	{
		int temp  = sum[i - 1] + *(arr + i);
		if (temp >= sum[i])
		{
			sum[i] = temp;
			path[i] = i-1;
		}
		else
		{
			sum[i] = *(arr + i);
			path[i] = -1;
		}
	}

    vector<int*> vec;
    vec.push_back(sum);
    vec.push_back(path);

	return vec;
}

int findIndexWithMaxValue(int n, int *arr)
{
    int max = *arr;
    int idx = 0;
    for(int i=1; i<n; i++)
    {
        if (*(arr + i) > max)
        {
            max = *(arr + i);
            idx = i;
        }
    }

    cout << "max value " << max << endl;

    return idx;
}

void printPath(int idx, int *path)
{
    while(idx > -1)
    {
        cout << idx;
        idx = path[idx];
    }
}

int main()
{
    int test[] = {5, 15, -30, 10, -5, 40, 10};
    vector<int*>ret = findContiguousSubsequence(7, test);

    int idxMaxValue = findIndexWithMaxValue(7, ret[0]);
    printPath(idxMaxValue, ret[1]);

    return 0;
}

