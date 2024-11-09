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
    Left = 80
    Top = 32
    Width = 71
    Height = 15
    Caption = 'Archivo texto'
  end
  object Edit1: TEdit
    Left = 16
    Top = 72
    Width = 449
    Height = 23
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 16
    Top = 112
    Width = 449
    Height = 23
    TabOrder = 1
  end
  object Button1: TButton
    Left = 32
    Top = 168
    Width = 75
    Height = 25
    Caption = 'pregunta 1'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 32
    Top = 208
    Width = 75
    Height = 25
    Caption = 'pregunta2'
    TabOrder = 3
    OnClick = Button2Click
  end
  object OpenTextFileDialog1: TOpenTextFileDialog
    Left = 584
    Top = 24
  end
end
