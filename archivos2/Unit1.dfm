object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'archivos con tipo'
  ClientHeight = 405
  ClientWidth = 747
  Color = clAqua
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  OnCreate = FormCreate
  TextHeight = 15
  object Label1: TLabel
    Left = 194
    Top = 24
    Width = 246
    Height = 37
    Caption = ' ABM Alumnos .dat'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 48
    Top = 72
    Width = 66
    Height = 28
    Caption = 'Codigo'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 48
    Top = 106
    Width = 77
    Height = 28
    Caption = 'Nombre'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 48
    Top = 149
    Width = 90
    Height = 28
    Caption = 'Direccion'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 48
    Top = 191
    Width = 99
    Height = 28
    Caption = 'Fecha_Nac'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 176
    Top = 72
    Width = 121
    Height = 23
    TabOrder = 0
    OnExit = Edit1Exit
  end
  object Edit2: TEdit
    Left = 176
    Top = 103
    Width = 217
    Height = 23
    MaxLength = 20
    TabOrder = 1
  end
  object Edit3: TEdit
    Left = 176
    Top = 157
    Width = 217
    Height = 23
    MaxLength = 20
    TabOrder = 2
  end
  object Edit4: TEdit
    Left = 176
    Top = 191
    Width = 57
    Height = 23
    TabOrder = 3
    TextHint = 'Dia'
  end
  object Edit5: TEdit
    Left = 256
    Top = 191
    Width = 57
    Height = 23
    TabOrder = 4
    TextHint = 'Mes'
  end
  object Edit6: TEdit
    Left = 336
    Top = 191
    Width = 97
    Height = 23
    TabOrder = 5
    TextHint = 'A'#241'o'
  end
  object Button1: TButton
    Left = 176
    Top = 232
    Width = 75
    Height = 25
    Caption = 'Guardar '
    TabOrder = 6
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 278
    Top = 232
    Width = 75
    Height = 25
    Caption = 'Eliminar'
    TabOrder = 7
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 384
    Top = 232
    Width = 89
    Height = 25
    Caption = 'Limpiar'
    TabOrder = 8
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 496
    Top = 156
    Width = 105
    Height = 25
    Caption = 'Reestructurar'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 9
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 336
    Top = 72
    Width = 75
    Height = 25
    Caption = 'Button5'
    TabOrder = 10
    OnClick = Button5Click
  end
  object MainMenu1: TMainMenu
    Left = 656
    Top = 304
    object Archivo1: TMenuItem
      Caption = 'Archivo'
      object Archivo2: TMenuItem
        Caption = 'Archivo'
      end
      object Reestructurar1: TMenuItem
        Caption = 'Reestructurar'
      end
      object Reestructurar2: TMenuItem
        Caption = 'Indexar por codigo'
        OnClick = Reestructurar2Click
      end
      object Indexarpornombre1: TMenuItem
        Caption = 'Indexar por nombre'
      end
    end
  end
end