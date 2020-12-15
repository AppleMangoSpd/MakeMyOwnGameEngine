#pragma once

class ComponentObject;

class Tree
{
public:
    Tree() : _nodeListSize(0) {};

    //트리에 노드 추가
    void addNode(ComponentObject* _addedNode);

    //넓이 우선 탐색
    void BFS_travel();
    //깊이 우선 탐색
    void DFS_travel();

private:
    //보유중인 노드의 개수
    int _nodeListSize;
    //보유중인 노드 배열
    ComponentObject* _nodeList[100];

    //깊이 우선 탐색시 사용되는 재귀함수
    void _startDFS_travel(ComponentObject* _currentNode);
};

