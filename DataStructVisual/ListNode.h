// ListNode.h: interface for the CListNode class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LISTNODE_H__66E64B98_2B17_488A_83A5_3E924C2A4C9E__INCLUDED_)
#define AFX_LISTNODE_H__66E64B98_2B17_488A_83A5_3E924C2A4C9E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CListNode : public CObject  
{
public:
	CListNode();
	virtual ~CListNode();
public:	
	CPoint m_Point;//单链表结点坐标位置
	COLORREF m_Color; //单链表结点颜色
	CString m_StrName; //单链表结点名称
	BOOL m_Visit;//单链表结点是否访问
	int m_Row;//链表结点显示行数
};

#endif // !defined(AFX_LISTNODE_H__66E64B98_2B17_488A_83A5_3E924C2A4C9E__INCLUDED_)
