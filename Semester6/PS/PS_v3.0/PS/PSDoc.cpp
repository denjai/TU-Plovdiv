// PSDoc.cpp : implementation of the CPSDoc class
//

#include "stdafx.h"
#include "PS.h"

#include "PSDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPSDoc

IMPLEMENT_DYNCREATE(CPSDoc, CDocument)

BEGIN_MESSAGE_MAP(CPSDoc, CDocument)
	ON_COMMAND(ID_FILE_SAVE, &CPSDoc::OnFileSave)
END_MESSAGE_MAP()


// CPSDoc construction/destruction

CPSDoc::CPSDoc()
{
	// TODO: add one-time construction code here
	m_image=0;

}

CPSDoc::~CPSDoc()
{
	delete m_image;
}

BOOL CPSDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}




// CPSDoc serialization

void CPSDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


// CPSDoc diagnostics

#ifdef _DEBUG
void CPSDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPSDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CPSDoc commands

