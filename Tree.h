#pragma once

class ComponentObject;

class Tree
{
public:
    Tree() : _nodeListSize(0) {};

    //Ʈ���� ��� �߰�
    void addNode(ComponentObject* _addedNode);

    //���� �켱 Ž��
    void BFS_travel();
    //���� �켱 Ž��
    void DFS_travel();

private:
    //�������� ����� ����
    int _nodeListSize;
    //�������� ��� �迭
    ComponentObject* _nodeList[100];

    //���� �켱 Ž���� ���Ǵ� ����Լ�
    void _startDFS_travel(ComponentObject* _currentNode);
};

