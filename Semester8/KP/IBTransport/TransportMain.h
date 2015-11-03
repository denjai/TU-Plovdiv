//---------------------------------------------------------------------------

#ifndef TransportMainH
#define TransportMainH
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
#include <IBStoredProc.hpp>
#include <IBTable.hpp>
#include <ExtCtrls.hpp>
#include <IBQuery.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TIBDatabase *IBDB;
        TIBTransaction *IBTS;
        TIBTable *IBTrucksTbl;
        TDataSource *IBTrucksDS;
        TIBStoredProc *IBTrucksSP;
        TDBGrid *IBTrucksDBG;
        TIBTable *IBTransportsTbl;
        TDataSource *IBTransportsDS;
        TIBStoredProc *IBTransportsSP;
        TDBGrid *DBTransportDBG;
        TIBTable *IBMatTbl;
        TIntegerField *IBTransportsTblID;
        TIntegerField *IBTransportsTblTID;
        TIntegerField *IBTransportsTblMID;
        TIBStringField *IBTransportsTblDATA;
        TIBBCDField *IBTransportsTblQUANTITY;
        TRadioGroup *RadioGroup;
        TEdit *SearchBox;
        TButton *SearchButton;
        TIBQuery *IBQuery;
        TDataSource *IBQueryDS;
        TDBGrid *IBQueryDBG;
        TEdit *QueryBox;
        TButton *QueryButton;
        TIntegerField *IBTrucksTblID;
        TIBStringField *IBTrucksTblKATNO;
        TIBStringField *IBTrucksTblDESCRIPTION;
        TStringField *IBTransportsTblMatLU;
        void __fastcall QueryButtonClick(TObject *Sender);
        void __fastcall IBTrucksTblBeforePost(TDataSet *DataSet);
        void __fastcall IBTransportsTblBeforePost(TDataSet *DataSet);
        void __fastcall RadioGroupClick(TObject *Sender);
        void __fastcall IBTrucksDBGExit(TObject *Sender);
        void __fastcall DBTransportDBGExit(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
