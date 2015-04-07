object ReportForm: TReportForm
  Left = 0
  Top = 0
  Caption = #1054#1090#1095#1105#1090
  ClientHeight = 426
  ClientWidth = 471
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 471
    Height = 22
    Caption = 'ToolBar1'
    TabOrder = 0
    object Panel2: TPanel
      Left = 0
      Top = 0
      Width = 58
      Height = 22
      BevelOuter = bvNone
      Caption = #1087#1077#1088#1080#1086#1076' '#1089
      TabOrder = 1
    end
    object DateTimePicker1: TDateTimePicker
      Left = 58
      Top = 0
      Width = 90
      Height = 22
      Date = 41520.397541458340000000
      Time = 41520.397541458340000000
      DateMode = dmUpDown
      TabOrder = 0
    end
    object Panel3: TPanel
      Left = 148
      Top = 0
      Width = 21
      Height = 22
      BevelOuter = bvNone
      Caption = #1087#1086
      TabOrder = 2
    end
    object DateTimePicker2: TDateTimePicker
      Left = 169
      Top = 0
      Width = 88
      Height = 22
      Date = 41520.399661412040000000
      Time = 41520.399661412040000000
      DateMode = dmUpDown
      TabOrder = 3
    end
    object CurrentYearCheckBox: TCheckBox
      Left = 257
      Top = 0
      Width = 97
      Height = 22
      Caption = #1058#1077#1082#1091#1097#1080#1081' '#1075#1086#1076
      TabOrder = 4
      OnClick = CurrentYearCheckBoxClick
    end
  end
  object PageControl1: TPageControl
    Left = 0
    Top = 22
    Width = 471
    Height = 404
    ActivePage = TabSheet1
    Align = alClient
    TabOrder = 1
    ExplicitLeft = -8
    ExplicitTop = 28
    object TabSheet1: TTabSheet
      Caption = #1055#1086' '#1087#1086#1083#1102
      object lb: TListBox
        Left = 0
        Top = 0
        Width = 463
        Height = 341
        Align = alClient
        ItemHeight = 13
        TabOrder = 0
      end
      object Panel1: TPanel
        Left = 0
        Top = 341
        Width = 463
        Height = 35
        Align = alBottom
        TabOrder = 1
        DesignSize = (
          463
          35)
        object Button1: TButton
          Left = 368
          Top = 6
          Width = 92
          Height = 25
          Anchors = [akRight, akBottom]
          Caption = #1057#1086#1079#1076#1072#1090#1100' '#1086#1090#1095#1105#1090
          TabOrder = 0
          OnClick = Button1Click
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = #1055#1086' '#1076#1074#1091#1084' '#1087#1086#1083#1103#1084
      ImageIndex = 1
      object GridPanel1: TGridPanel
        Left = 0
        Top = 0
        Width = 463
        Height = 341
        Align = alClient
        Caption = 'GridPanel1'
        ColumnCollection = <
          item
            Value = 49.788280203142350000
          end
          item
            Value = 50.211719796857660000
          end>
        ControlCollection = <
          item
            Column = 0
            Control = Panel4
            Row = 0
          end
          item
            Column = 1
            Control = Panel6
            Row = 0
          end>
        RowCollection = <
          item
            Value = 100.000000000000000000
          end>
        TabOrder = 0
        object Panel4: TPanel
          Left = 1
          Top = 1
          Width = 229
          Height = 339
          Align = alClient
          BevelOuter = bvNone
          TabOrder = 0
          object Panel5: TPanel
            Left = 0
            Top = 0
            Width = 229
            Height = 25
            Align = alTop
            BevelOuter = bvNone
            TabOrder = 0
            object Label1: TLabel
              Left = 8
              Top = 11
              Width = 43
              Height = 13
              Caption = #1050#1086#1083#1086#1085#1082#1072
            end
          end
          object ListBox1: TListBox
            Left = 0
            Top = 25
            Width = 229
            Height = 314
            Align = alClient
            ItemHeight = 13
            TabOrder = 1
          end
        end
        object Panel6: TPanel
          Left = 230
          Top = 1
          Width = 232
          Height = 339
          Align = alClient
          BevelOuter = bvNone
          TabOrder = 1
          object Panel7: TPanel
            Left = 0
            Top = 0
            Width = 232
            Height = 25
            Align = alTop
            BevelOuter = bvNone
            TabOrder = 0
            object Label2: TLabel
              Left = 8
              Top = 11
              Width = 37
              Height = 13
              Caption = #1057#1090#1088#1086#1082#1072
            end
          end
          object ListBox2: TListBox
            Left = 0
            Top = 25
            Width = 232
            Height = 314
            Align = alClient
            ItemHeight = 13
            TabOrder = 1
          end
        end
      end
      object Panel8: TPanel
        Left = 0
        Top = 341
        Width = 463
        Height = 35
        Align = alBottom
        TabOrder = 1
        DesignSize = (
          463
          35)
        object Button4: TButton
          Left = 360
          Top = 6
          Width = 89
          Height = 25
          Anchors = [akRight, akBottom]
          Caption = #1057#1086#1079#1076#1072#1090#1100' '#1086#1090#1095#1105#1090
          TabOrder = 0
          OnClick = Button4Click
        end
      end
    end
    object TabSheet3: TTabSheet
      Caption = #1044#1088#1091#1075#1080#1077
      ImageIndex = 2
      ExplicitLeft = 0
      object Button5: TButton
        Left = 3
        Top = 3
        Width = 144
        Height = 25
        Caption = #1042#1086#1079#1088#1072#1089#1090#1085#1099#1077' '#1082#1072#1090#1077#1075#1086#1088#1080#1080
        TabOrder = 0
        OnClick = Button5Click
      end
      object Button6: TButton
        Left = 3
        Top = 34
        Width = 144
        Height = 25
        Caption = #1055#1086' '#1091#1095#1088#1077#1078#1076#1077#1085#1080#1103#1084
        TabOrder = 1
        OnClick = Button6Click
      end
    end
  end
end
