// LinkList.h: interface for the CLinkList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINKLIST_H__D17E4BC7_E140_42A1_83B9_C2DD47E34755__INCLUDED_)
#define AFX_LINKLIST_H__D17E4BC7_E140_42A1_83B9_C2DD47E34755__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "math.h"
#include <afxtempl.h>
#include <afxwin.h>
#include <afxext.h>
#include "ListNode.h"

class CLinkList  
{
public:
	CLinkList();//���캯��
	virtual ~CLinkList();//��������
	void AddTail(CPoint vPoint,CString vString);//β�巨����������
	void InsertNode(CPoint vPoint,int vPos,CString vString);//�������в�����
	void DeleteNode(CPoint vPoint,int vPos);//������ɾ�����

	//ɾ������ֻ����ͷָ��
	void CleanList(CPoint vPoint);

	BOOL Search(CString vString);//��ֵ����,�����һ��CDC

	bool Searching(CString vString,int vPos);//����ͷ�ƶ�
	int CountNode();

	void DrawArrow(CPoint vBeginPoint, CPoint vEndpoint, CDC *pDC);//���Ƽ�ͷ
	bool DrawLinkNode(CListNode *vPListNode, CDC *pDC);//���ƽ��
	bool DrawLinkList(CDC *pDC);//���Ƶ�����
	void DrawPolyLine(CPoint curpoint, CPoint nextpoint, CDC *pDC);//��������
	void DrawSearchArrow(CDC *pDC);//���Ʋ��ҽ����ͷ
	void ClearSearchArrow(CDC *pDC);
	void TiaoZheng(CPoint vPoint);

	void Sort(CPoint vPoint);
	void Sort1(CPoint vPoint);
	//void Daozhi();

public:

	CTypedPtrList <CObList,CListNode*>   m_LinkList; //������������
private:
	CListNode* m_pCurLNode;//���ָʾ��
	CListNode* n_pCurLNode;//���ָʾ��
};

#endif // !defined(AFX_LINKLIST_H__D17E4BC7_E140_42A1_83B9_C2DD47E34755__INCLUDED_)
