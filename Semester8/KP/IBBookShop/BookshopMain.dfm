object Form1: TForm1
  Left = 261
  Top = 108
  Caption = 'BookShop'
  ClientHeight = 539
  ClientWidth = 861
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 120
  TextHeight = 16
  object DBGrid1: TDBGrid
    Left = 30
    Top = 113
    Width = 395
    Height = 159
    DataSource = IBAuthorsDS
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -14
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    OnExit = DBGrid1Exit
  end
  object DBGrid2: TDBGrid
    Left = 28
    Top = 349
    Width = 413
    Height = 169
    DataSource = IBBooksDS
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -14
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    OnExit = DBGrid2Exit
  end
  object SearchBox: TEdit
    Left = 142
    Top = 25
    Width = 178
    Height = 24
    TabOrder = 2
    OnChange = SearchBoxChange
  end
  object RadioGroup: TRadioGroup
    Left = 330
    Top = 1
    Width = 208
    Height = 110
    Caption = 'Search by:'
    ItemIndex = 1
    Items.Strings = (
      'Name'
      'Family')
    TabOrder = 3
    OnClick = RadioGroupClick
  end
  object DBGrid3: TDBGrid
    Left = 477
    Top = 349
    Width = 348
    Height = 159
    DataSource = IBQueryDS
    TabOrder = 4
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -14
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
  end
  object QueryBox: TEdit
    Left = 552
    Top = 316
    Width = 172
    Height = 24
    TabOrder = 5
  end
  object QueryBtn: TButton
    Left = 733
    Top = 308
    Width = 92
    Height = 29
    Caption = 'Run query'
    TabOrder = 6
    OnClick = QueryBtnClick
  end
  object IBDB: TIBDatabase
    Connected = True
    DatabaseName = 'localhost/gds_db:C:\Projects\IBBookShop\Data\IBBOOKSHOP.GDB'
    Params.Strings = (
      'user_name=SYSDBA'
      'password=masterkey')
    LoginPrompt = False
    ServerType = 'IBServer'
    Left = 32
    Top = 24
  end
  object IBTS: TIBTransaction
    Active = True
    DefaultDatabase = IBDB
    Left = 80
    Top = 24
  end
  object IBAuthorsTbl: TIBTable
    Database = IBDB
    Transaction = IBTS
    BeforePost = IBAuthorsTblBeforePost
    Active = True
    BufferChunks = 1000
    CachedUpdates = False
    FieldDefs = <
      item
        Name = 'ID'
        Attributes = [faRequired]
        DataType = ftInteger
      end
      item
        Name = 'NAME'
        DataType = ftWideString
        Size = 12
      end
      item
        Name = 'FAM'
        DataType = ftWideString
        Size = 15
      end>
    IndexDefs = <
      item
        Name = 'RDB$PRIMARY1'
        Fields = 'ID'
        Options = [ixPrimary, ixUnique]
      end
      item
        Name = 'AUTHORSTBLNAMENDX'
        Fields = 'NAME'
      end
      item
        Name = 'AUTHORSTBLFAMNDX'
        Fields = 'FAM'
      end>
    StoreDefs = True
    TableName = 'AUTHORS_TBL'
    UniDirectional = False
    Left = 32
    Top = 72
  end
  object IBAuthorsDS: TDataSource
    DataSet = IBAuthorsTbl
    Left = 72
    Top = 72
  end
  object IBBooksTbl: TIBTable
    Database = IBDB
    Transaction = IBTS
    BeforePost = IBBooksTblBeforePost
    Active = True
    BufferChunks = 1000
    CachedUpdates = False
    FieldDefs = <
      item
        Name = 'ID'
        Attributes = [faRequired]
        DataType = ftInteger
      end
      item
        Name = 'AID'
        DataType = ftInteger
      end
      item
        Name = 'GID'
        DataType = ftInteger
      end
      item
        Name = 'ISBN'
        DataType = ftWideString
        Size = 12
      end
      item
        Name = 'NAME'
        DataType = ftWideString
        Size = 50
      end>
    IndexDefs = <
      item
        Name = 'RDB$PRIMARY3'
        Fields = 'ID'
        Options = [ixPrimary, ixUnique]
      end
      item
        Name = 'RDB$FOREIGN4'
        Fields = 'AID'
      end
      item
        Name = 'RDB$FOREIGN5'
        Fields = 'GID'
      end>
    IndexFieldNames = 'AID'
    MasterFields = 'ID'
    MasterSource = IBAuthorsDS
    StoreDefs = True
    TableName = 'BOOKS_TBL'
    UniDirectional = False
    Left = 32
    Top = 312
    object IBBooksTblID: TIntegerField
      DisplayWidth = 12
      FieldName = 'ID'
      Required = True
    end
    object IBBooksTblAID: TIntegerField
      DisplayWidth = 12
      FieldName = 'AID'
    end
    object IBBooksTblGID: TIntegerField
      DisplayWidth = 12
      FieldName = 'GID'
    end
    object IBBooksTblISBN: TIBStringField
      DisplayWidth = 15
      FieldName = 'ISBN'
      Size = 12
    end
    object IBBooksTblNAME: TIBStringField
      DisplayWidth = 40
      FieldName = 'NAME'
      Size = 50
    end
    object IBBooksTblGenreLU: TStringField
      DisplayWidth = 26
      FieldKind = fkLookup
      FieldName = 'GenreLU'
      LookupDataSet = IBGenresTbl
      LookupKeyFields = 'ID'
      LookupResultField = 'NAME'
      KeyFields = 'GID'
      Size = 0
      Lookup = True
    end
  end
  object IBBooksDS: TDataSource
    DataSet = IBBooksTbl
    Left = 80
    Top = 312
  end
  object IBAuthorsSP: TIBStoredProc
    Database = IBDB
    Transaction = IBTS
    StoredProcName = 'AUTHORSTBL_IDSP'
    Left = 128
    Top = 72
  end
  object IBBooksSP: TIBStoredProc
    Database = IBDB
    Transaction = IBTS
    StoredProcName = 'BOOKSTBL_IDSP'
    Left = 136
    Top = 312
  end
  object IBGenresTbl: TIBTable
    Database = IBDB
    Transaction = IBTS
    Active = True
    BufferChunks = 1000
    CachedUpdates = False
    FieldDefs = <
      item
        Name = 'ID'
        Attributes = [faRequired]
        DataType = ftInteger
      end
      item
        Name = 'NAME'
        DataType = ftWideString
        Size = 15
      end>
    IndexDefs = <
      item
        Name = 'RDB$PRIMARY2'
        Fields = 'ID'
        Options = [ixPrimary, ixUnique]
      end>
    StoreDefs = True
    TableName = 'GENRES_TBL'
    UniDirectional = False
    Left = 192
    Top = 312
  end
  object IBQuery: TIBQuery
    Database = IBDB
    Transaction = IBTS
    Active = True
    BufferChunks = 1000
    CachedUpdates = False
    ParamCheck = True
    SQL.Strings = (
      'SELECT A.NAME as AUTHOR, B.NAME as BOOK, G.NAME AS GENRE'
      'FROM GENRES_TBL G, BOOKS_TBL B, AUTHORS_TBL A'
      'WHERE G.NAME LIKE :PNAME AND G.ID = B.GID AND B.AID = A.ID')
    Left = 472
    Top = 312
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'PNAME'
        ParamType = ptUnknown
      end>
  end
  object IBQueryDS: TDataSource
    DataSet = IBQuery
    Left = 512
    Top = 312
  end
end
