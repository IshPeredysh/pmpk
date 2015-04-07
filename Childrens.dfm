object ChildrensForm: TChildrensForm
  Left = 0
  Top = 0
  Caption = #1044#1077#1090#1080
  ClientHeight = 275
  ClientWidth = 525
  Color = clBtnFace
  ParentFont = True
  KeyPreview = True
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  OnKeyDown = FormKeyDown
  OnKeyPress = FormKeyPress
  OnResize = FormResize
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object dg: TDrawGrid
    Left = 0
    Top = 40
    Width = 525
    Height = 235
    Align = alClient
    ColCount = 2
    DefaultRowHeight = 18
    RowCount = 2
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine]
    TabOrder = 0
    OnDblClick = dgDblClick
    OnDrawCell = dgDrawCell
    OnMouseWheelDown = dgMouseWheelDown
    OnMouseWheelUp = dgMouseWheelUp
    ExplicitTop = 22
    ExplicitHeight = 253
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 525
    Height = 40
    ButtonHeight = 30
    Caption = 'ToolBar1'
    Images = Images.ImageList4
    TabOrder = 1
    object ToolButton1: TToolButton
      Left = 0
      Top = 0
      Caption = 'ToolButton1'
      ImageIndex = 1
      OnClick = ToolButton1Click
    end
    object ToolButton2: TToolButton
      Left = 23
      Top = 0
      Caption = 'ToolButton2'
      ImageIndex = 2
      OnClick = ToolButton2Click
    end
    object ToolButton3: TToolButton
      Left = 46
      Top = 0
      Width = 19
      Caption = 'ToolButton3'
      ImageIndex = 3
      Style = tbsSeparator
    end
    object ToolButton6: TToolButton
      Left = 65
      Top = 0
      Caption = 'ToolButton6'
      ImageIndex = 5
      OnClick = ToolButton6Click
    end
    object ToolButton5: TToolButton
      Left = 88
      Top = 0
      Width = 16
      Caption = 'ToolButton5'
      ImageIndex = 4
      Style = tbsSeparator
    end
    object Edit1: TEdit
      Left = 104
      Top = 0
      Width = 161
      Height = 30
      TabOrder = 0
      Text = #1055#1086#1080#1089#1082
      OnChange = ToolButton4Click
      OnEnter = Edit1Enter
      OnExit = Edit1Exit
    end
    object ToolButton4: TToolButton
      Left = 265
      Top = 0
      Hint = #1053#1072#1081#1090#1080' '#1089#1083#1077#1076#1091#1102#1097#1077#1075#1086
      Caption = 'ToolButton4'
      ImageIndex = 6
      ParentShowHint = False
      ShowHint = True
      OnClick = ToolButton4Click
    end
  end
end
