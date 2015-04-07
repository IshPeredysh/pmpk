object OrganizationsForm: TOrganizationsForm
  Left = 0
  Top = 0
  Caption = #1054#1088#1075#1072#1085#1080#1079#1072#1094#1080#1080
  ClientHeight = 412
  ClientWidth = 821
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  OnClose = FormClose
  OnResize = FormResize
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 260
    Top = 30
    Width = 2
    Height = 382
    ExplicitTop = 18
    ExplicitHeight = 358
  end
  object tv: TTreeView
    Left = 0
    Top = 30
    Width = 260
    Height = 382
    Align = alLeft
    HideSelection = False
    Images = Images.ImageList2
    Indent = 27
    SortType = stBoth
    StateImages = Images.ImageList2
    TabOrder = 0
    OnChange = tvChange
    OnCompare = tvCompare
    OnDragDrop = tvDragDrop
    OnDragOver = tvDragOver
    OnEdited = tvEdited
    OnEnter = tvEnter
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 821
    Height = 30
    AutoSize = True
    ButtonHeight = 30
    ButtonWidth = 31
    Caption = 'ToolBar1'
    Images = Images.ImageList5
    TabOrder = 1
    object AddFolderButton: TToolButton
      Left = 0
      Top = 0
      Hint = #1053#1086#1074#1072#1103' '#1087#1072#1087#1082#1072
      Caption = 'AddFolderButton'
      ImageIndex = 0
      ParentShowHint = False
      ShowHint = True
      OnClick = AddFolderButtonClick
    end
    object AddTextButton: TToolButton
      Left = 31
      Top = 0
      Hint = #1053#1086#1074#1072#1103' '#1089#1090#1088#1086#1082#1072
      Caption = 'AddTextButton'
      ImageIndex = 1
      ParentShowHint = False
      ShowHint = True
      OnClick = AddTextButtonClick
    end
    object DeleteButton: TToolButton
      Left = 62
      Top = 0
      Hint = #1059#1076#1072#1083#1080#1090#1100
      Caption = 'DeleteButton'
      ImageIndex = 2
      ParentShowHint = False
      ShowHint = True
      OnClick = DeleteButtonClick
    end
    object EditButton: TToolButton
      Left = 93
      Top = 0
      Hint = #1048#1079#1084#1077#1085#1080#1090#1100
      Caption = 'EditButton'
      ImageIndex = 3
      ParentShowHint = False
      ShowHint = True
      OnClick = EditButtonClick
    end
    object ToolButton1: TToolButton
      Left = 124
      Top = 0
      Width = 8
      Caption = 'ToolButton1'
      ImageIndex = 4
      Style = tbsSeparator
    end
    object AnchorButton: TToolButton
      Left = 132
      Top = 0
      Caption = 'AnchorButton'
      ImageIndex = 4
    end
  end
  object dg: TDrawGridSpec
    Left = 262
    Top = 30
    Width = 559
    Height = 382
    Align = alClient
    ColCount = 2
    DefaultRowHeight = 18
    FixedCols = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing]
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
    ColWidths = (
      272
      226)
  end
  object lb: TListBox
    Left = 560
    Top = 50
    Width = 121
    Height = 118
    Style = lbOwnerDrawFixed
    BevelInner = bvNone
    BevelOuter = bvNone
    ItemHeight = 18
    TabOrder = 3
    Visible = False
    OnClick = lbClick
    OnExit = lbExit
  end
end
