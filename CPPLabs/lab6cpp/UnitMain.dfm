object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 463
  ClientWidth = 764
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object LabelInfo: TLabel
    Left = 8
    Top = 8
    Width = 129
    Height = 23
    Caption = #1048#1085#1092#1086#1088#1084#1072#1094#1080#1103
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label1: TLabel
    Left = 8
    Top = 167
    Width = 73
    Height = 23
    Caption = #1044#1077#1088#1077#1074#1086
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 488
    Top = 11
    Width = 65
    Height = 23
    Caption = #1060'.'#1048'.'#1054'.'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 487
    Top = 75
    Width = 122
    Height = 23
    Caption = #8470' '#1055#1072#1089#1087#1086#1088#1090#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 699
    Top = 104
    Width = 55
    Height = 23
    Caption = #1050#1083#1102#1095
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object ReflectLabel: TLabel
    Left = 633
    Top = 172
    Width = 5
    Height = 19
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clPurple
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object LSLabel: TLabel
    Left = 257
    Top = 167
    Width = 192
    Height = 19
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object SG: TStringGrid
    Left = 8
    Top = 40
    Width = 441
    Height = 121
    BevelInner = bvLowered
    BevelKind = bkTile
    Color = clCream
    ColCount = 20
    DrawingStyle = gdsClassic
    RowCount = 3
    TabOrder = 0
  end
  object TV: TTreeView
    Left = 8
    Top = 208
    Width = 441
    Height = 247
    Indent = 19
    TabOrder = 1
  end
  object FIOEdit: TEdit
    Left = 488
    Top = 40
    Width = 121
    Height = 21
    TabOrder = 2
  end
  object PassNumEdit: TEdit
    Left = 488
    Top = 104
    Width = 121
    Height = 21
    TabOrder = 3
  end
  object AddButton: TButton
    Left = 633
    Top = 38
    Width = 121
    Height = 60
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    TabOrder = 4
    OnClick = AddButtonClick
  end
  object KeyEdit: TEdit
    Left = 633
    Top = 133
    Width = 121
    Height = 21
    TabOrder = 5
  end
  object DelButton: TButton
    Left = 496
    Top = 129
    Width = 113
    Height = 30
    Caption = #1059#1076#1072#1083#1080#1090#1100
    TabOrder = 6
    OnClick = DelButtonClick
  end
  object ReflectButton: TButton
    Left = 496
    Top = 165
    Width = 113
    Height = 30
    Caption = #1054#1090#1086#1073#1088#1072#1079#1080#1090#1100
    TabOrder = 7
    OnClick = ReflectButtonClick
  end
  object PreorderButton: TButton
    Left = 496
    Top = 248
    Width = 113
    Height = 33
    Caption = #1055#1088#1103#1084#1086#1081' '#1086#1073#1093#1086#1076
    TabOrder = 8
    OnClick = PreorderButtonClick
  end
  object Memo: TMemo
    Left = 615
    Top = 208
    Width = 139
    Height = 247
    Lines.Strings = (
      'Memo')
    ScrollBars = ssHorizontal
    TabOrder = 9
    WordWrap = False
  end
  object PostorderButton: TButton
    Left = 496
    Top = 287
    Width = 113
    Height = 33
    Caption = #1054#1073#1088#1072#1090#1085#1099#1081' '#1086#1073#1093#1086#1076
    TabOrder = 10
    OnClick = PostorderButtonClick
  end
  object CenteredButton: TButton
    Left = 496
    Top = 326
    Width = 113
    Height = 33
    Caption = #1055#1086' '#1074#1086#1079#1088'. '#1082#1083#1102#1095#1072
    TabOrder = 11
    OnClick = CenteredButtonClick
  end
  object ExitButton: TButton
    Left = 496
    Top = 422
    Width = 113
    Height = 33
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 12
    OnClick = ExitButtonClick
  end
  object LSButton: TButton
    Left = 96
    Top = 167
    Width = 139
    Height = 25
    Caption = #1059#1079#1083#1086#1074' '#1074' '#1083#1077#1074#1086#1081' '#1074#1077#1090#1074#1080
    TabOrder = 13
    OnClick = LSButtonClick
  end
end
