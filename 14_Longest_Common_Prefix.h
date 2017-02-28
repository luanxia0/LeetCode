#pragma once
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:

	struct TrieNode
	{
		int counter;
		unordered_map<char, TrieNode*> next;
	};

	string longestCommonPrefix(vector<string>& strs) {

		if (strs.empty())
		{
			return "";
		}
		if (strs.size() == 1) 
		{
			return strs[0];
		}


		//仅仅是作为一个根节点没有其他意义
		TrieNode *root = new TrieNode;

		string result;

		for (size_t i = 0; i < strs.size(); ++i)
		{
			TrieNode *curNode = root;
			result = "";

			for (size_t j = 0; j < strs[i].size(); ++j)
			{
				auto nextNode = curNode->next.find(strs[i][j]);

				if (nextNode != curNode->next.end())
				{
					curNode = nextNode->second;
					curNode->counter++;
				}
				else
				{
					auto tmpNode = new TrieNode;
					tmpNode->counter = 1;
					curNode->next[strs[i][j]] = tmpNode;
					curNode = tmpNode;
				}
			}
		}

		TrieNode *curNode = root;
		while (!curNode->next.empty())
		{
			if (curNode->next.size() == 1)
			{
				if (curNode->next.begin()->second->counter == strs.size())
				{
					result += curNode->next.begin()->first;
				}
				curNode = curNode->next.begin()->second;
			}
			else
			{
				return result;
			}
		}

		return result;

	}
};