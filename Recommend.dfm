object RecommendForm: TRecommendForm
  Left = 0
  Top = 0
  Caption = #1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080
  ClientHeight = 397
  ClientWidth = 654
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnResize = FormResize
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 253
    Top = 22
    Width = 2
    Height = 375
    ExplicitTop = 17
    ExplicitHeight = 380
  end
  object tv: TTreeView
    Left = 0
    Top = 22
    Width = 253
    Height = 375
    Align = alLeft
    Images = Images.ImageList1
    Indent = 19
    SortType = stBoth
    StateImages = Images.ImageList1
    TabOrder = 0
    OnChange = tvChange
    OnCompare = tvCompare
    OnDragDrop = tvDragDrop
    OnDragOver = tvDragOver
    OnEdited = tvEdited
    OnEnter = tvEnter
  end
  object dg: TDrawGridSpec
    Left = 255
    Top = 22
    Width = 399
    Height = 375
    Align = alClient
    ColCount = 1
    DefaultRowHeight = 18
    FixedCols = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing, goEditing]
    TabOrder = 1
    OnDblClick = dgDblClick
    OnDrawCell = dgDrawCell
    OnEnter = dgEnter
    OnGetEditText = dgGetEditText
    OnMouseDown = dgMouseDown
    OnMouseUp = dgMouseUp
    OnMouseWheelDown = dgMouseWheelDown
    OnMouseWheelUp = dgMouseWheelUp
    OnSelectCell = dgSelectCell
    OnSetEditText = dgSetEditText
    OnExitEdit = dgExitEdit
    ColWidths = (
      379)
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 654
    Height = 22
    AutoSize = True
    Caption = 'ToolBar1'
    Images = Images.ImageList4
    TabOrder = 2
    object AddFolderButton: TToolButton
      Left = 0
      Top = 0
      Caption = 'AddFolderButton'
      ImageIndex = 0
      OnClick = AddFolderButtonClick
    end
    object AddTextButton: TToolButton
      Left = 23
      Top = 0
      Caption = 'AddTextButton'
      ImageIndex = 1
      OnClick = AddTextButtonClick
    end
    object DeleteButton: TToolButton
      Left = 46
      Top = 0
      Caption = 'DeleteButton'
      ImageIndex = 2
      OnClick = DeleteButtonClick
    end
    object EditButton: TToolButton
      Left = 69
      Top = 0
      Caption = 'EditButton'
      ImageIndex = 3
      OnClick = EditButtonClick
    end
    object ToolButton1: TToolButton
      Left = 92
      Top = 0
      Width = 21
      Caption = 'ToolButton1'
      ImageIndex = 7
      Style = tbsSeparator
    end
    object AnchorButton: TToolButton
      Left = 113
      Top = 0
      Caption = 'AnchorButton'
      ImageIndex = 4
      OnClick = AnchorButtonClick
    end
  end
end
