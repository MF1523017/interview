#pragma once
#include<iostream>
using std::cout;
using std::endl;
class Solution {
public:
	bool isNumeric(char* string)
	{
		int index = 0;
		if ('+' == *string)
		{
			string++;
			index++;
		}
		else if ('-' == *string) {
			string++;
			index++;
		}
		int e_index = -1;
		int p_index = -1;

		bool e = false;
		bool p = false;
		while ('\0' != *string)
		{
			if ('e' == *string || 'E' == *string) {
				if (e)
					return false;
				else {
					e_index = index;
					e = !e;
					string++;
					if ('+' == *string || '-' == *string)
					{
						index++;
						string++;
					}
					else if ('\0' == *string)
						return false;
				}
			}
			else if ('.' == *string)
			{
				if (p)
					return false;
				else {
					p_index = index;
					p = !p;
				}
			}
			else if (*string>'9' || *string<'0')
				return false;
			string++;
			index++;
		}
		if (e&&p&&e_index<p_index)
			return false;
		return true;
	}
};
void testSolution()
{
	Solution s;
	cout << s.isNumeric("123.45e+6") << endl;
}