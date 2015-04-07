object ParentsForm: TParentsForm
  Left = 0
  Top = 0
  Caption = #1056#1086#1076#1080#1090#1077#1083#1080
  ClientHeight = 304
  ClientWidth = 493
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnResize = FormResize
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object dg: TDrawGrid
    Left = 0
    Top = 22
    Width = 493
    Height = 282
    Align = alClient
    ColCount = 2
    DefaultRowHeight = 18
    RowCount = 2
    FixedRows = 0
    TabOrder = 0
    OnDblClick = dgDblClick
    OnDrawCell = dgDrawCell
    OnMouseWheelDown = dgMouseWheelDown
    OnMouseWheelUp = dgMouseWheelUp
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 493
    Height = 22
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
    object Edit1: TEdit
      Left = 65
      Top = 0
      Width = 121
      Height = 22
      TabOrder = 0
      Text = #1055#1086#1080#1089#1082
      OnChange = Edit1Change
      OnEnter = Edit1Enter
      OnExit = Edit1Exit
    end
    object ToolButton4: TToolButton
      Left = 186
      Top = 0
      Caption = 'ToolButton4'
      ImageIndex = 6
      OnClick = ToolButton4Click
    end
  end
end
