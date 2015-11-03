object MainForm: TMainForm
  Left = 256
  Top = 121
  Width = 803
  Height = 672
  Caption = 'Telephone book'
  Color = clSkyBlue
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object PersonsDBG: TDBGrid
    Left = 32
    Top = 184
    Width = 417
    Height = 417
    DataSource = PersonsDS
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    OnExit = PersonsDBGExit
    Columns = <
      item
        Expanded = False
        FieldName = 'ID'
        Visible = False
      end
      item
        Expanded = False
        FieldName = 'NAME'
        Title.Caption = #1048#1084#1077
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'FAM'
        Title.Caption = #1060#1072#1084#1080#1083#1080#1103
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'ADDRESS'
        Title.Caption = #1040#1076#1088#1077#1089
        Visible = True
      end>
  end
  object TelsDBG: TDBGrid
    Left = 464
    Top = 184
    Width = 297
    Height = 145
    DataSource = TelsDS
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    OnExit = TelsDBGExit
    Columns = <
      item
        Expanded = False
        FieldName = 'ID'
        Visible = False
      end
      item
        Expanded = False
        FieldName = 'PID'
        Visible = False
      end
      item
        Expanded = False
        FieldName = 'TID'
        Visible = False
      end
      item
        Expanded = False
        FieldName = 'TelType'
        Title.Caption = #1058#1080#1087' '#1085#1072' '#1090#1077#1083#1077#1092#1086#1085#1072
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'NOMER'
        Title.Caption = #1053#1086#1084#1077#1088
        Width = 148
        Visible = True
      end>
  end
  object RadioGroup: TRadioGroup
    Left = 496
    Top = 24
    Width = 185
    Height = 105
    Caption = #1055#1086#1076#1088#1077#1076#1077#1085#1086' '#1087#1086
    ItemIndex = 0
    Items.Strings = (
      #1048#1084#1077
      #1060#1072#1084#1080#1083#1080#1103
      #1088#1077#1076' '#1085#1072' '#1074#1098#1074#1077#1076#1072#1085#1077)
    TabOrder = 2
    OnClick = RadioGroupClick
  end
  object SearchEB: TEdit
    Left = 136
    Top = 96
    Width = 193
    Height = 26
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clHotLight
    Font.Height = -16
    Font.Name = 'Verdana'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnChange = SearchBitBtnClick
  end
  object SearchBitBtn: TBitBtn
    Left = 352
    Top = 96
    Width = 75
    Height = 33
    Caption = #1058#1098#1088#1089#1077#1085#1077
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMenuHighlight
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 4
    OnClick = SearchBitBtnClick
  end
  object IBDB: TIBDatabase
    Connected = True
    DatabaseName = 'C:\Projects\IBTelBook\Data\IBTELBOOK.GDB'
    Params.Strings = (
      'user_name=SYSDBA'
      'password=masterkey')
    LoginPrompt = False
    DefaultTransaction = IBTS
    IdleTimer = 0
    SQLDialect = 3
    TraceFlags = []
    Left = 32
    Top = 96
  end
  object IBTS: TIBTransaction
    Active = True
    DefaultDatabase = IBDB
    AutoStopAction = saNone
    Left = 88
    Top = 96
  end
  object IBPersonsTbl: TIBTable
    Database = IBDB
    Transaction = IBTS
    BeforePost = IBPersonsTblBeforePost
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
        DataType = ftString
        Size = 12
      end
      item
        Name = 'FAM'
        DataType = ftString
        Size = 15
      end
      item
        Name = 'ADDRESS'
        DataType = ftString
        Size = 33
      end>
    IndexDefs = <
      item
        Name = 'RDB$PRIMARY1'
        Fields = 'ID'
        Options = [ixPrimary, ixUnique]
      end
      item
        Name = 'PERSONSTBLNAMENDX'
        Fields = 'NAME'
      end
      item
        Name = 'PERSONSTBLFAMNDX'
        Fields = 'FAM'
      end>
    StoreDefs = True
    TableName = 'PERSONS_TBL'
    Left = 32
    Top = 144
    object IBPersonsTblID: TIntegerField
      FieldName = 'ID'
    end
    object IBPersonsTblNAME: TIBStringField
      FieldName = 'NAME'
      Size = 12
    end
    object IBPersonsTblFAM: TIBStringField
      FieldName = 'FAM'
      Size = 15
    end
    object IBPersonsTblADDRESS: TIBStringField
      FieldName = 'ADDRESS'
      Size = 33
    end
  end
  object PersonsDS: TDataSource
    DataSet = IBPersonsTbl
    Left = 88
    Top = 144
  end
  object IBTelsTbl: TIBTable
    Database = IBDB
    Transaction = IBTS
    BeforePost = IBTelsTblBeforePost
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
        Name = 'PID'
        DataType = ftInteger
      end
      item
        Name = 'TID'
        DataType = ftInteger
      end
      item
        Name = 'NOMER'
        DataType = ftString
        Size = 33
      end>
    IndexDefs = <
      item
        Name = 'RDB$PRIMARY3'
        Fields = 'ID'
        Options = [ixPrimary, ixUnique]
      end
      item
        Name = 'RDB$FOREIGN4'
        Fields = 'PID'
      end
      item
        Name = 'RDB$FOREIGN5'
        Fields = 'TID'
      end>
    IndexFieldNames = 'PID'
    MasterFields = 'ID'
    MasterSource = PersonsDS
    StoreDefs = True
    TableName = 'TELS_TBL'
    Left = 504
    Top = 144
    object IBTelsTblID: TIntegerField
      FieldName = 'ID'
    end
    object IBTelsTblPID: TIntegerField
      FieldName = 'PID'
    end
    object IBTelsTblTID: TIntegerField
      FieldName = 'TID'
    end
    object IBTelsTblNOMER: TIBStringField
      FieldName = 'NOMER'
      Size = 33
    end
    object IBTelsTblTelType: TStringField
      FieldKind = fkLookup
      FieldName = 'TelType'
      LookupDataSet = IBTelTypesTbl
      LookupKeyFields = 'ID'
      LookupResultField = 'TELTYPE'
      KeyFields = 'TID'
      Lookup = True
    end
  end
  object TelsDS: TDataSource
    DataSet = IBTelsTbl
    Left = 552
    Top = 144
  end
  object IBPersonsSP: TIBStoredProc
    Database = IBDB
    Transaction = IBTS
    StoredProcName = 'PERSONSTBL_IDSP'
    Left = 152
    Top = 144
  end
  object IBTelsSP: TIBStoredProc
    Database = IBDB
    Transaction = IBTS
    StoredProcName = 'TELSTBL_IDSP'
    Left = 608
    Top = 144
  end
  object IBTelTypesTbl: TIBTable
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
        Name = 'TELTYPE'
        DataType = ftString
        Size = 10
      end>
    IndexDefs = <
      item
        Name = 'RDB$PRIMARY2'
        Fields = 'ID'
        Options = [ixPrimary, ixUnique]
      end>
    StoreDefs = True
    TableName = 'TELTYPES_TBL'
    Left = 488
    Top = 360
  end
end
