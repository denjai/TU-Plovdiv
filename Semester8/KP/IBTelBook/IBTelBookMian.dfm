object MainForm: TMainForm
  Left = 198
  Top = 160
  Caption = 'Ukazatel'
  ClientHeight = 435
  ClientWidth = 996
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 120
  TextHeight = 16
  object PersonsDBG: TDBGrid
    Left = 256
    Top = 10
    Width = 700
    Height = 198
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataSource = PersonsDS
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -14
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
  end
  object TelsDBG: TDBGrid
    Left = 266
    Top = 266
    Width = 690
    Height = 148
    Margins.Left = 4
    Margins.Top = 4
    Margins.Right = 4
    Margins.Bottom = 4
    DataSource = TelsDS
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -14
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
  end
  object IBDB: TIBDatabase
    Connected = True
    DatabaseName = 'localhost/gds_db:C:\Projects\IBTelBook\Data\IBTELBOOK.GDB'
    Params.Strings = (
      'user_name=SYSDBA'
      'password=masterkey')
    LoginPrompt = False
    DefaultTransaction = IBTS
    ServerType = 'IBServer'
    Left = 24
    Top = 16
  end
  object IBTS: TIBTransaction
    Active = True
    DefaultDatabase = IBDB
    Left = 88
    Top = 16
  end
  object IBPersonsTbl: TIBTable
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
      end>
    StoreDefs = True
    TableName = 'PERSONS_TBL'
    UniDirectional = False
    Left = 24
    Top = 72
  end
  object PersonsDS: TDataSource
    DataSet = IBPersonsTbl
    Left = 88
    Top = 72
  end
  object TelsDS: TDataSource
    DataSet = IBTELS_tbl
    Left = 96
    Top = 216
  end
  object IBTELS_tbl: TIBTable
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
        Name = 'PID'
        DataType = ftInteger
      end
      item
        Name = 'TID'
        DataType = ftInteger
      end
      item
        Name = 'NOMER'
        DataType = ftWideString
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
    UniDirectional = False
    Left = 40
    Top = 216
    object IBTELS_tblID: TIntegerField
      FieldName = 'ID'
      Required = True
    end
    object IBTELS_tblPID: TIntegerField
      FieldName = 'PID'
    end
    object IBTELS_tblTID: TIntegerField
      FieldName = 'TID'
    end
    object IBTELS_tblNOMER: TIBStringField
      FieldName = 'NOMER'
      Size = 33
    end
  end
end
