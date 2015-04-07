object ParentsInfoForm: TParentsInfoForm
  Left = 0
  Top = 0
  Caption = #1056#1086#1076#1080#1090#1077#1083#1080
  ClientHeight = 361
  ClientWidth = 512
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 0
    Top = 174
    Width = 512
    Height = 154
    Align = alClient
    Caption = #1044#1077#1090#1080
    TabOrder = 0
    ExplicitHeight = 90
    object ListBox1: TListBox
      Left = 2
      Top = 15
      Width = 508
      Height = 137
      Align = alClient
      ItemHeight = 13
      TabOrder = 0
      OnDblClick = ListBox1DblClick
      ExplicitHeight = 73
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 328
    Width = 512
    Height = 33
    Align = alBottom
    TabOrder = 1
    ExplicitTop = 264
    object CancelButton: TButton
      AlignWithMargins = True
      Left = 433
      Top = 4
      Width = 75
      Height = 25
      Align = alRight
      Caption = #1054#1090#1084#1077#1085#1072
      ModalResult = 2
      TabOrder = 0
      OnClick = CancelButtonClick
    end
    object Button1: TButton
      AlignWithMargins = True
      Left = 352
      Top = 4
      Width = 75
      Height = 25
      Align = alRight
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      ModalResult = 1
      TabOrder = 1
      OnClick = Button1Click
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 0
    Width = 512
    Height = 29
    Align = alTop
    TabOrder = 2
    object Label1: TLabel
      AlignWithMargins = True
      Left = 4
      Top = 4
      Width = 23
      Height = 21
      Align = alLeft
      Caption = #1060#1048#1054
      ExplicitLeft = 16
      ExplicitTop = 7
      ExplicitHeight = 13
    end
    object FIOEdit: TEdit
      AlignWithMargins = True
      Left = 33
      Top = 4
      Width = 475
      Height = 21
      Align = alClient
      TabOrder = 0
      OnChange = FIOEditChange
    end
  end
  object Panel4: TPanel
    Left = 0
    Top = 29
    Width = 512
    Height = 29
    Align = alTop
    TabOrder = 3
    object Label2: TLabel
      AlignWithMargins = True
      Left = 4
      Top = 4
      Width = 40
      Height = 21
      Align = alLeft
      Caption = #1042#1086#1079#1088#1072#1089#1090
      ExplicitLeft = 16
      ExplicitTop = 12
      ExplicitHeight = 13
    end
    object AgeEdit: TEdit
      AlignWithMargins = True
      Left = 50
      Top = 4
      Width = 111
      Height = 21
      Align = alLeft
      TabOrder = 0
      OnChange = AgeEditChange
    end
  end
  object Panel5: TPanel
    Left = 0
    Top = 58
    Width = 512
    Height = 29
    Align = alTop
    TabOrder = 4
    object Label3: TLabel
      AlignWithMargins = True
      Left = 4
      Top = 4
      Width = 67
      Height = 21
      Align = alLeft
      Caption = #1054#1073#1088#1072#1079#1086#1074#1072#1085#1080#1077
      ExplicitLeft = 16
      ExplicitTop = 7
      ExplicitHeight = 13
    end
    object EducationBoxSpec: TComboBoxSpec
      AlignWithMargins = True
      Left = 77
      Top = 4
      Width = 145
      Height = 21
      Align = alLeft
      ItemHeight = 13
      TabOrder = 0
      Text = '[][0][0][91]'
      OnSelect = BoxSpecSelect
      OnAfterSetItemID = BoxSpecAfterSetItemID
      ParentID = 91
      ListID = 1
    end
  end
  object Panel6: TPanel
    Left = 0
    Top = 87
    Width = 512
    Height = 29
    Align = alTop
    TabOrder = 5
    object Label4: TLabel
      AlignWithMargins = True
      Left = 4
      Top = 4
      Width = 72
      Height = 21
      Align = alLeft
      Caption = #1052#1077#1089#1090#1086' '#1088#1072#1073#1086#1090#1099
      ExplicitTop = 10
      ExplicitHeight = 13
    end
    object SpeedButton1: TSpeedButton
      AlignWithMargins = True
      Left = 488
      Top = 4
      Width = 20
      Height = 21
      Align = alRight
      Caption = '...'
      Visible = False
      ExplicitLeft = 475
      ExplicitTop = 5
      ExplicitHeight = 20
    end
    object WorkEditSpec: TEditSpec
      AlignWithMargins = True
      Left = 82
      Top = 4
      Width = 400
      Height = 21
      Align = alClient
      TabOrder = 0
      Text = 'WorkEditSpec'
      TextData = 'WorkEditSpec'
    end
  end
  object Panel7: TPanel
    Left = 0
    Top = 116
    Width = 512
    Height = 29
    Align = alTop
    TabOrder = 6
    object Label5: TLabel
      AlignWithMargins = True
      Left = 4
      Top = 4
      Width = 98
      Height = 21
      Align = alLeft
      Caption = #1042#1088#1077#1076#1085#1099#1077' '#1087#1088#1080#1074#1099#1095#1082#1080
      ExplicitTop = 6
      ExplicitHeight = 13
    end
    object BadHabitBoxSpec: TComboBoxSpec
      AlignWithMargins = True
      Left = 108
      Top = 4
      Width = 145
      Height = 21
      Align = alLeft
      ItemHeight = 13
      TabOrder = 0
      Text = '[][0][0][99]'
      OnSelect = BoxSpecSelect
      OnAfterSetItemID = BoxSpecAfterSetItemID
      ParentID = 99
      ListID = 1
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 145
    Width = 512
    Height = 29
    Align = alTop
    TabOrder = 7
    object Label6: TLabel
      AlignWithMargins = True
      Left = 4
      Top = 4
      Width = 126
      Height = 21
      Align = alLeft
      Caption = #1054#1090#1103#1075'. '#1085#1072#1089#1083#1077#1076#1089#1090#1074#1077#1085#1085#1086#1089#1090#1100
      ExplicitLeft = 7
      ExplicitTop = 6
      ExplicitHeight = 13
    end
    object BadStrainBoxSpec: TComboBoxSpec
      AlignWithMargins = True
      Left = 136
      Top = 4
      Width = 58
      Height = 21
      Align = alLeft
      ItemHeight = 13
      TabOrder = 0
      Text = '[][0][0][45]'
      OnSelect = BoxSpecSelect
      OnAfterSetItemID = BoxSpecAfterSetItemID
      ParentID = 45
      ListID = 1
    end
  end
end
