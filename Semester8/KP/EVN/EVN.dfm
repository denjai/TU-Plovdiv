object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 740
  ClientWidth = 1050
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 120
  TextHeight = 16
  object CustomersDBG: TDBGrid
    Left = 8
    Top = 128
    Width = 649
    Height = 120
    DataSource = CustomersDS
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -13
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
  end
  object DBGrid2: TDBGrid
    Left = 8
    Top = 440
    Width = 649
    Height = 120
    DataSource = AccountsDS
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -13
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
  end
  object SelectRG: TRadioGroup
    Left = 768
    Top = 40
    Width = 185
    Height = 105
    Caption = 'SelectRG'
    ItemIndex = 2
    Items.Strings = (
      'IME'
      'FAMILIQ'
      'red na vuvejdane')
    TabOrder = 2
    OnClick = SelectRGClick
  end
  object searchEB: TEdit
    Left = 568
    Top = 40
    Width = 121
    Height = 24
    TabOrder = 3
    OnChange = searchEBChange
  end
  object DBGrid1: TDBGrid
    Left = 696
    Top = 440
    Width = 320
    Height = 120
    DataSource = QueryDS
    TabOrder = 4
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -13
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
  end
  object QueryEB: TEdit
    Left = 832
    Top = 400
    Width = 121
    Height = 24
    TabOrder = 5
  end
  object QueryBITBTN: TBitBtn
    Left = 959
    Top = 400
    Width = 75
    Height = 25
    Caption = 'SQL'
    TabOrder = 6
    OnClick = QueryBITBTNClick
  end
  object IBCustomers: TIBTable
    Database = IBDB
    Transaction = IBTS
    BeforePost = IBCustomersBeforePost
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
        Name = 'EGN'
        DataType = ftWideString
        Size = 10
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
      end
      item
        Name = 'ADDRESS'
        DataType = ftWideString
        Size = 33
      end>
    IndexDefs = <
      item
        Name = 'RDB$PRIMARY1'
        Fields = 'ID'
        Options = [ixPrimary, ixUnique]
      end
      item
        Name = 'CUSTOMERSTBLNAMENDX'
        Fields = 'NAME'
      end
      item
        Name = 'CUSTOMERSTBLFAMNDX'
        Fields = 'FAM'
      end>
    StoreDefs = True
    TableName = 'CUSTOMERS_TBL'
    UniDirectional = False
    Left = 32
    Top = 80
  end
  object IBDB: TIBDatabase
    Connected = True
    DatabaseName = 'localhost/gds_db:C:\Projects\EVN\Data\EVN.GDB'
    Params.Strings = (
      'user_name=SYSDBA'
      'password=masterkey')
    LoginPrompt = False
    DefaultTransaction = IBTS
    ServerType = 'IBServer'
    Left = 16
    Top = 16
  end
  object IBTS: TIBTransaction
    Active = True
    DefaultDatabase = IBDB
    Left = 80
    Top = 16
  end
  object CustomersDS: TDataSource
    DataSet = IBCustomers
    Left = 104
    Top = 72
  end
  object AccountsDS: TDataSource
    DataSet = IBAccounts
    Left = 104
    Top = 392
  end
  object IBAccounts: TIBTable
    Database = IBDB
    Transaction = IBTS
    BeforePost = IBAccountsBeforePost
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
        Name = 'CID'
        DataType = ftInteger
      end
      item
        Name = 'ATID'
        DataType = ftInteger
      end
      item
        Name = 'ACCOUNT_NO'
        DataType = ftWideString
        Size = 12
      end
      item
        Name = 'DATA'
        DataType = ftInteger
      end
      item
        Name = 'PAYMENT'
        DataType = ftBCD
        Precision = 14
        Size = 2
      end>
    IndexDefs = <
      item
        Name = 'RDB$PRIMARY3'
        Fields = 'ID'
        Options = [ixPrimary, ixUnique]
      end
      item
        Name = 'RDB$FOREIGN4'
        Fields = 'CID'
      end
      item
        Name = 'RDB$FOREIGN5'
        Fields = 'ATID'
      end>
    IndexFieldNames = 'CID'
    MasterFields = 'ID'
    MasterSource = CustomersDS
    StoreDefs = True
    TableName = 'ACCOUNTS_TBL'
    UniDirectional = False
    Left = 24
    Top = 392
    object IBAccountsID: TIntegerField
      FieldName = 'ID'
      Required = True
    end
    object IBAccountsCID: TIntegerField
      FieldName = 'CID'
    end
    object IBAccountsATID: TIntegerField
      FieldName = 'ATID'
    end
    object IBAccountsACCOUNT_NO: TIBStringField
      FieldName = 'ACCOUNT_NO'
      Size = 12
    end
    object IBAccountsDATA: TIntegerField
      FieldName = 'DATA'
    end
    object IBAccountsPAYMENT: TIBBCDField
      FieldName = 'PAYMENT'
      Precision = 14
      Size = 2
    end
    object IBAccountsAcountsTpyeLU: TStringField
      FieldKind = fkLookup
      FieldName = 'AcountsTpyeLU'
      LookupDataSet = IBAccountTypes
      LookupKeyFields = 'ID'
      LookupResultField = 'ACCOUNTTYPE'
      KeyFields = 'ATID'
      Lookup = True
    end
  end
  object CustomersSP: TIBStoredProc
    Database = IBDB
    Transaction = IBTS
    StoredProcName = 'CUSTOMERSTBL_IDSP'
    Left = 192
    Top = 72
  end
  object AccountsSP: TIBStoredProc
    Database = IBDB
    Transaction = IBTS
    StoredProcName = 'ACCOUNTSTBL_IDSP'
    Left = 184
    Top = 392
  end
  object IBAccountTypes: TIBTable
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
        Name = 'ACCOUNTTYPE'
        DataType = ftWideString
        Size = 12
      end>
    IndexDefs = <
      item
        Name = 'RDB$PRIMARY2'
        Fields = 'ID'
        Options = [ixPrimary, ixUnique]
      end>
    StoreDefs = True
    TableName = 'ACCOUNTTYPES_TBL'
    UniDirectional = False
    Left = 312
    Top = 392
  end
  object IBQuery: TIBQuery
    Database = IBDB
    Transaction = IBTS
    Active = True
    BufferChunks = 1000
    CachedUpdates = False
    ParamCheck = True
    SQL.Strings = (
      'SELECT C.EGN, C.NAME, C.FAM, A.DATA, A.PAYMENT, ACT.ACCOUNTTYPE'
      'FROM CUSTOMERS_TBL C, ACCOUNTS_TBL A, ACCOUNTTYPES_TBL ACT'
      'WHERE C.EGN = :PEGN AND C.ID = A.CID AND A.ATID = ACT.ID')
    Left = 704
    Top = 392
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'PEGN'
        ParamType = ptUnknown
      end>
  end
  object QueryDS: TDataSource
    DataSet = IBQuery
    Left = 776
    Top = 392
  end
end
