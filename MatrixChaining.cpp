// MatrixChaining.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <limits>

int _tmain(int argc, _TCHAR* argv[])
{
	//std::vector<int> input = { 8, 12, 4, 10, 6, 8 };
	std::vector<int> input = { 30, 35, 15, 5, 10, 20, 25};
	std::vector<std::vector<long>> matrix = { {} };
	int n = input.size();
	for (int i = 1; i < n; ++i)
	{
		std::vector<long> inner;
		inner.push_back(-100);
		for (int x = n-i; x >= 0; --x)
		{
			if (x != n-i)
			{
				inner.push_back(0);
			}
		}
		matrix.push_back(inner);
	}

	for (int q = 1; q <= n-2; ++q)
	{
		for (int i = 1; i <= ((n-1) - q); ++i)
		{
			int j = i + q;
			long result = std::numeric_limits<long>::max();
			for (int k = i; k < j; ++k)
			{
				long inputResult = input[i - 1] * input[k] * input[j];
				long matrixResult = matrix.at(i).at(n - k) + matrix.at(k + 1).at(n - j);
				long check = matrixResult + inputResult;
				result = std::min(result, check);
			}
			matrix.at(i).at(n-j) = result;
		}
	}
	return 0;
}

