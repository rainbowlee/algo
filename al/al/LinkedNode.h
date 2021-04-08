#ifndef _LINKEDNODE_H_
#define _LINKEDNODE_H_
#pragma once
#include <string>
using namespace std;

struct Node
{
	Node()
	{
		mData = 0;
		mNext = nullptr;
		mPre = nullptr;
	}

	int				mData;
	Node*		mNext;
	Node*		mPre;
};

//typedef struct Node
//{
//	Node()
//	{
//		mData = 0;
//		mNext = nullptr;
//		mPre = nullptr;
//	}
//
//	int				mData;
//	Node*		mNext;
//	Node*		mPre;
//} Node;


class LinkedNode
{
public:
	static Node* AddHeadNode(Node* head, int value)
	{
		Node* newNode = new Node();
		newNode->mData = value;

		return AddHeadNode(head, newNode);
	}


	static Node* AddHeadNode(Node* head, Node* newNode)
	{
		if(head == nullptr)
			head = newNode;
		else
		{
			newNode->mNext = head;
			head = newNode;//漏写代码
		}
		return head;
	}

	//双向链表
	static Node* AddHeadNodeD(Node* head, int value)
	{
		Node* newNode = new Node();
		newNode->mData = value;

		return AddHeadNodeD(head, newNode);
	}

	//双向链表
	static Node* AddHeadNodeD(Node* head, Node* newNode)
	{
		if(head == nullptr)
			head = newNode;
		else
		{
			newNode->mNext = head;
			head->mPre = newNode;
			head = newNode;//漏写代码
		}
		return head;
	}

	static Node* AddTailNode(Node* head, Node* newNode)
	{
		if(head == nullptr)
			head = newNode;
		else
		{
			Node* iterNode = head;
			while (iterNode->mNext != nullptr)
			{
				iterNode = iterNode->mNext;
			}
			iterNode->mNext = newNode;
		}

		return head;
	}


	static Node* AddTailNode(Node* head, int value)
	{
		Node* newNode = new Node();
		newNode->mData = value;

		return AddTailNode(head, newNode);
	}

	static Node* AddTailNodeD(Node* head, Node* newNode)
	{
		if(head == nullptr)
			head = newNode;
		else
		{
			Node* iterNode = head;
			while (iterNode->mNext != nullptr)
			{
				iterNode = iterNode->mNext;
			}
			iterNode->mNext = newNode;
			newNode->mPre = iterNode;
		}

		return head;
	}


	static Node* AddTailNodeD(Node* head, int value)
	{
		Node* newNode = new Node();
		newNode->mData = value;

		return AddTailNodeD(head, newNode);
	}

	//返回头
	static Node* RemoveNode(Node* head, int value)
	{
		if(head == nullptr)
			return head;

		//head 单独处理
		Node* iterNode = head;
		if(head->mData == value)
		{
			Node* toDel = head;
			head = head->mNext;
			delete toDel;
			return head;
		}

		Node* preNode = head;
		Node* curNode = preNode->mNext;
		bool toDel = false;
		while (curNode != nullptr)
		{
			if(curNode->mData == value)
			{
				toDel = true;
				break;
			}
			
			preNode = curNode;
			curNode = curNode->mNext;
		}

		if(toDel)
		{
			preNode->mNext =  curNode->mNext;
			delete curNode;
		}

		return head;
	}

	static Node* RemoveNode(Node* head, Node* removeNode)
	{
		if(head == nullptr)
			return head;

		if(removeNode == nullptr)
			return head;
		
		if(head->mData == removeNode->mData)
		{
			Node* toDel = head;
			head = head->mNext;
			delete toDel;

			return head;
		}

		Node* pre = head;
		Node* cur = head->mNext;
		bool toDel = false;
		while (cur != nullptr)
		{
			if(cur == removeNode)
			{
				toDel = true;
				break;
			}

			pre = cur;
			cur = cur->mNext;
		}

		if(toDel)
		{
			pre->mNext = cur->mNext;
			delete cur;
		}

		return head;
	}

	//链表逆序
	static Node* Revert(Node* head)
	{
		Node* newhead = nullptr;
		Node* insertNode = head;
		while (insertNode != nullptr)
		{
			Node* add = insertNode;
			insertNode = insertNode->mNext;
			add->mNext = nullptr;
			
			//newhead = AddHeadNode(newhead, add);
			if(newhead == nullptr)
				newhead = add;
			else
			{
				add->mNext = newhead;
				newhead = add;//漏写代码
			}
		}

		return newhead;
	}

	//有序链表合并
	static Node* Merge(Node* head1, Node* head2)
	{
		//确保有序
		int cmpValue = 0;
		Node* iterNode = head1;
		while (iterNode != nullptr)
		{
			if(iterNode->mData < cmpValue)
				return nullptr;

			iterNode = iterNode->mNext;//漏写代码
		}
		iterNode = head2;
		while (iterNode != nullptr)
		{
			if(iterNode->mData < cmpValue)
				return nullptr;
			iterNode = iterNode->mNext;//漏写代码
		}

		Node* pNewHead = nullptr;
		Node* pNewNode = nullptr;
		Node* pIterNode1 = head1;
		Node* pIterNode2 = head2;

		while (pIterNode1 != nullptr && pIterNode2 != nullptr)
		{
			if(pIterNode1->mData <= pIterNode2->mData)
			{
				Node* addNode = pIterNode1;
				pIterNode1 = pIterNode1->mNext;
				addNode->mNext = NULL;

				if(pNewHead == nullptr)
				{
					pNewHead = addNode;
					pNewNode = pNewHead;
				}
				else
				{
					pNewNode->mNext = addNode;
					pNewNode = addNode;
				}
			}
			else
			{
				Node* addNode = pIterNode2;
				pIterNode2 = pIterNode2->mNext;
				addNode->mNext = NULL;

				if(pNewHead == nullptr)
				{
					pNewHead = addNode;
					pNewNode = pNewHead;
				}
				else
				{
					pNewNode->mNext = addNode;
					pNewNode = addNode;
				}
			}
		}

		while (pIterNode1 != nullptr)
		{
			Node* addNode = pIterNode1;
			pIterNode1 = pIterNode1->mNext;
			addNode->mNext = NULL;

			if(pNewHead == nullptr)
			{
				pNewHead = addNode;
				pNewNode = pNewHead;
			}
			else
			{
				pNewNode->mNext = addNode;
				pNewNode = addNode;
			}
		}

		while (pIterNode2 != nullptr)
		{
			Node* addNode = pIterNode2;
			pIterNode2 = pIterNode2->mNext;
			addNode->mNext = NULL;

			if(pNewHead == nullptr)
			{
				pNewHead = addNode;
				pNewNode = pNewHead;
			}
			else
			{
				pNewNode->mNext = addNode;
				pNewNode = addNode;
			}
		}

		return pNewHead;
	}

	//检查环
	static bool CheckRing(Node* head)
	{
		if(head == nullptr) return false;
		Node* pSlow = head;
		Node* pFast = head->mNext;
		while (pFast != nullptr && pSlow != nullptr)
		{
			pSlow = pSlow->mNext;
			if(pFast->mNext != nullptr && pFast->mNext->mNext != nullptr)
			{
				pFast = pFast->mNext->mNext;
			}
			else
				pFast = nullptr;
		
			if(pFast == pSlow)
				return true;
		}

		return false;
	}


	//删除后数n
	static Node* DeleLastN(Node* head, int lastn)
	{
		if(head == NULL)
			return head;
		if(lastn == 0)
			return head;

		Node* pFast = head;
		int n = lastn-1;
		while (n)
		{
			n--;
			pFast = pFast->mNext;
			if(pFast == nullptr)
				return head;
		}

		Node*pSlow = nullptr;
		/*
		pFast = pFast->mNext;
		if(pFast == nullptr)
		{
			pSlow = pSlow->mNext;
			delete head;

			return pSlow;
		}

		while (pFast->mNext != nullptr)
		{
			pFast= pFast->mNext;
			pSlow = pSlow->mNext;
		}

		pSlow = pSlow->mNext;
		delete head;
		return pSlow;
		*/

		while (pFast->mNext != nullptr)
		{
			pFast= pFast->mNext;
			if(pSlow == nullptr)
				pSlow = head;
			else	
				pSlow = pSlow->mNext;
		}

		//删除头
		if(pSlow == nullptr)
		{
			Node* toDel = head;
			head = head->mNext;
			delete toDel;
			return head;
		}
		//删除非头
		Node* toDel = pSlow->mNext;
		pSlow->mNext = pSlow->mNext->mNext;
		delete toDel;
		return head;
	}

	//获得中间点
	static Node* GetMid(Node* head)
	{
		if(head == nullptr)
			return nullptr;

		Node* pSlow = head;
		Node* pFast = head->mNext;
		
		if(pFast == nullptr)
			return pSlow;

		while (pFast != nullptr)
		{
			pFast = pFast->mNext;
			if(pFast == nullptr)
			{
				return nullptr;
			}

			if(pFast->mNext == nullptr)
			{
				return pSlow->mNext;
			}

			pFast = pFast->mNext;
			pSlow = pSlow->mNext;
		}


		return nullptr;
	}

	//回文判断
	static bool CheckHuiWen(Node* head)
	{
		if(head == nullptr)
			return true;

		Node* pFast = head;
		if(pFast->mNext == nullptr)
			return true;

		pFast = head->mNext;
		Node* pSlow = head;
		bool jishu = true;
		while (pFast != nullptr)
		{
			//2n+1
			if(pFast->mNext == nullptr)
			{
				jishu =  false;
				//双
				break;
			}
			pFast = pFast->mNext;
			//2n+2
			if(pFast->mNext == nullptr)
			{
				//单
				break;
			}

			pFast = pFast->mNext;
			pSlow = pSlow->mNext;
		}

		Node* left = head;
		Node* right = pSlow->mNext;

		if(jishu == true)
		{
			//出错位置
			//搞错位置
			pSlow = right;
			right = right->mNext;
		}
		right = Revert(right);

		Node* cmpRight = right;
		while (cmpRight != nullptr)
		{
			if(left->mData != cmpRight->mData)
				return false;
			
			left = left->mNext;
			cmpRight = cmpRight->mNext;
		}

		right = Revert(right);
		pSlow->mNext = right;
		return true;
	}

	//log
	static std::string ToString(Node* head)
	{
		string str;
		Node* iterNode = head;
		while (iterNode != nullptr)
		{
			if(iterNode == head)
				str += std::to_string(iterNode->mData);
			else
				str += "," + std::to_string(iterNode->mData);

			iterNode = iterNode->mNext;
		}

		return str;
	}


	static Node* Revert2(Node* pNode)
	{
		if(pNode == nullptr)
			return nullptr;

		Node* preNode = pNode;
		Node* curNode = pNode->mNext;
		pNode->mNext = nullptr;
		if(curNode != nullptr)
		{
			Node* nextNode = curNode->mNext;
			curNode->mNext = preNode;
			preNode = curNode;
			curNode = nextNode;		
		}

		return preNode;
	}
};
#endif

