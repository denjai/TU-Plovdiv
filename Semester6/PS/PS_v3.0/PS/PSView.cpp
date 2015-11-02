// PSView.cpp : implementation of the CPSView class
//

#include "stdafx.h"

#include "PS.h"
#include "PSDoc.h"
#include "PSView.h"
#include <afxstr.h>
#include <atlimage.h>
#include <comdef.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int k=0,flag=0,flag2=0,i=0;
CPoint p1,p2;
COLORREF clr=RGB(0,50,200);

CBitmap bmp;
BITMAP bmpInfo;
CBitmap* pOldBitmap;
int nX=0,nY=0;
CBitmap* pBitmap;


// CPSView

IMPLEMENT_DYNCREATE(CPSView, CView)

BEGIN_MESSAGE_MAP(CPSView, CView)
	// Standard printing commands
	ON_COMMAND(ID_DRAW_LINE, &CPSView::OnDrawLine)
	ON_COMMAND(ID_DRAW_ECLIPSE, &CPSView::OnDrawEclipse)
	ON_COMMAND(ID_DRAW_RECTANGLE, &CPSView::OnDrawRectangle)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	
	ON_COMMAND(ID_COLOR_SETCOLOR, &CPSView::OnColorSetcolor)
	ON_COMMAND(ID_FILE_OPEN, &CPSView::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, &CPSView::OnFileSave)
END_MESSAGE_MAP()

// CPSView construction/destruction

CPSView::CPSView()
{
	//m_nImageSize = SIZE_NONE;

}

CPSView::~CPSView()
{
}

BOOL CPSView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CPSView drawing

void CPSView::OnDraw(CDC* pDC)
{
	CPSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
    //---------------------------------------------------------------------- //bitmap
	   CDC dcMemory; 
      // Get the size of the bitmap
      pBitmap->GetBitmap(&bmpInfo);
	

      // Create an in-memory DC compatible with the
      // display DC we're using to paint
     
      dcMemory.CreateCompatibleDC(pDC);

      // Select the bitmap into the in-memory DC
      pOldBitmap = dcMemory.SelectObject(pBitmap);

      // Copy the bits from the in-memory DC into the on-
      // screen DC to actually do the painting. Use the centerpoint
      // we computed for the target offset.
      pDC->BitBlt(nX, nY, bmpInfo.bmWidth, bmpInfo.bmHeight, &dcMemory, 
         0, 0, SRCCOPY);
      //pDC->Rectangle(100,200,600,500);
		 

	//-----------------------------------------------------------------------------------------------------------------------
	CPen pen;
	CPen *poldpen;
	pen.CreatePen(PS_SOLID,4,clr);
	poldpen=pDC->SelectObject(&pen);

	if (!imgOriginal.IsNull()&&flag2==1){ // zarejda image-a 
		imgOriginal.StretchBlt(pDC->m_hDC,0,0,imgOriginal.GetWidth(),imgOriginal.GetHeight(),SRCCOPY);
		flag2=0;}


    if(flag==2&&k==2){
	  pDC->Rectangle(p1.x,p1.y,p2.x,p2.y);
	  flag=0;
	 }
	if(flag==2&&k==1){
		pDC->MoveTo(p1);
		pDC->LineTo(p2);
		flag=0;
	}
	if(flag==2&&k==3){
		pDC->Ellipse(p1.x,p1.y,p2.x,p2.y);
		flag=0;
	}
	else if(flag==2)
		flag=0;

	pDC->SelectObject(&poldpen);
	
	//--------------------------------------------
	dcMemory.BitBlt(nX, nY, bmpInfo.bmWidth, bmpInfo.bmHeight,pDC,    //oppppppppppp
         0, 0, SRCCOPY);
     imgOriginal.Destroy();     
     imgOriginal.Attach(*pBitmap);
    //imgOriginal.Save(_T("C:\\test.bmp"), Gdiplus::ImageFormatBMP);  //saves the file
	dcMemory.SelectObject(pOldBitmap);
}


// CPSView printing

BOOL CPSView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPSView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPSView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CPSView diagnostics

#ifdef _DEBUG
void CPSView::AssertValid() const
{
	CView::AssertValid();
}

void CPSView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPSDoc* CPSView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPSDoc)));
	return (CPSDoc*)m_pDocument;
}
#endif //_DEBUG


// CPSView message handlers

void CPSView::OnDrawLine()
{
	// TODO: Add your command handler code here
	k=1;
}

void CPSView::OnDrawEclipse()
{
	// TODO: Add your command handler code here
	k=3;
}

void CPSView::OnDrawRectangle()
{
	// TODO: Add your command handler code here
	k=2;
}

void CPSView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if(flag==1){
		p2=point;
		flag++;
		Invalidate(FALSE);
	}
	if(flag==0){
		p1=point;
		flag++;
	}
	
	
	CView::OnLButtonDown(nFlags, point);
}


void CPSView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default


	CView::OnMouseMove(nFlags, point);
}


void CPSView::OnColorSetcolor()
{
	// TODO: Add your command handler code here
	CColorDialog dlg1;	
    if (dlg1.DoModal() == IDOK)
             clr = dlg1.GetColor();
}

void CPSView::OnFileOpen()
{
	// TODO: Add your command handler code here
	CString strFilter;
	CSimpleArray<GUID> aguidFileTypes;
	HRESULT hResult;

	hResult = imgOriginal.GetExporterFilterString(strFilter,aguidFileTypes);
	if (FAILED(hResult)) {
		CString fmt;
		fmt.Format(L"GetExporterFilter failed:\n%x - %s", hResult, _com_error(hResult).ErrorMessage());
		::AfxMessageBox(fmt);
		return;
	}

	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST, strFilter);
	dlg.m_ofn.nFilterIndex = m_nFilterLoad;
	hResult = (int)dlg.DoModal();
	if(FAILED(hResult)) {
		return;
	}

	m_nFilterLoad = dlg.m_ofn.nFilterIndex;
	imgOriginal.Destroy();
	hResult = imgOriginal.Load(dlg.GetPathName());
	if (FAILED(hResult)) {
		CString fmt;
		fmt.Format(L"Load image failed:\n%x - %s", hResult, _com_error(hResult).ErrorMessage());
		::AfxMessageBox(fmt);
		return;
	}
	flag2=1;
	pBitmap = CBitmap::FromHandle(imgOriginal.m_hBitmap);
	Invalidate(FALSE);
	UpdateWindow();

}

void CPSView::OnFileSave()
{
	// TODO: Add your command handler code here
	CString strFilter;
	CSimpleArray<GUID> aguidFileTypes;
	HRESULT hResult;


	strFilter = "Bitmap image|*.bmp|JPEG image|*.jpg|GIF image|*.gif|PNG image|*.png||";

	CFileDialog dlg(FALSE,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_EXPLORER,strFilter);
	dlg.m_ofn.nFilterIndex = m_nFilterLoad;
	hResult = (int)dlg.DoModal();
	if (FAILED(hResult)) {
		return;
	}

    // Add the appropriate extension if the user didn't type one

	CString strFileName;
	CString strExtension;

	strFileName = dlg.m_ofn.lpstrFile;


	// add the file extension if the user didn't supply one
	if (dlg.m_ofn.nFileExtension == 0) 
	{
		switch (dlg.m_ofn.nFilterIndex)
		{
		case 1:
			strExtension = "bmp";
			break;
		case 2:
			strExtension = "jpg";
			break;
		case 3:
			strExtension = "gif";
			break;
		case 4:
			strExtension = "png";
			break;
		default:
			break;
		}

		strFileName = strFileName + '.' + strExtension;

	}

	// the extension on the file name will determine the file type that is saved
	hResult = imgOriginal.Save(strFileName);
	if (FAILED(hResult)) {
		CString fmt;
		fmt.Format(L"Save image failed:\n%x - %s", hResult, _com_error(hResult).ErrorMessage());
		::AfxMessageBox(fmt);
		return;
	}

}
