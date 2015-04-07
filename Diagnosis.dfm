object DiagnosisForm: TDiagnosisForm
  Left = 0
  Top = 0
  Caption = #1044#1080#1072#1075#1085#1086#1079#1099
  ClientHeight = 371
  ClientWidth = 604
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
    Left = 217
    Top = 25
    Width = 2
    Height = 346
    ExplicitTop = 17
    ExplicitHeight = 354
  end
  object tv: TTreeView
    Left = 0
    Top = 25
    Width = 217
    Height = 346
    Align = alLeft
    HideSelection = False
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
    OnEnter = dgEnter
  end
  object dg: TDrawGridSpec
    Left = 219
    Top = 25
    Width = 385
    Height = 346
    Align = alClient
    ColCount = 1
    DefaultRowHeight = 18
    FixedCols = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing]
    ScrollBars = ssVertical
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
      486)
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 604
    Height = 25
    AutoSize = True
    ButtonHeight = 23
    Caption = 'ToolBar1'
    Flat = False
    Images = Images.ImageList4
    TabOrder = 2
    object AddFolderButton: TToolButton
      Left = 0
      Top = 2
      Caption = 'AddFolderButton'
      ImageIndex = 0
      OnClick = AddFolderButtonClick
    end
    object AddTextButton: TToolButton
      Left = 23
      Top = 2
      Caption = 'AddTextButton'
      ImageIndex = 1
      OnClick = AddTextButtonClick
    end
    object DeleteButton: TToolButton
      Left = 46
      Top = 2
      Caption = 'DeleteButton'
      ImageIndex = 2
      OnClick = DeleteButtonClick
    end
    object EditButton: TToolButton
      Left = 69
      Top = 2
      Caption = 'EditButton'
      ImageIndex = 3
      OnClick = EditButtonClick
    end
    object ToolButton1: TToolButton
      Left = 92
      Top = 2
      Width = 13
      Caption = 'ToolButton1'
      ImageIndex = 5
      Style = tbsSeparator
    end
    object AnchorButton: TToolButton
      Left = 105
      Top = 2
      Caption = 'AnchorButton'
      ImageIndex = 4
      OnClick = AnchorButtonClick
    end
  end
end
