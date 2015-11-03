//---------------------------------------------------------------------------

#ifndef IBTelBookMainH
#define IBTelBookMainH
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
#include <IBStoredProc.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TIBDatabase *IBDB;
        TIBTransaction *IBTS;
        TIBTable *IBPersonsTbl;
        TDataSource *PersonsDS;
        TDBGrid *PersonsDBG;
        TIBTable *IBTelsTbl;
        TDataSource *TelsDS;
        TDBGrid *TelsDBG;
        TIntegerField *IBPersonsTblID;
        TIBStringField *IBPersonsTblNAME;
        TIBStringField *IBPersonsTblFAM;
        TIBStringField *IBPersonsTblADDRESS;
        TIntegerField *IBTelsTblID;
        TIntegerField *IBTelsTblPID;
        TIntegerField *IBTelsTblTID;
        TIBStringField *IBTelsTblNOMER;
        TIBStoredProc *IBPersonsSP;
        TIBStoredProc *IBTelsSP;
        TRadioGroup *RadioGroup;
    TEdit *SearchEB;
    TBitBtn *SearchBitBtn;
    TIBTable *IBTelTypesTbl;
    TStringField *IBTelsTblTelType;
        void __fastcall IBPersonsTblBeforePost(TDataSet *DataSet);
        void __fastcall IBTelsTblBeforePost(TDataSet *DataSet);
        void __fastcall PersonsDBGExit(TObject *Sender);
        void __fastcall TelsDBGExit(TObject *Sender);
        void __fastcall RadioGroupClick(TObject *Sender);
    void __fastcall SearchBitBtnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
