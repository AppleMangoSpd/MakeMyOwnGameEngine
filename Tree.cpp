#include "Tree.h"
#include <Queue>
//void Tree::addNode(ComponentObject* _addedNode)
//{
//	_nodeList[_nodeListSize] = _addedNode;
//	_nodeListSize += 1;
//}
//
////BFS
//void Tree::BFS_travel()
//{
//	std::queue<ComponentObject*> _nodeQueue;
//
//	//NodeList�� node�� _isConfirm ����
//	for (int i = 0; i < _nodeListSize; i++)
//	{
//		_nodeList[i]->Reset_IsConfirm();
//	}
//
//	//�ֻ��� ��忡�� ����
//	ComponentObject* firstNode = _nodeList[0];
//	//�ֻ��� ��� ť�� ����
//	_nodeQueue.enqueue(firstNode);
//
//	//ť�� ��������� ����
//	while (!_nodeQueue.isEmpty())
//	{
//		//ť�� ���� �տ��ִ� ���(���) ��ȸ
//		ComponentObject* _currentNode = _nodeQueue.peek();
//		_currentNode->Confirmed();
//
//		//���� ��忡�� ����Ǿ��ִ� ����Ȯ��
//		for (int i = 0; i < MAX_EDGE_LIST_SIZE; i++)
//		{
//			//���� ���� && ����� ��尡 ��ȸ���ִ��� Ȯ��
//			if ((_currentNode->_edgeList[i]) != nullptr &&
//				!(_currentNode->_edgeList[i]->GetRight()->Get_isConfirm()))
//			{
//				//����� ��带 ť�� ����
//				_nodeQueue.enqueue(_currentNode->_edgeList[i]->GetRight());
//			}
//		}
//		//���� ��ȸ�� ���� ť���� ����
//		_nodeQueue.dequeue();
//	}
//}
//
//void Tree::DFS_travel()
//{
//	//NodeList�� node�� _isConfirm ����
//	for (int i = 0; i < _nodeListSize; i++)
//	{
//		_nodeList[i]->Reset_IsConfirm();
//	}
//
//	//��ȸ����
//	ComponentObject* _currentNode = _nodeList[0];
//	this->_startDFS_travel(_currentNode);
//}
//
////���� node���� edge�� _edgelist��ȸ
////_edgelist�� edge ����� �ش� edge�� getright�� �̿��� �̾����� node�� ����/��ȸ���� Ȯ�� ��
////�ش� node�� �Ű������� starttravel����
////�̾����� edge ���� ��� Ż��
//void Tree::_startDFS_travel(ComponentObject* _currentNode)
//{
//	_currentNode->Confirmed();
//	for (int i = 0; i < MAX_EDGE_LIST_SIZE; i++)
//	{
//		if ((_currentNode->_edgeList[i]) != nullptr &&
//			!((_currentNode->_edgeList[i])->GetRight()->Get_isConfirm()))
//		{
//			_startDFS_travel((_currentNode->_edgeList[i])->GetRight());
//		}
//	}
//
//	return;
//}