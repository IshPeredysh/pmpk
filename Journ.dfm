object JournForm: TJournForm
  Left = 0
  Top = 0
  Caption = #1046#1091#1088#1085#1072#1083
  ClientHeight = 395
  ClientWidth = 680
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object sg: TStringGrid
    Left = 0
    Top = 53
    Width = 680
    Height = 342
    Align = alClient
    ColCount = 4
    DefaultRowHeight = 18
    FixedCols = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goRowSelect]
    TabOrder = 0
    OnDblClick = sgDblClick
    OnDrawCell = sgDrawCell
    OnMouseWheelDown = sgMouseWheelDown
    OnMouseWheelUp = sgMouseWheelUp
    ColWidths = (
      24
      144
      85
      384)
  end
  object CoolBar1: TCoolBar
    Left = 0
    Top = 0
    Width = 680
    Height = 53
    AutoSize = True
    Bands = <
      item
        Control = ToolBar1
        ImageIndex = -1
        MinHeight = 22
        Width = 676
      end
      item
        Control = ToolBar2
        ImageIndex = -1
        Width = 676
      end>
    object ToolBar1: TToolBar
      Left = 9
      Top = 0
      Width = 663
      Height = 22
      AutoSize = True
      Caption = 'ToolBar1'
      Images = Images.ImageList4
      TabOrder = 0
      object ToolButton1: TToolButton
        Left = 0
        Top = 0
        Hint = #1053#1086#1074#1099#1081' '#1087#1088#1086#1090#1086#1082#1086#1083
        Caption = 'ToolButton1'
        ImageIndex = 1
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButton1Click
      end
      object ToolButton4: TToolButton
        Left = 23
        Top = 0
        Hint = #1059#1076#1072#1083#1080#1090#1100' '#1087#1088#1086#1090#1086#1082#1086#1083
        Caption = 'ToolButton4'
        ImageIndex = 2
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButton4Click
      end
      object ToolButton5: TToolButton
        Left = 46
        Top = 0
        Width = 17
        Caption = 'ToolButton5'
        ImageIndex = 8
        Style = tbsSeparator
      end
      object ToolButton2: TToolButton
        Left = 63
        Top = 0
        Hint = #1054#1073#1085#1086#1074#1080#1090#1100' '#1089#1087#1080#1089#1086#1082
        Caption = 'ToolButton2'
        ImageIndex = 5
        ParentShowHint = False
        ShowHint = True
        OnClick = ToolButton2Click
      end
    end
    object ToolBar2: TToolBar
      Left = 9
      Top = 24
      Width = 663
      Height = 25
      Caption = 'ToolBar2'
      TabOrder = 1
      object Label1: TLabel
        AlignWithMargins = True
        Left = 0
        Top = 0
        Width = 56
        Height = 22
        Align = alLeft
        Caption = #1055#1086#1082#1072#1079#1072#1090#1100' '#1089
        Layout = tlCenter
      end
      object DateTimePicker1: TDateTimePicker
        Left = 56
        Top = 0
        Width = 80
        Height = 22
        Align = alLeft
        Date = 41513.959568680560000000
        Time = 41513.959568680560000000
        DateMode = dmUpDown
        TabOrder = 0
        OnChange = ToolButton2Click
      end
      object Label2: TLabel
        AlignWithMargins = True
        Left = 136
        Top = 0
        Width = 12
        Height = 22
        Align = alLeft
        Caption = #1087#1086
        Layout = tlCenter
      end
      object DateTimePicker2: TDateTimePicker
        Left = 148
        Top = 0
        Width = 80
        Height = 22
        Align = alLeft
        Date = 41513.962118773150000000
        Time = 41513.962118773150000000
        DateMode = dmUpDown
        TabOrder = 1
        OnChange = ToolButton2Click
      end
      object CurrentYearCheckBox: TCheckBox
        Left = 228
        Top = 0
        Width = 97
        Height = 22
        Align = alLeft
        Caption = #1058#1077#1082#1091#1097#1080#1081' '#1075#1086#1076
        TabOrder = 2
        OnClick = CurrentYearCheckBoxClick
      end
    end
  end
end
