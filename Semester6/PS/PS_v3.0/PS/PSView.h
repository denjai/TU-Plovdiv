// PSView.h : interface of the CPSView class
//

#include <afxstr.h>
#include <atlimage.h>
#include <comdef.h>

#pragma once


class CPSView : public CView
{
protected: // create from serialization only
	CPSView();
	DECLARE_DYNCREATE(CPSView)

// Attributes


public:
	CPSDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CPSView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif


// Generated message map functions
	private:
	CImage imgOriginal;
	int	m_nFilterLoad;
	CImage image;

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDrawLine();
	afx_msg void OnDrawEclipse();
	afx_msg void OnDrawRectangle();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnColorSetcolor();
	afx_msg void OnFileOpen();
	afx_msg void OnFileSave();
};

#ifndef _DEBUG  // debug version in PSView.cpp
inline CPSDoc* CPSView::GetDocument() const
   { return reinterpret_cast<CPSDoc*>(m_pDocument); }
#endif

