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
//	//NodeList의 node의 _isConfirm 리셋
//	for (int i = 0; i < _nodeListSize; i++)
//	{
//		_nodeList[i]->Reset_IsConfirm();
//	}
//
//	//최상위 노드에서 시작
//	ComponentObject* firstNode = _nodeList[0];
//	//최상위 노드 큐에 삽입
//	_nodeQueue.enqueue(firstNode);
//
//	//큐가 비어있으면 종료
//	while (!_nodeQueue.isEmpty())
//	{
//		//큐의 가장 앞에있는 요소(노드) 조회
//		ComponentObject* _currentNode = _nodeQueue.peek();
//		_currentNode->Confirmed();
//
//		//현재 노드에서 연결되어있는 엣지확인
//		for (int i = 0; i < MAX_EDGE_LIST_SIZE; i++)
//		{
//			//엣지 존재 && 연결된 노드가 조회되있는지 확인
//			if ((_currentNode->_edgeList[i]) != nullptr &&
//				!(_currentNode->_edgeList[i]->GetRight()->Get_isConfirm()))
//			{
//				//연결된 노드를 큐에 삽입
//				_nodeQueue.enqueue(_currentNode->_edgeList[i]->GetRight());
//			}
//		}
//		//현재 조회한 노드는 큐에서 삭제
//		_nodeQueue.dequeue();
//	}
//}
//
//void Tree::DFS_travel()
//{
//	//NodeList의 node의 _isConfirm 리셋
//	for (int i = 0; i < _nodeListSize; i++)
//	{
//		_nodeList[i]->Reset_IsConfirm();
//	}
//
//	//순회시작
//	ComponentObject* _currentNode = _nodeList[0];
//	this->_startDFS_travel(_currentNode);
//}
//
////현재 node에서 edge의 _edgelist순회
////_edgelist에 edge 존재시 해당 edge의 getright를 이용해 이어지는 node의 존재/조회여부 확인 후
////해당 node를 매개변수로 starttravel입장
////이어지는 edge 없을 경우 탈출
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