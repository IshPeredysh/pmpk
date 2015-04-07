object ChildrenInfoForm: TChildrenInfoForm
  Left = 0
  Top = 0
  Caption = #1048#1085#1092#1086#1088#1084#1072#1094#1080#1103' '#1086' '#1088#1077#1073#1105#1085#1082#1077
  ClientHeight = 319
  ClientWidth = 678
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -21
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  OnKeyDown = FormKeyDown
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 25
  object Panel19: TPanel
    Left = 0
    Top = 280
    Width = 678
    Height = 39
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 0
    object CancelButton: TButton
      AlignWithMargins = True
      Left = 576
      Top = 3
      Width = 99
      Height = 33
      Align = alRight
      Caption = #1054#1090#1084#1077#1085#1072
      TabOrder = 0
      OnClick = CancelButtonClick
    end
    object SaveButton: TButton
      AlignWithMargins = True
      Left = 448
      Top = 3
      Width = 122
      Height = 33
      Align = alRight
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      TabOrder = 1
      OnClick = SaveButtonClick
    end
    object Button1: TButton
      AlignWithMargins = True
      Left = 3
      Top = 3
      Width = 118
      Height = 33
      Align = alLeft
      Caption = #1055#1088#1086#1090#1086#1082#1086#1083
      TabOrder = 2
      OnClick = Button1Click
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 678
    Height = 33
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 1
    object Label2: TLabel
      Left = 335
      Top = 0
      Width = 149
      Height = 33
      Align = alLeft
      Caption = #1044#1072#1090#1072' '#1088#1086#1078#1076#1077#1085#1080#1103
      ExplicitLeft = 313
      ExplicitHeight = 25
    end
    object Label1: TLabel
      Left = 0
      Top = 0
      Width = 45
      Height = 33
      Align = alLeft
      Caption = #1060#1048#1054
      ExplicitHeight = 25
    end
    object FIOEdit: TEdit
      Left = 45
      Top = 0
      Width = 290
      Height = 33
      Align = alLeft
      TabOrder = 0
      Text = 'FIOEdit'
    end
    object BirthdayPickerSpec: TDateTimePickerSpec
      Left = 484
      Top = 0
      Width = 96
      Height = 33
      Align = alLeft
      Date = 41518.035737476850000000
      Time = 41518.035737476850000000
      TabOrder = 1
      OnChange = BirthdayPickerChange
      OnKeyDown = BirthdayPickerKeyDown
      TextData = '01.09.2013'
      ExplicitHeight = 21
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 33
    Width = 678
    Height = 32
    Align = alTop
    TabOrder = 2
    object Label3: TLabel
      Left = 1
      Top = 1
      Width = 58
      Height = 30
      Align = alLeft
      Caption = #1040#1076#1088#1077#1089
      ExplicitHeight = 25
    end
    object AreaButton: TSpeedButton
      Left = 235
      Top = 1
      Width = 21
      Height = 30
      Align = alLeft
      Caption = '...'
      OnClick = AreaButtonClick
      ExplicitLeft = 231
      ExplicitTop = 3
      ExplicitHeight = 21
    end
    object AreaEditSpec: TEditSpec
      Left = 59
      Top = 1
      Width = 176
      Height = 30
      Align = alLeft
      TabOrder = 0
      Text = '[][0][0][123]'
      OnAfterSetItemID = EditSpecAfterSetItemID
      TextData = '[][0][0][123]'
      ListID = 123
      ExplicitHeight = 33
    end
    object AdressEdit: TEdit
      Left = 256
      Top = 1
      Width = 421
      Height = 30
      Align = alClient
      TabOrder = 1
      Text = 'AdressEdit'
      ExplicitHeight = 33
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 65
    Width = 678
    Height = 32
    Align = alTop
    TabOrder = 3
    object Label4: TLabel
      Left = 1
      Top = 1
      Width = 155
      Height = 30
      Align = alLeft
      Caption = #1052#1077#1089#1090#1086' '#1086#1073#1091#1095#1077#1085#1080#1103
      ExplicitHeight = 25
    end
    object SpeedButton1: TSpeedButton
      Left = 629
      Top = 1
      Width = 21
      Height = 30
      Align = alLeft
      Caption = '...'
      OnClick = SpeedButton1Click
      ExplicitLeft = 583
      ExplicitHeight = 21
    end
    object PlaceStudyEditSpec: TEditSpec
      Left = 156
      Top = 1
      Width = 473
      Height = 30
      Align = alLeft
      ReadOnly = True
      TabOrder = 0
      Text = '[][0][0][36]'
      OnAfterSetItemID = EditSpecAfterSetItemID
      TextData = '[][0][0][36]'
      ListID = 36
      ExplicitHeight = 33
    end
  end
  object Panel4: TPanel
    Left = 0
    Top = 97
    Width = 678
    Height = 35
    Align = alTop
    TabOrder = 4
    ExplicitTop = 70
    object Label9: TLabel
      Left = 1
      Top = 1
      Width = 37
      Height = 33
      Align = alLeft
      Caption = #1055#1086#1083
      ExplicitHeight = 25
    end
    object SexBoxSpec: TComboBoxSpec
      Left = 38
      Top = 1
      Width = 97
      Height = 33
      Align = alLeft
      ItemHeight = 25
      TabOrder = 0
      OnSelect = SexBoxSpecSelect
      OnAfterSetItemID = SexBoxSpecAfterSetItemID
    end
  end
  object Panel6: TPanel
    Left = 0
    Top = 132
    Width = 678
    Height = 37
    Align = alTop
    TabOrder = 5
    object Label6: TLabel
      Left = 1
      Top = 1
      Width = 48
      Height = 35
      Align = alLeft
      Caption = #1054#1090#1077#1094
      ExplicitHeight = 25
    end
    object SpeedButton2: TSpeedButton
      Left = 318
      Top = 1
      Width = 21
      Height = 35
      Align = alLeft
      Caption = '...'
      OnClick = SpeedButton2Click
      ExplicitLeft = 324
      ExplicitTop = 3
      ExplicitHeight = 21
    end
    object Label7: TLabel
      Left = 339
      Top = 1
      Width = 48
      Height = 35
      Align = alLeft
      Caption = #1052#1072#1090#1100
      ExplicitHeight = 25
    end
    object SpeedButton3: TSpeedButton
      Left = 656
      Top = 1
      Width = 21
      Height = 35
      Align = alLeft
      Caption = '...'
      OnClick = SpeedButton3Click
      ExplicitLeft = 650
      ExplicitTop = 2
      ExplicitHeight = 21
    end
    object FatherEditSpec: TEditSpec
      Left = 49
      Top = 1
      Width = 269
      Height = 35
      Align = alLeft
      ReadOnly = True
      TabOrder = 0
      Text = '[][0][0][84]'
      OnAfterSetItemID = EditSpecAfterSetItemID
      TextData = '[][0][0][84]'
      ListID = 84
      ExplicitHeight = 33
    end
    object MotherEditSpec: TEditSpec
      Left = 387
      Top = 1
      Width = 269
      Height = 35
      Align = alLeft
      ReadOnly = True
      TabOrder = 1
      Text = '[][0][0][84]'
      OnAfterSetItemID = EditSpecAfterSetItemID
      TextData = '[][0][0][84]'
      ListID = 84
      ExplicitHeight = 33
    end
  end
  object GridPanel1: TGridPanel
    Left = 0
    Top = 169
    Width = 678
    Height = 111
    Align = alClient
    ColumnCollection = <
      item
        Value = 100.000000000000000000
      end>
    ControlCollection = <
      item
        Column = 0
        Control = Panel5
        Row = 0
      end
      item
        Column = 0
        Control = Panel7
        Row = 1
      end>
    RowCollection = <
      item
        Value = 50.000000000000000000
      end
      item
        Value = 50.000000000000000000
      end>
    TabOrder = 6
    ExplicitTop = 130
    ExplicitHeight = 150
    object Panel5: TPanel
      Left = 1
      Top = 1
      Width = 676
      Height = 54
      Align = alClient
      TabOrder = 0
      ExplicitHeight = 74
      object Label5: TLabel
        Left = 1
        Top = 1
        Width = 94
        Height = 52
        Align = alLeft
        Caption = #1048#1089#1090#1086#1088#1080#1103' '#1054#1073#1091#1095#1077#1085#1080#1103
        WordWrap = True
        ExplicitHeight = 50
      end
      object HistoryMemo: TMemo
        Left = 95
        Top = 1
        Width = 580
        Height = 52
        Align = alClient
        ScrollBars = ssVertical
        TabOrder = 0
        WantReturns = False
        ExplicitHeight = 72
      end
    end
    object Panel7: TPanel
      Left = 1
      Top = 55
      Width = 676
      Height = 55
      Align = alClient
      TabOrder = 1
      ExplicitTop = 75
      ExplicitHeight = 74
      object Label8: TLabel
        Left = 1
        Top = 1
        Width = 162
        Height = 53
        Align = alLeft
        Caption = #1044#1086#1087#1086#1083#1085#1080#1090#1077#1083#1100#1085#1072#1103' '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1103
        WordWrap = True
        ExplicitHeight = 50
      end
      object ExtInfoMemo: TMemo
        Left = 163
        Top = 1
        Width = 512
        Height = 53
        Align = alClient
        ScrollBars = ssVertical
        TabOrder = 0
        ExplicitHeight = 72
      end
    end
  end
end
