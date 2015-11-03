//---------------------------------------------------------------------------

#ifndef BookshopMainH
#define BookshopMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <IBDatabase.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <IBCustomDataSet.hpp>
#include <IBTable.hpp>
#include <IBStoredProc.hpp>
#include <ExtCtrls.hpp>
#include <IBQuery.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TIBDatabase *IBDB;
        TIBTransaction *IBTS;
        TIBTable *IBAuthorsTbl;
        TDataSource *IBAuthorsDS;
        TDBGrid *DBGrid1;
        TIBTable *IBBooksTbl;
        TDataSource *IBBooksDS;
        TDBGrid *DBGrid2;
        TIBStoredProc *IBAuthorsSP;
        TIBStoredProc *IBBooksSP;
        TEdit *SearchBox;
        TRadioGroup *RadioGroup;
        TIBTable *IBGenresTbl;
        TIntegerField *IBBooksTblID;
        TIntegerField *IBBooksTblAID;
        TIntegerField *IBBooksTblGID;
        TIBStringField *IBBooksTblISBN;
        TIBStringField *IBBooksTblNAME;
        TStringField *IBBooksTblGenreLU;
        TIBQuery *IBQuery;
        TDataSource *IBQueryDS;
        TDBGrid *DBGrid3;
        TEdit *QueryBox;
        TButton *QueryBtn;
        void __fastcall IBAuthorsTblBeforePost(TDataSet *DataSet);
        void __fastcall IBBooksTblBeforePost(TDataSet *DataSet);
        void __fastcall DBGrid1Exit(TObject *Sender);
        void __fastcall DBGrid2Exit(TObject *Sender);
        void __fastcall RadioGroupClick(TObject *Sender);
        void __fastcall SearchBoxChange(TObject *Sender);
        void __fastcall QueryBtnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
