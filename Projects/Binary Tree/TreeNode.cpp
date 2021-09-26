#include "TreeNode.h"
#include <raygui.h>
#include <stdio.h>

TreeNode::TreeNode(int value)
{
	m_value = value;
	m_left = 0;
	m_right = 0;
}
TreeNode::~TreeNode()
{}

void TreeNode::SetData(int value)
{
	m_value = value;
}
void TreeNode::SetLeft(TreeNode* node)
{
	m_left = node;
}
void TreeNode::SetRight(TreeNode* node)
{
	m_right = node;
}

void TreeNode::Draw(int x, int y, bool selected)
{
	static char buffer[10];
	sprintf_s(buffer, "%d", m_value);//store value in buffer

	DrawCircle(x, y, 30, YELLOW);

	if (selected == true)
		DrawCircle(x, y, 28, GREEN);
	else
		DrawCircle(x, y, 28, BLACK);


	DrawText(buffer, x - 12, y - 10, 12, WHITE);
}
