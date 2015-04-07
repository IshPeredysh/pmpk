object AttrAppointForm: TAttrAppointForm
  Left = 0
  Top = 0
  Caption = #1040#1090#1088#1080#1073#1091#1090#1099' '#1076#1086#1083#1078#1085#1086#1089#1090#1077#1081
  ClientHeight = 371
  ClientWidth = 707
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnResize = FormResize
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object dg: TDrawGridSpec
    Left = 0
    Top = 22
    Width = 707
    Height = 349
    Align = alClient
    ColCount = 3
    DefaultRowHeight = 18
    FixedCols = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing]
    PopupMenu = PopupMenu1
    TabOrder = 0
    OnContextPopup = dgContextPopup
    OnDrawCell = dgDrawCell
    OnKeyPress = dgKeyPress
    OnMouseDown = dgMouseDown
    OnMouseUp = dgMouseUp
    OnMouseWheelDown = dgMouseWheelDown
    OnMouseWheelUp = dgMouseWheelUp
    ColWidths = (
      245
      194
      239)
    RowHeights = (
      18
      18
      18
      18
      18)
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 707
    Height = 22
    Caption = 'ToolBar1'
    Images = Images.ImageList4
    TabOrder = 1
    object EditButton: TToolButton
      Left = 0
      Top = 0
      Hint = #1048#1079#1084#1077#1085#1080#1090#1100
      Caption = 'EditButton'
      ImageIndex = 3
      ParentShowHint = False
      ShowHint = True
      OnClick = EditButtonClick
    end
  end
  object PopupMenu1: TPopupMenu
    Left = 24
    Top = 120
    object N1: TMenuItem
      Caption = #1050#1086#1087#1080#1088#1086#1074#1072#1090#1100
      OnClick = N1Click
    end
  end
end
