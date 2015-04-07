object GroupDataForm: TGroupDataForm
  Left = 0
  Top = 0
  Caption = #1043#1088#1091#1087#1087#1099' '#1076#1072#1085#1085#1099#1093
  ClientHeight = 392
  ClientWidth = 684
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
    Left = 199
    Top = 22
    Width = 2
    Height = 370
    ExplicitTop = 17
    ExplicitHeight = 348
  end
  object tv: TTreeView
    Left = 0
    Top = 22
    Width = 199
    Height = 370
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
    OnEnter = tvEnter
    OnGetImageIndex = tvGetImageIndex
  end
  object dg: TDrawGridSpec
    Left = 201
    Top = 22
    Width = 483
    Height = 370
    Align = alClient
    ColCount = 1
    DefaultRowHeight = 18
    FixedCols = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing]
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
      457)
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 684
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
    object ToolButton2: TToolButton
      Left = 92
      Top = 0
      Width = 13
      Caption = 'ToolButton2'
      ImageIndex = 8
      Style = tbsSeparator
    end
    object AnchorButton: TToolButton
      Left = 105
      Top = 0
      Caption = 'AnchorButton'
      ImageIndex = 4
      OnClick = AnchorButtonClick
    end
  end
end
