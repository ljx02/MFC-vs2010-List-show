// stdafx.cpp : source file that includes just the standard includes
//	DataStructVisual.pch will be the pre-compiled header
//	stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"
#include "math.h"

void DrawArrow(CPoint vBeginPoint, CPoint vEndpoint, CDC *pDC)
{
	CPoint tPoint; 
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
	pDC->MoveTo(vEndpoint); 
	pDC->LineTo(tPoint);
	
	tAngle=-tAngle;
	tRotY=tY*cos(tAngle)+tX*sin(tAngle); 
	tRotX=tX*cos(tAngle)-tY*sin(tAngle); 
	tRotY=tRotY/5+vEndpoint.y; 
	tRotX=tRotX/5+vEndpoint.x; 
	tPoint.x=(int)tRotX; 
	tPoint.y=(int)tRotY; 
	pDC->MoveTo(vEndpoint); 
	pDC->LineTo(tPoint);
}
int cmp(const void *vAVal,const void *vBVal)
{
	int tAVal=*(int *)vAVal;
	int tBVal=*(int *)vBVal;
	return tAVal-tBVal;
}