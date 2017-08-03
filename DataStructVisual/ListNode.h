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
	CPoint m_Point;//������������λ��
	COLORREF m_Color; //����������ɫ
	CString m_StrName; //������������
	BOOL m_Visit;//���������Ƿ����
	int m_Row;//��������ʾ����
};

#endif // !defined(AFX_LISTNODE_H__66E64B98_2B17_488A_83A5_3E924C2A4C9E__INCLUDED_)
