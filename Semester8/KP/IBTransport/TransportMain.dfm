object Form1: TForm1
  Left = 207
  Top = 125
  Caption = 'Form1'
  ClientHeight = 455
  ClientWidth = 999
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 120
  TextHeight = 16
  object IBTrucksDBG: TDBGrid
    Left = 20
    Top = 86
    Width = 394
    Height = 148
    DataSource = IBTrucksDS
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -14
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    OnExit = IBTrucksDBGExit
  end
  object DBTransportDBG: TDBGrid
    Left = 22
    Top = 282
    Width = 483
    Height = 148
    DataSource = IBTransportsDS
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -14
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    OnExit = DBTransportDBGExit
    Columns = <
      item
        Expanded = False
        FieldName = 'ID'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'DATA'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'QUANTITY'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'MatLU'
        Visible = True
      end>
  end
  object RadioGroup: TRadioGroup
    Left = 424
    Top = 12
    Width = 553
    Height = 60
    Caption = 'Menu'
    Columns = 3
    ItemIndex = 2
    Items.Strings = (
      'KATNO'
      'DESCRIPTION'
      'PO RED NA VAVEJDANE')
    TabOrder = 2
    OnClick = RadioGroupClick
  end
  object SearchBox: TEdit
    Left = 148
    Top = 23
    Width = 149
    Height = 24
    TabOrder = 3
  end
  object SearchButton: TButton
    Left = 306
    Top = 23
    Width = 100
    Height = 31
    Caption = 'Search'
    TabOrder = 4
  end
  object IBQueryDBG: TDBGrid
    Left = 524
    Top = 284
    Width = 394
    Height = 147
    DataSource = IBQueryDS
    TabOrder = 5
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -14
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
  end
  object QueryBox: TEdit
    Left = 604
    Top = 244
    Width = 149
    Height = 24
    TabOrder = 6
  end
  object QueryButton: TButton
    Left = 772
    Top = 244
    Width = 92
    Height = 30
    Caption = 'Query'
    TabOrder = 7
    OnClick = QueryButtonClick
  end
  object IBDB: TIBDatabase
    Connected = True
    DatabaseName = 'localhost/gds_db:C:\Projects\IBTransport\Data\IBTRANSPORT.GDB'
    Params.Strings = (
      'user_name=SYSDBA'
      'password=masterkey')
    LoginPrompt = False
    DefaultTransaction = IBTS
    ServerType = 'IBServer'
    Left = 16
    Top = 8
  end
  object IBTS: TIBTransaction
    Active = True
    DefaultDatabase = IBDB
    Left = 56
    Top = 8
  end
  object IBTrucksTbl: TIBTable
    Database = IBDB
    Transaction = IBTS
    BeforePost = IBTrucksTblBeforePost
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
        Name = 'KATNO'
        DataType = ftWideString
        Size = 12
      end
      item
        Name = 'DESCRIPTION'
        DataType = ftWideString
        Size = 25
      end>
    IndexDefs = <
      item
        Name = 'RDB$PRIMARY1'
        Fields = 'ID'
        Options = [ixPrimary, ixUnique]
      end
      item
        Name = 'TRUCKSTBLKATNONDX'
        Fields = 'KATNO'
      end
      item
        Name = 'TRUCKSTBLDESCRIPTIONNDX'
        Fields = 'DESCRIPTION'
      end>
    StoreDefs = True
    TableName = 'TRUCKS_TBL'
    UniDirectional = False
    Left = 16
    Top = 48
    object IBTrucksTblID: TIntegerField
      FieldName = 'ID'
    end
    object IBTrucksTblKATNO: TIBStringField
      FieldName = 'KATNO'
      Size = 12
    end
    object IBTrucksTblDESCRIPTION: TIBStringField
      FieldName = 'DESCRIPTION'
      Size = 25
    end
  end
  object IBTrucksDS: TDataSource
    DataSet = IBTrucksTbl
    Left = 56
    Top = 48
  end
  object IBTrucksSP: TIBStoredProc
    Database = IBDB
    Transaction = IBTS
    StoredProcName = 'TRUCKSTBL_IDSP'
    Left = 96
    Top = 48
  end
  object IBTransportsTbl: TIBTable
    Database = IBDB
    Transaction = IBTS
    BeforePost = IBTransportsTblBeforePost
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
        Name = 'TID'
        DataType = ftInteger
      end
      item
        Name = 'MID'
        DataType = ftInteger
      end
      item
        Name = 'DATA'
        DataType = ftWideString
        Size = 12
      end
      item
        Name = 'QUANTITY'
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
        Fields = 'TID'
      end
      item
        Name = 'RDB$FOREIGN5'
        Fields = 'MID'
      end>
    IndexFieldNames = 'TID'
    MasterFields = 'ID'
    MasterSource = IBTrucksDS
    StoreDefs = True
    TableName = 'TRANSPORTS_TBL'
    UniDirectional = False
    Left = 16
    Top = 240
    object IBTransportsTblID: TIntegerField
      FieldName = 'ID'
    end
    object IBTransportsTblTID: TIntegerField
      FieldName = 'TID'
    end
    object IBTransportsTblMID: TIntegerField
      FieldName = 'MID'
    end
    object IBTransportsTblDATA: TIBStringField
      FieldName = 'DATA'
      Size = 12
    end
    object IBTransportsTblQUANTITY: TIBBCDField
      FieldName = 'QUANTITY'
      Precision = 18
      Size = 2
    end
    object IBTransportsTblMatLU: TStringField
      FieldKind = fkLookup
      FieldName = 'MatLU'
      LookupDataSet = IBMatTbl
      LookupKeyFields = 'ID'
      LookupResultField = 'NAME'
      KeyFields = 'MID'
      Lookup = True
    end
  end
  object IBTransportsDS: TDataSource
    DataSet = IBTransportsTbl
    Left = 56
    Top = 240
  end
  object IBTransportsSP: TIBStoredProc
    Database = IBDB
    Transaction = IBTS
    StoredProcName = 'TRANSPORTSTBL_IDSP'
    Left = 96
    Top = 240
  end
  object IBMatTbl: TIBTable
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
        Size = 25
      end>
    IndexDefs = <
      item
        Name = 'RDB$PRIMARY2'
        Fields = 'ID'
        Options = [ixPrimary, ixUnique]
      end>
    StoreDefs = True
    TableName = 'MAT_TBL'
    UniDirectional = False
    Left = 272
    Top = 240
  end
  object IBQuery: TIBQuery
    Database = IBDB
    Transaction = IBTS
    Active = True
    BufferChunks = 1000
    CachedUpdates = False
    ParamCheck = True
    SQL.Strings = (
      'SELECT M.NAME AS MATERIAL, SUM(T.QUANTITY) AS KOLICHESTVO'
      'FROM TRUCKS_TBL TK, TRANSPORTS_TBL T, MAT_TBL M'
      'WHERE TK.KATNO = :PKATNO AND TK.ID = T.TID AND T.MID = M.ID'
      'GROUP BY M.NAME')
    Left = 528
    Top = 240
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'PKATNO'
        ParamType = ptUnknown
      end>
  end
  object IBQueryDS: TDataSource
    DataSet = IBQuery
    Left = 568
    Top = 240
  end
end
