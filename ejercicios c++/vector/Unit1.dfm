object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'vectores'
  ClientHeight = 442
  ClientWidth = 1044
  Color = clAqua
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -20
  Font.Name = 'Segoe UI'
  Font.Style = [fsBold]
  TextHeight = 28
  object Edit_1: TLabel
    Left = 64
    Top = 11
    Width = 36
    Height = 17
    Caption = 'Edit_1'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 40
    Top = 45
    Width = 337
    Height = 36
    TabOrder = 0
  end
  object Button1: TButton
    Left = 618
    Top = 337
    Width = 147
    Height = 25
    Caption = 'Matriz_cf_fp'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 174
    Top = 258
    Width = 155
    Height = 25
    Caption = 'Vector_<100'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 8
    Top = 289
    Width = 160
    Height = 25
    Caption = 'Generar_cad_inv'
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 8
    Top = 320
    Width = 129
    Height = 25
    Caption = 'palindromo'
    TabOrder = 4
    OnClick = Button4Click
  end
  object vect_palindromo: TButton
    Left = 182
    Top = 289
    Width = 179
    Height = 25
    Caption = 'vect_palindromo'
    TabOrder = 5
    OnClick = vect_palindromoClick
  end
  object Button6: TButton
    Left = 8
    Top = 351
    Width = 137
    Height = 25
    Caption = 'vect_a_cadena'
    TabOrder = 6
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 8
    Top = 258
    Width = 129
    Height = 25
    Caption = 'Generar_cad'
    TabOrder = 7
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 798
    Top = 306
    Width = 139
    Height = 25
    Caption = 'TSuperior_asc'
    TabOrder = 8
    OnClick = Button8Click
  end
  object Button9: TButton
    Left = 8
    Top = 134
    Width = 160
    Height = 25
    Caption = 'cantidad_digitos'
    TabOrder = 9
    OnClick = Button9Click
  end
  object Edit2: TEdit
    Left = 392
    Top = 45
    Width = 121
    Height = 36
    TabOrder = 10
  end
  object SG1: TStringGrid
    Left = 8
    Top = 87
    Width = 417
    Height = 41
    ColCount = 1
    DefaultColWidth = 35
    DefaultRowHeight = 35
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goFixedRowDefAlign]
    TabOrder = 11
  end
  object Button10: TButton
    Left = 8
    Top = 165
    Width = 137
    Height = 25
    Caption = 'CargarVector'
    TabOrder = 12
    OnClick = Button10Click
  end
  object Button11: TButton
    Left = 8
    Top = 196
    Width = 75
    Height = 25
    Caption = 'suma'
    TabOrder = 13
    OnClick = Button11Click
  end
  object Button12: TButton
    Left = 8
    Top = 227
    Width = 75
    Height = 25
    Caption = 'Invertir'
    TabOrder = 14
    OnClick = Button12Click
  end
  object Button13: TButton
    Left = 174
    Top = 134
    Width = 139
    Height = 25
    Caption = 'num_may'
    TabOrder = 15
    OnClick = Button13Click
  end
  object Button14: TButton
    Left = 174
    Top = 165
    Width = 155
    Height = 25
    Caption = 'inv_numpares'
    TabOrder = 16
    OnClick = Button14Click
  end
  object Button15: TButton
    Left = 174
    Top = 196
    Width = 155
    Height = 25
    Caption = 'Delete_firsWord'
    TabOrder = 17
  end
  object Button16: TButton
    Left = 174
    Top = 227
    Width = 187
    Height = 25
    Caption = 'cargar_1er_Caracter'
    TabOrder = 18
    OnClick = Button16Click
  end
  object SG2: TStringGrid
    Left = 618
    Top = 11
    Width = 295
    Height = 272
    ColCount = 7
    DefaultColWidth = 38
    DefaultRowHeight = 38
    FixedCols = 0
    RowCount = 7
    FixedRows = 0
    TabOrder = 19
  end
  object Button5: TButton
    Left = 182
    Top = 320
    Width = 219
    Height = 25
    Caption = 'eliminar_n_elementos'
    TabOrder = 20
    OnClick = Button5Click
  end
  object Button17: TButton
    Left = 618
    Top = 306
    Width = 153
    Height = 25
    Caption = 'Matriz_fp_cf'
    TabOrder = 21
    OnClick = Button17Click
  end
  object Button18: TButton
    Left = 618
    Top = 368
    Width = 153
    Height = 25
    Caption = 'TInferior_asc'
    TabOrder = 22
    OnClick = Button18Click
  end
  object Button19: TButton
    Left = 798
    Top = 337
    Width = 163
    Height = 25
    Caption = 'Cargar_Tprin'
    TabOrder = 23
    OnClick = Button19Click
  end
  object Button20: TButton
    Left = 798
    Top = 368
    Width = 115
    Height = 25
    Caption = 'Tprinc2'
    TabOrder = 24
    OnClick = Button20Click
  end
  object Button21: TButton
    Left = 618
    Top = 399
    Width = 147
    Height = 25
    Caption = '111,222'
    TabOrder = 25
    OnClick = Button21Click
  end
  object Button22: TButton
    Left = 182
    Top = 351
    Width = 123
    Height = 25
    Caption = 'cargar_num'
    TabOrder = 26
    OnClick = Button22Click
  end
end
