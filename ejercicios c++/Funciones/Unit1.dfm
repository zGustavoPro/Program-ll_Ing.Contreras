object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Funciones'
  ClientHeight = 442
  ClientWidth = 628
  Color = clAqua
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poDesigned
  TextHeight = 15
  object Edit1: TEdit
    Left = 16
    Top = 48
    Width = 121
    Height = 23
    TabOrder = 0
    TextHint = 'edit1'
  end
  object Edit2: TEdit
    Left = 208
    Top = 48
    Width = 121
    Height = 23
    TabOrder = 1
    TextHint = 'edit2'
  end
  object Button1: TButton
    Left = 16
    Top = 88
    Width = 75
    Height = 25
    Caption = 'suma'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 16
    Top = 128
    Width = 75
    Height = 25
    Caption = 'sum_par'
    TabOrder = 3
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 16
    Top = 159
    Width = 75
    Height = 25
    Caption = 'sum_impar'
    TabOrder = 4
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 16
    Top = 190
    Width = 75
    Height = 25
    Caption = 'invertir'
    TabOrder = 5
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 16
    Top = 221
    Width = 75
    Height = 25
    Caption = 'factorial'
    TabOrder = 6
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 16
    Top = 252
    Width = 75
    Height = 25
    Caption = 'inver_cad'
    TabOrder = 7
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 16
    Top = 283
    Width = 75
    Height = 25
    Caption = 'ult_num'
    TabOrder = 8
    OnClick = Button7Click
  end
  object SG1: TStringGrid
    Left = 40
    Top = 8
    Width = 320
    Height = 25
    ColCount = 7
    DefaultColWidth = 32
    DefaultRowHeight = 34
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goFixedRowDefAlign]
    TabOrder = 9
  end
  object Button8: TButton
    Left = 16
    Top = 314
    Width = 75
    Height = 25
    Caption = 'inv_Vpar'
    TabOrder = 10
    OnClick = Button8Click
  end
  object Button9: TButton
    Left = 128
    Top = 88
    Width = 75
    Height = 25
    Caption = 'inv_Vector'
    TabOrder = 11
    OnClick = Button9Click
  end
  object Button10: TButton
    Left = 128
    Top = 128
    Width = 75
    Height = 25
    Caption = 'Cargar'
    TabOrder = 12
    OnClick = Button10Click
  end
  object Button11: TButton
    Left = 128
    Top = 159
    Width = 75
    Height = 25
    Caption = 'Cant_dig'
    TabOrder = 13
    OnClick = Button11Click
  end
  object Button12: TButton
    Left = 128
    Top = 190
    Width = 75
    Height = 25
    Caption = 'columnas'
    TabOrder = 14
    OnClick = Button12Click
  end
end
