//---------------------------------------------------------------------------

#ifndef EVNH
#define EVNH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <IBCustomDataSet.hpp>
#include <IBDatabase.hpp>
#include <IBTable.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <IBStoredProc.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <IBQuery.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TIBTable *IBCustomers;
	TIBDatabase *IBDB;
	TIBTransaction *IBTS;
	TDataSource *CustomersDS;
	TDBGrid *CustomersDBG;
	TDBGrid *DBGrid2;
	TDataSource *AccountsDS;
	TIBTable *IBAccounts;
	TIBStoredProc *CustomersSP;
	TIBStoredProc *AccountsSP;
	TRadioGroup *SelectRG;
	TEdit *searchEB;
	TIBTable *IBAccountTypes;
	TIntegerField *IBAccountsID;
	TIntegerField *IBAccountsCID;
	TIntegerField *IBAccountsATID;
	TIBStringField *IBAccountsACCOUNT_NO;
	TIntegerField *IBAccountsDATA;
	TIBBCDField *IBAccountsPAYMENT;
	TStringField *IBAccountsAcountsTpyeLU;
	TIBQuery *IBQuery;
	TDataSource *QueryDS;
	TDBGrid *DBGrid1;
	TEdit *QueryEB;
	TBitBtn *QueryBITBTN;
	void __fastcall IBCustomersBeforePost(TDataSet *DataSet);
	void __fastcall IBAccountsBeforePost(TDataSet *DataSet);
	void __fastcall SelectRGClick(TObject *Sender);
	void __fastcall searchEBChange(TObject *Sender);
	void __fastcall QueryBITBTNClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
