object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 433
  ClientWidth = 944
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label1: TLabel
    Left = 176
    Top = 19
    Width = 152
    Height = 23
    Caption = 'ARCHIVOS TEXTOS'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 160
    Top = 184
    Width = 138
    Height = 23
    Caption = 'ARCHIVOS TIPOS'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 48
    Top = 256
    Width = 52
    Height = 15
    Caption = 'NOMBRE:'
  end
  object Label4: TLabel
    Left = 46
    Top = 227
    Width = 48
    Height = 15
    Caption = 'CODIGO:'
  end
  object Label5: TLabel
    Left = 48
    Top = 288
    Width = 57
    Height = 15
    Caption = 'TELEFONO'
  end
  object Label6: TLabel
    Left = 48
    Top = 314
    Width = 22
    Height = 15
    Caption = 'SEX.'
  end
  object Edit1: TEdit
    Left = 32
    Top = 48
    Width = 433
    Height = 23
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 32
    Top = 88
    Width = 433
    Height = 23
    TabOrder = 1
  end
  object Button1: TButton
    Left = 144
    Top = 128
    Width = 75
    Height = 25
    Caption = 'Abrir Archivo'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 264
    Top = 128
    Width = 75
    Height = 25
    Caption = 'crear archivo'
    TabOrder = 3
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 48
    Top = 128
    Width = 75
    Height = 25
    Caption = 'Button3'
    TabOrder = 4
    OnClick = Button3Click
  end
  object Edit3: TEdit
    Left = 144
    Top = 224
    Width = 121
    Height = 23
    TabOrder = 5
  end
  object Edit4: TEdit
    Left = 144
    Top = 253
    Width = 121
    Height = 23
    TabOrder = 6
  end
  object Edit5: TEdit
    Left = 144
    Top = 282
    Width = 121
    Height = 23
    TabOrder = 7
  end
  object Edit6: TEdit
    Left = 144
    Top = 311
    Width = 121
    Height = 23
    TabOrder = 8
  end
  object Button4: TButton
    Left = 376
    Top = 128
    Width = 75
    Height = 25
    Caption = 'contar_pal'
    TabOrder = 9
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 488
    Top = 128
    Width = 75
    Height = 25
    Caption = 'eliminar_linea'
    TabOrder = 10
    OnClick = Button5Click
  end
  object OpenTextFileDialog1: TOpenTextFileDialog
    Left = 544
    Top = 40
  end
end