#pragma once
#include "BaseTestDataStructure.h"
#include <string>
#include <sstream>
using namespace std;

/*
59 / 59 test cases passed.
Status: Accepted
Runtime: 6 ms
*/


class Solution {
public:

	int lengthOfLastWord(string s)
	{		
		int i = s.size() - 1;
		while (isspace(s[i]))
		{
			--i;
		}

		if (i == -1)
		{
			return 0;
		}

		int count = 0;
		while (i >= 0 && !isspace(s[i]))
		{
			++count;
			--i;
		}

		return count;
	}
};