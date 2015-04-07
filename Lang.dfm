object LangForm: TLangForm
  Left = 0
  Top = 0
  Caption = #1071#1079#1099#1082#1080
  ClientHeight = 311
  ClientWidth = 318
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  OnResize = FormResize
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object dg: TDrawGridSpec
    Left = 0
    Top = 22
    Width = 318
    Height = 289
    Align = alClient
    ColCount = 2
    DefaultRowHeight = 18
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing]
    TabOrder = 0
    OnDblClick = dgDblClick
    OnDrawCell = dgDrawCell
    OnGetEditText = dgGetEditText
    OnMouseWheelDown = dgMouseWheelDown
    OnMouseWheelUp = dgMouseWheelUp
    OnSetEditText = dgSetEditText
    OnExitEdit = dgExitEdit
    ColWidths = (
      62
      228)
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 318
    Height = 22
    Caption = 'ToolBar1'
    Images = Images.ImageList4
    TabOrder = 1
    object AddStringButton: TToolButton
      Left = 0
      Top = 0
      Hint = #1044#1086#1073#1072#1074#1080#1090#1100
      Caption = 'AddStringButton'
      ImageIndex = 1
      ParentShowHint = False
      ShowHint = True
      OnClick = AddStringButtonClick
    end
    object DeleteButton: TToolButton
      Left = 23
      Top = 0
      Hint = #1059#1076#1072#1083#1080#1090#1100
      Caption = 'DeleteButton'
      ImageIndex = 2
      ParentShowHint = False
      ShowHint = True
      OnClick = DeleteButtonClick
    end
    object EditButton: TToolButton
      Left = 46
      Top = 0
      Hint = #1048#1079#1084#1077#1085#1080#1090#1100
      Caption = 'EditButton'
      ImageIndex = 3
      ParentShowHint = False
      ShowHint = True
      OnClick = EditButtonClick
    end
  end
end
