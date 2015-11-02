// PSDoc.h : interface of the CPSDoc class
//


#pragma once


class CPSDoc : public CDocument
{
protected: // create from serialization only
	CPSDoc();
	DECLARE_DYNCREATE(CPSDoc)

// Attributes
private:
	CImage *m_image;
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CPSDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	//afx_msg void OnFileSave();
};


