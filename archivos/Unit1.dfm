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
  object Label1: TLabel
    Left = 72
    Top = 24
    Width = 44
    Height = 15
    Caption = 'archivos'
  end
  object Edit1: TEdit
    Left = 32
    Top = 45
    Width = 177
    Height = 23
    TabOrder = 0
  end
  object Button1: TButton
    Left = 32
    Top = 122
    Width = 75
    Height = 25
    Caption = 'cant_pala'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Edit2: TEdit
    Left = 32
    Top = 74
    Width = 177
    Height = 23
    TabOrder = 2
  end
  object Button2: TButton
    Left = 32
    Top = 153
    Width = 75
    Height = 25
    Caption = 'cant_pal2'
    TabOrder = 3
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 32
    Top = 184
    Width = 75
    Height = 25
    Caption = 'pal_vocal'
    TabOrder = 4
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 32
    Top = 215
    Width = 75
    Height = 25
    Caption = 'dele_notalf'
    TabOrder = 5
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 32
    Top = 246
    Width = 75
    Height = 25
    Caption = 'Alinear_izq'
    TabOrder = 6
    OnClick = Button5Click
  end
  object OpenTextFileDialog1: TOpenTextFileDialog
    Left = 496
    Top = 40
  end
end