//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BookshopMain.h"
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
void __fastcall TForm1::IBAuthorsTblBeforePost(TDataSet *DataSet)
{
if (IBAuthorsTbl->State == dsInsert) {

IBAuthorsSP->Prepare();
IBAuthorsSP->ExecProc();
IBAuthorsTbl->FieldByName("ID")->AsInteger = IBAuthorsSP->ParamByName("ID")->AsInteger;
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::IBBooksTblBeforePost(TDataSet *DataSet)
{
if (IBBooksTbl->State == dsInsert) {

IBBooksSP->Prepare();
IBBooksSP->ExecProc();
IBBooksTbl->FieldByName("ID")->AsInteger = IBBooksSP->ParamByName("ID")->AsInteger;
}        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DBGrid1Exit(TObject *Sender)
{
if ((IBAuthorsTbl->State == dsInsert) || (IBAuthorsTbl->State == dsEdit))
IBAuthorsTbl->Post();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DBGrid2Exit(TObject *Sender)
{
 if ((IBBooksTbl->State == dsInsert) || (IBBooksTbl->State == dsEdit))
IBBooksTbl->Post();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioGroupClick(TObject *Sender)
{
switch (RadioGroup->ItemIndex)       {

case 0: IBAuthorsTbl->IndexName = "AuthorsTblNameNDX"; break;
case 1: IBAuthorsTbl->IndexName = "AuthorsTblFamNDX"; break;

}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SearchBoxChange(TObject *Sender)
{

TLocateOptions oplist;
oplist.Clear();
oplist<<loPartialKey;

switch (RadioGroup->ItemIndex)       {

case 0:IBAuthorsTbl->Locate("NAME", SearchBox->Text, oplist); break;
case 1:IBAuthorsTbl->Locate("FAM", SearchBox->Text, oplist); break;

}


}
//---------------------------------------------------------------------------

void __fastcall TForm1::QueryBtnClick(TObject *Sender)
{
IBQuery->Close();
IBQuery->Prepare();
IBQuery->ParamByName("PNAME")->AsString= QueryBox->Text;
IBQuery->Open();
}
//---------------------------------------------------------------------------

