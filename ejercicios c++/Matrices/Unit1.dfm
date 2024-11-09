object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 442
  ClientWidth = 628
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Panel1: TPanel
    Left = 48
    Top = 8
    Width = 521
    Height = 385
    Color = clAqua
    ParentBackground = False
    TabOrder = 0
    object Label1: TLabel
      Left = 240
      Top = 24
      Width = 93
      Height = 31
      Caption = 'Matriz_1'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -23
      Font.Name = 'Segoe UI'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object SG1: TStringGrid
      Left = 96
      Top = 72
      Width = 320
      Height = 120
      ColCount = 1
      DefaultColWidth = 32
      DefaultRowHeight = 30
      FixedCols = 0
      RowCount = 1
      FixedRows = 0
      TabOrder = 0
    end
  end
end
