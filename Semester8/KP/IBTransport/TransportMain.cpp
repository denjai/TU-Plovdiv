//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TransportMain.h"
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
void __fastcall TForm1::QueryButtonClick(TObject *Sender)
{
     IBQuery->Close();
        IBQuery->Prepare();
        IBQuery->ParamByName("PKATNO")->AsString = QueryBox->Text;
        IBQuery->Open();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::IBTrucksTblBeforePost(TDataSet *DataSet)
{
  if ( IBTrucksTbl->State == dsInsert ){
                IBTrucksSP->Prepare();
                IBTrucksSP->ExecProc();
                IBTrucksTbl->FieldByName("ID")->AsInteger =
                        IBTrucksSP->ParamByName("ID")->AsInteger;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::IBTransportsTblBeforePost(TDataSet *DataSet)
{
 if ( IBTransportsTbl->State == dsInsert ){
                IBTransportsSP->Prepare();
                IBTransportsSP->ExecProc();
                IBTransportsTbl->FieldByName("ID")->AsInteger =
                        IBTransportsSP->ParamByName("ID")->AsInteger;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioGroupClick(TObject *Sender)
{
  switch ( RadioGroup->ItemIndex ) {
                case 0: IBTrucksTbl->IndexName = "TrucksTblKatNoNDX";
                        break;
                case 1: IBTrucksTbl->IndexName = "TrucksTblDescriptionNDX";
                        break;
                case 2: IBTrucksTbl->IndexName = "";
                        break;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::IBTrucksDBGExit(TObject *Sender)
{
 if ( IBTrucksTbl->State == dsInsert || IBTrucksTbl->State == dsEdit )
                IBTrucksTbl->Post();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DBTransportDBGExit(TObject *Sender)
{
 if ( IBTransportsTbl->State == dsInsert || IBTransportsTbl->State == dsEdit )
                IBTransportsTbl->Post();
}
//---------------------------------------------------------------------------
