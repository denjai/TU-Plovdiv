//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "EVN.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::IBCustomersBeforePost(TDataSet *DataSet)
{
 if(IBCustomers->State == dsInsert)
    {
	CustomersSP->Prepare();
	CustomersSP->ExecProc();
	IBCustomers->FieldByName("ID")->AsInteger = CustomersSP->ParamByName("ID")->AsInteger;

	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::IBAccountsBeforePost(TDataSet *DataSet)
{
	if(IBAccounts->State == dsInsert)
	{
	AccountsSP->Prepare();
	AccountsSP->ExecProc();
	IBAccounts->FieldByName("ID")->AsInteger = AccountsSP->ParamByName("ID")->AsInteger;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SelectRGClick(TObject *Sender)
{
   switch (SelectRG->ItemIndex)
    {
	case 0: IBCustomers->IndexName= "CustomersTblNameNDX"; break;
	case 1: IBCustomers->IndexName= "CustomersTblFamNDX"; break;
    case 2: IBCustomers->IndexName= ""; break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::searchEBChange(TObject *Sender)
{
    TLocateOptions Opts;
    Opts.Clear();
    Opts<<loPartialKey;

    switch (SelectRG->ItemIndex)
    {
    case 0: IBCustomers->Locate("NAME",searchEB->Text, Opts); break;
	case 1: IBCustomers->Locate("FAM",searchEB->Text, Opts); break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::QueryBITBTNClick(TObject *Sender)
{
 IBQuery->Close();
 IBQuery->Prepare();
 IBQuery->ParamByName("PEGN") ->AsString = QueryEB->Text;
 IBQuery->Open();
}
//---------------------------------------------------------------------------
