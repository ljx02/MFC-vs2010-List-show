// LinkList.cpp: implementation of the CLinkList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "datastructvisual.h"
#include "LinkList.h"
#include "ListNode.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLinkList::CLinkList()
{

}

CLinkList::~CLinkList()
{

}
void CLinkList::AddTail(CPoint vPoint,CString vString)
{
	int tWidth,tHeight;
	int tCount=m_LinkList.GetCount();

	tWidth=vPoint.x;
	tHeight=vPoint.y;

	CListNode *pLNode = new CListNode();
	pLNode->m_Visit=0;
	pLNode->m_Color=RGB(0,0,0);
	pLNode->m_StrName=vString;

	int tPerNodeWidth=(tWidth-160)/70;
	int tRow=tCount/tPerNodeWidth;
	int tCol=tCount%tPerNodeWidth;
	if((tRow-1)*70<tHeight-150){
		pLNode->m_Row=tRow;
		pLNode->m_Point.x=(tCol-1)*70+150;
		pLNode->m_Point.y=(tRow-1)*70+100;
		m_LinkList.AddTail(pLNode);
	}else
	{
		::AfxMessageBox("�����Ŀ����!");
		return;
	}
}
void CLinkList::DrawArrow(CPoint vBeginPoint, CPoint vEndpoint, CDC *pDC)
{
	CPoint tPoint; 
	CPen drawPen;
	drawPen.CreatePen(PS_SOLID,2,RGB(255,0,0));
	pDC->SelectObject(&drawPen);
	pDC->MoveTo(vBeginPoint); 
	pDC->LineTo(vEndpoint); 

	

	double tX=vBeginPoint.x-vEndpoint.x;
	double tY=vBeginPoint.y-vEndpoint.y; 
	double tRotX,tRotY; 
	double tAngle=asin(1.0)/3;

	tRotY=tY*cos(tAngle)+tX*sin(tAngle); 
	tRotX=tX*cos(tAngle)-tY*sin(tAngle); 
	tRotY=tRotY/5+vEndpoint.y; 
	tRotX=tRotX/5+vEndpoint.x; 

	tPoint.x=(int)tRotX; 
	tPoint.y=(int)tRotY; 
	pDC->MoveTo(vEndpoint.x,vEndpoint.y);
	pDC->LineTo(tPoint);  //�����ϼ�ͷ

	tAngle=-tAngle;
	tRotY=tY*cos(tAngle)+tX*sin(tAngle); 
	tRotX=tX*cos(tAngle)-tY*sin(tAngle); 
	tRotY=tRotY/5+vEndpoint.y; 
	tRotX=tRotX/5+vEndpoint.x; 
	tPoint.x=(int)tRotX; 
	tPoint.y=(int)tRotY; 

	pDC->MoveTo(vEndpoint.x,vEndpoint.y); 
	pDC->LineTo(tPoint); //�����°��ͷ
}
bool CLinkList::DrawLinkNode(CListNode *vPListNode, CDC *pDC)
{
	CPen tDrawPen,*tPOldPen;

	int a;
	srand((unsigned) time(0));
	a = rand();
	tDrawPen.CreatePen(PS_SOLID,2,RGB(a,225,100)); //���ýڵ���ɫ

	CRect tNodeRect, tLinkRect;
	CPoint tCPoint=vPListNode->m_Point;

	tPOldPen=pDC->SelectObject(&tDrawPen);

	CPen clearPen;
	clearPen.CreatePen(PS_SOLID,1,RGB(225,255,255));
	int i;
	for(i=10;i>0;i--)
	{
		pDC->SelectObject(&tDrawPen);
		tNodeRect.SetRect((tCPoint.x+i)-10,tCPoint.y-15,(tCPoint.x+i)+15,tCPoint.y+15);
		tLinkRect.SetRect((tCPoint.x+i)+15,tCPoint.y-15,(tCPoint.x+i)+2*14,tCPoint.y+15); 
		pDC->Rectangle(tNodeRect);
		Sleep(10);
		pDC->SelectObject(&clearPen);
		tNodeRect.SetRect((tCPoint.x+i)-10,tCPoint.y-15,(tCPoint.x+i)+15,tCPoint.y+15);
		tLinkRect.SetRect((tCPoint.x+i)+15,tCPoint.y-15,(tCPoint.x+i)+2*14,tCPoint.y+15); 
		pDC->Rectangle(tNodeRect);
	}

	pDC->SelectObject(&tDrawPen);
	
	tNodeRect.SetRect(tCPoint.x-10,tCPoint.y-15,
		tCPoint.x+15,tCPoint.y+15);   //����һ�����Σ�left,top,right,bottom��
	tLinkRect.SetRect(tCPoint.x+15,tCPoint.y-15,
		tCPoint.x+2*14,tCPoint.y+15);  
	if(!pDC->Rectangle(tNodeRect)) return false;
	pDC->SelectObject(&tDrawPen);
	if(!pDC->Rectangle(tLinkRect)) return false;

    pDC->SelectObject(tPOldPen);
	CString tStrName;
	tStrName.Format("%d",vPListNode->m_StrName);//�������ֵ����CString tStrName
	if(!pDC->TextOut(tCPoint.x-18+15,tCPoint.y-15+7,
		vPListNode->m_StrName)) return false;
   	return true;
}

bool CLinkList::DrawLinkList(CDC *pDC)
{

	POSITION TPos,TPrePos;
	CString tStr;
	CPoint tEndPoint,tBeginPoint;
	CListNode *tPCurLNode,*tPNextLNode;

	for(TPos = m_LinkList.GetHeadPosition();TPos != NULL;)
	{
		TPrePos=TPos;
		tPCurLNode=m_LinkList.GetNext(TPos);

		DrawLinkNode(tPCurLNode,pDC);
		Sleep(100);
		if(TPos!=NULL)
        {
			tPNextLNode=m_LinkList.GetAt(TPos);
			if(tPCurLNode->m_Row==tPNextLNode->m_Row)
			{
				tBeginPoint.x=tPCurLNode->m_Point.x+18;
				tBeginPoint.y=tPCurLNode->m_Point.y;
				tEndPoint.x=tPNextLNode->m_Point.x-12;
				tEndPoint.y=tPNextLNode->m_Point.y;
				DrawArrow(tBeginPoint,tEndPoint,pDC);
			}else
			{
				DrawPolyLine(tPCurLNode->m_Point,
					tPNextLNode->m_Point,pDC);
			}
		}
	}
    //���Ʊ�ͷָ��

	//������β���ͷָ��

	tPCurLNode=m_LinkList.GetHead();
	CPoint tCurPoint, tNextPoint;
	tCurPoint.x=tPCurLNode->m_Point.x-52;
	tCurPoint.y=tPCurLNode->m_Point.y;
	tNextPoint.x=tPCurLNode->m_Point.x-12;
	tNextPoint.y=tPCurLNode->m_Point.y;

	DrawArrow(tCurPoint,tNextPoint,pDC);

	tStr="Head";
	if(!pDC->TextOut(tPCurLNode->m_Point.x-52,
		tCurPoint.y-18,tStr)) return false;
	//���Ʊ�βָ��
	tPCurLNode=m_LinkList.GetTail();
	tCurPoint.x=tPCurLNode->m_Point.x+18;
	tCurPoint.y=tPCurLNode->m_Point.y+48;
	tNextPoint.x=tPCurLNode->m_Point.x+18;
	tNextPoint.y=tPCurLNode->m_Point.y+12;

	DrawArrow(tCurPoint,tNextPoint,pDC);
	tStr="Tail";
	if(!pDC->TextOut(tNextPoint.x+4,
		tNextPoint.y+10,tStr)) return false;

	return true;
}
void CLinkList::DrawPolyLine(CPoint vCurpoint, 
							 CPoint vNextpoint, CDC *pDC)
{
	CPoint tBPoint,tEPoint;
	CListNode *tPCurLNode=m_LinkList.GetHead();

	CPen drawPen;
	drawPen.CreatePen(PS_SOLID,2,RGB(255,0,0));

	pDC->SelectObject(&drawPen);
	tBPoint.x=vCurpoint.x+18;
	tBPoint.y=vCurpoint.y;
	tEPoint.x=vCurpoint.x+48;
	tEPoint.y=vCurpoint.y;
	pDC->MoveTo(tBPoint);
	pDC->LineTo(tEPoint);

	tBPoint=tEPoint;
	tEPoint.x=tEPoint.x;
	tEPoint.y=tEPoint.y+35;
	pDC->MoveTo(tBPoint);
	pDC->LineTo(tEPoint);

	tBPoint=tEPoint;
	tEPoint.x=tPCurLNode->m_Point.x-52;
	pDC->MoveTo(tBPoint);
	pDC->LineTo(tEPoint);

	tBPoint=tEPoint;
	tEPoint.x=tEPoint.x;
	tEPoint.y=tEPoint.y+35;
	pDC->MoveTo(tBPoint);
	pDC->LineTo(tEPoint);

	tBPoint=tEPoint;
	tEPoint.x=tBPoint.x+40;
	
	DrawArrow(tBPoint,tEPoint,pDC);
}
void CLinkList::InsertNode(CPoint vPoint,int vPos,CString vString)
{

	int tWidth,tHeight,tPos;
	int tCount=m_LinkList.GetCount();
	POSITION pos;
	CListNode *pCurLNode;
	tWidth=vPoint.x;
	tHeight=vPoint.y;

	if(vPos<0 && vPos>=tCount)
	{
		::AfxMessageBox("����λ�ô���!");
		return;
	}
	int tPerNodeWidth=(tWidth-160)/70;
	int tRow=(tCount+1)/tPerNodeWidth;
	
	if((tRow-1)*70>tHeight-150){
		::AfxMessageBox("�����Ŀ����,���ܲ���!");
		return;
	}else{

		pos=m_LinkList.FindIndex(vPos);
		tRow=(vPos)/tPerNodeWidth;
		int tCol=vPos%tPerNodeWidth;
		CListNode *pLNode = new CListNode();

		pLNode->m_Visit=0;
		pLNode->m_Color = RGB(0,225,0);//�����ɫ�ı�
		pLNode->m_StrName=vString;
		m_LinkList.InsertBefore(pos,pLNode);
		//�޸ĺ��������ʾλ��

		    tPos=vPos;
		    pos=m_LinkList.FindIndex(tPos);
			pCurLNode=m_LinkList.GetAt(pos);
			tRow=tPos/tPerNodeWidth;
			tCol=tPos%tPerNodeWidth;
			pCurLNode->m_Row=tRow;
			pCurLNode->m_Point.x=(tCol-1)*70+150;
			pCurLNode->m_Point.y=(tRow-1)*10+100;
			pCurLNode->m_Color = RGB(225,0,0);
			m_LinkList.SetAt(pos,pCurLNode);
			//pCurLNode->m_Color = RGB(a,b,c);

		    for(int i=tPos+1;i<m_LinkList.GetCount();i++)
		    {
			pos=m_LinkList.FindIndex(i);
			pCurLNode=m_LinkList.GetAt(pos);
			tRow=i/tPerNodeWidth;
			tCol=i%tPerNodeWidth;
			pCurLNode->m_Row=tRow;
			pCurLNode->m_Point.x=(tCol-1)*70+150;
			pCurLNode->m_Point.y=(tRow-1)*70+100;

			m_LinkList.SetAt(pos,pCurLNode);
		    }
		}
		
	}


void CLinkList::TiaoZheng(CPoint vPoint)
{
	int tCount = m_LinkList.GetCount();
	CListNode* pLNode;
	POSITION tpos;

	int tWidth,tHeight;
	tWidth=vPoint.x;
	tHeight=vPoint.y;
	int tPerNodeWidth=(tWidth-160)/70;
	int tRow=(tCount+1)/tPerNodeWidth;
	int tCol = (tCount+1)%tPerNodeWidth;
	//tRow=(vPos)/tPerNodeWidth;
	//int tCol=vPos%tPerNodeWidth;
	

	for(int i =0;i<tCount;i++)
	{
		tpos = m_LinkList.FindIndex(i);
		pLNode = m_LinkList.GetAt(tpos);
		tRow=i/tPerNodeWidth;
		tCol=i%tPerNodeWidth;
		pLNode->m_Row=tRow;
		pLNode->m_Point.x=(tCol-1)*70+150;
		pLNode->m_Point.y=(tRow-1)*70+100;
		m_LinkList.SetAt(tpos,pLNode);
	}
}

void CLinkList::Sort(CPoint vPoint)
{
	int tCount = m_LinkList.GetCount();
	//������������
	int a[20];
	memset(a,0,sizeof(int));

	if(tCount <= 2)
	{
		//ֱ���������
	}
	else
	{
		POSITION tPos;
		CListNode* pNode;
		int temp = 0,t=0;
		CStringA str = " ";
		CString str1 =" ";
		for(int i = 1;i < tCount;i++)
		{
			tPos = m_LinkList.FindIndex(i);
			pNode = m_LinkList.GetAt(tPos);
			str1 = pNode->m_StrName;
			a[i] = _ttoi(str1);
		}
		//��������
		for(int i = 1;i<tCount;i++)
		{
			for(int j = i+1;j<tCount;j++)
			{
				if(a[i] < a[j])
				{
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
		}
		for(int i=1;i<tCount;i++)
		{
			//���Ӵ�С�����ѷ���������
			t = a[i];
			str.Format("%d",t);//��int��ת��ΪCString
			InsertNode(vPoint,1,str);//����ͷ�巨����������Ϊ��С��������

		}
		for(int i =1;i<tCount;i++)
		{
			//ɾ��ͬһ��λ��tCount��
			DeleteNode(vPoint,tCount);
		}
	}
}

void CLinkList::Sort1(CPoint vPoint)
{
	int tCount = m_LinkList.GetCount();
	//������������
	int a[20];
	memset(a,0,sizeof(int));

	if(tCount <= 2)
	{
		//ֱ���������
	}
	else
	{
		POSITION tPos;
		CListNode* pNode;
		int temp = 0,t=0;
		CStringA str = " ";
		CString str1 =" ";
		for(int i = 1;i < tCount;i++)
		{
			tPos = m_LinkList.FindIndex(i);
			pNode = m_LinkList.GetAt(tPos);
			str1 = pNode->m_StrName;
			a[i] = _ttoi(str1);
		}
		//��������
		for(int i = 1;i<tCount;i++)
		{
			for(int j = i+1;j<tCount;j++)
			{
				if(a[i] > a[j])
				{
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
		}
		for(int i=1;i<tCount;i++)
		{
			t = a[i];
			str.Format("%d",t);//��int��ת��ΪCString
			InsertNode(vPoint,1,str);
		}
		for(int i =1;i<tCount;i++)
		{
			//ɾ��ͬһ��λ��tCount��
			DeleteNode(vPoint,tCount);
		}
	}
}

void CLinkList::DeleteNode(CPoint vPoint,int vPos)
{

	int tWidth,tHeight;
	int tCount=m_LinkList.GetCount();
	POSITION pos;
	CListNode *pCurLNode;
	tWidth=vPoint.x;
	tHeight=vPoint.y;

	if(vPos<0 && vPos>=tCount)
	{
		::AfxMessageBox("ɾ��λ�ô���!");
		return;
	}
	if(tCount<=1){
		::AfxMessageBox("����Ϊ��,����ɾ��!");
		return;
	}else{

		int tPerNodeWidth=(tWidth-160)/70;
		int tRow=(tCount+1)/tPerNodeWidth;
		pos=m_LinkList.FindIndex(vPos);
		tRow=(vPos)/tPerNodeWidth;
		int tCol=vPos%tPerNodeWidth;
		m_LinkList.RemoveAt(pos);

		//�޸ĺ��������ʾλ��
		for(int i=vPos;i<m_LinkList.GetCount();i++)
		{
			pos=m_LinkList.FindIndex(i);
			pCurLNode=m_LinkList.GetAt(pos);

			tRow=i/tPerNodeWidth;
			tCol=i%tPerNodeWidth;

			pCurLNode->m_Row=tRow;
			pCurLNode->m_Point.x=(tCol-1)*70+150; //��ǰ��һλ
			pCurLNode->m_Point.y=(tRow-1)*70+100;
			m_LinkList.SetAt(pos,pCurLNode);

		}
	}
}


//ɾ������
void CLinkList::CleanList(CPoint vPoint)
{	
	int tCount = m_LinkList.GetCount();
	for(int i=tCount-1;i>0;i--)
	{
		DeleteNode(vPoint,i);//vPoint ��һ����ֵ��perWidth = 8;
	}
}


//���Һ���
bool CLinkList::Searching(CString vString,int vPos)
{
	POSITION pos;
	CListNode *pCurLNode;
	pos = m_LinkList.FindIndex(vPos);
	pCurLNode = m_LinkList.GetAt(pos);

	if(vString != pCurLNode->m_StrName)
	{
		m_pCurLNode = pCurLNode;
		n_pCurLNode = pCurLNode;
		return true;
	}
	else
	{
		return false;	
	}
}

int CLinkList::CountNode()
{
	//���ؽ��ĸ���
	return m_LinkList.GetCount();
}

BOOL CLinkList::Search(CString vString)
{
	POSITION pos;
	CListNode *pCurLNode;
	int i=0;
	int tCount=m_LinkList.GetCount(); 
	for(pos = m_LinkList.GetHeadPosition();pos != NULL;) 
	{ 
		i++;
		pCurLNode=m_LinkList.GetNext(pos);
		if(vString==pCurLNode->m_StrName)
		{
			m_pCurLNode=pCurLNode;
			n_pCurLNode=pCurLNode;
			return(TRUE);
		}
		if(i>=tCount)
		{
			::AfxMessageBox("���ҵĽ�㲻���ڣ�");
			return(FALSE);
		}
		
	} 
	return(TRUE);
}
void CLinkList::DrawSearchArrow(CDC *pDC)
{
	CPoint tBegin,tEnd;
	tBegin.x=m_pCurLNode->m_Point.x+5;
	tBegin.y=m_pCurLNode->m_Point.y+50;
	tEnd.x=m_pCurLNode->m_Point.x+5;
	tEnd.y=m_pCurLNode->m_Point.y+15;
	//CPen tDrawPen;
	//tDrawPen.CreatePen(PS_SOLID,1,RGB(0,0,255);
	//pDC->SelectObject(&tDrawPen);
	DrawArrow(tBegin,tEnd,pDC); 
}
