object ComboBoxForm: TComboBoxForm
  Left = 0
  Top = 0
  Caption = #1042#1099#1087#1072#1076#1072#1102#1097#1080#1077' '#1089#1087#1080#1089#1082#1080
  ClientHeight = 378
  ClientWidth = 543
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
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
    Top = 23
    Width = 2
    Height = 355
    ExplicitTop = 17
    ExplicitHeight = 354
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 543
    Height = 23
    AutoSize = True
    ButtonHeight = 23
    Caption = 'ToolBar1'
    Images = Images.ImageList4
    TabOrder = 0
    object AddFolderButton: TToolButton
      Left = 0
      Top = 0
      Caption = 'AddFolderButton'
      ImageIndex = 0
      Visible = False
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
      Width = 13
      Caption = 'ToolButton1'
      ImageIndex = 7
      Style = tbsSeparator
      Visible = False
    end
    object AnchorButton: TToolButton
      Left = 105
      Top = 0
      Caption = 'AnchorButton'
      ImageIndex = 4
      OnClick = AnchorButtonClick
    end
  end
  object tv: TTreeView
    Left = 0
    Top = 23
    Width = 217
    Height = 355
    Align = alLeft
    HideSelection = False
    Images = Images.ImageList1
    Indent = 19
    ReadOnly = True
    SortType = stBoth
    TabOrder = 1
    OnChange = tvChange
    OnCompare = tvCompare
    OnDragDrop = tvDragDrop
    OnDragOver = tvDragOver
    OnEdited = tvEdited
    OnEnter = tvEnter
  end
  object dg: TDrawGridSpec
    Left = 219
    Top = 23
    Width = 324
    Height = 355
    Align = alClient
    ColCount = 1
    DefaultRowHeight = 18
    FixedCols = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing]
    ScrollBars = ssVertical
    TabOrder = 2
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
    ExplicitLeft = 223
    ExplicitTop = 29
    ColWidths = (
      486)
  end
end
