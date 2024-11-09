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
  OnCreate = FormCreate
  TextHeight = 15
  object Label1: TLabel
    Left = 176
    Top = 24
    Width = 88
    Height = 15
    Caption = 'ARCHIVOS DATA'
  end
  object Label2: TLabel
    Left = 40
    Top = 75
    Width = 45
    Height = 15
    Caption = 'CODIGO'
  end
  object Label3: TLabel
    Left = 40
    Top = 112
    Width = 49
    Height = 15
    Caption = 'NOMBRE'
  end
  object Label4: TLabel
    Left = 40
    Top = 133
    Width = 61
    Height = 15
    Caption = 'DIRECCION'
  end
  object Label5: TLabel
    Left = 40
    Top = 176
    Width = 37
    Height = 15
    Caption = 'FECHA'
  end
  object Label6: TLabel
    Left = 144
    Top = 208
    Width = 19
    Height = 15
    Caption = 'DIA'
  end
  object Label7: TLabel
    Left = 241
    Top = 208
    Width = 23
    Height = 15
    Caption = 'MES'
  end
  object Label8: TLabel
    Left = 336
    Top = 208
    Width = 26
    Height = 15
    Caption = 'A'#209'O'
  end
  object Edit1: TEdit
    Left = 128
    Top = 72
    Width = 121
    Height = 23
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 128
    Top = 101
    Width = 121
    Height = 23
    TabOrder = 1
  end
  object Edit3: TEdit
    Left = 128
    Top = 130
    Width = 121
    Height = 23
    TabOrder = 2
  end
  object Edit4: TEdit
    Left = 120
    Top = 173
    Width = 65
    Height = 23
    TabOrder = 3
  end
  object Edit5: TEdit
    Left = 216
    Top = 173
    Width = 73
    Height = 23
    TabOrder = 4
  end
  object Edit6: TEdit
    Left = 320
    Top = 173
    Width = 57
    Height = 23
    TabOrder = 5
  end
  object Button1: TButton
    Left = 40
    Top = 264
    Width = 75
    Height = 25
    Caption = 'Guardar'
    TabOrder = 6
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 144
    Top = 264
    Width = 75
    Height = 25
    Caption = 'Button2'
    TabOrder = 7
  end
  object Button3: TButton
    Left = 256
    Top = 264
    Width = 75
    Height = 25
    Caption = 'Button3'
    TabOrder = 8
  end
end
