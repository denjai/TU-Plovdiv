//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "IBTelBookMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::IBPersonsTblBeforePost(TDataSet *DataSet)
   {
   if(IBPersonsTbl->State == dsInsert)
      {
      IBPersonsSP->Prepare();
      IBPersonsSP->ExecProc();
      IBPersonsTbl->FieldByName("ID")->AsInteger =
         IBPersonsSP->ParamByName("ID")->AsInteger;
      }
   }
//---------------------------------------------------------------------------
void __fastcall TMainForm::IBTelsTblBeforePost(TDataSet *DataSet)
   {
   if(IBTelsTbl->State == dsInsert)
      {
      IBTelsSP->Prepare();
      IBTelsSP->ExecProc();
      IBTelsTbl->FieldByName("ID")->AsInteger =
         IBTelsSP->ParamByName("ID")->AsInteger;
      }
   }
//---------------------------------------------------------------------------
void __fastcall TMainForm::PersonsDBGExit(TObject *Sender)
   {
   if((IBPersonsTbl->State == dsInsert) ||
      (IBPersonsTbl->State == dsEdit))
         IBPersonsTbl->Post();
   }
//---------------------------------------------------------------------------
void __fastcall TMainForm::TelsDBGExit(TObject *Sender)
   {
   if((IBTelsTbl->State == dsInsert) ||
      (IBTelsTbl->State == dsEdit))
         IBTelsTbl->Post();
   }
//---------------------------------------------------------------------------

void __fastcall TMainForm::RadioGroupClick(TObject *Sender)
{
    switch(RadioGroup->ItemIndex) {
        case 0:
            IBPersonsTbl->IndexName = "PersonsTblNameNDX";
            break;
        case 1:
            IBPersonsTbl->IndexName = "PersonsTblFamNDX";
            break;
        case 2:
            IBPersonsTbl->IndexName = "";
            break;
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SearchBitBtnClick(TObject *Sender)
{
    TLocateOptions Opts;

    Opts.Clear();
    Opts << loPartialKey;
    Opts << loCaseInsensitive;

    switch(RadioGroup->ItemIndex) {
        case 0:
            IBPersonsTbl->Locate("NAME", SearchEB->Text, Opts);
            break;
        case 1:
            IBPersonsTbl->Locate("FAM", SearchEB->Text, Opts);
            break;
    }
}
//---------------------------------------------------------------------------

