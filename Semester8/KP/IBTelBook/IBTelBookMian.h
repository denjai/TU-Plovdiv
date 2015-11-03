//---------------------------------------------------------------------------

#ifndef IBTelBookMianH
#define IBTelBookMianH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBTable.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TIBDatabase *IBDB;
        TIBTransaction *IBTS;
        TIBTable *IBPersonsTbl;
        TDataSource *PersonsDS;
        TDBGrid *PersonsDBG;
        TDataSource *TelsDS;
        TDBGrid *TelsDBG;
        TIBTable *IBTELS_tbl;
        TIntegerField *IBTELS_tblID;
        TIntegerField *IBTELS_tblPID;
        TIntegerField *IBTELS_tblTID;
        TIBStringField *IBTELS_tblNOMER;
private:	// User declarations
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
