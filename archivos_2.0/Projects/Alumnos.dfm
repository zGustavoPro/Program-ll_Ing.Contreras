object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 389
  ClientWidth = 620
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OnCreate = FormCreate
  TextHeight = 13
  object Label1: TLabel
    Left = 184
    Top = 16
    Width = 223
    Height = 33
    Caption = 'ABM Alumnos.data'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 64
    Top = 80
    Width = 71
    Height = 25
    Caption = 'Codigo:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 51
    Top = 119
    Width = 81
    Height = 25
    Caption = 'Nombre:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 39
    Top = 158
    Width = 93
    Height = 25
    Caption = 'Direccion:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 15
    Top = 212
    Width = 203
    Height = 25
    Caption = 'Fecha de Nacimiento:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label6: TLabel
    Left = 227
    Top = 243
    Width = 30
    Height = 25
    Caption = 'Dia'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label7: TLabel
    Left = 263
    Top = 243
    Width = 36
    Height = 25
    Caption = 'Mes'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label8: TLabel
    Left = 310
    Top = 243
    Width = 36
    Height = 25
    Caption = 'A'#241'o'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 138
    Top = 80
    Width = 71
    Height = 33
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    Text = '0'
    OnExit = Edit1Exit
  end
  object Edit2: TEdit
    Left = 138
    Top = 119
    Width = 351
    Height = 33
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    MaxLength = 30
    ParentFont = False
    TabOrder = 1
  end
  object Edit3: TEdit
    Left = 138
    Top = 158
    Width = 351
    Height = 33
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    MaxLength = 25
    ParentFont = False
    TabOrder = 2
  end
  object Edit4: TEdit
    Left = 224
    Top = 209
    Width = 33
    Height = 33
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
  end
  object Edit5: TEdit
    Left = 263
    Top = 209
    Width = 33
    Height = 33
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
  end
  object Edit6: TEdit
    Left = 302
    Top = 209
    Width = 51
    Height = 33
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
  end
  object Button1: TButton
    Left = 136
    Top = 328
    Width = 82
    Height = 25
    Caption = 'Guardar'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 240
    Top = 328
    Width = 89
    Height = 25
    Caption = 'Eliminar'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 352
    Top = 328
    Width = 97
    Height = 25
    Caption = 'LIMPIAR'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 8
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 464
    Top = 264
    Width = 131
    Height = 33
    Caption = 'Reestructurar'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 9
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 224
    Top = 80
    Width = 75
    Height = 25
    Caption = 'Button5'
    TabOrder = 10
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 8
    Top = 320
    Width = 105
    Height = 25
    Caption = 'actualizaar_datos'
    TabOrder = 11
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 414
    Top = 80
    Width = 75
    Height = 25
    Caption = 'Button7'
    TabOrder = 12
    OnClick = Button7Click
  end
  object Edit7: TEdit
    Left = 136
    Top = 274
    Width = 121
    Height = 21
    TabOrder = 13
  end
  object MainMenu1: TMainMenu
    Left = 520
    Top = 336
    object Archivo1: TMenuItem
      Caption = 'Archivo'
      object Reestructurar1: TMenuItem
        Caption = 'Reestructurar'
      end
      object IndexarporCodigo1: TMenuItem
        Caption = 'Indexar por Codigo'
        OnClick = IndexarporCodigo1Click
      end
      object Indexarpornombre1: TMenuItem
        Caption = 'Indexar por nombre'
      end
    end
  end
end
