object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1058#1054#1042#1040#1056#1080#1097
  ClientHeight = 532
  ClientWidth = 907
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
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 346
    Height = 35
    Caption = #1057#1087#1080#1089#1086#1082' '#1090#1086#1074#1072#1088#1086#1074' '#1085#1072' '#1089#1082#1083#1072#1076#1077
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -29
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 266
    Width = 369
    Height = 35
    Caption = #1057#1087#1080#1089#1086#1082' '#1086#1078#1080#1076#1072#1077#1084#1099#1093' '#1090#1086#1074#1072#1088#1086#1074
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -29
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 408
    Top = 10
    Width = 161
    Height = 19
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1090#1086#1074#1072#1088#1072
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clPurple
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 408
    Top = 62
    Width = 139
    Height = 19
    Caption = #1050#1086#1083'-'#1074#1086' '#1090#1086#1074'. '#1077#1076#1080#1085#1080#1094
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clPurple
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 408
    Top = 114
    Width = 139
    Height = 19
    Caption = #1062#1077#1085#1072' '#1090#1086#1074'. '#1077#1076#1080#1085#1080#1094#1099
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clPurple
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label6: TLabel
    Left = 408
    Top = 166
    Width = 106
    Height = 19
    Caption = #1044#1072#1090#1072' '#1087#1086#1089#1090#1072#1074#1082#1080
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clPurple
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object AwaitedOutput: TRichEdit
    Left = 8
    Top = 307
    Width = 369
    Height = 210
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clNavy
    Font.Height = -15
    Font.Name = 'Calibri'
    Font.Style = [fsBold]
    ParentFont = False
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 0
    WordWrap = False
  end
  object InStockOutput: TRichEdit
    Left = 8
    Top = 40
    Width = 369
    Height = 210
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clNavy
    Font.Height = -15
    Font.Name = 'Calibri'
    Font.Style = [fsBold]
    ParentFont = False
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 1
    WordWrap = False
  end
  object NameEdit: TEdit
    Left = 408
    Top = 35
    Width = 161
    Height = 21
    TabOrder = 2
  end
  object AmountEdit: TEdit
    Left = 408
    Top = 87
    Width = 161
    Height = 21
    TabOrder = 3
  end
  object CostEdit: TEdit
    Left = 408
    Top = 139
    Width = 161
    Height = 21
    TabOrder = 4
  end
  object DateTimePicker: TDateTimePicker
    Left = 408
    Top = 191
    Width = 161
    Height = 21
    Date = 43926.776997581020000000
    Time = 43926.776997581020000000
    TabOrder = 5
  end
  object AddButton: TButton
    Left = 408
    Top = 225
    Width = 161
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1087#1086#1089#1090#1072#1074#1082#1091
    TabOrder = 6
    OnClick = AddButtonClick
  end
  object ExitButton: TButton
    Left = 408
    Top = 480
    Width = 161
    Height = 25
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 7
    OnClick = ExitButtonClick
  end
  object REInfoBoard: TRichEdit
    Left = 592
    Top = 8
    Width = 307
    Height = 509
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clNavy
    Font.Height = -15
    Font.Name = 'Calibri'
    Font.Style = [fsBold]
    ParentFont = False
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 8
    WordWrap = False
  end
  object ToFindEdit: TEdit
    Left = 408
    Top = 336
    Width = 161
    Height = 21
    TabOrder = 9
  end
  object FindByName: TButton
    Left = 408
    Top = 363
    Width = 161
    Height = 25
    Caption = #1055#1086' '#1085#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1102
    TabOrder = 10
    OnClick = FindByNameClick
  end
  object FindByAmount: TButton
    Left = 408
    Top = 394
    Width = 161
    Height = 25
    Caption = #1055#1086' '#1082#1086#1083#1080#1095#1077#1089#1090#1074#1091' '#1085#1072' '#1089#1082#1083#1072#1076#1077
    TabOrder = 11
    OnClick = FindByAmountClick
  end
  object FindByCost: TButton
    Left = 408
    Top = 425
    Width = 161
    Height = 25
    Caption = #1055#1086' '#1094#1077#1085#1077
    TabOrder = 12
    OnClick = FindByCostClick
  end
end
