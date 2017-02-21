#pragma once
#include "BaseTestDataStructure.h"

/*
26 / 26 test cases passed.
Status: Accepted
Runtime: 19 ms
*/

class Solution {
public:

	ListNode *reverseList(ListNode *head)
	{
		ListNode tmpHead(0);
		while (head)
		{
			auto tmpNode = head;
			head = head->next;
			tmpNode->next = tmpHead.next;
			tmpHead.next = tmpNode;
		}
		return tmpHead.next;
	}

	bool isPalindrome(ListNode* head)
	{
		ListNode *first = head;
		ListNode *second = head;

		if (!second->next)
		{
			return true;
		}

		while (second && second->next)
		{
			first = first->next;
			second = second->next->next;
		}

		if (second)
		{
			first = first->next;
		}

		auto secondHalf = reverseList(first);

		while (head && secondHalf)
		{
			if (head->val != secondHalf->val)
			{
				return false;
			}
			head = head->next;
			secondHalf = secondHalf->next;
		}

		return true;
	}
};
