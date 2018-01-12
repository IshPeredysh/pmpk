object ProtocolForm: TProtocolForm
  Left = 0
  Top = 0
  Caption = #1055#1088#1086#1090#1086#1082#1086#1083
  ClientHeight = 645
  ClientWidth = 742
  Color = clBtnFace
  ParentFont = True
  KeyPreview = True
  Menu = MainMenu1
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnKeyDown = FormKeyDown
  OnMouseWheelDown = FormMouseWheelDown
  OnMouseWheelUp = FormMouseWheelUp
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 26
    Width = 742
    Height = 619
    ActivePage = CommonTab
    Align = alClient
    Images = ImageList1
    TabOrder = 0
    OnChange = PageControl1Change
    object CommonTab: TTabSheet
      Caption = #1048#1085#1092#1086#1088#1084#1072#1094#1080#1103' '#1086' '#1088#1077#1073#1105#1085#1082#1077
      Enabled = False
      ImageIndex = -1
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object ScrollBox1: TScrollBox
        Left = 0
        Top = 0
        Width = 734
        Height = 590
        Align = alClient
        BevelInner = bvNone
        BevelOuter = bvNone
        Padding.Left = 3
        Padding.Top = 3
        Padding.Right = 3
        Padding.Bottom = 3
        TabOrder = 0
        OnMouseWheel = ScrollBoxMouseWheel
        object GroupBox1: TGroupBox
          AlignWithMargins = True
          Left = 6
          Top = 43
          Width = 701
          Height = 270
          Margins.Top = 10
          Align = alTop
          Caption = #1048#1085#1092#1086#1088#1084#1072#1094#1080#1103' '#1086' '#1088#1077#1073#1105#1085#1082#1077
          Padding.Left = 3
          Padding.Top = 3
          Padding.Right = 3
          Padding.Bottom = 3
          TabOrder = 1
          object Panel16: TPanel
            Left = 5
            Top = 47
            Width = 691
            Height = 32
            Align = alTop
            TabOrder = 1
            object Label4: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 87
              Height = 13
              Align = alLeft
              Caption = #1044#1072#1090#1072' '#1088#1086#1078#1076#1077#1085#1080#1103': '
              Layout = tlCenter
            end
            object DateTimePickerSpec2: TDateTimePickerSpec
              AlignWithMargins = True
              Left = 97
              Top = 4
              Width = 95
              Height = 24
              Align = alLeft
              Date = 41455.947719907410000000
              Time = 41455.947719907410000000
              PopupMenu = PopupMenu1
              TabOrder = 0
              OnChange = DateTimePickerChanged
              OnKeyDown = DateTimePickerSpecKeyDown
              FieldName = #1044#1072#1090#1072#1056#1086#1078#1076#1077#1085#1080#1103
              FieldType = 3
              TextData = '30.06.2013'
              Appointment = 4
            end
          end
          object Panel17: TPanel
            Left = 5
            Top = 79
            Width = 691
            Height = 29
            Align = alTop
            TabOrder = 2
            object Label16: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 26
              Height = 13
              Align = alLeft
              Caption = #1055#1086#1083': '
              Layout = tlCenter
            end
            object ComboBoxSpec1: TComboBoxSpec
              AlignWithMargins = True
              Left = 36
              Top = 4
              Width = 95
              Height = 21
              Align = alLeft
              ItemHeight = 0
              TabOrder = 0
              Text = '['#1055#1086#1083'][5][4][104]'
              OnSelect = ComboBoxSpecSelect
              OnAfterSetItemID = ComboBoxChanged
              OnMouseWheelUp = ComboBoxSpecMouseWheelUp
              OnMouseWheelDown = ComboBoxSpecMouseWheelDown
              FieldName = #1055#1086#1083
              FieldType = 5
              ParentID = 104
              Appointment = 4
              ListID = 1
            end
          end
          object Panel18: TPanel
            Left = 5
            Top = 108
            Width = 691
            Height = 29
            Align = alTop
            TabOrder = 3
            object Label6: TLabel
              AlignWithMargins = True
              Left = 48
              Top = 4
              Width = 74
              Height = 21
              Align = alLeft
              Caption = #1056#1072#1081#1086#1085', '#1075#1086#1088#1086#1076': '
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object Label5: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 38
              Height = 21
              Align = alLeft
              Caption = #1040#1076#1088#1077#1089': '
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object SpeedButton5: TSpeedButton
              AlignWithMargins = True
              Left = 664
              Top = 4
              Width = 23
              Height = 21
              Align = alRight
              Caption = '...'
              OnClick = SpeedButton5Click
              ExplicitLeft = 653
              ExplicitTop = -3
            end
            object RichEditSpec7: TRichEditSpec
              AlignWithMargins = True
              Left = 128
              Top = 4
              Width = 530
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1043#1086#1088#1086#1076'][4][0][123]')
              TabOrder = 0
              OnChange = RichEditChanged
              OnExit = RichEditSpecExit
              OnKeyDown = RichEditSpecKeyDown
              OnKeyPress = RichEditSpecKeyPress
              OnKeyUp = RichEditSpecKeyUp
              OnAfterSetItemID = RichEditSpecAfterSetItemID
              FieldName = #1043#1086#1088#1086#1076
              FieldType = 4
              TextData = '['#1043#1086#1088#1086#1076'][4][0][123]'
              ListID = 123
              Appointment = 4
            end
          end
          object Panel19: TPanel
            Left = 5
            Top = 137
            Width = 691
            Height = 29
            Align = alTop
            TabOrder = 4
            object Label7: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 38
              Height = 21
              Align = alLeft
              Caption = #1040#1076#1088#1077#1089': '
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object RichEditSpec2: TRichEditSpec
              AlignWithMargins = True
              Left = 48
              Top = 4
              Width = 639
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1040#1076#1088#1077#1089'][1][4][0]')
              TabOrder = 0
              OnChange = RichEditChanged
              FieldName = #1040#1076#1088#1077#1089
              FieldType = 1
              TextData = '['#1040#1076#1088#1077#1089'][1][4][0]'
              Appointment = 4
            end
          end
          object Panel24: TPanel
            Left = 5
            Top = 166
            Width = 691
            Height = 29
            Align = alTop
            TabOrder = 5
            object Label12: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 100
              Height = 21
              Align = alLeft
              Caption = #1048#1089#1090#1086#1088#1080#1103' '#1086#1073#1091#1095#1077#1085#1080#1103': '
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object RichEditSpec5: TRichEditSpec
              AlignWithMargins = True
              Left = 110
              Top = 4
              Width = 577
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1048#1089#1090#1086#1088#1080#1103#1054#1073#1091#1095#1077#1085#1080#1103'][1][4][0]')
              TabOrder = 0
              OnChange = RichEditChanged
              FieldName = #1048#1089#1090#1086#1088#1080#1103#1054#1073#1091#1095#1077#1085#1080#1103
              FieldType = 1
              TextData = '['#1048#1089#1090#1086#1088#1080#1103#1054#1073#1091#1095#1077#1085#1080#1103'][1][4][0]'
              Appointment = 4
            end
          end
          object Panel25: TPanel
            Left = 5
            Top = 224
            Width = 691
            Height = 29
            Align = alTop
            TabOrder = 7
            object Label11: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 171
              Height = 21
              Align = alLeft
              Caption = #1043#1076#1077' '#1086#1073#1091#1095#1072#1077#1090#1089#1103' ('#1074#1086#1089#1087#1080#1090#1099#1074#1072#1077#1090#1089#1103'): '
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object SpeedButton1: TSpeedButton
              AlignWithMargins = True
              Left = 664
              Top = 4
              Width = 23
              Height = 21
              Align = alRight
              Caption = '...'
              OnClick = SpeedButton1Click
              ExplicitLeft = 643
              ExplicitTop = -3
            end
            object RichEditSpec4: TRichEditSpec
              AlignWithMargins = True
              Left = 181
              Top = 4
              Width = 477
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1043#1076#1077#1054#1073#1091#1095#1072#1077#1090#1089#1103'][4][0][36]')
              TabOrder = 0
              OnChange = RichEditChanged
              OnExit = RichEditSpecExit
              OnKeyDown = RichEditSpecKeyDown
              OnKeyPress = RichEditSpecKeyPress
              OnKeyUp = RichEditSpecKeyUp
              OnAfterSetItemID = RichEditSpecAfterSetItemID
              FieldName = #1043#1076#1077#1054#1073#1091#1095#1072#1077#1090#1089#1103
              FieldType = 4
              TextData = '['#1043#1076#1077#1054#1073#1091#1095#1072#1077#1090#1089#1103'][4][0][36]'
              ListID = 36
              Appointment = 4
            end
          end
          object Panel26: TPanel
            Left = 5
            Top = 195
            Width = 691
            Height = 29
            Align = alTop
            TabOrder = 6
            object Label14: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 96
              Height = 21
              Align = alLeft
              Caption = #1044#1086#1087'. '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1103': '
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object RichEditSpec8: TRichEditSpec
              AlignWithMargins = True
              Left = 106
              Top = 4
              Width = 581
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1056#1077#1073#1077#1085#1086#1082#1044#1086#1087#1048#1085#1092#1086'][1][4][0]')
              TabOrder = 0
              OnChange = RichEditChanged
              FieldName = #1056#1077#1073#1077#1085#1086#1082#1044#1086#1087#1048#1085#1092#1086
              FieldType = 1
              TextData = '['#1056#1077#1073#1077#1085#1086#1082#1044#1086#1087#1048#1085#1092#1086'][1][4][0]'
              Appointment = 4
            end
          end
          object Panel14: TPanel
            Left = 5
            Top = 18
            Width = 691
            Height = 29
            Align = alTop
            TabOrder = 0
            object Label124: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 30
              Height = 21
              Align = alLeft
              Caption = #1060#1048#1054': '
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object SpeedButton63: TSpeedButton
              AlignWithMargins = True
              Left = 664
              Top = 4
              Width = 23
              Height = 21
              Align = alRight
              Caption = '...'
              OnClick = ButtonClickGetChildren
              ExplicitLeft = 629
              ExplicitTop = 1
            end
            object RichEditSpec1: TRichEditSpec
              AlignWithMargins = True
              Left = 40
              Top = 4
              Width = 618
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1060#1048#1054#1056#1077#1073#1077#1085#1082#1072'][4][0][18]')
              PopupMenu = PopupMenu1
              TabOrder = 0
              OnChange = RichEditChanged
              OnExit = RichEditSpecExit
              OnKeyDown = RichEditSpecKeyDown
              OnKeyPress = RichEditSpecKeyPress
              OnKeyUp = RichEditSpecKeyUp
              OnAfterSetItemID = RichEditSpecAfterSetItemID
              FieldName = #1060#1048#1054#1056#1077#1073#1077#1085#1082#1072
              FieldType = 4
              TextData = '['#1060#1048#1054#1056#1077#1073#1077#1085#1082#1072'][4][0][18]'
              ListID = 18
              Appointment = 4
            end
          end
        end
        object Panel1: TPanel
          Left = 3
          Top = 3
          Width = 707
          Height = 30
          Align = alTop
          BevelOuter = bvNone
          TabOrder = 0
          object Label2: TLabel
            AlignWithMargins = True
            Left = 198
            Top = 3
            Width = 123
            Height = 13
            Align = alLeft
            Caption = #1056#1077#1075#1080#1089#1090#1088#1072#1094#1080#1086#1085#1085#1099#1081' '#1085#1086#1084#1077#1088
          end
          object Label1: TLabel
            AlignWithMargins = True
            Left = 3
            Top = 3
            Width = 101
            Height = 13
            Align = alLeft
            Caption = #1044#1072#1090#1072' '#1086#1073#1089#1083#1077#1076#1086#1074#1072#1085#1080#1103
          end
          object EditSpec1: TEditSpec
            AlignWithMargins = True
            Left = 327
            Top = 3
            Width = 123
            Height = 24
            Align = alLeft
            TabOrder = 1
            Text = '['#1056#1077#1075#1053#1086#1084#1077#1088'][2][4][0]'
            OnChange = EditSpec1Change
            FieldName = #1056#1077#1075#1053#1086#1084#1077#1088
            FieldType = 2
            TextData = '['#1056#1077#1075#1053#1086#1084#1077#1088'][2][4][0]'
            Appointment = 4
            ExplicitHeight = 21
          end
          object DateTimePickerSpec1: TDateTimePickerSpec
            AlignWithMargins = True
            Left = 110
            Top = 3
            Width = 82
            Height = 24
            Align = alLeft
            Date = 0.946672986108751500
            Time = 0.946672986108751500
            TabOrder = 0
            OnChange = DateTimePickerChanged
            FieldName = #1044#1072#1090#1072#1054#1073#1089#1083#1077#1076#1086#1074#1072#1085#1080#1103
            FieldType = 3
            TextData = '30.12.1899'
            Appointment = 4
          end
        end
        object GroupBox2: TGroupBox
          Left = 3
          Top = 512
          Width = 707
          Height = 516
          Align = alTop
          Caption = #1057#1074#1077#1076#1077#1085#1080#1103' '#1086' '#1088#1086#1076#1080#1090#1077#1083#1103#1093
          TabOrder = 3
          object Panel34: TPanel
            Left = 2
            Top = 454
            Width = 703
            Height = 29
            Align = alTop
            TabOrder = 3
            object Label25: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 89
              Height = 21
              Align = alLeft
              Caption = #1044#1086#1087'. '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1103
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object RichEditSpec16: TRichEditSpec
              AlignWithMargins = True
              Left = 99
              Top = 4
              Width = 600
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1057#1077#1084#1100#1103#1044#1086#1087#1048#1085#1092#1086'][1][4][0]')
              TabOrder = 0
              OnChange = RichEditChanged
              FieldName = #1057#1077#1084#1100#1103#1044#1086#1087#1048#1085#1092#1086
              FieldType = 1
              TextData = '['#1057#1077#1084#1100#1103#1044#1086#1087#1048#1085#1092#1086'][1][4][0]'
              Appointment = 4
            end
          end
          object Panel35: TPanel
            Left = 2
            Top = 425
            Width = 703
            Height = 29
            Align = alTop
            TabOrder = 2
            object Label26: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 133
              Height = 13
              Align = alLeft
              Caption = #1057#1086#1089#1090#1072#1074' '#1089#1077#1084#1100#1080', '#1089#1086#1094'. '#1089#1090#1072#1090#1091#1089
              Layout = tlCenter
            end
            object Label69: TLabel
              AlignWithMargins = True
              Left = 244
              Top = 4
              Width = 22
              Height = 13
              Align = alLeft
              Caption = #1095#1077#1083'.'
              Layout = tlCenter
            end
            object ComboBoxSpec29: TComboBoxSpec
              AlignWithMargins = True
              Left = 272
              Top = 4
              Width = 158
              Height = 21
              Align = alLeft
              ItemHeight = 0
              TabOrder = 1
              Text = '['#1057#1086#1094#1057#1090#1072#1090#1091#1089#1057#1077#1084#1100#1080'][5][4][134]'
              OnSelect = ComboBoxSpecSelect
              OnAfterSetItemID = ComboBoxSpecAfterSetItemID
              FieldName = #1057#1086#1094#1057#1090#1072#1090#1091#1089#1057#1077#1084#1100#1080
              FieldType = 5
              ParentID = 134
              Appointment = 4
              ListID = 1
            end
            object EditSpec2: TEditSpec
              AlignWithMargins = True
              Left = 143
              Top = 4
              Width = 95
              Height = 21
              Align = alLeft
              TabOrder = 0
              Text = '['#1057#1086#1089#1090#1072#1074#1057#1077#1084#1100#1080'][2][4][0]'
              OnChange = EditChanged
              FieldName = #1057#1086#1089#1090#1072#1074#1057#1077#1084#1100#1080
              FieldType = 2
              TextData = '['#1057#1086#1089#1090#1072#1074#1057#1077#1084#1100#1080'][2][4][0]'
              Appointment = 4
            end
          end
          object GroupBox3: TGroupBox
            Left = 2
            Top = 15
            Width = 703
            Height = 207
            Align = alTop
            Caption = #1054#1090#1077#1094
            Padding.Bottom = 3
            TabOrder = 0
            object Panel28: TPanel
              Left = 2
              Top = 15
              Width = 699
              Height = 29
              Align = alTop
              TabOrder = 0
              object Label24: TLabel
                AlignWithMargins = True
                Left = 4
                Top = 4
                Width = 30
                Height = 21
                Align = alLeft
                Caption = #1060#1048#1054': '
                Layout = tlCenter
                ExplicitHeight = 13
              end
              object SpeedButton7: TSpeedButton
                Left = 675
                Top = 1
                Width = 23
                Height = 27
                Align = alRight
                Caption = '...'
                OnClick = ButtonClickGetFather
                ExplicitLeft = 662
                ExplicitTop = 4
                ExplicitHeight = 21
              end
              object RichEditSpec15: TRichEditSpec
                AlignWithMargins = True
                Left = 40
                Top = 4
                Width = 632
                Height = 21
                Align = alClient
                Lines.Strings = (
                  '['#1054#1090#1077#1094#1060#1048#1054'][4][0][84]')
                TabOrder = 0
                OnChange = RichEditChanged
                OnExit = RichEditSpecExit
                OnKeyDown = RichEditSpecKeyDown
                OnKeyPress = RichEditSpecKeyPress
                OnKeyUp = RichEditSpecKeyUp
                OnAfterSetItemID = RichEditSpecAfterSetItemID
                FieldName = #1054#1090#1077#1094#1060#1048#1054
                FieldType = 4
                TextData = '['#1054#1090#1077#1094#1060#1048#1054'][4][0][84]'
                ListID = 84
                Appointment = 4
              end
            end
            object Panel36: TPanel
              Left = 2
              Top = 44
              Width = 699
              Height = 29
              Align = alTop
              TabOrder = 1
              object Label27: TLabel
                AlignWithMargins = True
                Left = 4
                Top = 4
                Width = 47
                Height = 21
                Align = alLeft
                Caption = #1042#1086#1079#1088#1072#1089#1090': '
                Layout = tlCenter
                ExplicitHeight = 13
              end
              object RichEditSpec20: TRichEditSpec
                AlignWithMargins = True
                Left = 57
                Top = 4
                Width = 638
                Height = 21
                Align = alClient
                Lines.Strings = (
                  '['#1054#1090#1077#1094#1042#1086#1079#1088#1072#1089#1090'][2][4][0]')
                TabOrder = 0
                OnChange = RichEditChanged
                FieldName = #1054#1090#1077#1094#1042#1086#1079#1088#1072#1089#1090
                FieldType = 2
                TextData = '['#1054#1090#1077#1094#1042#1086#1079#1088#1072#1089#1090'][2][4][0]'
                Appointment = 4
              end
            end
            object Panel37: TPanel
              Left = 2
              Top = 73
              Width = 699
              Height = 29
              Align = alTop
              TabOrder = 2
              object Label29: TLabel
                AlignWithMargins = True
                Left = 4
                Top = 4
                Width = 74
                Height = 13
                Align = alLeft
                Caption = #1054#1073#1088#1072#1079#1086#1074#1072#1085#1080#1077': '
                Layout = tlCenter
              end
              object ComboBoxSpec3: TComboBoxSpec
                AlignWithMargins = True
                Left = 84
                Top = 4
                Width = 150
                Height = 21
                Align = alLeft
                ItemHeight = 0
                TabOrder = 0
                Text = '['#1054#1090#1077#1094#1054#1073#1088#1072#1079#1086#1074#1072#1085#1080#1077'][5][4][91]'
                OnSelect = ComboBoxSpecSelect
                OnAfterSetItemID = ComboBoxSpecAfterSetItemID
                OnMouseWheelUp = ComboBoxSpecMouseWheelUp
                OnMouseWheelDown = ComboBoxSpecMouseWheelDown
                FieldName = #1054#1090#1077#1094#1054#1073#1088#1072#1079#1086#1074#1072#1085#1080#1077
                FieldType = 5
                ParentID = 91
                Appointment = 4
                ListID = 1
              end
            end
            object Panel39: TPanel
              Left = 2
              Top = 102
              Width = 699
              Height = 29
              Align = alTop
              TabOrder = 3
              object Label30: TLabel
                AlignWithMargins = True
                Left = 4
                Top = 4
                Width = 79
                Height = 21
                Align = alLeft
                Caption = #1052#1077#1089#1090#1086' '#1088#1072#1073#1086#1090#1099': '
                Layout = tlCenter
                ExplicitHeight = 13
              end
              object RichEditSpec22: TRichEditSpec
                AlignWithMargins = True
                Left = 89
                Top = 4
                Width = 606
                Height = 21
                Align = alClient
                Lines.Strings = (
                  '['#1054#1090#1077#1094#1052#1077#1089#1090#1086#1056#1072#1073#1086#1090#1099'][1][4][0]')
                TabOrder = 0
                OnChange = RichEditChanged
                FieldName = #1054#1090#1077#1094#1052#1077#1089#1090#1086#1056#1072#1073#1086#1090#1099
                FieldType = 1
                TextData = '['#1054#1090#1077#1094#1052#1077#1089#1090#1086#1056#1072#1073#1086#1090#1099'][1][4][0]'
                Appointment = 4
              end
            end
            object Panel40: TPanel
              Left = 2
              Top = 131
              Width = 699
              Height = 29
              Align = alTop
              TabOrder = 4
              object Label133: TLabel
                AlignWithMargins = True
                Left = 4
                Top = 4
                Width = 105
                Height = 13
                Align = alLeft
                Caption = #1042#1088#1077#1076#1085#1099#1077' '#1087#1088#1080#1074#1099#1095#1082#1080': '
                Layout = tlCenter
              end
              object ComboBoxSpec4: TComboBoxSpec
                AlignWithMargins = True
                Left = 115
                Top = 4
                Width = 150
                Height = 21
                Align = alLeft
                ItemHeight = 0
                TabOrder = 0
                Text = '['#1054#1090#1077#1094#1042#1055'][5][4][99]'
                OnSelect = ComboBoxSpecSelect
                OnAfterSetItemID = ComboBoxSpecAfterSetItemID
                OnMouseWheelUp = ComboBoxSpecMouseWheelUp
                OnMouseWheelDown = ComboBoxSpecMouseWheelDown
                FieldName = #1054#1090#1077#1094#1042#1055
                FieldType = 5
                ParentID = 99
                Appointment = 4
                ListID = 1
              end
            end
            object Panel41: TPanel
              Left = 2
              Top = 160
              Width = 699
              Height = 29
              Align = alTop
              TabOrder = 5
              object Label134: TLabel
                AlignWithMargins = True
                Left = 4
                Top = 4
                Width = 174
                Height = 13
                Align = alLeft
                Caption = #1054#1090#1103#1075#1086#1097#1105#1085#1085#1072#1103' '#1085#1072#1089#1083#1077#1076#1089#1090#1074#1077#1085#1085#1086#1089#1090#1100': '
                Layout = tlCenter
              end
              object ComboBoxSpec5: TComboBoxSpec
                AlignWithMargins = True
                Left = 184
                Top = 4
                Width = 150
                Height = 21
                Align = alLeft
                ItemHeight = 0
                TabOrder = 0
                Text = '['#1054#1090#1077#1094#1053#1072#1089#1083#1077#1076#1089#1090#1074#1077#1085#1085#1086#1089#1090#1100'][5][4][45]'
                OnSelect = ComboBoxSpecSelect
                OnAfterSetItemID = ComboBoxSpecAfterSetItemID
                OnMouseWheelUp = ComboBoxSpecMouseWheelUp
                OnMouseWheelDown = ComboBoxSpecMouseWheelDown
                FieldName = #1054#1090#1077#1094#1053#1072#1089#1083#1077#1076#1089#1090#1074#1077#1085#1085#1086#1089#1090#1100
                FieldType = 5
                ParentID = 45
                Appointment = 4
                ListID = 1
              end
            end
          end
          object GroupBox4: TGroupBox
            Left = 2
            Top = 222
            Width = 703
            Height = 203
            Align = alTop
            Caption = #1052#1072#1090#1100
            TabOrder = 1
            object Panel38: TPanel
              Left = 2
              Top = 131
              Width = 699
              Height = 29
              Align = alTop
              TabOrder = 4
              object Label28: TLabel
                AlignWithMargins = True
                Left = 4
                Top = 4
                Width = 98
                Height = 13
                Align = alLeft
                Caption = #1042#1088#1077#1076#1085#1099#1077' '#1087#1088#1080#1074#1099#1095#1082#1080
                Layout = tlCenter
              end
              object ComboBoxSpec7: TComboBoxSpec
                AlignWithMargins = True
                Left = 108
                Top = 4
                Width = 150
                Height = 21
                Align = alLeft
                ItemHeight = 0
                TabOrder = 0
                Text = '['#1052#1072#1090#1100#1042#1055'][5][4][99]'
                OnSelect = ComboBoxSpecSelect
                OnAfterSetItemID = ComboBoxSpecAfterSetItemID
                OnMouseWheelUp = ComboBoxSpecMouseWheelUp
                OnMouseWheelDown = ComboBoxSpecMouseWheelDown
                FieldName = #1052#1072#1090#1100#1042#1055
                FieldType = 5
                ParentID = 99
                Appointment = 4
                ListID = 1
              end
            end
            object Panel31: TPanel
              Left = 2
              Top = 73
              Width = 699
              Height = 29
              Align = alTop
              TabOrder = 2
              object Label130: TLabel
                AlignWithMargins = True
                Left = 4
                Top = 4
                Width = 67
                Height = 13
                Align = alLeft
                Caption = #1054#1073#1088#1072#1079#1086#1074#1072#1085#1080#1077
                Layout = tlCenter
              end
              object ComboBoxSpec6: TComboBoxSpec
                AlignWithMargins = True
                Left = 77
                Top = 4
                Width = 150
                Height = 21
                Align = alLeft
                ItemHeight = 0
                TabOrder = 0
                Text = '['#1052#1072#1090#1100#1054#1073#1088#1072#1079#1086#1074#1072#1085#1080#1077'][5][4][91]'
                OnSelect = ComboBoxSpecSelect
                OnAfterSetItemID = ComboBoxSpecAfterSetItemID
                OnMouseWheelUp = ComboBoxSpecMouseWheelUp
                OnMouseWheelDown = ComboBoxSpecMouseWheelDown
                FieldName = #1052#1072#1090#1100#1054#1073#1088#1072#1079#1086#1074#1072#1085#1080#1077
                FieldType = 5
                ParentID = 91
                Appointment = 4
                ListID = 1
              end
            end
            object Panel32: TPanel
              Left = 2
              Top = 44
              Width = 699
              Height = 29
              Align = alTop
              TabOrder = 1
              object Label131: TLabel
                AlignWithMargins = True
                Left = 4
                Top = 4
                Width = 40
                Height = 21
                Align = alLeft
                Caption = #1042#1086#1079#1088#1072#1089#1090
                Layout = tlCenter
                ExplicitHeight = 13
              end
              object RichEditSpec13: TRichEditSpec
                AlignWithMargins = True
                Left = 50
                Top = 4
                Width = 645
                Height = 21
                Align = alClient
                Lines.Strings = (
                  '['#1052#1072#1090#1100#1042#1086#1079#1088#1072#1089#1090'][2][4][0]')
                TabOrder = 0
                OnChange = RichEditChanged
                FieldName = #1052#1072#1090#1100#1042#1086#1079#1088#1072#1089#1090
                FieldType = 2
                TextData = '['#1052#1072#1090#1100#1042#1086#1079#1088#1072#1089#1090'][2][4][0]'
                Appointment = 4
              end
            end
            object Panel30: TPanel
              Left = 2
              Top = 102
              Width = 699
              Height = 29
              Align = alTop
              TabOrder = 3
              object Label10: TLabel
                AlignWithMargins = True
                Left = 4
                Top = 4
                Width = 72
                Height = 21
                Align = alLeft
                Caption = #1052#1077#1089#1090#1086' '#1088#1072#1073#1086#1090#1099
                Layout = tlCenter
                ExplicitHeight = 13
              end
              object RichEditSpec11: TRichEditSpec
                AlignWithMargins = True
                Left = 82
                Top = 4
                Width = 613
                Height = 21
                Align = alClient
                Lines.Strings = (
                  '['#1052#1072#1090#1100#1052#1077#1089#1090#1086#1056#1072#1073#1086#1090#1099'][1][4][0]')
                TabOrder = 0
                OnChange = RichEditChanged
                FieldName = #1052#1072#1090#1100#1052#1077#1089#1090#1086#1056#1072#1073#1086#1090#1099
                FieldType = 1
                TextData = '['#1052#1072#1090#1100#1052#1077#1089#1090#1086#1056#1072#1073#1086#1090#1099'][1][4][0]'
                Appointment = 4
              end
            end
            object Panel33: TPanel
              Left = 2
              Top = 15
              Width = 699
              Height = 29
              Align = alTop
              TabOrder = 0
              object Label132: TLabel
                AlignWithMargins = True
                Left = 4
                Top = 4
                Width = 23
                Height = 21
                Align = alLeft
                Caption = #1060#1048#1054
                Layout = tlCenter
                ExplicitHeight = 13
              end
              object SpeedButton8: TSpeedButton
                Left = 675
                Top = 1
                Width = 23
                Height = 27
                Align = alRight
                Caption = '...'
                OnClick = ButtonClickGetMother
                ExplicitLeft = 624
                ExplicitTop = -3
                ExplicitHeight = 21
              end
              object RichEditSpec14: TRichEditSpec
                AlignWithMargins = True
                Left = 33
                Top = 4
                Width = 639
                Height = 21
                Align = alClient
                Lines.Strings = (
                  '['#1052#1072#1090#1100#1060#1048#1054'][4][0][84]')
                TabOrder = 0
                OnChange = RichEditChanged
                OnExit = RichEditSpecExit
                OnKeyDown = RichEditSpecKeyDown
                OnKeyPress = RichEditSpecKeyPress
                OnKeyUp = RichEditSpecKeyUp
                OnAfterSetItemID = RichEditSpecAfterSetItemID
                FieldName = #1052#1072#1090#1100#1060#1048#1054
                FieldType = 4
                TextData = '['#1052#1072#1090#1100#1060#1048#1054'][4][0][84]'
                ListID = 84
                Appointment = 4
              end
            end
            object Panel29: TPanel
              Left = 2
              Top = 160
              Width = 699
              Height = 30
              Align = alTop
              TabOrder = 5
              object Label23: TLabel
                AlignWithMargins = True
                Left = 4
                Top = 4
                Width = 167
                Height = 13
                Align = alLeft
                Caption = #1054#1090#1103#1075#1086#1097#1105#1085#1085#1072#1103' '#1085#1072#1089#1083#1077#1076#1089#1090#1074#1077#1085#1085#1086#1089#1090#1100
                Layout = tlCenter
              end
              object ComboBoxSpec8: TComboBoxSpec
                AlignWithMargins = True
                Left = 177
                Top = 4
                Width = 150
                Height = 21
                Align = alLeft
                ItemHeight = 0
                TabOrder = 0
                Text = '['#1052#1072#1090#1100#1053#1072#1089#1083#1077#1076#1089#1090#1074#1077#1085#1085#1086#1089#1090#1100'][5][4][45]'
                OnSelect = ComboBoxSpecSelect
                OnAfterSetItemID = ComboBoxSpecAfterSetItemID
                OnMouseWheelUp = ComboBoxSpecMouseWheelUp
                OnMouseWheelDown = ComboBoxSpecMouseWheelDown
                FieldName = #1052#1072#1090#1100#1053#1072#1089#1083#1077#1076#1089#1090#1074#1077#1085#1085#1086#1089#1090#1100
                FieldType = 5
                ParentID = 45
                Appointment = 4
                ListID = 1
              end
            end
          end
        end
        object GroupBox5: TGroupBox
          Left = 3
          Top = 1028
          Width = 707
          Height = 447
          Align = alTop
          Caption = #1040#1085#1072#1084#1085#1077#1089#1090#1080#1095#1077#1089#1082#1080#1077' '#1076#1072#1085#1085#1099#1077
          Padding.Left = 3
          Padding.Top = 3
          Padding.Right = 3
          Padding.Bottom = 3
          TabOrder = 4
          object GroupBox6: TGroupBox
            Left = 5
            Top = 250
            Width = 697
            Height = 88
            Align = alTop
            Caption = #1056#1072#1085#1085#1077#1077' '#1088#1077#1095#1077#1074#1086#1077' '#1088#1072#1079#1074#1080#1090#1080#1077
            Padding.Left = 3
            Padding.Top = 3
            Padding.Right = 3
            Padding.Bottom = 3
            TabOrder = 0
            object Panel50: TPanel
              Left = 5
              Top = 18
              Width = 687
              Height = 29
              Align = alTop
              TabOrder = 0
              object Label33: TLabel
                AlignWithMargins = True
                Left = 4
                Top = 4
                Width = 67
                Height = 21
                Align = alLeft
                Caption = #1057#1083#1086#1074#1086' '#1089', '#1084#1077#1089'.'
                ExplicitHeight = 13
              end
              object RichEditSpec33: TRichEditSpec
                AlignWithMargins = True
                Left = 77
                Top = 4
                Width = 606
                Height = 21
                Align = alClient
                Lines.Strings = (
                  '['#1057#1083#1086#1074#1086#1057'][2][4][0]')
                TabOrder = 0
                OnChange = RichEditChanged
                FieldName = #1057#1083#1086#1074#1086#1057
                FieldType = 2
                TextData = '['#1057#1083#1086#1074#1086#1057'][2][4][0]'
                Appointment = 4
              end
            end
            object Panel51: TPanel
              Left = 5
              Top = 47
              Width = 687
              Height = 29
              Align = alTop
              TabOrder = 1
              object Label34: TLabel
                AlignWithMargins = True
                Left = 4
                Top = 4
                Width = 64
                Height = 21
                Align = alLeft
                Caption = #1060#1088#1072#1079#1072' '#1089', '#1083#1077#1090
                ExplicitHeight = 13
              end
              object RichEditSpec34: TRichEditSpec
                AlignWithMargins = True
                Left = 74
                Top = 4
                Width = 609
                Height = 21
                Align = alClient
                Lines.Strings = (
                  '['#1060#1088#1072#1079#1072#1057'][2][4][0]')
                TabOrder = 0
                OnChange = RichEditChanged
                FieldName = #1060#1088#1072#1079#1072#1057
                FieldType = 2
                TextData = '['#1060#1088#1072#1079#1072#1057'][2][4][0]'
                Appointment = 4
              end
            end
          end
          object Panel52: TPanel
            Left = 5
            Top = 338
            Width = 697
            Height = 29
            Align = alTop
            TabOrder = 1
            object Label35: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 136
              Height = 21
              Align = alLeft
              Caption = #1050#1091#1076#1072' '#1087#1077#1088#1077#1074#1077#1076#1105#1085' '#1087#1086#1089#1083#1077' '#1088'/'#1076
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object ComboBoxSpec9: TComboBoxSpec
              AlignWithMargins = True
              Left = 146
              Top = 4
              Width = 170
              Height = 21
              Align = alLeft
              ItemHeight = 0
              TabOrder = 0
              Text = '['#1055#1086#1089#1083#1077#1056#1086#1076#1076#1086#1084#1072'][5][4][127]'
              OnSelect = ComboBoxSpecSelect
              OnAfterSetItemID = ComboBoxSpecAfterSetItemID
              OnMouseWheelUp = ComboBoxSpecMouseWheelUp
              OnMouseWheelDown = ComboBoxSpecMouseWheelDown
              FieldName = #1055#1086#1089#1083#1077#1056#1086#1076#1076#1086#1084#1072
              FieldType = 5
              ParentID = 127
              Appointment = 4
              ListID = 1
            end
            object RichEditSpec10: TRichEditSpec
              AlignWithMargins = True
              Left = 322
              Top = 4
              Width = 371
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1055#1086#1089#1083#1077#1056#1086#1076#1076#1086#1084#1072#1044#1088#1091#1075#1086#1077'][1][4][0]')
              TabOrder = 1
              OnChange = RichEditChanged
              FieldName = #1055#1086#1089#1083#1077#1056#1086#1076#1076#1086#1084#1072#1044#1088#1091#1075#1086#1077
              FieldType = 1
              TextData = '['#1055#1086#1089#1083#1077#1056#1086#1076#1076#1086#1084#1072#1044#1088#1091#1075#1086#1077'][1][4][0]'
              Appointment = 4
            end
          end
          object Panel53: TPanel
            Left = 5
            Top = 396
            Width = 697
            Height = 29
            Align = alTop
            TabOrder = 3
            object Label36: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 89
              Height = 21
              Align = alLeft
              Caption = #1044#1086#1087'. '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1103
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object RichEditSpec36: TRichEditSpec
              AlignWithMargins = True
              Left = 99
              Top = 4
              Width = 594
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1040#1085#1072#1084#1085#1077#1079#1044#1086#1087#1048#1085#1092#1086'][1][4][0]')
              TabOrder = 0
              OnChange = RichEditChanged
              FieldName = #1040#1085#1072#1084#1085#1077#1079#1044#1086#1087#1048#1085#1092#1086
              FieldType = 1
              TextData = '['#1040#1085#1072#1084#1085#1077#1079#1044#1086#1087#1048#1085#1092#1086'][1][4][0]'
              Appointment = 4
            end
          end
          object Panel54: TPanel
            Left = 5
            Top = 367
            Width = 697
            Height = 29
            Align = alTop
            TabOrder = 2
            object Label37: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 13
              Height = 21
              Align = alLeft
              Caption = 'DS'
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object SpeedButton9: TSpeedButton
              AlignWithMargins = True
              Left = 670
              Top = 4
              Width = 23
              Height = 21
              Align = alRight
              Glyph.Data = {
                E6000000424DE60000000000000076000000280000000E0000000E0000000100
                0400000000007000000000000000000000001000000000000000000000000000
                BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
                FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
                3300333333333333330033333333333333003333300033333300333330F03333
                3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
                3300333330F033333300333330F0333333003333300033333300333333333333
                33003333333333333300}
              OnClick = SpeedButton9Click
              ExplicitLeft = 668
              ExplicitTop = 7
              ExplicitHeight = 15
            end
            object RichEditSpec37: TRichEditSpec
              AlignWithMargins = True
              Left = 23
              Top = 4
              Width = 641
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1040#1085#1072#1084#1085#1077#1079#1044#1080#1072#1075#1085#1086#1079'][1][0][39]')
              TabOrder = 0
              OnChange = RichEditChanged
              OnExit = RichEditSpecExit
              OnKeyDown = RichEditSpecKeyDown
              OnKeyPress = RichEditSpecKeyPress
              OnKeyUp = RichEditSpecKeyUp
              FieldName = #1040#1085#1072#1084#1085#1077#1079#1044#1080#1072#1075#1085#1086#1079
              FieldType = 1
              TextData = '['#1040#1085#1072#1084#1085#1077#1079#1044#1080#1072#1075#1085#1086#1079'][1][0][39]'
              ListID = 39
              Appointment = 4
            end
          end
          object Panel42: TPanel
            Left = 5
            Top = 18
            Width = 697
            Height = 29
            Align = alTop
            TabOrder = 4
            object Label17: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 126
              Height = 13
              Align = alLeft
              Caption = #1041#1077#1088#1077#1084#1077#1085#1085#1086#1089#1090#1100' ('#1087#1086' '#1089#1095#1105#1090#1091')'
              Layout = tlCenter
            end
            object EditSpec3: TEditSpec
              AlignWithMargins = True
              Left = 136
              Top = 4
              Width = 557
              Height = 21
              Align = alClient
              TabOrder = 0
              Text = '['#1040#1085#1072#1084#1085#1077#1079#1041#1077#1088#1077#1084#1077#1085#1085#1086#1089#1090#1100#1055#1086#1057#1095#1077#1090#1091'][2][4][0]'
              OnChange = EditChanged
              FieldName = #1040#1085#1072#1084#1085#1077#1079#1041#1077#1088#1077#1084#1077#1085#1085#1086#1089#1090#1100#1055#1086#1057#1095#1077#1090#1091
              FieldType = 2
              TextData = '['#1040#1085#1072#1084#1085#1077#1079#1041#1077#1088#1077#1084#1077#1085#1085#1086#1089#1090#1100#1055#1086#1057#1095#1077#1090#1091'][2][4][0]'
              Appointment = 4
            end
          end
          object Panel43: TPanel
            Left = 5
            Top = 47
            Width = 697
            Height = 29
            Align = alTop
            TabOrder = 5
            object Label18: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 116
              Height = 21
              Align = alLeft
              Caption = #1058#1077#1095#1077#1085#1080#1077' '#1073#1077#1088#1077#1084#1077#1085#1085#1086#1089#1090#1080
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object RichEditSpec26: TRichEditSpec
              AlignWithMargins = True
              Left = 126
              Top = 4
              Width = 567
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1058#1077#1095#1077#1085#1080#1077#1041#1077#1088#1077#1084#1077#1085#1085#1086#1089#1090#1080'][1][4][0]')
              TabOrder = 0
              OnChange = RichEditChanged
              FieldName = #1058#1077#1095#1077#1085#1080#1077#1041#1077#1088#1077#1084#1077#1085#1085#1086#1089#1090#1080
              FieldType = 1
              TextData = '['#1058#1077#1095#1077#1085#1080#1077#1041#1077#1088#1077#1084#1077#1085#1085#1086#1089#1090#1080'][1][4][0]'
              Appointment = 4
            end
          end
          object Panel47: TPanel
            Left = 5
            Top = 76
            Width = 697
            Height = 29
            Align = alTop
            TabOrder = 6
            object Label22: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 74
              Height = 21
              Align = alLeft
              Caption = #1056#1086#1076#1099' '#1087#1086' '#1089#1095#1105#1090#1091
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object RichEditSpec30: TRichEditSpec
              AlignWithMargins = True
              Left = 84
              Top = 4
              Width = 609
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1040#1085#1072#1084#1085#1077#1079#1056#1086#1076#1099#1055#1086#1057#1095#1077#1090#1091'][2][4][0]')
              TabOrder = 0
              OnChange = RichEditChanged
              FieldName = #1040#1085#1072#1084#1085#1077#1079#1056#1086#1076#1099#1055#1086#1057#1095#1077#1090#1091
              FieldType = 2
              TextData = '['#1040#1085#1072#1084#1085#1077#1079#1056#1086#1076#1099#1055#1086#1057#1095#1077#1090#1091'][2][4][0]'
              Appointment = 4
            end
          end
          object Panel46: TPanel
            Left = 5
            Top = 105
            Width = 697
            Height = 29
            Align = alTop
            TabOrder = 7
            object Label21: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 89
              Height = 21
              Align = alLeft
              Caption = #1057#1088#1086#1082' '#1088#1086#1076#1086#1074', '#1085#1077#1076'.'
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object RichEditSpec29: TRichEditSpec
              AlignWithMargins = True
              Left = 99
              Top = 4
              Width = 594
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1040#1085#1072#1084#1085#1077#1079#1057#1088#1086#1082#1056#1086#1076#1086#1074'][2][4][0]')
              TabOrder = 0
              OnChange = RichEditChanged
              FieldName = #1040#1085#1072#1084#1085#1077#1079#1057#1088#1086#1082#1056#1086#1076#1086#1074
              FieldType = 2
              TextData = '['#1040#1085#1072#1084#1085#1077#1079#1057#1088#1086#1082#1056#1086#1076#1086#1074'][2][4][0]'
              Appointment = 4
            end
          end
          object Panel45: TPanel
            Left = 5
            Top = 134
            Width = 697
            Height = 29
            Align = alTop
            TabOrder = 8
            object Label20: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 163
              Height = 21
              Align = alLeft
              Caption = #1054#1089#1086#1073#1077#1085#1085#1086#1089#1090#1080' '#1087#1088#1086#1090#1077#1082#1072#1085#1080#1103' '#1088#1086#1076#1086#1074
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object RichEditSpec28: TRichEditSpec
              AlignWithMargins = True
              Left = 173
              Top = 4
              Width = 520
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1054#1089#1086#1073#1077#1085#1085#1086#1089#1090#1080#1056#1086#1076#1086#1074'][1][4][0]')
              TabOrder = 0
              OnChange = RichEditChanged
              FieldName = #1054#1089#1086#1073#1077#1085#1085#1086#1089#1090#1080#1056#1086#1076#1086#1074
              FieldType = 1
              TextData = '['#1054#1089#1086#1073#1077#1085#1085#1086#1089#1090#1080#1056#1086#1076#1086#1074'][1][4][0]'
              Appointment = 4
            end
          end
          object Panel49: TPanel
            Left = 5
            Top = 163
            Width = 697
            Height = 29
            Align = alTop
            TabOrder = 9
            object Label32: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 159
              Height = 21
              Align = alLeft
              Caption = #1042#1077#1089' '#1088#1077#1073#1105#1085#1082#1072' '#1087#1088#1080' '#1088#1086#1078#1076#1077#1085#1080#1080', '#1075#1088'.'
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object RichEditSpec32: TRichEditSpec
              AlignWithMargins = True
              Left = 169
              Top = 4
              Width = 524
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1042#1077#1089#1055#1088#1080#1056#1086#1078#1076#1077#1085#1080#1080'][2][4][0]')
              TabOrder = 0
              OnChange = RichEditChanged
              FieldName = #1042#1077#1089#1055#1088#1080#1056#1086#1078#1076#1077#1085#1080#1080
              FieldType = 2
              TextData = '['#1042#1077#1089#1055#1088#1080#1056#1086#1078#1076#1077#1085#1080#1080'][2][4][0]'
              Appointment = 4
            end
          end
          object Panel48: TPanel
            Left = 5
            Top = 192
            Width = 697
            Height = 29
            Align = alTop
            TabOrder = 10
            object Label31: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 167
              Height = 21
              Align = alLeft
              Caption = #1054#1094#1077#1085#1082#1072' '#1087#1086' '#1096#1082#1072#1083#1077' '#1040#1055#1043#1040#1056', '#1073#1072#1083#1083#1086#1074
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object RichEditSpec31: TRichEditSpec
              AlignWithMargins = True
              Left = 177
              Top = 4
              Width = 516
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1040#1055#1043#1040#1056'][2][4][0]')
              TabOrder = 0
              OnChange = RichEditChanged
              FieldName = #1040#1055#1043#1040#1056
              FieldType = 2
              TextData = '['#1040#1055#1043#1040#1056'][2][4][0]'
              Appointment = 4
            end
          end
          object Panel44: TPanel
            Left = 5
            Top = 221
            Width = 697
            Height = 29
            Align = alTop
            TabOrder = 11
            object Label19: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 67
              Height = 21
              Align = alLeft
              Caption = #1061#1086#1076#1080#1090' '#1089', '#1084#1077#1089'.'
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object RichEditSpec27: TRichEditSpec
              AlignWithMargins = True
              Left = 77
              Top = 4
              Width = 616
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1061#1086#1076#1080#1090#1057'][2][4][0]')
              TabOrder = 0
              OnChange = RichEditChanged
              FieldName = #1061#1086#1076#1080#1090#1057
              FieldType = 2
              TextData = '['#1061#1086#1076#1080#1090#1057'][2][4][0]'
              Appointment = 4
            end
          end
        end
        object GroupBox7: TGroupBox
          Left = 3
          Top = 1475
          Width = 707
          Height = 250
          Align = alTop
          Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090#1099' '#1084#1077#1076#1080#1094#1080#1085#1089#1082#1086#1075#1086' '#1086#1073#1089#1083#1077#1076#1086#1074#1072#1085#1080#1077#1103
          Padding.Left = 3
          Padding.Top = 3
          Padding.Right = 3
          Padding.Bottom = 3
          TabOrder = 5
          object Panel56: TPanel
            Left = 5
            Top = 18
            Width = 697
            Height = 29
            Align = alTop
            TabOrder = 0
            object Label39: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 133
              Height = 21
              Align = alLeft
              Caption = #1057#1090#1086#1084#1072#1090#1080#1095#1077#1089#1082#1086#1077' '#1089#1086#1089#1090#1086#1103#1085#1080#1077
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object SpeedButton10: TSpeedButton
              AlignWithMargins = True
              Left = 670
              Top = 4
              Width = 23
              Height = 21
              Align = alRight
              Glyph.Data = {
                E6000000424DE60000000000000076000000280000000E0000000E0000000100
                0400000000007000000000000000000000001000000000000000000000000000
                BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
                FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
                3300333333333333330033333333333333003333300033333300333330F03333
                3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
                3300333330F033333300333330F0333333003333300033333300333333333333
                33003333333333333300}
              OnClick = SpeedButton10Click
              ExplicitLeft = 629
            end
            object RichEditSpec39: TRichEditSpec
              AlignWithMargins = True
              Left = 143
              Top = 4
              Width = 521
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1057#1086#1084#1072#1090#1080#1095#1077#1089#1082#1086#1077#1057#1086#1089#1090#1086#1103#1085#1080#1077'][1][0][62]')
              TabOrder = 0
              OnChange = RichEditChanged
              OnExit = RichEditSpecExit
              OnKeyDown = RichEditSpecKeyDown
              OnKeyPress = RichEditSpecKeyPress
              OnKeyUp = RichEditSpecKeyUp
              FieldName = #1057#1086#1084#1072#1090#1080#1095#1077#1089#1082#1086#1077#1057#1086#1089#1090#1086#1103#1085#1080#1077
              FieldType = 1
              TextData = '['#1057#1086#1084#1072#1090#1080#1095#1077#1089#1082#1086#1077#1057#1086#1089#1090#1086#1103#1085#1080#1077'][1][0][62]'
              ListID = 62
              Appointment = 4
            end
          end
          object Panel3: TPanel
            Left = 5
            Top = 47
            Width = 697
            Height = 29
            Align = alTop
            TabOrder = 1
            object Label40: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 112
              Height = 21
              Align = alLeft
              Caption = 'DS '#1085#1077#1074#1088#1086#1083#1086#1075#1072', '#1052#1050#1041' 10'
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object SpeedButton11: TSpeedButton
              AlignWithMargins = True
              Left = 670
              Top = 4
              Width = 23
              Height = 21
              Align = alRight
              Glyph.Data = {
                E6000000424DE60000000000000076000000280000000E0000000E0000000100
                0400000000007000000000000000000000001000000000000000000000000000
                BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
                FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
                3300333333333333330033333333333333003333300033333300333330F03333
                3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
                3300333330F033333300333330F0333333003333300033333300333333333333
                33003333333333333300}
              OnClick = SpeedButton11Click
              ExplicitLeft = 625
            end
            object RichEditSpec40: TRichEditSpec
              AlignWithMargins = True
              Left = 122
              Top = 4
              Width = 542
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1044#1080#1072#1075#1085#1086#1079#1053#1077#1074#1088#1086#1083#1086#1075#1072'][1][0][39]')
              TabOrder = 0
              OnChange = RichEditChanged
              OnExit = RichEditSpecExit
              OnKeyDown = RichEditSpecKeyDown
              OnKeyPress = RichEditSpecKeyPress
              OnKeyUp = RichEditSpecKeyUp
              FieldName = #1044#1080#1072#1075#1085#1086#1079#1053#1077#1074#1088#1086#1083#1086#1075#1072
              FieldType = 1
              TextData = '['#1044#1080#1072#1075#1085#1086#1079#1053#1077#1074#1088#1086#1083#1086#1075#1072'][1][0][39]'
              ListID = 39
              Appointment = 4
            end
          end
          object Panel4: TPanel
            Left = 5
            Top = 197
            Width = 697
            Height = 29
            Align = alTop
            TabOrder = 5
            object Label41: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 89
              Height = 21
              Align = alLeft
              Caption = #1044#1086#1087'. '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1103
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object RichEditSpec41: TRichEditSpec
              AlignWithMargins = True
              Left = 99
              Top = 4
              Width = 594
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1052#1077#1076#1044#1086#1087#1048#1085#1092#1086'][1][4][0]')
              TabOrder = 0
              OnChange = RichEditChanged
              FieldName = #1052#1077#1076#1044#1086#1087#1048#1085#1092#1086
              FieldType = 1
              TextData = '['#1052#1077#1076#1044#1086#1087#1048#1085#1092#1086'][1][4][0]'
              Appointment = 4
            end
          end
          object Panel5: TPanel
            Left = 5
            Top = 168
            Width = 697
            Height = 29
            Align = alTop
            TabOrder = 4
            object Label42: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 139
              Height = 21
              Align = alLeft
              Caption = #1047#1072#1082#1083#1102#1095#1077#1085#1080#1077' '#1086#1092#1090#1072#1083#1100#1084#1086#1083#1086#1075#1072
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object SpeedButton14: TSpeedButton
              AlignWithMargins = True
              Left = 670
              Top = 4
              Width = 23
              Height = 21
              Align = alRight
              Glyph.Data = {
                E6000000424DE60000000000000076000000280000000E0000000E0000000100
                0400000000007000000000000000000000001000000000000000000000000000
                BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
                FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
                3300333333333333330033333333333333003333300033333300333330F03333
                3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
                3300333330F033333300333330F0333333003333300033333300333333333333
                33003333333333333300}
              OnClick = SpeedButton14Click
              ExplicitLeft = 637
            end
            object RichEditSpec42: TRichEditSpec
              AlignWithMargins = True
              Left = 149
              Top = 4
              Width = 515
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1054#1092#1090#1072#1083#1100#1084#1086#1083#1086#1075'][1][0][62]')
              TabOrder = 0
              OnChange = RichEditChanged
              OnExit = RichEditSpecExit
              OnKeyDown = RichEditSpecKeyDown
              OnKeyPress = RichEditSpecKeyPress
              OnKeyUp = RichEditSpecKeyUp
              FieldName = #1054#1092#1090#1072#1083#1100#1084#1086#1083#1086#1075
              FieldType = 1
              TextData = '['#1054#1092#1090#1072#1083#1100#1084#1086#1083#1086#1075'][1][0][62]'
              ListID = 62
              Appointment = 4
            end
          end
          object Panel6: TPanel
            Left = 5
            Top = 139
            Width = 697
            Height = 29
            Align = alTop
            TabOrder = 3
            object Label43: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 148
              Height = 21
              Align = alLeft
              Caption = #1047#1072#1082#1083#1102#1095#1077#1085#1080#1077' '#1086#1090#1086#1083#1072#1088#1080#1085#1075#1086#1083#1086#1075#1072
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object SpeedButton13: TSpeedButton
              AlignWithMargins = True
              Left = 670
              Top = 4
              Width = 23
              Height = 21
              Align = alRight
              Glyph.Data = {
                E6000000424DE60000000000000076000000280000000E0000000E0000000100
                0400000000007000000000000000000000001000000000000000000000000000
                BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
                FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
                3300333333333333330033333333333333003333300033333300333330F03333
                3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
                3300333330F033333300333330F0333333003333300033333300333333333333
                33003333333333333300}
              OnClick = SpeedButton13Click
              ExplicitLeft = 678
              ExplicitTop = 6
            end
            object RichEditSpec43: TRichEditSpec
              AlignWithMargins = True
              Left = 158
              Top = 4
              Width = 506
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1054#1090#1086#1083#1072#1088#1080#1085#1075#1086#1083#1086#1075'][1][0][62]')
              TabOrder = 0
              OnChange = RichEditChanged
              OnExit = RichEditSpecExit
              OnKeyDown = RichEditSpecKeyDown
              OnKeyPress = RichEditSpecKeyPress
              OnKeyUp = RichEditSpecKeyUp
              FieldName = #1054#1090#1086#1083#1072#1088#1080#1085#1075#1086#1083#1086#1075
              FieldType = 1
              TextData = '['#1054#1090#1086#1083#1072#1088#1080#1085#1075#1086#1083#1086#1075'][1][0][62]'
              ListID = 62
              Appointment = 4
            end
          end
          object Panel55: TPanel
            Left = 5
            Top = 76
            Width = 697
            Height = 63
            Align = alTop
            Constraints.MinHeight = 57
            TabOrder = 2
            object Label38: TLabel
              Tag = 3
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 173
              Height = 55
              Align = alLeft
              Caption = #1047#1072#1082#1083#1102#1095#1077#1085#1080#1077'  '#1084#1077#1076#1080#1082#1086'-'#1075#1077#1085#1077#1090#1080#1095#1077#1089#1082#1086#1077' '#1082#1086#1085#1089#1091#1083#1100#1090#1072#1094#1080#1080' '#1087#1088#1080' '#1085#1077#1086#1073#1093#1086#1076#1080#1084#1086#1089#1090#1080
              Color = clBtnFace
              ParentColor = False
              Layout = tlCenter
              WordWrap = True
              ExplicitHeight = 39
            end
            object SpeedButton12: TSpeedButton
              AlignWithMargins = True
              Left = 670
              Top = 4
              Width = 23
              Height = 55
              Align = alRight
              Glyph.Data = {
                E6000000424DE60000000000000076000000280000000E0000000E0000000100
                0400000000007000000000000000000000001000000000000000000000000000
                BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
                FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
                3300333333333333330033333333333333003333300033333300333330F03333
                3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
                3300333330F033333300333330F0333333003333300033333300333333333333
                33003333333333333300}
              OnClick = SpeedButton12Click
              ExplicitLeft = 625
            end
            object RichEditSpec38: TRichEditSpec
              AlignWithMargins = True
              Left = 183
              Top = 4
              Width = 481
              Height = 55
              Align = alClient
              Lines.Strings = (
                '['#1052#1043#1050#1086#1085#1089'][1][0][62]')
              TabOrder = 0
              OnChange = RichEditChanged
              OnExit = RichEditSpecExit
              OnKeyDown = RichEditSpecKeyDown
              OnKeyPress = RichEditSpecKeyPress
              OnKeyUp = RichEditSpecKeyUp
              FieldName = #1052#1043#1050#1086#1085#1089
              FieldType = 1
              TextData = '['#1052#1043#1050#1086#1085#1089'][1][0][62]'
              ListID = 62
              Appointment = 4
            end
          end
        end
        object GroupBox16: TGroupBox
          AlignWithMargins = True
          Left = 6
          Top = 326
          Width = 701
          Height = 183
          Margins.Top = 10
          Align = alTop
          Caption = #1054#1073#1089#1083#1077#1076#1086#1074#1072#1085#1080#1077
          TabOrder = 2
          object Panel20: TPanel
            Left = 2
            Top = 15
            Width = 697
            Height = 29
            Align = alTop
            TabOrder = 0
            object Label8: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 175
              Height = 13
              Align = alLeft
              Caption = #1050#1077#1084' '#1085#1072#1087#1088#1072#1074#1083#1077#1085' '#1085#1072' '#1082#1086#1085#1089#1091#1083#1100#1090#1072#1094#1080#1102': '
              Layout = tlCenter
            end
            object ComboBoxSpec2: TComboBoxSpec
              AlignWithMargins = True
              Left = 185
              Top = 4
              Width = 168
              Height = 21
              Align = alLeft
              ItemHeight = 0
              TabOrder = 0
              Text = '['#1050#1077#1084#1053#1072#1087#1088#1072#1074#1083#1077#1085'][5][4][27]'
              OnSelect = ComboBoxSpecSelect
              OnAfterSetItemID = ComboBoxChanged
              OnMouseWheelUp = ComboBoxSpecMouseWheelUp
              OnMouseWheelDown = ComboBoxSpecMouseWheelDown
              FieldName = #1050#1077#1084#1053#1072#1087#1088#1072#1074#1083#1077#1085
              FieldType = 5
              ParentID = 27
              Appointment = 4
              ListID = 1
            end
            object EditSpec6: TEditSpec
              AlignWithMargins = True
              Left = 359
              Top = 4
              Width = 334
              Height = 21
              Align = alClient
              TabOrder = 1
              Text = '['#1050#1077#1084#1053#1072#1087#1088#1072#1074#1083#1077#1085#1044#1088#1091#1075#1086#1077'][1][4][0]'
              OnChange = EditChanged
              FieldName = #1050#1077#1084#1053#1072#1087#1088#1072#1074#1083#1077#1085#1044#1088#1091#1075#1086#1077
              FieldType = 1
              TextData = '['#1050#1077#1084#1053#1072#1087#1088#1072#1074#1083#1077#1085#1044#1088#1091#1075#1086#1077'][1][4][0]'
              Appointment = 4
            end
          end
          object Panel21: TPanel
            Left = 2
            Top = 44
            Width = 697
            Height = 29
            Align = alTop
            TabOrder = 1
            object Label9: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 108
              Height = 13
              Align = alLeft
              Caption = #1044#1072#1090#1072' '#1086#1073#1089#1083#1077#1076#1086#1074#1072#1085#1080#1103': '
              Layout = tlCenter
            end
            object DateTimePickerSpec3: TDateTimePickerSpec
              AlignWithMargins = True
              Left = 118
              Top = 4
              Width = 95
              Height = 21
              Align = alLeft
              Date = 41464.501961585650000000
              Time = 41464.501961585650000000
              TabOrder = 0
              OnChange = DateTimePickerSpecSetFormat
              OnKeyDown = DateTimePickerSpecKeyDown
              FieldName = #1055#1088#1077#1076#1044#1072#1090#1072#1054#1073#1089#1083#1077#1076#1086#1074#1072#1085#1080#1103
              FieldType = 3
              TextData = '09.07.2013'
              Appointment = 4
            end
          end
          object Panel23: TPanel
            Left = 2
            Top = 73
            Width = 697
            Height = 29
            Align = alTop
            TabOrder = 2
            object Label128: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 20
              Height = 21
              Align = alLeft
              Caption = 'DS: '
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object SpeedButton2: TSpeedButton
              Left = 673
              Top = 1
              Width = 23
              Height = 27
              Align = alRight
              Glyph.Data = {
                E6000000424DE60000000000000076000000280000000E0000000E0000000100
                0400000000007000000000000000000000001000000000000000000000000000
                BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
                FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
                3300333333333333330033333333333333003333300033333300333330F03333
                3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
                3300333330F033333300333330F0333333003333300033333300333333333333
                33003333333333333300}
              OnClick = SpeedButton2Click
              ExplicitLeft = 649
              ExplicitTop = -3
              ExplicitHeight = 21
            end
            object RichEditSpec3: TRichEditSpec
              AlignWithMargins = True
              Left = 30
              Top = 4
              Width = 640
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1053#1072#1095#1072#1083#1100#1085#1099#1081#1044#1080#1072#1075#1085#1086#1079'][1][0][39]')
              TabOrder = 0
              OnChange = RichEditChanged
              OnExit = RichEditSpecExit
              OnKeyDown = RichEditSpecKeyDown
              OnKeyPress = RichEditSpecKeyPress
              OnKeyUp = RichEditSpecKeyUp
              FieldName = #1053#1072#1095#1072#1083#1100#1085#1099#1081#1044#1080#1072#1075#1085#1086#1079
              FieldType = 1
              TextData = '['#1053#1072#1095#1072#1083#1100#1085#1099#1081#1044#1080#1072#1075#1085#1086#1079'][1][0][39]'
              ListID = 39
              Appointment = 4
            end
          end
          object Panel27: TPanel
            Left = 2
            Top = 102
            Width = 697
            Height = 29
            Align = alTop
            TabOrder = 3
            object Label13: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 99
              Height = 21
              Align = alLeft
              Caption = #1050#1072#1090#1077#1075#1086#1088#1080#1080' '#1088#1077#1073#1105#1085#1082#1072
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object SpeedButton3: TSpeedButton
              Left = 673
              Top = 1
              Width = 23
              Height = 27
              Align = alRight
              Glyph.Data = {
                E6000000424DE60000000000000076000000280000000E0000000E0000000100
                0400000000007000000000000000000000001000000000000000000000000000
                BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
                FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
                3300333333333333330033333333333333003333300033333300333330F03333
                3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
                3300333330F033333300333330F0333333003333300033333300333333333333
                33003333333333333300}
              OnClick = SpeedButton3Click
              ExplicitLeft = 752
              ExplicitTop = -4
              ExplicitHeight = 21
            end
            object RichEditSpec6: TRichEditSpec
              AlignWithMargins = True
              Left = 109
              Top = 4
              Width = 561
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1050#1072#1090#1077#1075#1086#1088#1080#1080#1056#1077#1073#1077#1085#1082#1072'][1][0][62]')
              TabOrder = 0
              OnChange = RichEditChanged
              OnExit = RichEditSpecExit
              OnKeyDown = RichEditSpecKeyDown
              OnKeyPress = RichEditSpecKeyPress
              OnKeyUp = RichEditSpecKeyUp
              FieldName = #1050#1072#1090#1077#1075#1086#1088#1080#1080#1056#1077#1073#1077#1085#1082#1072
              FieldType = 1
              TextData = '['#1050#1072#1090#1077#1075#1086#1088#1080#1080#1056#1077#1073#1077#1085#1082#1072'][1][0][62]'
              ListID = 62
              Appointment = 4
            end
          end
          object Panel22: TPanel
            Left = 2
            Top = 131
            Width = 697
            Height = 29
            Align = alTop
            TabOrder = 4
            object Label15: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 42
              Height = 21
              Align = alLeft
              Caption = #1050#1072#1090#1072#1083#1086#1075
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object SpeedButton4: TSpeedButton
              Left = 673
              Top = 1
              Width = 23
              Height = 27
              Align = alRight
              Glyph.Data = {
                E6000000424DE60000000000000076000000280000000E0000000E0000000100
                0400000000007000000000000000000000001000000000000000000000000000
                BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
                FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
                3300333333333333330033333333333333003333300033333300333330F03333
                3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
                3300333330F033333300333330F0333333003333300033333300333333333333
                33003333333333333300}
              OnClick = SpeedButton4Click
              ExplicitLeft = 736
              ExplicitTop = 5
              ExplicitHeight = 21
            end
            object RichEditSpec9: TRichEditSpec
              AlignWithMargins = True
              Left = 52
              Top = 4
              Width = 618
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1050#1072#1090#1072#1083#1086#1075'][1][4][0]')
              TabOrder = 0
              OnChange = RichEditChanged
              FieldName = #1050#1072#1090#1072#1083#1086#1075
              FieldType = 1
              TextData = '['#1050#1072#1090#1072#1083#1086#1075'][1][4][0]'
              Appointment = 4
            end
          end
        end
      end
    end
    object TabSheet1: TTabSheet
      Caption = #1054#1089#1084#1086#1088#1090' '#1085#1077#1074#1088#1086#1083#1086#1075#1072
      ImageIndex = -1
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object ScrollBox2: TScrollBox
        Left = 0
        Top = 0
        Width = 734
        Height = 590
        Align = alClient
        TabOrder = 0
        OnMouseWheel = ScrollBoxMouseWheel
        object GroupBox8: TGroupBox
          Left = 0
          Top = 0
          Width = 713
          Height = 786
          Align = alTop
          Caption = #1053#1077#1074#1088#1086#1083#1086#1075#1080#1095#1077#1089#1082#1080#1081' '#1089#1090#1072#1090#1091#1089
          TabOrder = 0
          object GroupBox9: TGroupBox
            Left = 2
            Top = 595
            Width = 709
            Height = 87
            Align = alTop
            Caption = #1057#1080#1083#1072' '#1084#1099#1096#1094
            Padding.Left = 3
            Padding.Top = 3
            Padding.Right = 3
            Padding.Bottom = 3
            TabOrder = 19
            object Panel77: TPanel
              Left = 5
              Top = 18
              Width = 699
              Height = 29
              Align = alTop
              TabOrder = 0
              object Label64: TLabel
                AlignWithMargins = True
                Left = 4
                Top = 4
                Width = 119
                Height = 21
                Align = alLeft
                Caption = #1042' '#1074#1077#1088#1093#1085#1080#1093' '#1082#1086#1085#1077#1095#1085#1086#1089#1090#1103#1093
                Layout = tlCenter
                ExplicitHeight = 13
              end
              object Label61: TLabel
                AlignWithMargins = True
                Left = 295
                Top = 4
                Width = 36
                Height = 21
                Align = alLeft
                Caption = #1073#1072#1083#1083#1086#1074
                Layout = tlCenter
                ExplicitHeight = 13
              end
              object RichEditSpec54: TRichEditSpec
                AlignWithMargins = True
                Left = 129
                Top = 4
                Width = 160
                Height = 21
                Align = alLeft
                Lines.Strings = (
                  '['#1053#1077#1074#1088#1086#1083#1086#1075#1057#1080#1083#1072#1042#1077#1088#1093'][2][1][0]')
                TabOrder = 0
                OnChange = RichEditChanged
                FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1057#1080#1083#1072#1042#1077#1088#1093
                FieldType = 2
                TextData = '['#1053#1077#1074#1088#1086#1083#1086#1075#1057#1080#1083#1072#1042#1077#1088#1093'][2][1][0]'
                Appointment = 1
              end
            end
            object Panel76: TPanel
              Left = 5
              Top = 47
              Width = 699
              Height = 29
              Align = alTop
              TabOrder = 1
              object Label63: TLabel
                AlignWithMargins = True
                Left = 4
                Top = 4
                Width = 115
                Height = 21
                Align = alLeft
                Caption = #1042' '#1085#1080#1078#1085#1080#1093' '#1082#1086#1085#1077#1095#1085#1086#1089#1090#1103#1093
                Layout = tlCenter
                ExplicitHeight = 13
              end
              object Label62: TLabel
                AlignWithMargins = True
                Left = 291
                Top = 4
                Width = 36
                Height = 21
                Align = alLeft
                Caption = #1073#1072#1083#1083#1086#1074
                Layout = tlCenter
                ExplicitHeight = 13
              end
              object RichEditSpec53: TRichEditSpec
                AlignWithMargins = True
                Left = 125
                Top = 4
                Width = 160
                Height = 21
                Align = alLeft
                Lines.Strings = (
                  '['#1053#1077#1074#1088#1086#1083#1086#1075#1057#1080#1083#1072#1053#1080#1079'][2][1][0]')
                TabOrder = 0
                OnChange = RichEditChanged
                FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1057#1080#1083#1072#1053#1080#1079
                FieldType = 2
                TextData = '['#1053#1077#1074#1088#1086#1083#1086#1075#1057#1080#1083#1072#1053#1080#1079'][2][1][0]'
                Appointment = 1
              end
            end
          end
          object GroupBox10: TGroupBox
            Left = 2
            Top = 682
            Width = 709
            Height = 95
            Align = alTop
            Caption = #1057#1091#1093#1086#1078#1080#1083#1100#1085#1099#1077' '#1088#1077#1092#1083#1077#1082#1089#1099
            Padding.Left = 3
            Padding.Top = 3
            Padding.Right = 3
            Padding.Bottom = 3
            TabOrder = 20
            object Panel81: TPanel
              Left = 5
              Top = 18
              Width = 699
              Height = 29
              Align = alTop
              TabOrder = 0
              object Label66: TLabel
                AlignWithMargins = True
                Left = 4
                Top = 4
                Width = 119
                Height = 21
                Align = alLeft
                Caption = #1042' '#1074#1077#1088#1093#1085#1080#1093' '#1082#1086#1085#1077#1095#1085#1086#1089#1090#1103#1093
                Layout = tlCenter
                ExplicitHeight = 13
              end
              object RichEditSpec56: TRichEditSpec
                AlignWithMargins = True
                Left = 300
                Top = 4
                Width = 395
                Height = 21
                Align = alClient
                Lines.Strings = (
                  '['#1053#1077#1074#1088#1086#1083#1086#1075#1057#1091#1093#1086#1078#1042#1077#1088#1093#1044#1086#1087'][1][1][0]')
                TabOrder = 1
                OnChange = RichEditChanged
                FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1057#1091#1093#1086#1078#1042#1077#1088#1093#1044#1086#1087
                FieldType = 1
                TextData = '['#1053#1077#1074#1088#1086#1083#1086#1075#1057#1091#1093#1086#1078#1042#1077#1088#1093#1044#1086#1087'][1][1][0]'
                Appointment = 1
              end
              object ComboBoxSpec27: TComboBoxSpec
                AlignWithMargins = True
                Left = 129
                Top = 4
                Width = 165
                Height = 21
                Align = alLeft
                ItemHeight = 0
                TabOrder = 0
                Text = '['#1053#1077#1074#1088#1086#1083#1086#1075#1057#1091#1093#1086#1078#1042#1077#1088#1093'][5][1][64]'
                OnSelect = ComboBoxSpecSelect
                OnAfterSetItemID = ComboBoxChanged
                OnMouseWheelUp = ComboBoxSpecMouseWheelUp
                OnMouseWheelDown = ComboBoxSpecMouseWheelDown
                FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1057#1091#1093#1086#1078#1042#1077#1088#1093
                FieldType = 5
                ParentID = 64
                Appointment = 1
                ListID = 1
              end
            end
            object Panel82: TPanel
              Left = 5
              Top = 47
              Width = 699
              Height = 29
              Align = alTop
              TabOrder = 1
              object Label67: TLabel
                AlignWithMargins = True
                Left = 4
                Top = 4
                Width = 115
                Height = 21
                Align = alLeft
                Caption = #1042' '#1085#1080#1078#1085#1080#1093' '#1082#1086#1085#1077#1095#1085#1086#1089#1090#1103#1093
                Layout = tlCenter
                ExplicitHeight = 13
              end
              object RichEditSpec57: TRichEditSpec
                AlignWithMargins = True
                Left = 296
                Top = 4
                Width = 399
                Height = 21
                Align = alClient
                Lines.Strings = (
                  '['#1053#1077#1074#1088#1086#1083#1086#1075#1057#1091#1093#1086#1078#1053#1080#1079#1044#1086#1087'][1][1][0]')
                TabOrder = 1
                OnChange = RichEditChanged
                FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1057#1091#1093#1086#1078#1053#1080#1079#1044#1086#1087
                FieldType = 1
                TextData = '['#1053#1077#1074#1088#1086#1083#1086#1075#1057#1091#1093#1086#1078#1053#1080#1079#1044#1086#1087'][1][1][0]'
                Appointment = 1
              end
              object ComboBoxSpec28: TComboBoxSpec
                AlignWithMargins = True
                Left = 125
                Top = 4
                Width = 165
                Height = 21
                Align = alLeft
                ItemHeight = 0
                TabOrder = 0
                Text = '['#1053#1077#1074#1088#1086#1083#1086#1075#1057#1091#1093#1086#1078#1053#1080#1079'][5][1][64]'
                OnSelect = ComboBoxSpecSelect
                OnAfterSetItemID = ComboBoxChanged
                OnMouseWheelUp = ComboBoxSpecMouseWheelUp
                OnMouseWheelDown = ComboBoxSpecMouseWheelDown
                FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1057#1091#1093#1086#1078#1053#1080#1079
                FieldType = 5
                ParentID = 64
                Appointment = 1
                ListID = 64
              end
            end
          end
          object Panel58: TPanel
            Left = 2
            Top = 73
            Width = 709
            Height = 29
            Align = alTop
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 2
            object Label46: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 181
              Height = 13
              Align = alLeft
              Caption = #1042#1077#1085#1086#1079#1085#1072#1103' '#1089#1077#1090#1100' '#1085#1072' '#1075#1086#1083#1086#1074#1077' '#1074#1099#1088#1072#1078#1077#1085#1072
              Layout = tlCenter
            end
            object ComboBoxSpec10: TComboBoxSpec
              AlignWithMargins = True
              Left = 191
              Top = 4
              Width = 144
              Height = 21
              Align = alLeft
              ItemHeight = 0
              TabOrder = 0
              Text = '['#1053#1077#1074#1088#1086#1083#1086#1075#1042#1099#1088#1072#1078#1077#1085#1085#1072#1103#1042#1077#1085#1086#1079#1085#1072#1103#1057#1077#1090#1100'][5][1][45]'
              OnSelect = ComboBoxSpecSelect
              OnAfterSetItemID = ComboBoxChanged
              OnMouseWheelUp = ComboBoxSpecMouseWheelUp
              OnMouseWheelDown = ComboBoxSpecMouseWheelDown
              FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1042#1099#1088#1072#1078#1077#1085#1085#1072#1103#1042#1077#1085#1086#1079#1085#1072#1103#1057#1077#1090#1100
              FieldType = 5
              ParentID = 45
              Appointment = 1
              ListID = 1
            end
          end
          object Panel59: TPanel
            Left = 2
            Top = 276
            Width = 709
            Height = 29
            Align = alTop
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 9
            object Label47: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 41
              Height = 13
              Align = alLeft
              Caption = #1053#1080#1089#1090#1072#1075#1084
              Layout = tlCenter
            end
            object ComboBoxSpec14: TComboBoxSpec
              AlignWithMargins = True
              Left = 51
              Top = 4
              Width = 144
              Height = 21
              Align = alLeft
              ItemHeight = 0
              TabOrder = 0
              Text = '['#1053#1077#1074#1088#1086#1083#1086#1075#1053#1080#1089#1090#1072#1075#1084'][5][1][45]'
              OnSelect = ComboBoxSpecSelect
              OnAfterSetItemID = ComboBoxChanged
              OnMouseWheelUp = ComboBoxSpecMouseWheelUp
              OnMouseWheelDown = ComboBoxSpecMouseWheelDown
              FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1053#1080#1089#1090#1072#1075#1084
              FieldType = 5
              ParentID = 45
              Appointment = 1
              ListID = 1
            end
          end
          object Panel60: TPanel
            Left = 2
            Top = 218
            Width = 709
            Height = 29
            Align = alTop
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 7
            object Label48: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 130
              Height = 21
              Align = alLeft
              Caption = #1044#1074#1080#1078#1077#1085#1080#1077' '#1075#1083#1072#1079#1085#1099#1093' '#1103#1073#1083#1086#1082
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object ComboBoxSpec13: TComboBoxSpec
              AlignWithMargins = True
              Left = 140
              Top = 4
              Width = 144
              Height = 21
              Align = alLeft
              ItemHeight = 0
              TabOrder = 0
              Text = '['#1053#1077#1074#1088#1086#1083#1086#1075#1044#1074#1080#1078#1077#1085#1080#1077#1043#1083#1072#1079#1085#1099#1093#1071#1073#1083#1086#1082'][5][1][48]'
              OnSelect = ComboBoxSpecSelect
              OnAfterSetItemID = ComboBoxChanged
              OnMouseWheelUp = ComboBoxSpecMouseWheelUp
              OnMouseWheelDown = ComboBoxSpecMouseWheelDown
              FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1044#1074#1080#1078#1077#1085#1080#1077#1043#1083#1072#1079#1085#1099#1093#1071#1073#1083#1086#1082
              FieldType = 5
              ParentID = 48
              Appointment = 1
              ListID = 1
            end
            object RichEditSpec21: TRichEditSpec
              AlignWithMargins = True
              Left = 290
              Top = 4
              Width = 415
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1053#1077#1074#1088#1086#1083#1086#1075#1044#1074#1080#1078#1077#1085#1080#1077#1043#1083#1072#1079#1085#1099#1093#1071#1073#1083#1086#1082#1044#1088#1091#1075#1086#1077'][1][1][0]')
              TabOrder = 1
              OnChange = RichEditChanged
              FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1044#1074#1080#1078#1077#1085#1080#1077#1043#1083#1072#1079#1085#1099#1093#1071#1073#1083#1086#1082#1044#1088#1091#1075#1086#1077
              FieldType = 1
              TextData = '['#1053#1077#1074#1088#1086#1083#1086#1075#1044#1074#1080#1078#1077#1085#1080#1077#1043#1083#1072#1079#1085#1099#1093#1071#1073#1083#1086#1082#1044#1088#1091#1075#1086#1077'][1][1][0]'
              Appointment = 1
            end
          end
          object Panel61: TPanel
            Left = 2
            Top = 189
            Width = 709
            Height = 29
            Align = alTop
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 6
            object Label49: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 137
              Height = 13
              Align = alLeft
              Caption = #1043#1083#1072#1079#1085#1099#1077' '#1097#1077#1083#1080' '#1089#1080#1084#1077#1090#1088#1080#1095#1085#1099
              Layout = tlCenter
            end
            object ComboBoxSpec12: TComboBoxSpec
              AlignWithMargins = True
              Left = 147
              Top = 4
              Width = 144
              Height = 21
              Align = alLeft
              ItemHeight = 0
              TabOrder = 0
              Text = '['#1053#1077#1074#1088#1086#1083#1086#1075#1043#1083#1072#1079#1085#1099#1077#1065#1077#1083#1080#1057#1080#1084#1084#1077#1090#1088#1080#1095#1085#1099'][5][1][45]'
              OnSelect = ComboBoxSpecSelect
              OnAfterSetItemID = ComboBoxChanged
              OnMouseWheelUp = ComboBoxSpecMouseWheelUp
              OnMouseWheelDown = ComboBoxSpecMouseWheelDown
              FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1043#1083#1072#1079#1085#1099#1077#1065#1077#1083#1080#1057#1080#1084#1084#1077#1090#1088#1080#1095#1085#1099
              FieldType = 5
              ParentID = 45
              Appointment = 1
              ListID = 1
            end
          end
          object Panel63: TPanel
            Left = 2
            Top = 131
            Width = 709
            Height = 29
            Align = alTop
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 4
            object Label51: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 100
              Height = 13
              Align = alLeft
              Caption = #1047#1088#1072#1095#1082#1080' '#1089#1080#1084#1077#1090#1088#1080#1095#1085#1099
              Layout = tlCenter
            end
            object ComboBoxSpec11: TComboBoxSpec
              AlignWithMargins = True
              Left = 110
              Top = 4
              Width = 144
              Height = 21
              Align = alLeft
              ItemHeight = 0
              TabOrder = 0
              Text = '['#1053#1077#1074#1088#1086#1083#1086#1075#1047#1088#1072#1095#1082#1080#1057#1080#1084#1084#1077#1090#1088#1080#1095#1085#1099'][5][1][45]'
              OnSelect = ComboBoxSpecSelect
              OnAfterSetItemID = ComboBoxChanged
              OnMouseWheelUp = ComboBoxSpecMouseWheelUp
              OnMouseWheelDown = ComboBoxSpecMouseWheelDown
              FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1047#1088#1072#1095#1082#1080#1057#1080#1084#1084#1077#1090#1088#1080#1095#1085#1099
              FieldType = 5
              ParentID = 45
              Appointment = 1
              ListID = 1
            end
          end
          object Panel64: TPanel
            Left = 2
            Top = 102
            Width = 709
            Height = 29
            Align = alTop
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 3
            object Label135: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 77
              Height = 21
              Align = alLeft
              Caption = #1047#1088#1072#1095#1082#1080' '#1056#1072#1074#1085#1099#1077
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object RichEditSpec46: TRichEditSpec
              AlignWithMargins = True
              Left = 87
              Top = 4
              Width = 618
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1053#1077#1074#1088#1086#1083#1086#1075#1047#1088#1072#1095#1082#1080#1056#1072#1074#1085#1099#1077'][1][1][0]')
              TabOrder = 0
              OnChange = RichEditChanged
              FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1047#1088#1072#1095#1082#1080#1056#1072#1074#1085#1099#1077
              FieldType = 1
              TextData = '['#1053#1077#1074#1088#1086#1083#1086#1075#1047#1088#1072#1095#1082#1080#1056#1072#1074#1085#1099#1077'][1][1][0]'
              Appointment = 1
            end
          end
          object Panel65: TPanel
            Left = 2
            Top = 247
            Width = 709
            Height = 29
            Align = alTop
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 8
            object Label52: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 58
              Height = 13
              Align = alLeft
              Caption = #1050#1086#1089#1086#1075#1083#1072#1079#1080#1077
              Layout = tlCenter
            end
            object ComboBoxSpec15: TComboBoxSpec
              AlignWithMargins = True
              Left = 68
              Top = 4
              Width = 144
              Height = 21
              Align = alLeft
              ItemHeight = 0
              TabOrder = 0
              Text = '['#1053#1077#1074#1088#1086#1083#1086#1075#1050#1086#1089#1086#1075#1083#1072#1079#1080#1077'][5][1][45]'
              OnSelect = ComboBoxSpecSelect
              OnAfterSetItemID = ComboBoxChanged
              OnMouseWheelUp = ComboBoxSpecMouseWheelUp
              OnMouseWheelDown = ComboBoxSpecMouseWheelDown
              FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1050#1086#1089#1086#1075#1083#1072#1079#1080#1077
              FieldType = 5
              ParentID = 45
              Appointment = 1
              ListID = 1
            end
          end
          object Panel66: TPanel
            Left = 2
            Top = 160
            Width = 709
            Height = 29
            Align = alTop
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 5
            object Label53: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 73
              Height = 21
              Align = alLeft
              Caption = #1043#1083#1072#1079#1085#1099#1077' '#1097#1077#1083#1080
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object RichEditSpec23: TRichEditSpec
              AlignWithMargins = True
              Left = 83
              Top = 4
              Width = 622
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1053#1077#1074#1088#1086#1083#1086#1075#1043#1083#1072#1079#1085#1099#1077#1065#1077#1083#1080'][1][1][0]')
              TabOrder = 0
              OnChange = RichEditChanged
              FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1043#1083#1072#1079#1085#1099#1077#1065#1077#1083#1080
              FieldType = 1
              TextData = '['#1053#1077#1074#1088#1086#1083#1086#1075#1043#1083#1072#1079#1085#1099#1077#1065#1077#1083#1080'][1][1][0]'
              Appointment = 1
            end
          end
          object Panel67: TPanel
            Left = 2
            Top = 334
            Width = 709
            Height = 29
            Align = alTop
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 11
            object Label54: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 197
              Height = 21
              Align = alLeft
              Caption = #1050#1086#1085#1074#1077#1088#1075#1077#1085#1094#1080#1103' '#1080' '#1072#1082#1082#1086#1084#1086#1076#1072#1094#1080#1103' '#1089#1086#1093#1088#1072#1085#1099
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object Label50: TLabel
              AlignWithMargins = True
              Left = 358
              Top = 4
              Width = 4
              Height = 21
              Align = alLeft
              Caption = '/'
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object ComboBoxSpec16: TComboBoxSpec
              AlignWithMargins = True
              Left = 207
              Top = 4
              Width = 145
              Height = 21
              Align = alLeft
              ItemHeight = 0
              TabOrder = 0
              Text = '['#1053#1077#1074#1088#1086#1083#1086#1075#1050#1086#1085#1074#1077#1088#1075#1077#1085#1094#1080#1103'][5][1][52]'
              OnSelect = ComboBoxSpecSelect
              OnAfterSetItemID = ComboBoxChanged
              OnMouseWheelUp = ComboBoxSpecMouseWheelUp
              OnMouseWheelDown = ComboBoxSpecMouseWheelDown
              FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1050#1086#1085#1074#1077#1088#1075#1077#1085#1094#1080#1103
              FieldType = 5
              ParentID = 52
              Appointment = 1
              ListID = 1
            end
            object RichEditSpec24: TRichEditSpec
              AlignWithMargins = True
              Left = 368
              Top = 4
              Width = 337
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1053#1077#1074#1088#1086#1083#1086#1075#1050#1086#1085#1074#1077#1088#1075#1077#1085#1094#1080#1103#1044#1088#1091#1075#1086#1077'][1][1][0]')
              TabOrder = 1
              OnChange = RichEditChanged
              FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1050#1086#1085#1074#1077#1088#1075#1077#1085#1094#1080#1103#1044#1088#1091#1075#1086#1077
              FieldType = 1
              TextData = '['#1053#1077#1074#1088#1086#1083#1086#1075#1050#1086#1085#1074#1077#1088#1075#1077#1085#1094#1080#1103#1044#1088#1091#1075#1086#1077'][1][1][0]'
              Appointment = 1
            end
          end
          object Panel68: TPanel
            Left = 2
            Top = 479
            Width = 709
            Height = 29
            Align = alTop
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 15
            object Label55: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 26
              Height = 21
              Align = alLeft
              Caption = #1071#1079#1099#1082
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object SpeedButton17: TSpeedButton
              AlignWithMargins = True
              Left = 682
              Top = 4
              Width = 23
              Height = 21
              Align = alRight
              Glyph.Data = {
                E6000000424DE60000000000000076000000280000000E0000000E0000000100
                0400000000007000000000000000000000001000000000000000000000000000
                BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
                FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
                3300333333333333330033333333333333003333300033333300333330F03333
                3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
                3300333330F033333300333330F0333333003333300033333300333333333333
                33003333333333333300}
              OnClick = SpeedButton17Click
              ExplicitLeft = 643
              ExplicitTop = 1
            end
            object RichEditSpec35: TRichEditSpec
              AlignWithMargins = True
              Left = 36
              Top = 4
              Width = 640
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1053#1077#1074#1088#1086#1083#1086#1075#1071#1079#1099#1082'][1][0][62]')
              TabOrder = 0
              OnChange = RichEditChanged
              OnExit = RichEditSpecExit
              OnKeyDown = RichEditSpecKeyDown
              OnKeyPress = RichEditSpecKeyPress
              FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1071#1079#1099#1082
              FieldType = 1
              TextData = '['#1053#1077#1074#1088#1086#1083#1086#1075#1071#1079#1099#1082'][1][0][62]'
              ListID = 62
              Appointment = 1
            end
          end
          object Panel70: TPanel
            Left = 2
            Top = 421
            Width = 709
            Height = 29
            Align = alTop
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 14
            object Label57: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 99
              Height = 13
              Align = alLeft
              Caption = #1051#1080#1094#1086' '#1089#1080#1084#1084#1077#1090#1088#1080#1095#1085#1086#1077
              Layout = tlCenter
            end
            object ComboBoxSpec17: TComboBoxSpec
              AlignWithMargins = True
              Left = 109
              Top = 4
              Width = 150
              Height = 21
              Align = alLeft
              ItemHeight = 0
              TabOrder = 0
              Text = '['#1053#1077#1074#1088#1086#1083#1086#1075#1051#1080#1094#1086#1057#1080#1084#1084#1077#1090#1088#1080#1095#1085#1086#1077'][5][1][45]'
              OnSelect = ComboBoxSpecSelect
              OnAfterSetItemID = ComboBoxChanged
              OnMouseWheelUp = ComboBoxSpecMouseWheelUp
              OnMouseWheelDown = ComboBoxSpecMouseWheelDown
              FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1051#1080#1094#1086#1057#1080#1084#1084#1077#1090#1088#1080#1095#1085#1086#1077
              FieldType = 5
              ParentID = 45
              Appointment = 1
              ListID = 1
            end
          end
          object Panel71: TPanel
            Left = 2
            Top = 392
            Width = 709
            Height = 29
            Align = alTop
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 13
            object Label58: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 27
              Height = 21
              Align = alLeft
              Caption = 'VII n.'
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object RichEditSpec48: TRichEditSpec
              AlignWithMargins = True
              Left = 37
              Top = 4
              Width = 668
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1053#1077#1074#1088#1086#1083#1086#1075'8][1][1][0]')
              TabOrder = 0
              OnChange = RichEditChanged
              FieldName = #1053#1077#1074#1088#1086#1083#1086#1075'8'
              FieldType = 1
              TextData = '['#1053#1077#1074#1088#1086#1083#1086#1075'8][1][1][0]'
              Appointment = 1
            end
          end
          object Panel72: TPanel
            Left = 2
            Top = 363
            Width = 709
            Height = 29
            Align = alTop
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 12
            object Label59: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 49
              Height = 21
              Align = alLeft
              Caption = 'Vis OD/OS'
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object Splitter1: TSplitter
              Left = 222
              Top = 1
              Width = 11
              Height = 27
            end
            object RichEditSpec49: TRichEditSpec
              AlignWithMargins = True
              Left = 236
              Top = 4
              Width = 469
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1053#1077#1074#1088#1086#1083#1086#1075'OS][2][1][0]')
              TabOrder = 1
              OnChange = RichEditChanged
              FieldName = #1053#1077#1074#1088#1086#1083#1086#1075'OS'
              FieldType = 2
              TextData = '['#1053#1077#1074#1088#1086#1083#1086#1075'OS][2][1][0]'
              Appointment = 1
            end
            object RichEditSpec51: TRichEditSpec
              AlignWithMargins = True
              Left = 59
              Top = 4
              Width = 160
              Height = 21
              Align = alLeft
              Lines.Strings = (
                '['#1053#1077#1074#1088#1086#1083#1086#1075'OD][2][1][0]')
              TabOrder = 0
              OnChange = RichEditChanged
              FieldName = #1053#1077#1074#1088#1086#1083#1086#1075'OD'
              FieldType = 2
              TextData = '['#1053#1077#1074#1088#1086#1083#1086#1075'OD][2][1][0]'
              Appointment = 1
            end
          end
          object Panel73: TPanel
            Left = 2
            Top = 305
            Width = 709
            Height = 29
            Align = alTop
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 10
            object Label60: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 127
              Height = 21
              Align = alLeft
              Caption = #1056#1077#1072#1082#1094#1080#1103' '#1079#1088#1072#1095#1082#1086#1074' '#1085#1072' '#1089#1074#1077#1090
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object RichEditSpec50: TRichEditSpec
              AlignWithMargins = True
              Left = 137
              Top = 4
              Width = 568
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1053#1077#1074#1088#1086#1083#1086#1075#1056#1077#1072#1082#1094#1080#1103#1053#1072#1057#1074#1077#1090'][1][1][0]')
              TabOrder = 0
              OnChange = RichEditChanged
              FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1056#1077#1072#1082#1094#1080#1103#1053#1072#1057#1074#1077#1090
              FieldType = 1
              TextData = '['#1053#1077#1074#1088#1086#1083#1086#1075#1056#1077#1072#1082#1094#1080#1103#1053#1072#1057#1074#1077#1090'][1][1][0]'
              Appointment = 1
            end
          end
          object Panel78: TPanel
            Left = 2
            Top = 566
            Width = 709
            Height = 29
            Align = alTop
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 18
            object Label65: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 29
              Height = 21
              Align = alLeft
              Caption = #1058#1086#1085#1091#1089
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object RichEditSpec55: TRichEditSpec
              AlignWithMargins = True
              Left = 205
              Top = 4
              Width = 500
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1053#1077#1074#1088#1086#1083#1086#1075#1058#1086#1085#1091#1089#1043#1076#1077'][1][1][0]')
              TabOrder = 1
              OnChange = RichEditChanged
              FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1058#1086#1085#1091#1089#1043#1076#1077
              FieldType = 1
              TextData = '['#1053#1077#1074#1088#1086#1083#1086#1075#1058#1086#1085#1091#1089#1043#1076#1077'][1][1][0]'
              Appointment = 1
            end
            object ComboBoxSpec21: TComboBoxSpec
              AlignWithMargins = True
              Left = 39
              Top = 4
              Width = 160
              Height = 21
              Align = alLeft
              ItemHeight = 0
              TabOrder = 0
              Text = '['#1053#1077#1074#1088#1086#1083#1086#1075#1058#1086#1085#1091#1089'][5][1][56]'
              OnSelect = ComboBoxSpecSelect
              OnAfterSetItemID = ComboBoxChanged
              OnMouseWheelUp = ComboBoxSpecMouseWheelUp
              OnMouseWheelDown = ComboBoxSpecMouseWheelDown
              FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1058#1086#1085#1091#1089
              FieldType = 5
              ParentID = 56
              Appointment = 1
              ListID = 1
            end
          end
          object Panel79: TPanel
            Left = 2
            Top = 537
            Width = 709
            Height = 29
            Align = alTop
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 17
            object Label136: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 51
              Height = 13
              Align = alLeft
              Caption = #1044#1080#1089#1092#1086#1085#1080#1103
            end
            object ComboBoxSpec20: TComboBoxSpec
              AlignWithMargins = True
              Left = 61
              Top = 4
              Width = 150
              Height = 21
              Align = alLeft
              ItemHeight = 0
              TabOrder = 0
              Text = '['#1053#1077#1074#1088#1086#1083#1086#1075#1044#1080#1089#1092#1086#1085#1080#1103'][5][1][45]'
              OnSelect = ComboBoxSpecSelect
              OnAfterSetItemID = ComboBoxChanged
              OnMouseWheelUp = ComboBoxSpecMouseWheelUp
              OnMouseWheelDown = ComboBoxSpecMouseWheelDown
              FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1044#1080#1089#1092#1086#1085#1080#1103
              FieldType = 5
              ParentID = 45
              Appointment = 1
              ListID = 1
            end
          end
          object Panel80: TPanel
            Left = 2
            Top = 508
            Width = 709
            Height = 29
            Align = alTop
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 16
            object Label137: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 50
              Height = 13
              Align = alLeft
              Caption = #1044#1080#1089#1092#1072#1075#1080#1103
              Layout = tlCenter
            end
            object ComboBoxSpec19: TComboBoxSpec
              AlignWithMargins = True
              Left = 60
              Top = 4
              Width = 150
              Height = 21
              Align = alLeft
              ItemHeight = 0
              TabOrder = 0
              Text = '['#1053#1077#1074#1088#1086#1083#1086#1075#1044#1080#1089#1092#1072#1075#1080#1103'][5][1][45]'
              OnSelect = ComboBoxSpecSelect
              OnAfterSetItemID = ComboBoxChanged
              OnMouseWheelUp = ComboBoxSpecMouseWheelUp
              OnMouseWheelDown = ComboBoxSpecMouseWheelDown
              FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1044#1080#1089#1092#1072#1075#1080#1103
              FieldType = 5
              ParentID = 45
              Appointment = 1
              ListID = 1
            end
          end
          object Panel57: TPanel
            Left = 2
            Top = 15
            Width = 709
            Height = 29
            Align = alTop
            TabOrder = 0
            object Label45: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 42
              Height = 21
              Align = alLeft
              Caption = #1046#1072#1083#1086#1073#1099
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object SpeedButton16: TSpeedButton
              AlignWithMargins = True
              Left = 682
              Top = 4
              Width = 23
              Height = 21
              Align = alRight
              Glyph.Data = {
                E6000000424DE60000000000000076000000280000000E0000000E0000000100
                0400000000007000000000000000000000001000000000000000000000000000
                BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
                FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
                3300333333333333330033333333333333003333300033333300333330F03333
                3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
                3300333330F033333300333330F0333333003333300033333300333333333333
                33003333333333333300}
              OnClick = SpeedButton16Click
              ExplicitLeft = 643
              ExplicitTop = 1
            end
            object RichEditSpec19: TRichEditSpec
              AlignWithMargins = True
              Left = 52
              Top = 4
              Width = 624
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1053#1077#1074#1088#1086#1083#1086#1075#1046#1072#1083#1086#1073#1099'][1][0][62]')
              TabOrder = 0
              OnChange = RichEditChanged
              OnExit = RichEditSpecExit
              OnKeyDown = RichEditSpecKeyDown
              OnKeyPress = RichEditSpecKeyPress
              FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1046#1072#1083#1086#1073#1099
              FieldType = 1
              TextData = '['#1053#1077#1074#1088#1086#1083#1086#1075#1046#1072#1083#1086#1073#1099'][1][0][62]'
              ListID = 62
              Appointment = 1
            end
          end
          object Panel7: TPanel
            Left = 2
            Top = 44
            Width = 709
            Height = 29
            Align = alTop
            TabOrder = 1
            object Label44: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 63
              Height = 21
              Align = alLeft
              Caption = #1054#1073#1098#1077#1082#1090#1080#1074#1085#1086
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object SpeedButton15: TSpeedButton
              AlignWithMargins = True
              Left = 682
              Top = 4
              Width = 23
              Height = 21
              Align = alRight
              Glyph.Data = {
                E6000000424DE60000000000000076000000280000000E0000000E0000000100
                0400000000007000000000000000000000001000000000000000000000000000
                BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
                FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
                3300333333333333330033333333333333003333300033333300333330F03333
                3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
                3300333330F033333300333330F0333333003333300033333300333333333333
                33003333333333333300}
              OnClick = SpeedButton15Click
              ExplicitLeft = 643
              ExplicitTop = 1
            end
            object RichEditSpec12: TRichEditSpec
              AlignWithMargins = True
              Left = 73
              Top = 4
              Width = 603
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1053#1077#1074#1088#1086#1083#1086#1075#1054#1073#1098#1077#1082#1090#1080#1074#1085#1086'][1][0][62]')
              TabOrder = 0
              OnChange = RichEditChanged
              OnExit = RichEditSpecExit
              OnKeyDown = RichEditSpecKeyDown
              OnKeyPress = RichEditSpecKeyPress
              FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1054#1073#1098#1077#1082#1090#1080#1074#1085#1086
              FieldType = 1
              TextData = '['#1053#1077#1074#1088#1086#1083#1086#1075#1054#1073#1098#1077#1082#1090#1080#1074#1085#1086'][1][0][62]'
              ListID = 62
              Appointment = 1
            end
          end
          object Panel2: TPanel
            Left = 2
            Top = 450
            Width = 709
            Height = 29
            Align = alTop
            TabOrder = 21
            object Label56: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 122
              Height = 21
              Align = alLeft
              Caption = #1054#1088#1072#1083#1100#1085#1099#1077' '#1072#1074#1090#1086#1084#1072#1090#1080#1079#1084#1099
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object ComboBoxSpec18: TComboBoxSpec
              AlignWithMargins = True
              Left = 132
              Top = 4
              Width = 144
              Height = 21
              Align = alLeft
              ItemHeight = 0
              TabOrder = 0
              Text = '['#1053#1077#1074#1088#1086#1083#1086#1075#1054#1088#1072#1083#1100#1085#1099#1077#1040#1074#1090#1086#1084#1072#1090#1080#1079#1084#1099'][5][1][45]'
              OnSelect = ComboBoxSpecSelect
              OnAfterSetItemID = ComboBoxChanged
              OnMouseWheelUp = ComboBoxSpecMouseWheelUp
              OnMouseWheelDown = ComboBoxSpecMouseWheelDown
              FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1054#1088#1072#1083#1100#1085#1099#1077#1040#1074#1090#1086#1084#1072#1090#1080#1079#1084#1099
              FieldType = 5
              ParentID = 45
              Appointment = 1
              ListID = 1
            end
            object RichEditSpec45: TRichEditSpec
              AlignWithMargins = True
              Left = 282
              Top = 4
              Width = 423
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1053#1077#1074#1088#1086#1083#1086#1075#1054#1088#1072#1083#1100#1085#1099#1077#1040#1074#1090#1086#1084#1072#1090#1080#1079#1084#1099#1044#1088#1091#1075#1086#1077'][1][1][0]')
              TabOrder = 1
              OnChange = RichEditChanged
              FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1054#1088#1072#1083#1100#1085#1099#1077#1040#1074#1090#1086#1084#1072#1090#1080#1079#1084#1099#1044#1088#1091#1075#1086#1077
              FieldType = 1
              TextData = '['#1053#1077#1074#1088#1086#1083#1086#1075#1054#1088#1072#1083#1100#1085#1099#1077#1040#1074#1090#1086#1084#1072#1090#1080#1079#1084#1099#1044#1088#1091#1075#1086#1077'][1][1][0]'
              Appointment = 1
            end
          end
        end
        object Panel83: TPanel
          Left = 0
          Top = 989
          Width = 713
          Height = 29
          Align = alTop
          TabOrder = 8
          object Label68: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 89
            Height = 21
            Align = alLeft
            Caption = #1044#1086#1087'. '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1103
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object RichEditSpec58: TRichEditSpec
            AlignWithMargins = True
            Left = 99
            Top = 4
            Width = 610
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1053#1077#1074#1088#1086#1083#1086#1075#1044#1086#1087#1048#1085#1092#1086'][1][1][0]')
            TabOrder = 0
            OnChange = RichEditChanged
            FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1044#1086#1087#1048#1085#1092#1086
            FieldType = 1
            TextData = '['#1053#1077#1074#1088#1086#1083#1086#1075#1044#1086#1087#1048#1085#1092#1086'][1][1][0]'
            Appointment = 1
          end
        end
        object Panel84: TPanel
          Left = 0
          Top = 786
          Width = 713
          Height = 29
          Align = alTop
          TabOrder = 1
          object Label70: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 212
            Height = 21
            Align = alLeft
            Caption = #1055#1072#1090#1086#1083#1086#1075#1080#1095#1077#1089#1082#1080#1077' '#1088#1077#1092#1083#1077#1082#1089#1099' '#1057'. '#1041#1072#1073#1080#1085#1089#1082#1086#1075#1086
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object RichEditSpec59: TRichEditSpec
            AlignWithMargins = True
            Left = 222
            Top = 4
            Width = 487
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1053#1077#1074#1088#1086#1083#1086#1075#1041#1072#1073#1080#1085#1089#1082#1080#1081'][1][1][0]')
            TabOrder = 0
            OnChange = RichEditChanged
            FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1041#1072#1073#1080#1085#1089#1082#1080#1081
            FieldType = 1
            TextData = '['#1053#1077#1074#1088#1086#1083#1086#1075#1041#1072#1073#1080#1085#1089#1082#1080#1081'][1][1][0]'
            Appointment = 1
          end
        end
        object Panel85: TPanel
          Left = 0
          Top = 960
          Width = 713
          Height = 29
          Align = alTop
          TabOrder = 7
          object Label71: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 131
            Height = 21
            Align = alLeft
            Caption = #1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080' '#1088#1086#1076#1080#1090#1077#1083#1103#1084
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object SpeedButton20: TSpeedButton
            AlignWithMargins = True
            Left = 686
            Top = 4
            Width = 23
            Height = 21
            Align = alRight
            Glyph.Data = {
              E6000000424DE60000000000000076000000280000000E0000000E0000000100
              0400000000007000000000000000000000001000000000000000000000000000
              BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
              3300333333333333330033333333333333003333300033333300333330F03333
              3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
              3300333330F033333300333330F0333333003333300033333300333333333333
              33003333333333333300}
            OnClick = SpeedButton20Click
            ExplicitLeft = 640
            ExplicitTop = -4
          end
          object RichEditSpec60: TRichEditSpec
            AlignWithMargins = True
            Left = 141
            Top = 4
            Width = 539
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1053#1077#1074#1088#1086#1083#1086#1075#1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080#1056#1086#1076#1080#1090#1077#1083#1103#1084'][1][0][121]')
            TabOrder = 0
            OnChange = RichEditChanged
            OnExit = RichEditSpecExit
            OnKeyDown = RichEditSpecKeyDown
            OnKeyPress = RichEditSpecKeyPress
            FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080#1056#1086#1076#1080#1090#1077#1083#1103#1084
            FieldType = 1
            TextData = '['#1053#1077#1074#1088#1086#1083#1086#1075#1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080#1056#1086#1076#1080#1090#1077#1083#1103#1084'][1][0][121]'
            ListID = 121
            Appointment = 1
          end
        end
        object Panel86: TPanel
          Left = 0
          Top = 931
          Width = 713
          Height = 29
          Align = alTop
          TabOrder = 6
          object Label72: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 129
            Height = 21
            Align = alLeft
            Caption = #1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080' '#1087#1077#1076#1072#1075#1086#1075#1072#1084
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object SpeedButton19: TSpeedButton
            AlignWithMargins = True
            Left = 686
            Top = 4
            Width = 23
            Height = 21
            Align = alRight
            Glyph.Data = {
              E6000000424DE60000000000000076000000280000000E0000000E0000000100
              0400000000007000000000000000000000001000000000000000000000000000
              BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
              3300333333333333330033333333333333003333300033333300333330F03333
              3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
              3300333330F033333300333330F0333333003333300033333300333333333333
              33003333333333333300}
            OnClick = SpeedButton19Click
            ExplicitLeft = 640
            ExplicitTop = 5
          end
          object RichEditSpec61: TRichEditSpec
            AlignWithMargins = True
            Left = 139
            Top = 4
            Width = 541
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1053#1077#1074#1088#1086#1083#1086#1075#1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080'][1][0][121]')
            TabOrder = 0
            OnChange = RichEditChanged
            OnExit = RichEditSpecExit
            OnKeyDown = RichEditSpecKeyDown
            OnKeyPress = RichEditSpecKeyPress
            FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080
            FieldType = 1
            TextData = '['#1053#1077#1074#1088#1086#1083#1086#1075#1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080'][1][0][121]'
            ListID = 121
            Appointment = 1
          end
        end
        object Panel87: TPanel
          Left = 0
          Top = 902
          Width = 713
          Height = 29
          Align = alTop
          TabOrder = 5
          object Label73: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 13
            Height = 21
            Align = alLeft
            Caption = 'DS'
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object SpeedButton18: TSpeedButton
            AlignWithMargins = True
            Left = 686
            Top = 4
            Width = 23
            Height = 21
            Align = alRight
            Glyph.Data = {
              E6000000424DE60000000000000076000000280000000E0000000E0000000100
              0400000000007000000000000000000000001000000000000000000000000000
              BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
              3300333333333333330033333333333333003333300033333300333330F03333
              3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
              3300333330F033333300333330F0333333003333300033333300333333333333
              33003333333333333300}
            OnClick = SpeedButton18Click
            ExplicitLeft = 644
            ExplicitTop = -3
          end
          object RichEditSpec62: TRichEditSpec
            AlignWithMargins = True
            Left = 23
            Top = 4
            Width = 657
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1053#1077#1074#1088#1086#1083#1086#1075#1044#1080#1072#1075#1085#1086#1079#1099'][1][0][39]')
            TabOrder = 0
            OnChange = RichEditChanged
            OnExit = RichEditSpecExit
            OnKeyDown = RichEditSpecKeyDown
            OnKeyPress = RichEditSpecKeyPress
            FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1044#1080#1072#1075#1085#1086#1079#1099
            FieldType = 1
            TextData = '['#1053#1077#1074#1088#1086#1083#1086#1075#1044#1080#1072#1075#1085#1086#1079#1099'][1][0][39]'
            ListID = 39
            Appointment = 1
          end
        end
        object Panel88: TPanel
          Left = 0
          Top = 873
          Width = 713
          Height = 29
          Align = alTop
          TabOrder = 4
          object Label74: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 21
            Height = 21
            Align = alLeft
            Caption = #1055#1053#1055
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object RichEditSpec63: TRichEditSpec
            AlignWithMargins = True
            Left = 182
            Top = 4
            Width = 527
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1053#1077#1074#1088#1086#1083#1086#1075#1055#1053#1055#1044#1086#1087'][1][1][0]')
            TabOrder = 1
            OnChange = RichEditChanged
            FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1055#1053#1055#1044#1086#1087
            FieldType = 1
            TextData = '['#1053#1077#1074#1088#1086#1083#1086#1075#1055#1053#1055#1044#1086#1087'][1][1][0]'
            Appointment = 1
          end
          object ComboBoxSpec24: TComboBoxSpec
            AlignWithMargins = True
            Left = 31
            Top = 4
            Width = 145
            Height = 21
            Align = alLeft
            ItemHeight = 0
            TabOrder = 0
            Text = '['#1053#1077#1074#1088#1086#1083#1086#1075#1055#1053#1055'][5][1][73]'
            OnSelect = ComboBoxSpecSelect
            OnAfterSetItemID = ComboBoxChanged
            OnMouseWheelUp = ComboBoxSpecMouseWheelUp
            OnMouseWheelDown = ComboBoxSpecMouseWheelDown
            FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1055#1053#1055
            FieldType = 5
            ParentID = 73
            Appointment = 1
            ListID = 1
          end
        end
        object Panel89: TPanel
          Left = 0
          Top = 844
          Width = 713
          Height = 29
          Align = alTop
          TabOrder = 3
          object Label75: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 132
            Height = 13
            Align = alLeft
            Caption = #1042' '#1087#1086#1079#1077' '#1056#1086#1084#1073#1077#1088#1075#1072' '#1091#1089#1090#1086#1081#1095#1080#1074
            Layout = tlCenter
          end
          object ComboBoxSpec23: TComboBoxSpec
            AlignWithMargins = True
            Left = 142
            Top = 4
            Width = 150
            Height = 21
            Align = alLeft
            ItemHeight = 0
            TabOrder = 0
            Text = '['#1053#1077#1074#1088#1086#1083#1086#1075#1056#1086#1084#1073#1077#1088#1075'][5][1][45]'
            OnSelect = ComboBoxSpecSelect
            OnAfterSetItemID = ComboBoxChanged
            OnMouseWheelUp = ComboBoxSpecMouseWheelUp
            OnMouseWheelDown = ComboBoxSpecMouseWheelDown
            FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1056#1086#1084#1073#1077#1088#1075
            FieldType = 5
            ParentID = 45
            Appointment = 1
            ListID = 1
          end
        end
        object Panel90: TPanel
          Left = 0
          Top = 815
          Width = 713
          Height = 29
          Align = alTop
          TabOrder = 2
          object Label138: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 95
            Height = 13
            Align = alLeft
            Caption = #1063#1091#1074#1089#1090#1074#1080#1090#1077#1083#1100#1085#1086#1089#1090#1100
            Layout = tlCenter
          end
          object ComboBoxSpec22: TComboBoxSpec
            AlignWithMargins = True
            Left = 105
            Top = 4
            Width = 150
            Height = 21
            Align = alLeft
            ItemHeight = 0
            TabOrder = 0
            Text = '['#1053#1077#1074#1088#1086#1083#1086#1075#1063#1091#1074#1089#1090#1074#1080#1090#1077#1083#1100#1085#1086#1089#1090#1100'][5][1][69]'
            OnSelect = ComboBoxSpecSelect
            OnAfterSetItemID = ComboBoxChanged
            OnMouseWheelUp = ComboBoxSpecMouseWheelUp
            OnMouseWheelDown = ComboBoxSpecMouseWheelDown
            FieldName = #1053#1077#1074#1088#1086#1083#1086#1075#1063#1091#1074#1089#1090#1074#1080#1090#1077#1083#1100#1085#1086#1089#1090#1100
            FieldType = 5
            ParentID = 69
            Appointment = 1
            ListID = 1
          end
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = #1054#1089#1084#1086#1090#1088' '#1087#1089#1080#1093#1080#1072#1090#1088#1072
      ImageIndex = -1
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object ScrollBox4: TScrollBox
        Left = 0
        Top = 0
        Width = 734
        Height = 590
        Align = alClient
        TabOrder = 0
        OnMouseWheel = ScrollBoxMouseWheel
        object GroupBox15: TGroupBox
          Left = 0
          Top = 87
          Width = 730
          Height = 180
          Align = alTop
          Caption = #1055#1089#1080#1093#1080#1095#1077#1089#1082#1080#1081' '#1089#1090#1072#1090#1091#1089
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          Padding.Left = 3
          Padding.Top = 3
          Padding.Right = 3
          Padding.Bottom = 3
          ParentFont = False
          TabOrder = 3
          object Panel10: TPanel
            Left = 5
            Top = 105
            Width = 720
            Height = 29
            Align = alTop
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 3
            object Label80: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 131
              Height = 21
              Align = alLeft
              Caption = #1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080' '#1088#1086#1076#1080#1090#1077#1083#1103#1084
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object SpeedButton25: TSpeedButton
              AlignWithMargins = True
              Left = 693
              Top = 4
              Width = 23
              Height = 21
              Align = alRight
              Glyph.Data = {
                E6000000424DE60000000000000076000000280000000E0000000E0000000100
                0400000000007000000000000000000000001000000000000000000000000000
                BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
                FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
                3300333333333333330033333333333333003333300033333300333330F03333
                3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
                3300333330F033333300333330F0333333003333300033333300333333333333
                33003333333333333300}
              OnClick = SpeedButton25Click
              ExplicitLeft = 643
              ExplicitTop = 1
            end
            object RichEditSpec68: TRichEditSpec
              AlignWithMargins = True
              Left = 141
              Top = 4
              Width = 546
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1055#1089#1080#1093#1080#1072#1090#1088#1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080#1056#1086#1076#1080#1090#1077#1083#1103#1084'][1][0][121]')
              TabOrder = 0
              OnChange = RichEditChanged
              OnExit = RichEditSpecExit
              OnKeyDown = RichEditSpecKeyDown
              OnKeyPress = RichEditSpecKeyPress
              FieldName = #1055#1089#1080#1093#1080#1072#1090#1088#1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080#1056#1086#1076#1080#1090#1077#1083#1103#1084
              FieldType = 1
              TextData = '['#1055#1089#1080#1093#1080#1072#1090#1088#1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080#1056#1086#1076#1080#1090#1077#1083#1103#1084'][1][0][121]'
              ListID = 121
              Appointment = 2
            end
          end
          object Panel8: TPanel
            Left = 5
            Top = 134
            Width = 720
            Height = 29
            Align = alTop
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 4
            object Label76: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 89
              Height = 21
              Align = alLeft
              Caption = #1044#1086#1087'. '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1103
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object RichEditSpec64: TRichEditSpec
              AlignWithMargins = True
              Left = 99
              Top = 4
              Width = 617
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1055#1089#1080#1093#1080#1072#1090#1088#1044#1086#1087#1048#1085#1092#1086'][1][2][0]')
              TabOrder = 0
              OnChange = RichEditChanged
              FieldName = #1055#1089#1080#1093#1080#1072#1090#1088#1044#1086#1087#1048#1085#1092#1086
              FieldType = 1
              TextData = '['#1055#1089#1080#1093#1080#1072#1090#1088#1044#1086#1087#1048#1085#1092#1086'][1][2][0]'
              Appointment = 2
            end
          end
          object Panel93: TPanel
            Left = 5
            Top = 76
            Width = 720
            Height = 29
            Align = alTop
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 2
            object Label81: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 129
              Height = 21
              Align = alLeft
              Caption = #1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080' '#1087#1077#1076#1072#1075#1086#1075#1072#1084
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object SpeedButton26: TSpeedButton
              AlignWithMargins = True
              Left = 693
              Top = 4
              Width = 23
              Height = 21
              Align = alRight
              Glyph.Data = {
                E6000000424DE60000000000000076000000280000000E0000000E0000000100
                0400000000007000000000000000000000001000000000000000000000000000
                BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
                FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
                3300333333333333330033333333333333003333300033333300333330F03333
                3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
                3300333330F033333300333330F0333333003333300033333300333333333333
                33003333333333333300}
              OnClick = SpeedButton26Click
              ExplicitLeft = 643
              ExplicitTop = 1
            end
            object RichEditSpec69: TRichEditSpec
              AlignWithMargins = True
              Left = 139
              Top = 4
              Width = 548
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1055#1089#1080#1093#1080#1072#1090#1088#1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080'][1][0][121]')
              TabOrder = 0
              OnChange = RichEditChanged
              OnExit = RichEditSpecExit
              OnKeyDown = RichEditSpecKeyDown
              OnKeyPress = RichEditSpecKeyPress
              FieldName = #1055#1089#1080#1093#1080#1072#1090#1088#1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080
              FieldType = 1
              TextData = '['#1055#1089#1080#1093#1080#1072#1090#1088#1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080'][1][0][121]'
              ListID = 121
              Appointment = 2
            end
          end
          object Panel94: TPanel
            Left = 5
            Top = 47
            Width = 720
            Height = 29
            Align = alTop
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 1
            object Label82: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 13
              Height = 21
              Align = alLeft
              Caption = 'DS'
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object SpeedButton27: TSpeedButton
              AlignWithMargins = True
              Left = 693
              Top = 4
              Width = 23
              Height = 21
              Align = alRight
              Glyph.Data = {
                E6000000424DE60000000000000076000000280000000E0000000E0000000100
                0400000000007000000000000000000000001000000000000000000000000000
                BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
                FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
                3300333333333333330033333333333333003333300033333300333330F03333
                3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
                3300333330F033333300333330F0333333003333300033333300333333333333
                33003333333333333300}
              OnClick = SpeedButton27Click
              ExplicitLeft = 643
              ExplicitTop = 1
            end
            object RichEditSpec70: TRichEditSpec
              AlignWithMargins = True
              Left = 23
              Top = 4
              Width = 664
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1055#1089#1080#1093#1080#1072#1090#1088#1044#1080#1072#1075#1085#1086#1079#1099'][1][0][39]')
              TabOrder = 0
              OnChange = RichEditChanged
              OnExit = RichEditSpecExit
              OnKeyDown = RichEditSpecKeyDown
              OnKeyPress = RichEditSpecKeyPress
              FieldName = #1055#1089#1080#1093#1080#1072#1090#1088#1044#1080#1072#1075#1085#1086#1079#1099
              FieldType = 1
              TextData = '['#1055#1089#1080#1093#1080#1072#1090#1088#1044#1080#1072#1075#1085#1086#1079#1099'][1][0][39]'
              ListID = 39
              Appointment = 2
            end
          end
          object Panel95: TPanel
            Left = 5
            Top = 18
            Width = 720
            Height = 29
            Align = alTop
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
            object SpeedButton28: TSpeedButton
              AlignWithMargins = True
              Left = 693
              Top = 4
              Width = 23
              Height = 21
              Align = alRight
              Glyph.Data = {
                E6000000424DE60000000000000076000000280000000E0000000E0000000100
                0400000000007000000000000000000000001000000000000000000000000000
                BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
                FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
                3300333333333333330033333333333333003333300033333300333330F03333
                3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
                3300333330F033333300333330F0333333003333300033333300333333333333
                33003333333333333300}
              OnClick = SpeedButton28Click
              ExplicitLeft = 643
              ExplicitTop = 1
            end
            object RichEditSpec71: TRichEditSpec
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 683
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1055#1089#1080#1093#1080#1072#1090#1088#1057#1090#1072#1090#1091#1089'][1][0][62]')
              TabOrder = 0
              OnChange = RichEditChanged
              OnExit = RichEditSpecExit
              OnKeyDown = RichEditSpecKeyDown
              OnKeyPress = RichEditSpecKeyPress
              FieldName = #1055#1089#1080#1093#1080#1072#1090#1088#1057#1090#1072#1090#1091#1089
              FieldType = 1
              TextData = '['#1055#1089#1080#1093#1080#1072#1090#1088#1057#1090#1072#1090#1091#1089'][1][0][62]'
              ListID = 62
              Appointment = 2
            end
          end
        end
        object Panel9: TPanel
          Left = 0
          Top = 58
          Width = 730
          Height = 29
          Align = alTop
          TabOrder = 2
          object Label77: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 42
            Height = 21
            Align = alLeft
            Caption = #1046#1072#1083#1086#1073#1099
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object SpeedButton22: TSpeedButton
            AlignWithMargins = True
            Left = 703
            Top = 4
            Width = 23
            Height = 21
            Align = alRight
            Glyph.Data = {
              E6000000424DE60000000000000076000000280000000E0000000E0000000100
              0400000000007000000000000000000000001000000000000000000000000000
              BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
              3300333333333333330033333333333333003333300033333300333330F03333
              3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
              3300333330F033333300333330F0333333003333300033333300333333333333
              33003333333333333300}
            OnClick = SpeedButton22Click
            ExplicitLeft = 643
            ExplicitTop = 1
          end
          object RichEditSpec65: TRichEditSpec
            AlignWithMargins = True
            Left = 52
            Top = 4
            Width = 645
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1055#1089#1080#1093#1080#1072#1090#1088#1046#1072#1083#1086#1073#1099'][1][0][62]')
            TabOrder = 0
            OnChange = RichEditChanged
            OnExit = RichEditSpecExit
            OnKeyDown = RichEditSpecKeyDown
            OnKeyPress = RichEditSpecKeyPress
            FieldName = #1055#1089#1080#1093#1080#1072#1090#1088#1046#1072#1083#1086#1073#1099
            FieldType = 1
            TextData = '['#1055#1089#1080#1093#1080#1072#1090#1088#1046#1072#1083#1086#1073#1099'][1][0][62]'
            ListID = 62
            Appointment = 2
          end
        end
        object Panel91: TPanel
          Left = 0
          Top = 29
          Width = 730
          Height = 29
          Align = alTop
          TabOrder = 1
          object Label78: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 62
            Height = 21
            Align = alLeft
            Caption = #1048#1079' '#1072#1085#1072#1084#1085#1077#1079#1072
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object SpeedButton23: TSpeedButton
            AlignWithMargins = True
            Left = 703
            Top = 4
            Width = 23
            Height = 21
            Align = alRight
            Glyph.Data = {
              E6000000424DE60000000000000076000000280000000E0000000E0000000100
              0400000000007000000000000000000000001000000000000000000000000000
              BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
              3300333333333333330033333333333333003333300033333300333330F03333
              3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
              3300333330F033333300333330F0333333003333300033333300333333333333
              33003333333333333300}
            OnClick = SpeedButton23Click
            ExplicitLeft = 676
            ExplicitTop = -3
          end
          object RichEditSpec66: TRichEditSpec
            AlignWithMargins = True
            Left = 72
            Top = 4
            Width = 625
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1055#1089#1080#1093#1080#1072#1090#1088#1040#1085#1072#1084#1085#1077#1079'][1][0][62]')
            TabOrder = 0
            OnChange = RichEditChanged
            OnExit = RichEditSpecExit
            OnKeyDown = RichEditSpecKeyDown
            OnKeyPress = RichEditSpecKeyPress
            FieldName = #1055#1089#1080#1093#1080#1072#1090#1088#1040#1085#1072#1084#1085#1077#1079
            FieldType = 1
            TextData = '['#1055#1089#1080#1093#1080#1072#1090#1088#1040#1085#1072#1084#1085#1077#1079'][1][0][62]'
            ListID = 62
            Appointment = 2
          end
        end
        object Panel92: TPanel
          Left = 0
          Top = 0
          Width = 730
          Height = 29
          Align = alTop
          TabOrder = 0
          object Label79: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 338
            Height = 21
            Align = alLeft
            Caption = #1053#1072' '#1087#1088#1080#1105#1084#1077' '#1086#1089#1084#1086#1090#1088#1077#1085'('#1072') '#1089' '#1076#1086#1073#1088#1086#1074#1086#1083#1100#1085#1086#1075#1086' '#1089#1086#1075#1083#1072#1089#1080#1103' '#1080' '#1074' '#1087#1088#1080#1089#1091#1090#1089#1090#1074#1080#1080
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object SpeedButton24: TSpeedButton
            AlignWithMargins = True
            Left = 703
            Top = 4
            Width = 23
            Height = 21
            Align = alRight
            Glyph.Data = {
              E6000000424DE60000000000000076000000280000000E0000000E0000000100
              0400000000007000000000000000000000001000000000000000000000000000
              BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
              3300333333333333330033333333333333003333300033333300333330F03333
              3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
              3300333330F033333300333330F0333333003333300033333300333333333333
              33003333333333333300}
            OnClick = SpeedButton24Click
            ExplicitLeft = 643
            ExplicitTop = 1
          end
          object RichEditSpec67: TRichEditSpec
            AlignWithMargins = True
            Left = 348
            Top = 4
            Width = 349
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1055#1089#1080#1093#1080#1072#1090#1088#1042#1055#1088#1080#1089#1091#1090#1089#1090#1074#1080#1080'][1][0][62]')
            TabOrder = 0
            OnChange = RichEditChanged
            OnExit = RichEditSpecExit
            OnKeyDown = RichEditSpecKeyDown
            OnKeyPress = RichEditSpecKeyPress
            FieldName = #1055#1089#1080#1093#1080#1072#1090#1088#1042#1055#1088#1080#1089#1091#1090#1089#1090#1074#1080#1080
            FieldType = 1
            TextData = '['#1055#1089#1080#1093#1080#1072#1090#1088#1042#1055#1088#1080#1089#1091#1090#1089#1090#1074#1080#1080'][1][0][62]'
            ListID = 62
            Appointment = 2
          end
        end
      end
    end
    object TabSheet3: TTabSheet
      Caption = #1055#1089#1080#1093#1086#1083#1086#1075#1080#1095#1077#1089#1082#1086#1077' '#1086#1073#1089#1083#1077#1076#1086#1074#1072#1085#1080#1077
      ImageIndex = -1
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object ScrollBox7: TScrollBox
        Left = 0
        Top = 0
        Width = 734
        Height = 590
        Align = alClient
        TabOrder = 0
        object Panel100: TPanel
          Left = 0
          Top = 0
          Width = 730
          Height = 29
          Align = alTop
          TabOrder = 0
          object SpeedButton31: TSpeedButton
            AlignWithMargins = True
            Left = 703
            Top = 4
            Width = 23
            Height = 21
            Align = alRight
            Glyph.Data = {
              E6000000424DE60000000000000076000000280000000E0000000E0000000100
              0400000000007000000000000000000000001000000000000000000000000000
              BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
              3300333333333333330033333333333333003333300033333300333330F03333
              3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
              3300333330F033333300333330F0333333003333300033333300333333333333
              33003333333333333300}
            OnClick = SpeedButton31Click
            ExplicitLeft = 643
            ExplicitTop = 1
          end
          object RichEditSpec76: TRichEditSpec
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 693
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1055#1089#1080#1093#1086#1083#1086#1075#1054#1087#1080#1089#1072#1085#1080#1077'][1][0][62]')
            TabOrder = 0
            OnChange = RichEditChanged
            OnExit = RichEditSpecExit
            OnKeyDown = RichEditSpecKeyDown
            OnKeyPress = RichEditSpecKeyPress
            FieldName = #1055#1089#1080#1093#1086#1083#1086#1075#1054#1087#1080#1089#1072#1085#1080#1077
            FieldType = 1
            TextData = '['#1055#1089#1080#1093#1086#1083#1086#1075#1054#1087#1080#1089#1072#1085#1080#1077'][1][0][62]'
            ListID = 62
            Appointment = 5
          end
        end
        object Panel99: TPanel
          Left = 0
          Top = 29
          Width = 730
          Height = 29
          Align = alTop
          TabOrder = 1
          object Label86: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 13
            Height = 21
            Align = alLeft
            Caption = 'DS'
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object SpeedButton30: TSpeedButton
            AlignWithMargins = True
            Left = 703
            Top = 4
            Width = 23
            Height = 21
            Align = alRight
            Glyph.Data = {
              E6000000424DE60000000000000076000000280000000E0000000E0000000100
              0400000000007000000000000000000000001000000000000000000000000000
              BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
              3300333333333333330033333333333333003333300033333300333330F03333
              3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
              3300333330F033333300333330F0333333003333300033333300333333333333
              33003333333333333300}
            OnClick = SpeedButton30Click
            ExplicitLeft = 643
            ExplicitTop = 1
          end
          object RichEditSpec75: TRichEditSpec
            AlignWithMargins = True
            Left = 23
            Top = 4
            Width = 674
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1055#1089#1080#1093#1086#1083#1086#1075#1044#1080#1072#1075#1085#1086#1079#1099'][1][0][39]')
            TabOrder = 0
            OnChange = RichEditChanged
            OnExit = RichEditSpecExit
            OnKeyDown = RichEditSpecKeyDown
            OnKeyPress = RichEditSpecKeyPress
            FieldName = #1055#1089#1080#1093#1086#1083#1086#1075#1044#1080#1072#1075#1085#1086#1079#1099
            FieldType = 1
            TextData = '['#1055#1089#1080#1093#1086#1083#1086#1075#1044#1080#1072#1075#1085#1086#1079#1099'][1][0][39]'
            ListID = 39
            Appointment = 5
          end
        end
        object Panel98: TPanel
          Left = 0
          Top = 58
          Width = 730
          Height = 29
          Align = alTop
          TabOrder = 2
          object Label85: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 129
            Height = 21
            Align = alLeft
            Caption = #1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080' '#1087#1077#1076#1072#1075#1086#1075#1072#1084
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object SpeedButton29: TSpeedButton
            AlignWithMargins = True
            Left = 703
            Top = 4
            Width = 23
            Height = 21
            Align = alRight
            Glyph.Data = {
              E6000000424DE60000000000000076000000280000000E0000000E0000000100
              0400000000007000000000000000000000001000000000000000000000000000
              BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
              3300333333333333330033333333333333003333300033333300333330F03333
              3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
              3300333330F033333300333330F0333333003333300033333300333333333333
              33003333333333333300}
            OnClick = SpeedButton29Click
            ExplicitLeft = 643
            ExplicitTop = 1
          end
          object RichEditSpec74: TRichEditSpec
            AlignWithMargins = True
            Left = 139
            Top = 4
            Width = 558
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1055#1089#1080#1093#1086#1083#1086#1075#1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080'][1][0][121]')
            TabOrder = 0
            OnChange = RichEditChanged
            OnExit = RichEditSpecExit
            OnKeyDown = RichEditSpecKeyDown
            OnKeyPress = RichEditSpecKeyPress
            FieldName = #1055#1089#1080#1093#1086#1083#1086#1075#1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080
            FieldType = 1
            TextData = '['#1055#1089#1080#1093#1086#1083#1086#1075#1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080'][1][0][121]'
            ListID = 121
            Appointment = 5
          end
        end
        object Panel96: TPanel
          Left = 0
          Top = 87
          Width = 730
          Height = 29
          Align = alTop
          TabOrder = 3
          object Label83: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 131
            Height = 21
            Align = alLeft
            Caption = #1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080' '#1088#1086#1076#1080#1090#1077#1083#1103#1084
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object SpeedButton21: TSpeedButton
            AlignWithMargins = True
            Left = 703
            Top = 4
            Width = 23
            Height = 21
            Align = alRight
            Glyph.Data = {
              E6000000424DE60000000000000076000000280000000E0000000E0000000100
              0400000000007000000000000000000000001000000000000000000000000000
              BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
              3300333333333333330033333333333333003333300033333300333330F03333
              3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
              3300333330F033333300333330F0333333003333300033333300333333333333
              33003333333333333300}
            OnClick = SpeedButton21Click
            ExplicitLeft = 643
            ExplicitTop = 1
          end
          object RichEditSpec72: TRichEditSpec
            AlignWithMargins = True
            Left = 141
            Top = 4
            Width = 556
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1055#1089#1080#1093#1086#1083#1086#1075#1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080#1056#1086#1076#1080#1090#1077#1083#1103#1084'][1][0][121]')
            TabOrder = 0
            OnChange = RichEditChanged
            OnExit = RichEditSpecExit
            OnKeyDown = RichEditSpecKeyDown
            OnKeyPress = RichEditSpecKeyPress
            FieldName = #1055#1089#1080#1093#1086#1083#1086#1075#1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080#1056#1086#1076#1080#1090#1077#1083#1103#1084
            FieldType = 1
            TextData = '['#1055#1089#1080#1093#1086#1083#1086#1075#1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080#1056#1086#1076#1080#1090#1077#1083#1103#1084'][1][0][121]'
            ListID = 121
            Appointment = 5
          end
        end
        object Panel97: TPanel
          Left = 0
          Top = 116
          Width = 730
          Height = 29
          Align = alTop
          TabOrder = 4
          object Label84: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 89
            Height = 21
            Align = alLeft
            Caption = #1044#1086#1087'. '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1103
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object RichEditSpec73: TRichEditSpec
            AlignWithMargins = True
            Left = 99
            Top = 4
            Width = 627
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1055#1089#1080#1093#1086#1083#1086#1075#1044#1086#1087#1048#1085#1092#1086'][1][5][0]')
            TabOrder = 0
            OnChange = RichEditChanged
            FieldName = #1055#1089#1080#1093#1086#1083#1086#1075#1044#1086#1087#1048#1085#1092#1086
            FieldType = 1
            TextData = '['#1055#1089#1080#1093#1086#1083#1086#1075#1044#1086#1087#1048#1085#1092#1086'][1][5][0]'
            Appointment = 5
          end
        end
      end
    end
    object TabSheet4: TTabSheet
      Caption = #1051#1086#1075#1086#1087#1077#1076#1080#1095#1077#1089#1082#1086#1077' '#1086#1073#1089#1083#1077#1076#1086#1074#1072#1085#1080#1077
      ImageIndex = -1
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object ScrollBox6: TScrollBox
        Left = 0
        Top = 0
        Width = 734
        Height = 590
        Align = alClient
        TabOrder = 0
        object GroupBox11: TGroupBox
          Left = 0
          Top = 29
          Width = 730
          Height = 84
          Align = alTop
          Caption = #1047#1072#1085#1103#1090#1080#1103' '#1089' '#1083#1086#1075#1086#1087#1077#1076#1086#1084
          Padding.Left = 3
          Padding.Top = 3
          Padding.Right = 3
          Padding.Bottom = 3
          TabOrder = 0
          object Panel11: TPanel
            Left = 5
            Top = 18
            Width = 720
            Height = 29
            Align = alTop
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
            object Label88: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 74
              Height = 21
              Align = alLeft
              Caption = #1043#1076#1077' '#1079#1072#1085#1080#1084#1072#1083#1089#1103
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object SpeedButton59: TSpeedButton
              AlignWithMargins = True
              Left = 693
              Top = 4
              Width = 23
              Height = 21
              Align = alRight
              Caption = '...'
              OnClick = SpeedButton59Click
              ExplicitLeft = 686
              ExplicitTop = -4
            end
            object RichEditSpec47: TRichEditSpec
              AlignWithMargins = True
              Left = 84
              Top = 4
              Width = 603
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1051#1086#1075#1086#1087#1077#1076#1043#1076#1077#1047#1072#1085#1080#1084#1072#1083#1089#1103'][4][0][36]')
              TabOrder = 0
              OnChange = RichEditChanged
              OnExit = RichEditSpecExit
              OnKeyDown = RichEditSpecKeyDown
              OnKeyPress = RichEditSpecKeyPress
              OnAfterSetItemID = RichEditSpecAfterSetItemID
              FieldName = #1051#1086#1075#1086#1087#1077#1076#1043#1076#1077#1047#1072#1085#1080#1084#1072#1083#1089#1103
              FieldType = 4
              TextData = '['#1051#1086#1075#1086#1087#1077#1076#1043#1076#1077#1047#1072#1085#1080#1084#1072#1083#1089#1103'][4][0][36]'
              ListID = 36
              Appointment = 6
            end
          end
          object Panel102: TPanel
            Left = 5
            Top = 47
            Width = 720
            Height = 29
            Align = alTop
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 1
            object Label89: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 124
              Height = 21
              Align = alLeft
              Caption = #1044#1086#1089#1090#1080#1075#1085#1091#1090#1099#1081' '#1088#1077#1079#1091#1083#1100#1090#1072#1090
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object SpeedButton32: TSpeedButton
              AlignWithMargins = True
              Left = 693
              Top = 4
              Width = 23
              Height = 21
              Align = alRight
              Glyph.Data = {
                E6000000424DE60000000000000076000000280000000E0000000E0000000100
                0400000000007000000000000000000000001000000000000000000000000000
                BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
                FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
                3300333333333333330033333333333333003333300033333300333330F03333
                3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
                3300333330F033333300333330F0333333003333300033333300333333333333
                33003333333333333300}
              OnClick = SpeedButton32Click
              ExplicitLeft = 643
              ExplicitTop = 1
            end
            object RichEditSpec77: TRichEditSpec
              AlignWithMargins = True
              Left = 134
              Top = 4
              Width = 553
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1051#1086#1075#1086#1087#1077#1076#1056#1077#1079#1091#1083#1100#1090#1072#1090'][1][0][62]')
              TabOrder = 0
              OnChange = RichEditChanged
              OnExit = RichEditSpecExit
              OnKeyDown = RichEditSpecKeyDown
              OnKeyPress = RichEditSpecKeyPress
              FieldName = #1051#1086#1075#1086#1087#1077#1076#1056#1077#1079#1091#1083#1100#1090#1072#1090
              FieldType = 1
              TextData = '['#1051#1086#1075#1086#1087#1077#1076#1056#1077#1079#1091#1083#1100#1090#1072#1090'][1][0][62]'
              ListID = 62
              Appointment = 6
            end
          end
        end
        object Panel113: TPanel
          Left = 0
          Top = 403
          Width = 730
          Height = 29
          Align = alTop
          TabOrder = 1
          object Label140: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 89
            Height = 21
            Align = alLeft
            Caption = #1044#1086#1087'. '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1103
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object RichEditSpec88: TRichEditSpec
            AlignWithMargins = True
            Left = 99
            Top = 4
            Width = 627
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1051#1086#1075#1086#1087#1077#1076#1044#1086#1087#1048#1085#1092#1086'][1][6][0]')
            TabOrder = 0
            OnChange = RichEditChanged
            FieldName = #1051#1086#1075#1086#1087#1077#1076#1044#1086#1087#1048#1085#1092#1086
            FieldType = 1
            TextData = '['#1051#1086#1075#1086#1087#1077#1076#1044#1086#1087#1048#1085#1092#1086'][1][6][0]'
            Appointment = 6
          end
        end
        object Panel112: TPanel
          Left = 0
          Top = 374
          Width = 730
          Height = 29
          Align = alTop
          TabOrder = 2
          object Label98: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 131
            Height = 21
            Align = alLeft
            Caption = #1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080' '#1088#1086#1076#1080#1090#1077#1083#1103#1084
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object SpeedButton42: TSpeedButton
            AlignWithMargins = True
            Left = 703
            Top = 4
            Width = 23
            Height = 21
            Align = alRight
            Glyph.Data = {
              E6000000424DE60000000000000076000000280000000E0000000E0000000100
              0400000000007000000000000000000000001000000000000000000000000000
              BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
              3300333333333333330033333333333333003333300033333300333330F03333
              3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
              3300333330F033333300333330F0333333003333300033333300333333333333
              33003333333333333300}
            OnClick = SpeedButton42Click
            ExplicitLeft = 643
            ExplicitTop = 1
          end
          object RichEditSpec87: TRichEditSpec
            AlignWithMargins = True
            Left = 141
            Top = 4
            Width = 556
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1051#1086#1075#1086#1087#1077#1076#1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080#1056#1086#1076#1080#1090#1077#1083#1103#1084'][1][0][121]')
            TabOrder = 0
            OnChange = RichEditChanged
            OnExit = RichEditSpecExit
            OnKeyDown = RichEditSpecKeyDown
            OnKeyPress = RichEditSpecKeyPress
            FieldName = #1051#1086#1075#1086#1087#1077#1076#1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080#1056#1086#1076#1080#1090#1077#1083#1103#1084
            FieldType = 1
            TextData = '['#1051#1086#1075#1086#1087#1077#1076#1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080#1056#1086#1076#1080#1090#1077#1083#1103#1084'][1][0][121]'
            ListID = 121
            Appointment = 6
          end
        end
        object Panel111: TPanel
          Left = 0
          Top = 345
          Width = 730
          Height = 29
          Align = alTop
          TabOrder = 3
          object Label97: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 129
            Height = 21
            Align = alLeft
            Caption = #1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080' '#1087#1077#1076#1072#1075#1086#1075#1072#1084
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object SpeedButton41: TSpeedButton
            AlignWithMargins = True
            Left = 703
            Top = 4
            Width = 23
            Height = 21
            Align = alRight
            Glyph.Data = {
              E6000000424DE60000000000000076000000280000000E0000000E0000000100
              0400000000007000000000000000000000001000000000000000000000000000
              BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
              3300333333333333330033333333333333003333300033333300333330F03333
              3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
              3300333330F033333300333330F0333333003333300033333300333333333333
              33003333333333333300}
            OnClick = SpeedButton41Click
            ExplicitLeft = 643
            ExplicitTop = 1
          end
          object RichEditSpec86: TRichEditSpec
            AlignWithMargins = True
            Left = 139
            Top = 4
            Width = 558
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1051#1086#1075#1086#1087#1077#1076#1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080'][1][0][121]')
            TabOrder = 0
            OnChange = RichEditChanged
            OnExit = RichEditSpecExit
            OnKeyDown = RichEditSpecKeyDown
            OnKeyPress = RichEditSpecKeyPress
            FieldName = #1051#1086#1075#1086#1087#1077#1076#1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080
            FieldType = 1
            TextData = '['#1051#1086#1075#1086#1087#1077#1076#1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080'][1][0][121]'
            ListID = 121
            Appointment = 6
          end
        end
        object Panel110: TPanel
          Left = 0
          Top = 316
          Width = 730
          Height = 29
          Align = alTop
          TabOrder = 4
          object Label96: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 63
            Height = 21
            Align = alLeft
            Caption = #1047#1072#1082#1083#1102#1095#1077#1085#1080#1077
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object SpeedButton40: TSpeedButton
            AlignWithMargins = True
            Left = 703
            Top = 4
            Width = 23
            Height = 21
            Align = alRight
            Glyph.Data = {
              E6000000424DE60000000000000076000000280000000E0000000E0000000100
              0400000000007000000000000000000000001000000000000000000000000000
              BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
              3300333333333333330033333333333333003333300033333300333330F03333
              3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
              3300333330F033333300333330F0333333003333300033333300333333333333
              33003333333333333300}
            OnClick = SpeedButton40Click
            ExplicitLeft = 643
            ExplicitTop = 1
          end
          object RichEditSpec85: TRichEditSpec
            AlignWithMargins = True
            Left = 73
            Top = 4
            Width = 624
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1051#1086#1075#1086#1087#1077#1076#1044#1080#1072#1075#1085#1086#1079#1099'][1][0][39]')
            TabOrder = 0
            OnChange = RichEditChanged
            OnExit = RichEditSpecExit
            OnKeyDown = RichEditSpecKeyDown
            OnKeyPress = RichEditSpecKeyPress
            FieldName = #1051#1086#1075#1086#1087#1077#1076#1044#1080#1072#1075#1085#1086#1079#1099
            FieldType = 1
            TextData = '['#1051#1086#1075#1086#1087#1077#1076#1044#1080#1072#1075#1085#1086#1079#1099'][1][0][39]'
            ListID = 39
            Appointment = 6
          end
        end
        object Panel109: TPanel
          Left = 0
          Top = 287
          Width = 730
          Height = 29
          Align = alTop
          TabOrder = 5
          object Label95: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 214
            Height = 21
            Align = alLeft
            Caption = #1054#1089#1086#1073#1077#1085#1085#1086#1089#1090#1080' '#1088#1077#1095#1080' '#1089#1074#1103#1079#1072#1085#1085#1099#1077' '#1089' '#1079#1072#1080#1082#1072#1085#1080#1077#1084
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object SpeedButton39: TSpeedButton
            AlignWithMargins = True
            Left = 703
            Top = 4
            Width = 23
            Height = 21
            Align = alRight
            Glyph.Data = {
              E6000000424DE60000000000000076000000280000000E0000000E0000000100
              0400000000007000000000000000000000001000000000000000000000000000
              BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
              3300333333333333330033333333333333003333300033333300333330F03333
              3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
              3300333330F033333300333330F0333333003333300033333300333333333333
              33003333333333333300}
            OnClick = SpeedButton39Click
            ExplicitLeft = 643
            ExplicitTop = 1
          end
          object RichEditSpec84: TRichEditSpec
            AlignWithMargins = True
            Left = 224
            Top = 4
            Width = 473
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1051#1086#1075#1086#1087#1077#1076#1047#1072#1080#1082#1072#1085#1080#1077'][1][0][62]')
            TabOrder = 0
            OnChange = RichEditChanged
            OnExit = RichEditSpecExit
            OnKeyDown = RichEditSpecKeyDown
            OnKeyPress = RichEditSpecKeyPress
            FieldName = #1051#1086#1075#1086#1087#1077#1076#1047#1072#1080#1082#1072#1085#1080#1077
            FieldType = 1
            TextData = '['#1051#1086#1075#1086#1087#1077#1076#1047#1072#1080#1082#1072#1085#1080#1077'][1][0][62]'
            ListID = 62
            Appointment = 6
          end
        end
        object Panel108: TPanel
          Left = 0
          Top = 258
          Width = 730
          Height = 29
          Align = alTop
          TabOrder = 6
          object Label94: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 37
            Height = 21
            Align = alLeft
            Caption = #1063#1090#1077#1085#1080#1077
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object SpeedButton38: TSpeedButton
            AlignWithMargins = True
            Left = 703
            Top = 4
            Width = 23
            Height = 21
            Align = alRight
            Glyph.Data = {
              E6000000424DE60000000000000076000000280000000E0000000E0000000100
              0400000000007000000000000000000000001000000000000000000000000000
              BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
              3300333333333333330033333333333333003333300033333300333330F03333
              3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
              3300333330F033333300333330F0333333003333300033333300333333333333
              33003333333333333300}
            OnClick = SpeedButton38Click
            ExplicitLeft = 643
            ExplicitTop = 1
          end
          object RichEditSpec83: TRichEditSpec
            AlignWithMargins = True
            Left = 47
            Top = 4
            Width = 650
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1051#1086#1075#1086#1087#1077#1076#1063#1090#1077#1085#1080#1077'][1][0][62]')
            TabOrder = 0
            OnChange = RichEditChanged
            OnExit = RichEditSpecExit
            OnKeyDown = RichEditSpecKeyDown
            OnKeyPress = RichEditSpecKeyPress
            FieldName = #1051#1086#1075#1086#1087#1077#1076#1063#1090#1077#1085#1080#1077
            FieldType = 1
            TextData = '['#1051#1086#1075#1086#1087#1077#1076#1063#1090#1077#1085#1080#1077'][1][0][62]'
            ListID = 62
            Appointment = 6
          end
        end
        object Panel103: TPanel
          Left = 0
          Top = 229
          Width = 730
          Height = 29
          Align = alTop
          TabOrder = 7
          object Label90: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 36
            Height = 21
            Align = alLeft
            Caption = #1055#1080#1089#1100#1084#1086
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object SpeedButton33: TSpeedButton
            AlignWithMargins = True
            Left = 703
            Top = 4
            Width = 23
            Height = 21
            Align = alRight
            Glyph.Data = {
              E6000000424DE60000000000000076000000280000000E0000000E0000000100
              0400000000007000000000000000000000001000000000000000000000000000
              BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
              3300333333333333330033333333333333003333300033333300333330F03333
              3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
              3300333330F033333300333330F0333333003333300033333300333333333333
              33003333333333333300}
            OnClick = SpeedButton33Click
            ExplicitLeft = 643
            ExplicitTop = 1
          end
          object RichEditSpec78: TRichEditSpec
            AlignWithMargins = True
            Left = 46
            Top = 4
            Width = 651
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1051#1086#1075#1086#1087#1077#1076#1055#1080#1089#1100#1084#1086'][1][0][62]')
            TabOrder = 0
            OnChange = RichEditChanged
            OnExit = RichEditSpecExit
            OnKeyDown = RichEditSpecKeyDown
            OnKeyPress = RichEditSpecKeyPress
            FieldName = #1051#1086#1075#1086#1087#1077#1076#1055#1080#1089#1100#1084#1086
            FieldType = 1
            TextData = '['#1051#1086#1075#1086#1087#1077#1076#1055#1080#1089#1100#1084#1086'][1][0][62]'
            ListID = 62
            Appointment = 6
          end
        end
        object Panel104: TPanel
          Left = 0
          Top = 200
          Width = 730
          Height = 29
          Align = alTop
          TabOrder = 8
          object Label91: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 142
            Height = 21
            Align = alLeft
            Caption = #1043#1088#1072#1084#1084#1072#1090#1080#1095#1077#1089#1082#1080#1081' '#1089#1090#1088#1086#1081' '#1088#1077#1095#1080
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object SpeedButton34: TSpeedButton
            AlignWithMargins = True
            Left = 703
            Top = 4
            Width = 23
            Height = 21
            Align = alRight
            Glyph.Data = {
              E6000000424DE60000000000000076000000280000000E0000000E0000000100
              0400000000007000000000000000000000001000000000000000000000000000
              BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
              3300333333333333330033333333333333003333300033333300333330F03333
              3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
              3300333330F033333300333330F0333333003333300033333300333333333333
              33003333333333333300}
            OnClick = SpeedButton34Click
            ExplicitLeft = 643
            ExplicitTop = 1
          end
          object RichEditSpec79: TRichEditSpec
            AlignWithMargins = True
            Left = 152
            Top = 4
            Width = 545
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1051#1086#1075#1086#1087#1077#1076#1057#1090#1088#1086#1081#1056#1077#1095#1080'][1][0][62]')
            TabOrder = 0
            OnChange = RichEditChanged
            OnExit = RichEditSpecExit
            OnKeyDown = RichEditSpecKeyDown
            OnKeyPress = RichEditSpecKeyPress
            FieldName = #1051#1086#1075#1086#1087#1077#1076#1057#1090#1088#1086#1081#1056#1077#1095#1080
            FieldType = 1
            TextData = '['#1051#1086#1075#1086#1087#1077#1076#1057#1090#1088#1086#1081#1056#1077#1095#1080'][1][0][62]'
            ListID = 62
            Appointment = 6
          end
        end
        object Panel105: TPanel
          Left = 0
          Top = 171
          Width = 730
          Height = 29
          Align = alTop
          TabOrder = 9
          object Label92: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 88
            Height = 21
            Align = alLeft
            Caption = #1057#1083#1086#1074#1072#1088#1085#1099#1081' '#1079#1072#1087#1072#1089
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object SpeedButton35: TSpeedButton
            AlignWithMargins = True
            Left = 703
            Top = 4
            Width = 23
            Height = 21
            Align = alRight
            Glyph.Data = {
              E6000000424DE60000000000000076000000280000000E0000000E0000000100
              0400000000007000000000000000000000001000000000000000000000000000
              BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
              3300333333333333330033333333333333003333300033333300333330F03333
              3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
              3300333330F033333300333330F0333333003333300033333300333333333333
              33003333333333333300}
            OnClick = SpeedButton35Click
            ExplicitLeft = 643
            ExplicitTop = 1
          end
          object RichEditSpec80: TRichEditSpec
            AlignWithMargins = True
            Left = 98
            Top = 4
            Width = 599
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1051#1086#1075#1086#1087#1077#1076#1057#1083#1086#1074#1072#1088#1085#1099#1081#1047#1072#1087#1072#1089'][1][0][62]')
            TabOrder = 0
            OnChange = RichEditChanged
            OnExit = RichEditSpecExit
            OnKeyDown = RichEditSpecKeyDown
            OnKeyPress = RichEditSpecKeyPress
            FieldName = #1051#1086#1075#1086#1087#1077#1076#1057#1083#1086#1074#1072#1088#1085#1099#1081#1047#1072#1087#1072#1089
            FieldType = 1
            TextData = '['#1051#1086#1075#1086#1087#1077#1076#1057#1083#1086#1074#1072#1088#1085#1099#1081#1047#1072#1087#1072#1089'][1][0][62]'
            ListID = 62
            Appointment = 6
          end
        end
        object Panel106: TPanel
          Left = 0
          Top = 142
          Width = 730
          Height = 29
          Align = alTop
          TabOrder = 10
          object Label93: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 119
            Height = 21
            Align = alLeft
            Caption = #1047#1074#1091#1082#1086#1074#1072#1103' '#1089#1090#1086#1088#1086#1085#1072' '#1088#1077#1095#1080
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object SpeedButton36: TSpeedButton
            AlignWithMargins = True
            Left = 703
            Top = 4
            Width = 23
            Height = 21
            Align = alRight
            Glyph.Data = {
              E6000000424DE60000000000000076000000280000000E0000000E0000000100
              0400000000007000000000000000000000001000000000000000000000000000
              BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
              3300333333333333330033333333333333003333300033333300333330F03333
              3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
              3300333330F033333300333330F0333333003333300033333300333333333333
              33003333333333333300}
            OnClick = SpeedButton36Click
            ExplicitLeft = 643
            ExplicitTop = 1
          end
          object RichEditSpec81: TRichEditSpec
            AlignWithMargins = True
            Left = 129
            Top = 4
            Width = 568
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1051#1086#1075#1086#1087#1077#1076#1047#1074#1091#1082'][1][0][62]')
            TabOrder = 0
            OnChange = RichEditChanged
            OnExit = RichEditSpecExit
            OnKeyDown = RichEditSpecKeyDown
            OnKeyPress = RichEditSpecKeyPress
            FieldName = #1051#1086#1075#1086#1087#1077#1076#1047#1074#1091#1082
            FieldType = 1
            TextData = '['#1051#1086#1075#1086#1087#1077#1076#1047#1074#1091#1082'][1][0][62]'
            ListID = 62
            Appointment = 6
          end
        end
        object Panel101: TPanel
          Left = 0
          Top = 0
          Width = 730
          Height = 29
          Align = alTop
          TabOrder = 11
          object Label87: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 106
            Height = 21
            Align = alLeft
            Caption = #1056#1086#1076#1085#1086#1081' '#1103#1079#1099#1082' '#1074' '#1089#1077#1084#1100#1077
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object SpeedButton58: TSpeedButton
            AlignWithMargins = True
            Left = 703
            Top = 4
            Width = 23
            Height = 21
            Align = alRight
            Caption = '...'
            OnClick = SpeedButton58Click
            ExplicitLeft = 686
            ExplicitTop = -4
          end
          object RichEditSpec44: TRichEditSpec
            AlignWithMargins = True
            Left = 116
            Top = 4
            Width = 581
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1051#1086#1075#1086#1087#1077#1076#1071#1079#1099#1082'][4][0][76]')
            TabOrder = 0
            OnChange = RichEditChanged
            OnExit = RichEditSpecExit
            OnKeyDown = RichEditSpecKeyDown
            OnKeyPress = RichEditSpecKeyPress
            OnAfterSetItemID = RichEditSpecAfterSetItemID
            FieldName = #1051#1086#1075#1086#1087#1077#1076#1071#1079#1099#1082
            FieldType = 4
            TextData = '['#1051#1086#1075#1086#1087#1077#1076#1071#1079#1099#1082'][4][0][76]'
            ListID = 76
            Appointment = 6
          end
        end
        object Panel107: TPanel
          Left = 0
          Top = 113
          Width = 730
          Height = 29
          Align = alTop
          TabOrder = 12
          object Label139: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 69
            Height = 21
            Align = alLeft
            Caption = #1057#1074#1103#1079#1085#1072#1103' '#1088#1077#1095#1100
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object SpeedButton37: TSpeedButton
            AlignWithMargins = True
            Left = 703
            Top = 4
            Width = 23
            Height = 21
            Align = alRight
            Glyph.Data = {
              E6000000424DE60000000000000076000000280000000E0000000E0000000100
              0400000000007000000000000000000000001000000000000000000000000000
              BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
              3300333333333333330033333333333333003333300033333300333330F03333
              3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
              3300333330F033333300333330F0333333003333300033333300333333333333
              33003333333333333300}
            OnClick = SpeedButton37Click
            ExplicitLeft = 643
            ExplicitTop = 1
          end
          object RichEditSpec82: TRichEditSpec
            AlignWithMargins = True
            Left = 79
            Top = 4
            Width = 618
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1051#1086#1075#1086#1087#1077#1076#1056#1077#1095#1100'][1][0][62]')
            TabOrder = 0
            OnChange = RichEditChanged
            OnExit = RichEditSpecExit
            OnKeyDown = RichEditSpecKeyDown
            OnKeyPress = RichEditSpecKeyPress
            FieldName = #1051#1086#1075#1086#1087#1077#1076#1056#1077#1095#1100
            FieldType = 1
            TextData = '['#1051#1086#1075#1086#1087#1077#1076#1056#1077#1095#1100'][1][0][62]'
            ListID = 62
            Appointment = 6
          end
        end
      end
    end
    object TabSheet5: TTabSheet
      Caption = #1055#1077#1076#1072#1075#1086#1075#1080#1095#1077#1089#1082#1086#1077' '#1086#1073#1089#1083#1077#1076#1086#1074#1072#1085#1080#1077
      ImageIndex = -1
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object ScrollBox5: TScrollBox
        Left = 0
        Top = 0
        Width = 734
        Height = 590
        Align = alClient
        TabOrder = 0
        OnMouseWheel = ScrollBoxMouseWheel
        object Panel119: TPanel
          Left = 0
          Top = 0
          Width = 713
          Height = 29
          Align = alTop
          TabOrder = 0
          object Label141: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 303
            Height = 21
            Align = alLeft
            Caption = #1047#1085#1072#1085#1080#1103' '#1080' '#1085#1072#1074#1099#1082#1080' '#1087#1086' '#1087#1088#1086#1075#1088#1072#1084#1084#1085#1086#1084#1091' '#1084#1072#1090#1077#1088#1080#1072#1083#1091' '#1044#1054#1059' ('#1096#1082#1086#1083#1099')'
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object SpeedButton43: TSpeedButton
            AlignWithMargins = True
            Left = 686
            Top = 4
            Width = 23
            Height = 21
            Align = alRight
            Glyph.Data = {
              E6000000424DE60000000000000076000000280000000E0000000E0000000100
              0400000000007000000000000000000000001000000000000000000000000000
              BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
              3300333333333333330033333333333333003333300033333300333330F03333
              3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
              3300333330F033333300333330F0333333003333300033333300333333333333
              33003333333333333300}
            OnClick = SpeedButton43Click
            ExplicitLeft = 643
            ExplicitTop = 1
          end
          object RichEditSpec89: TRichEditSpec
            AlignWithMargins = True
            Left = 313
            Top = 4
            Width = 367
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1055#1088#1086#1075#1088#1072#1084#1084#1072'][1][0][62]')
            TabOrder = 0
            OnChange = RichEditChanged
            OnExit = RichEditSpecExit
            OnKeyDown = RichEditSpecKeyDown
            OnKeyPress = RichEditSpecKeyPress
            FieldName = #1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1055#1088#1086#1075#1088#1072#1084#1084#1072
            FieldType = 1
            TextData = '['#1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1055#1088#1086#1075#1088#1072#1084#1084#1072'][1][0][62]'
            ListID = 62
            Appointment = 3
          end
        end
        object Panel118: TPanel
          Left = 0
          Top = 29
          Width = 713
          Height = 29
          Align = alTop
          TabOrder = 1
          object Label104: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 239
            Height = 21
            Align = alLeft
            Caption = #1047#1085#1072#1085#1080#1103' '#1080' '#1087#1088#1077#1076#1089#1090#1072#1074#1083#1077#1085#1080#1103' '#1086#1073' '#1086#1082#1088#1091#1078#1072#1102#1097#1077#1084' '#1084#1080#1088#1077
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object SpeedButton44: TSpeedButton
            AlignWithMargins = True
            Left = 686
            Top = 4
            Width = 23
            Height = 21
            Align = alRight
            Glyph.Data = {
              E6000000424DE60000000000000076000000280000000E0000000E0000000100
              0400000000007000000000000000000000001000000000000000000000000000
              BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
              3300333333333333330033333333333333003333300033333300333330F03333
              3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
              3300333330F033333300333330F0333333003333300033333300333333333333
              33003333333333333300}
            OnClick = SpeedButton44Click
            ExplicitLeft = 643
            ExplicitTop = 1
          end
          object RichEditSpec90: TRichEditSpec
            AlignWithMargins = True
            Left = 249
            Top = 4
            Width = 431
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1054#1082#1088#1052#1080#1088'][1][0][62]')
            TabOrder = 0
            OnChange = RichEditChanged
            OnExit = RichEditSpecExit
            OnKeyDown = RichEditSpecKeyDown
            OnKeyPress = RichEditSpecKeyPress
            FieldName = #1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1054#1082#1088#1052#1080#1088
            FieldType = 1
            TextData = '['#1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1054#1082#1088#1052#1080#1088'][1][0][62]'
            ListID = 62
            Appointment = 3
          end
        end
        object Panel117: TPanel
          Left = 0
          Top = 58
          Width = 713
          Height = 29
          Align = alTop
          TabOrder = 2
          object Label103: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 239
            Height = 21
            Align = alLeft
            Caption = #1054#1088#1080#1077#1085#1090#1080#1088#1086#1074#1072#1085#1085#1086#1089#1090#1100' '#1074' '#1087#1088#1086#1089#1090#1088#1072#1085#1089#1090#1074#1077' '#1080' '#1074#1088#1077#1084#1077#1085#1080
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object SpeedButton45: TSpeedButton
            AlignWithMargins = True
            Left = 686
            Top = 4
            Width = 23
            Height = 21
            Align = alRight
            Glyph.Data = {
              E6000000424DE60000000000000076000000280000000E0000000E0000000100
              0400000000007000000000000000000000001000000000000000000000000000
              BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
              3300333333333333330033333333333333003333300033333300333330F03333
              3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
              3300333330F033333300333330F0333333003333300033333300333333333333
              33003333333333333300}
            OnClick = SpeedButton45Click
            ExplicitLeft = 643
            ExplicitTop = 1
          end
          object RichEditSpec91: TRichEditSpec
            AlignWithMargins = True
            Left = 249
            Top = 4
            Width = 431
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1055#1088#1086#1089#1090#1088#1072#1085#1089#1090#1074#1086'][1][0][62]')
            TabOrder = 0
            OnChange = RichEditChanged
            OnExit = RichEditSpecExit
            OnKeyDown = RichEditSpecKeyDown
            OnKeyPress = RichEditSpecKeyPress
            FieldName = #1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1055#1088#1086#1089#1090#1088#1072#1085#1089#1090#1074#1086
            FieldType = 1
            TextData = '['#1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1055#1088#1086#1089#1090#1088#1072#1085#1089#1090#1074#1086'][1][0][62]'
            ListID = 62
            Appointment = 3
          end
        end
        object Panel116: TPanel
          Left = 0
          Top = 87
          Width = 713
          Height = 29
          Align = alTop
          TabOrder = 3
          object Label102: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 251
            Height = 21
            Align = alLeft
            Caption = #1047#1085#1072#1085#1080#1103' '#1087#1086' '#1088#1091#1089#1089#1082#1086#1084#1091' '#1103#1079#1099#1082#1091', '#1095#1090#1077#1085#1080#1102' ('#1083#1080#1090#1077#1088#1072#1090#1091#1088#1077')'
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object SpeedButton46: TSpeedButton
            AlignWithMargins = True
            Left = 686
            Top = 4
            Width = 23
            Height = 21
            Align = alRight
            Glyph.Data = {
              E6000000424DE60000000000000076000000280000000E0000000E0000000100
              0400000000007000000000000000000000001000000000000000000000000000
              BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
              3300333333333333330033333333333333003333300033333300333330F03333
              3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
              3300333330F033333300333330F0333333003333300033333300333333333333
              33003333333333333300}
            OnClick = SpeedButton46Click
            ExplicitLeft = 1000
            ExplicitTop = 1
          end
          object RichEditSpec92: TRichEditSpec
            AlignWithMargins = True
            Left = 261
            Top = 4
            Width = 419
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1056#1091#1089#1071#1079'][1][0][62]')
            TabOrder = 0
            OnChange = RichEditChanged
            OnExit = RichEditSpecExit
            OnKeyDown = RichEditSpecKeyDown
            OnKeyPress = RichEditSpecKeyPress
            FieldName = #1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1056#1091#1089#1071#1079
            FieldType = 1
            TextData = '['#1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1056#1091#1089#1071#1079'][1][0][62]'
            ListID = 62
            Appointment = 3
          end
        end
        object Panel115: TPanel
          Left = 0
          Top = 116
          Width = 713
          Height = 29
          Align = alTop
          TabOrder = 4
          object Label101: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 114
            Height = 21
            Align = alLeft
            Caption = #1047#1085#1072#1085#1080#1103' '#1087#1086' '#1084#1072#1090#1077#1084#1072#1090#1080#1082#1077
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object SpeedButton47: TSpeedButton
            AlignWithMargins = True
            Left = 686
            Top = 4
            Width = 23
            Height = 21
            Align = alRight
            Glyph.Data = {
              E6000000424DE60000000000000076000000280000000E0000000E0000000100
              0400000000007000000000000000000000001000000000000000000000000000
              BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
              3300333333333333330033333333333333003333300033333300333330F03333
              3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
              3300333330F033333300333330F0333333003333300033333300333333333333
              33003333333333333300}
            OnClick = SpeedButton47Click
            ExplicitLeft = 1000
            ExplicitTop = 1
          end
          object RichEditSpec93: TRichEditSpec
            AlignWithMargins = True
            Left = 124
            Top = 4
            Width = 556
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1052#1072#1090#1077#1084'][1][0][62]')
            TabOrder = 0
            OnChange = RichEditChanged
            OnExit = RichEditSpecExit
            OnKeyDown = RichEditSpecKeyDown
            OnKeyPress = RichEditSpecKeyPress
            FieldName = #1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1052#1072#1090#1077#1084
            FieldType = 1
            TextData = '['#1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1052#1072#1090#1077#1084'][1][0][62]'
            ListID = 62
            Appointment = 3
          end
        end
        object Panel114: TPanel
          Left = 0
          Top = 145
          Width = 713
          Height = 29
          Align = alTop
          TabOrder = 5
          object Label100: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 110
            Height = 21
            Align = alLeft
            Caption = #1055#1086' '#1076#1088#1091#1075#1080#1084' '#1087#1088#1077#1076#1084#1077#1090#1072#1084
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object SpeedButton48: TSpeedButton
            AlignWithMargins = True
            Left = 686
            Top = 4
            Width = 23
            Height = 21
            Align = alRight
            Glyph.Data = {
              E6000000424DE60000000000000076000000280000000E0000000E0000000100
              0400000000007000000000000000000000001000000000000000000000000000
              BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
              3300333333333333330033333333333333003333300033333300333330F03333
              3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
              3300333330F033333300333330F0333333003333300033333300333333333333
              33003333333333333300}
            OnClick = SpeedButton48Click
            ExplicitLeft = 1000
            ExplicitTop = 1
          end
          object RichEditSpec94: TRichEditSpec
            AlignWithMargins = True
            Left = 120
            Top = 4
            Width = 560
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1044#1088#1091#1075#1080#1077'][1][0][62]')
            TabOrder = 0
            OnChange = RichEditChanged
            OnExit = RichEditSpecExit
            OnKeyDown = RichEditSpecKeyDown
            OnKeyPress = RichEditSpecKeyPress
            FieldName = #1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1044#1088#1091#1075#1080#1077
            FieldType = 1
            TextData = '['#1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1044#1088#1091#1075#1080#1077'][1][0][62]'
            ListID = 62
            Appointment = 3
          end
        end
        object Panel125: TPanel
          Left = 0
          Top = 174
          Width = 713
          Height = 29
          Align = alTop
          TabOrder = 6
          object Label114: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 226
            Height = 21
            Align = alLeft
            Caption = #1054#1073#1091#1095#1072#1077#1084#1086#1089#1090#1100', '#1089#1087#1086#1089#1086#1073#1099' '#1074#1099#1087#1086#1083#1085#1077#1085#1080#1103' '#1079#1072#1076#1072#1085#1080#1081
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object SpeedButton49: TSpeedButton
            AlignWithMargins = True
            Left = 686
            Top = 4
            Width = 23
            Height = 21
            Align = alRight
            Glyph.Data = {
              E6000000424DE60000000000000076000000280000000E0000000E0000000100
              0400000000007000000000000000000000001000000000000000000000000000
              BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
              3300333333333333330033333333333333003333300033333300333330F03333
              3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
              3300333330F033333300333330F0333333003333300033333300333333333333
              33003333333333333300}
            OnClick = SpeedButton49Click
            ExplicitLeft = 1000
            ExplicitTop = 1
          end
          object RichEditSpec95: TRichEditSpec
            AlignWithMargins = True
            Left = 236
            Top = 4
            Width = 444
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1054#1073#1091#1095#1072#1077#1084#1086#1089#1090#1100'][1][0][62]')
            TabOrder = 0
            OnChange = RichEditChanged
            OnExit = RichEditSpecExit
            OnKeyDown = RichEditSpecKeyDown
            OnKeyPress = RichEditSpecKeyPress
            FieldName = #1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1054#1073#1091#1095#1072#1077#1084#1086#1089#1090#1100
            FieldType = 1
            TextData = '['#1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1054#1073#1091#1095#1072#1077#1084#1086#1089#1090#1100'][1][0][62]'
            ListID = 62
            Appointment = 3
          end
        end
        object Panel124: TPanel
          Left = 0
          Top = 203
          Width = 713
          Height = 29
          Align = alTop
          TabOrder = 7
          object Label113: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 121
            Height = 21
            Align = alLeft
            Caption = #1054#1090#1085#1086#1096#1077#1085#1080#1077' '#1082' '#1086#1073#1091#1095#1077#1085#1080#1102
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object SpeedButton50: TSpeedButton
            AlignWithMargins = True
            Left = 686
            Top = 4
            Width = 23
            Height = 21
            Align = alRight
            Glyph.Data = {
              E6000000424DE60000000000000076000000280000000E0000000E0000000100
              0400000000007000000000000000000000001000000000000000000000000000
              BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
              3300333333333333330033333333333333003333300033333300333330F03333
              3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
              3300333330F033333300333330F0333333003333300033333300333333333333
              33003333333333333300}
            OnClick = SpeedButton50Click
            ExplicitLeft = 1000
            ExplicitTop = 1
          end
          object RichEditSpec96: TRichEditSpec
            AlignWithMargins = True
            Left = 131
            Top = 4
            Width = 549
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1054#1090#1085#1086#1096#1077#1085#1080#1077'][1][0][62]')
            TabOrder = 0
            OnChange = RichEditChanged
            OnExit = RichEditSpecExit
            OnKeyDown = RichEditSpecKeyDown
            OnKeyPress = RichEditSpecKeyPress
            FieldName = #1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1054#1090#1085#1086#1096#1077#1085#1080#1077
            FieldType = 1
            TextData = '['#1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1054#1090#1085#1086#1096#1077#1085#1080#1077'][1][0][62]'
            ListID = 62
            Appointment = 3
          end
        end
        object Panel123: TPanel
          Left = 0
          Top = 232
          Width = 713
          Height = 29
          Align = alTop
          TabOrder = 8
          object Label112: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 210
            Height = 21
            Align = alLeft
            Caption = #1053#1072#1074#1099#1082#1080' '#1082' '#1089#1086#1094#1080#1072#1083#1100#1085#1086'-'#1073#1099#1090#1086#1074#1086#1081' '#1072#1076#1072#1087#1090#1072#1094#1080#1080
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object SpeedButton51: TSpeedButton
            AlignWithMargins = True
            Left = 686
            Top = 4
            Width = 23
            Height = 21
            Align = alRight
            Glyph.Data = {
              E6000000424DE60000000000000076000000280000000E0000000E0000000100
              0400000000007000000000000000000000001000000000000000000000000000
              BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
              3300333333333333330033333333333333003333300033333300333330F03333
              3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
              3300333330F033333300333330F0333333003333300033333300333333333333
              33003333333333333300}
            OnClick = SpeedButton51Click
            ExplicitLeft = 1000
            ExplicitTop = 1
          end
          object RichEditSpec97: TRichEditSpec
            AlignWithMargins = True
            Left = 220
            Top = 4
            Width = 460
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1057#1086#1094#1041#1099#1090'][1][0][62]')
            TabOrder = 0
            OnChange = RichEditChanged
            OnExit = RichEditSpecExit
            OnKeyDown = RichEditSpecKeyDown
            OnKeyPress = RichEditSpecKeyPress
            FieldName = #1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1057#1086#1094#1041#1099#1090
            FieldType = 1
            TextData = '['#1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1057#1086#1094#1041#1099#1090'][1][0][62]'
            ListID = 62
            Appointment = 3
          end
        end
        object Panel122: TPanel
          Left = 0
          Top = 261
          Width = 713
          Height = 29
          Align = alTop
          TabOrder = 9
          object Label111: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 63
            Height = 21
            Align = alLeft
            Caption = #1047#1072#1082#1083#1102#1095#1077#1085#1080#1077
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object SpeedButton52: TSpeedButton
            AlignWithMargins = True
            Left = 686
            Top = 4
            Width = 23
            Height = 21
            Align = alRight
            Glyph.Data = {
              E6000000424DE60000000000000076000000280000000E0000000E0000000100
              0400000000007000000000000000000000001000000000000000000000000000
              BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
              3300333333333333330033333333333333003333300033333300333330F03333
              3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
              3300333330F033333300333330F0333333003333300033333300333333333333
              33003333333333333300}
            OnClick = SpeedButton52Click
            ExplicitLeft = 1000
            ExplicitTop = 1
          end
          object RichEditSpec98: TRichEditSpec
            AlignWithMargins = True
            Left = 73
            Top = 4
            Width = 607
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1044#1080#1072#1075#1085#1086#1079#1099'][1][0][121]')
            TabOrder = 0
            OnChange = RichEditChanged
            OnExit = RichEditSpecExit
            OnKeyDown = RichEditSpecKeyDown
            OnKeyPress = RichEditSpecKeyPress
            FieldName = #1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1044#1080#1072#1075#1085#1086#1079#1099
            FieldType = 1
            TextData = '['#1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1044#1080#1072#1075#1085#1086#1079#1099'][1][0][121]'
            ListID = 121
            Appointment = 3
          end
        end
        object Panel121: TPanel
          Left = 0
          Top = 290
          Width = 713
          Height = 29
          Align = alTop
          TabOrder = 10
          object Label110: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 129
            Height = 21
            Align = alLeft
            Caption = #1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080' '#1087#1077#1076#1072#1075#1086#1075#1072#1084
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object SpeedButton53: TSpeedButton
            AlignWithMargins = True
            Left = 686
            Top = 4
            Width = 23
            Height = 21
            Align = alRight
            Glyph.Data = {
              E6000000424DE60000000000000076000000280000000E0000000E0000000100
              0400000000007000000000000000000000001000000000000000000000000000
              BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
              3300333333333333330033333333333333003333300033333300333330F03333
              3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
              3300333330F033333300333330F0333333003333300033333300333333333333
              33003333333333333300}
            OnClick = SpeedButton53Click
            ExplicitLeft = 1000
            ExplicitTop = 1
          end
          object RichEditSpec99: TRichEditSpec
            AlignWithMargins = True
            Left = 139
            Top = 4
            Width = 541
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080'][1][0][121]')
            TabOrder = 0
            OnChange = RichEditChanged
            OnExit = RichEditSpecExit
            OnKeyDown = RichEditSpecKeyDown
            OnKeyPress = RichEditSpecKeyPress
            FieldName = #1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080
            FieldType = 1
            TextData = '['#1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080'][1][0][121]'
            ListID = 121
            Appointment = 3
          end
        end
        object Panel120: TPanel
          Left = 0
          Top = 319
          Width = 713
          Height = 29
          Align = alTop
          TabOrder = 11
          object Label105: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 131
            Height = 21
            Align = alLeft
            Caption = #1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080' '#1088#1086#1076#1080#1090#1077#1083#1103#1084
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object SpeedButton54: TSpeedButton
            AlignWithMargins = True
            Left = 686
            Top = 4
            Width = 23
            Height = 21
            Align = alRight
            Glyph.Data = {
              E6000000424DE60000000000000076000000280000000E0000000E0000000100
              0400000000007000000000000000000000001000000000000000000000000000
              BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
              3300333333333333330033333333333333003333300033333300333330F03333
              3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
              3300333330F033333300333330F0333333003333300033333300333333333333
              33003333333333333300}
            OnClick = SpeedButton54Click
            ExplicitLeft = 1000
            ExplicitTop = 1
          end
          object RichEditSpec100: TRichEditSpec
            AlignWithMargins = True
            Left = 141
            Top = 4
            Width = 539
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080#1056#1086#1076#1080#1090#1077#1083#1103#1084'][1][0][121]')
            TabOrder = 0
            OnChange = RichEditChanged
            OnExit = RichEditSpecExit
            OnKeyDown = RichEditSpecKeyDown
            OnKeyPress = RichEditSpecKeyPress
            FieldName = #1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080#1056#1086#1076#1080#1090#1077#1083#1103#1084
            FieldType = 1
            TextData = '['#1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080#1056#1086#1076#1080#1090#1077#1083#1103#1084'][1][0][121]'
            ListID = 121
            Appointment = 3
          end
        end
        object Panel12: TPanel
          Left = 0
          Top = 348
          Width = 713
          Height = 29
          Align = alTop
          TabOrder = 12
          object Label99: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 89
            Height = 21
            Align = alLeft
            Caption = #1044#1086#1087'. '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1103
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object RichEditSpec101: TRichEditSpec
            AlignWithMargins = True
            Left = 99
            Top = 4
            Width = 610
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1044#1086#1087#1048#1085#1092#1086'][1][3][0]')
            TabOrder = 0
            OnChange = RichEditChanged
            FieldName = #1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1044#1086#1087#1048#1085#1092#1086
            FieldType = 1
            TextData = '['#1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1044#1086#1087#1048#1085#1092#1086'][1][3][0]'
            Appointment = 3
          end
        end
        object GroupBox17: TGroupBox
          Left = 0
          Top = 377
          Width = 713
          Height = 116
          Align = alTop
          Caption = #1047#1072#1082#1083#1102#1095#1077#1085#1080#1077
          TabOrder = 13
          object Panel62: TPanel
            Left = 2
            Top = 15
            Width = 709
            Height = 34
            Align = alTop
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
            object Label126: TLabel
              Tag = 2
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 376
              Height = 26
              Align = alLeft
              Caption = 
                #1055#1086' '#1088#1077#1079#1091#1083#1100#1090#1072#1090#1072#1084' '#1082#1086#1084#1087#1083#1077#1082#1089#1085#1086#1075#1086' '#1087#1089#1080#1093#1086#1083#1086#1075#1086'-'#1084#1077#1076#1080#1082#1086'-'#1087#1077#1076#1072#1075#1086#1075#1080#1095#1077#1089#1082#1086#1075#1086' '#1086#1073#1089 +
                #1083#1077#1076#1086#1074#1072#1085#1080#1103' '#1089#1090#1072#1090#1091#1089' '#1088#1077#1073#1077#1085#1082#1072' '#1089' '#1086#1075#1088#1072#1085#1080#1095#1077#1085#1085#1099#1084#1080' '#1074#1086#1079#1084#1086#1078#1085#1086#1089#1090#1103#1084#1080' '#1079#1076#1086#1088#1086#1074#1100#1103
              Layout = tlCenter
              WordWrap = True
              ExplicitLeft = 9
              ExplicitTop = 2
            end
            object ComboBoxSpec31: TComboBoxSpec
              AlignWithMargins = True
              Left = 386
              Top = 4
              Width = 145
              Height = 21
              Align = alLeft
              ItemHeight = 0
              TabOrder = 0
              Text = '['#1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1055#1086#1056#1077#1079#1091#1083#1100#1090#1072#1090#1072#1084'][5][3][170]'
              OnSelect = ComboBoxSpecSelect
              OnAfterSetItemID = ComboBoxChanged
              OnMouseWheelUp = ComboBoxSpecMouseWheelUp
              OnMouseWheelDown = ComboBoxSpecMouseWheelDown
              FieldName = #1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1055#1086#1056#1077#1079#1091#1083#1100#1090#1072#1090#1072#1084
              FieldType = 5
              ParentID = 170
              Appointment = 3
              ListID = 1
            end
          end
          object Panel74: TPanel
            Left = 2
            Top = 49
            Width = 709
            Height = 29
            Align = alTop
            TabOrder = 1
            object Label125: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 121
              Height = 13
              Align = alLeft
              Caption = #1042#1099#1103#1074#1083#1077#1085#1099' '#1090#1088#1091#1076#1085#1086#1089#1090#1080' '#1074' '
              Layout = tlCenter
            end
            object ComboBoxSpec30: TComboBoxSpec
              AlignWithMargins = True
              Left = 131
              Top = 4
              Width = 135
              Height = 21
              Align = alLeft
              ItemHeight = 0
              TabOrder = 0
              Text = '['#1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1042#1099#1103#1074#1083#1077#1085#1099#1058#1088#1091#1076#1085#1086#1089#1090#1080'][5][3][174]'
              OnSelect = ComboBoxSpecSelect
              OnAfterSetItemID = ComboBoxChanged
              OnMouseWheelUp = ComboBoxSpecMouseWheelUp
              OnMouseWheelDown = ComboBoxSpecMouseWheelDown
              FieldName = #1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1042#1099#1103#1074#1083#1077#1085#1099#1058#1088#1091#1076#1085#1086#1089#1090#1080
              FieldType = 5
              ParentID = 174
              Appointment = 3
              ListID = 1
            end
          end
          object Panel75: TPanel
            Left = 2
            Top = 78
            Width = 709
            Height = 29
            Align = alTop
            TabOrder = 2
            object Label3: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 79
              Height = 21
              Align = alLeft
              Caption = #1086#1073#1091#1089#1083#1086#1074#1083#1077#1085#1085#1099#1077
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object SpeedButton6: TSpeedButton
              AlignWithMargins = True
              Left = 682
              Top = 4
              Width = 23
              Height = 21
              Align = alRight
              Glyph.Data = {
                E6000000424DE60000000000000076000000280000000E0000000E0000000100
                0400000000007000000000000000000000001000000000000000000000000000
                BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
                FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
                3300333333333333330033333333333333003333300033333300333330F03333
                3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
                3300333330F033333300333330F0333333003333300033333300333333333333
                33003333333333333300}
              OnClick = SpeedButton6Click
              ExplicitTop = 6
            end
            object RichEditSpec17: TRichEditSpec
              AlignWithMargins = True
              Left = 89
              Top = 4
              Width = 587
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1054#1073#1091#1089#1083#1086#1074#1083#1077#1085#1085#1099#1077'][1][3][0]')
              TabOrder = 0
              OnChange = RichEditChanged
              OnExit = RichEditSpecExit
              OnKeyDown = RichEditSpecKeyDown
              OnKeyPress = RichEditSpecKeyPress
              FieldName = #1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1054#1073#1091#1089#1083#1086#1074#1083#1077#1085#1085#1099#1077
              FieldType = 1
              TextData = '['#1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1054#1073#1091#1089#1083#1086#1074#1083#1077#1085#1085#1099#1077'][1][3][0]'
              Appointment = 3
            end
          end
        end
        object GroupBox18: TGroupBox
          Left = 0
          Top = 493
          Width = 713
          Height = 104
          Align = alTop
          Caption = #1056#1077#1073#1077#1085#1086#1082' '#1085#1091#1078#1076#1072#1077#1090#1089#1103' '#1074' '#1089#1087#1077#1094#1080#1072#1083#1100#1085#1099#1093' '#1086#1073#1088#1072#1079#1086#1074#1072#1090#1077#1083#1100#1085#1099#1093' '#1091#1089#1083#1086#1074#1080#1103#1093
          TabOrder = 14
          object Panel134: TPanel
            Left = 2
            Top = 15
            Width = 709
            Height = 29
            Align = alTop
            TabOrder = 0
            object Label127: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 62
              Height = 13
              Align = alLeft
              Caption = #1054#1073#1091#1095#1077#1085#1080#1077' '#1074' '
              Layout = tlCenter
            end
            object Label129: TLabel
              AlignWithMargins = True
              Left = 131
              Top = 4
              Width = 211
              Height = 13
              Align = alLeft
              Caption = #1082#1083#1072#1089#1089#1077' '#1086#1073#1088#1072#1079#1086#1074#1072#1090#1077#1083#1100#1085#1086#1081' '#1086#1088#1075#1072#1085#1080#1079#1072#1094#1080#1080' '#1087#1086' '
              Layout = tlCenter
            end
            object ComboBoxSpec32: TComboBoxSpec
              AlignWithMargins = True
              Left = 72
              Top = 4
              Width = 53
              Height = 21
              Align = alLeft
              ItemHeight = 0
              TabOrder = 0
              Text = '['#1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1050#1083#1072#1089#1089'][5][3][177]'
              OnSelect = ComboBoxSpecSelect
              OnAfterSetItemID = ComboBoxChanged
              OnMouseWheelUp = ComboBoxSpecMouseWheelUp
              OnMouseWheelDown = ComboBoxSpecMouseWheelDown
              FieldName = #1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1050#1083#1072#1089#1089
              FieldType = 5
              ParentID = 177
              Appointment = 3
              ListID = 1
            end
            object ComboBoxSpec33: TComboBoxSpec
              AlignWithMargins = True
              Left = 348
              Top = 4
              Width = 321
              Height = 21
              Align = alLeft
              ItemHeight = 0
              TabOrder = 1
              Text = '['#1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1055#1086#1055#1088#1086#1075#1088#1072#1084#1084#1077'][5][3][189]'
              OnSelect = ComboBoxSpecSelect
              OnAfterSetItemID = ComboBoxChanged
              OnMouseWheelUp = ComboBoxSpecMouseWheelUp
              OnMouseWheelDown = ComboBoxSpecMouseWheelDown
              FieldName = #1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1055#1086#1055#1088#1086#1075#1088#1072#1084#1084#1077
              FieldType = 5
              ParentID = 189
              Appointment = 3
              ListID = 1
            end
          end
          object Panel135: TPanel
            Left = 2
            Top = 44
            Width = 709
            Height = 29
            Align = alTop
            TabOrder = 1
            object Label142: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 56
              Height = 21
              Align = alLeft
              Caption = #1076#1083#1103' '#1076#1077#1090#1077#1081' '
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object SpeedButton64: TSpeedButton
              AlignWithMargins = True
              Left = 682
              Top = 4
              Width = 23
              Height = 21
              Align = alRight
              Glyph.Data = {
                E6000000424DE60000000000000076000000280000000E0000000E0000000100
                0400000000007000000000000000000000001000000000000000000000000000
                BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
                FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
                3300333333333333330033333333333333003333300033333300333330F03333
                3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
                3300333330F033333300333330F0333333003333300033333300333333333333
                33003333333333333300}
              OnClick = SpeedButton64Click
              ExplicitLeft = 688
              ExplicitTop = 6
            end
            object RichEditSpec18: TRichEditSpec
              AlignWithMargins = True
              Left = 66
              Top = 4
              Width = 610
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1044#1083#1103#1044#1077#1090#1077#1081'][1][3][0]')
              TabOrder = 0
              OnChange = RichEditChanged
              OnExit = RichEditSpecExit
              OnKeyDown = RichEditSpecKeyDown
              OnKeyPress = RichEditSpecKeyPress
              FieldName = #1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1044#1083#1103#1044#1077#1090#1077#1081
              FieldType = 1
              TextData = '['#1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1044#1083#1103#1044#1077#1090#1077#1081'][1][3][0]'
              Appointment = 3
            end
          end
          object Panel136: TPanel
            Left = 2
            Top = 73
            Width = 709
            Height = 29
            Align = alTop
            TabOrder = 2
            object Label143: TLabel
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 236
              Height = 21
              Align = alLeft
              Caption = #1053#1072#1080#1073#1086#1083#1077#1077' '#1101#1092#1092#1077#1082#1090#1080#1074#1085#1099#1084' '#1103#1074#1083#1103#1077#1090#1089#1103' '#1086#1073#1091#1095#1077#1085#1080#1077' '#1074' '
              Layout = tlCenter
              ExplicitHeight = 13
            end
            object SpeedButton65: TSpeedButton
              AlignWithMargins = True
              Left = 682
              Top = 4
              Width = 23
              Height = 21
              Align = alRight
              Glyph.Data = {
                E6000000424DE60000000000000076000000280000000E0000000E0000000100
                0400000000007000000000000000000000001000000000000000000000000000
                BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
                FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
                3300333333333333330033333333333333003333300033333300333330F03333
                3300333330F033333300330000F000033300330FFFFFFF033300330000F00003
                3300333330F033333300333330F0333333003333300033333300333333333333
                33003333333333333300}
              OnClick = SpeedButton65Click
              ExplicitLeft = 686
              ExplicitTop = 5
            end
            object RichEditSpec25: TRichEditSpec
              AlignWithMargins = True
              Left = 246
              Top = 4
              Width = 430
              Height = 21
              Align = alClient
              Lines.Strings = (
                '['#1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1069#1092#1092#1077#1082#1090#1054#1073#1091#1095'][1][3][0]')
              TabOrder = 0
              OnChange = RichEditChanged
              FieldName = #1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1069#1092#1092#1077#1082#1090#1054#1073#1091#1095
              FieldType = 1
              TextData = '['#1044#1077#1092#1077#1082#1090#1086#1083#1086#1075#1069#1092#1092#1077#1082#1090#1054#1073#1091#1095'][1][3][0]'
              Appointment = 3
            end
          end
        end
      end
    end
    object TabSheet6: TTabSheet
      Caption = #1050#1086#1083#1083#1077#1075#1080#1072#1083#1100#1085#1086#1077' '#1079#1072#1082#1083#1102#1095#1077#1085#1080#1077
      ImageIndex = -1
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object ScrollBox3: TScrollBox
        Left = 0
        Top = 0
        Width = 734
        Height = 590
        Align = alClient
        TabOrder = 0
        OnMouseWheel = ScrollBoxMouseWheel
        object GroupBox12: TGroupBox
          Left = 0
          Top = 29
          Width = 730
          Height = 193
          Align = alTop
          Caption = #1054#1073#1088#1072#1079#1086#1074#1072#1090#1077#1083#1100#1085#1099#1081' '#1084#1072#1088#1096#1088#1091#1090
          Padding.Left = 3
          Padding.Top = 3
          Padding.Right = 3
          Padding.Bottom = 3
          TabOrder = 1
          Visible = False
          object GroupBox13: TGroupBox
            Left = 5
            Top = 18
            Width = 720
            Height = 59
            Align = alTop
            Caption = #1064#1082#1086#1083#1100#1085#1080#1082
            Padding.Left = 3
            Padding.Top = 3
            Padding.Right = 3
            Padding.Bottom = 3
            TabOrder = 0
            object Panel13: TPanel
              Left = 5
              Top = 18
              Width = 710
              Height = 29
              Align = alTop
              TabOrder = 0
              object Label118: TLabel
                AlignWithMargins = True
                Left = 4
                Top = 4
                Width = 50
                Height = 21
                Align = alLeft
                Caption = #1054#1073#1091#1095#1077#1085#1080#1077
                Layout = tlCenter
                ExplicitHeight = 13
              end
              object Label119: TLabel
                AlignWithMargins = True
                Left = 163
                Top = 4
                Width = 74
                Height = 21
                Align = alLeft
                Caption = '   '#1082#1083#1072#1089#1089' '#1096#1082#1086#1083#1099
                Layout = tlCenter
                ExplicitHeight = 13
              end
              object Label120: TLabel
                AlignWithMargins = True
                Left = 390
                Top = 4
                Width = 77
                Height = 21
                Align = alLeft
                Caption = '   '#1087#1086' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
                Layout = tlCenter
                ExplicitHeight = 13
              end
              object SpeedButton60: TSpeedButton
                AlignWithMargins = True
                Left = 361
                Top = 4
                Width = 23
                Height = 21
                Align = alLeft
                Caption = '...'
                OnClick = SpeedButton60Click
                ExplicitLeft = 353
                ExplicitTop = 1
              end
              object RichEditSpec103: TRichEditSpec
                AlignWithMargins = True
                Left = 60
                Top = 4
                Width = 97
                Height = 21
                Align = alLeft
                Lines.Strings = (
                  '['#1050#1083#1072#1089#1089'][2][7][0]')
                TabOrder = 0
                OnChange = RichEditModify
                FieldName = #1050#1083#1072#1089#1089
                FieldType = 2
                TextData = '['#1050#1083#1072#1089#1089'][2][7][0]'
                Appointment = 7
              end
              object RichEditSpec104: TRichEditSpec
                AlignWithMargins = True
                Left = 243
                Top = 4
                Width = 112
                Height = 21
                Align = alLeft
                Lines.Strings = (
                  '['#1064#1082#1086#1083#1072'][4][0][135]')
                TabOrder = 1
                OnChange = RichEditChanged
                OnExit = RichEditSpecExit
                OnKeyDown = RichEditSpecKeyDown
                OnKeyPress = RichEditSpecKeyPress
                OnAfterSetItemID = RichEditSpecAfterSetItemID
                FieldName = #1064#1082#1086#1083#1072
                FieldType = 4
                TextData = '['#1064#1082#1086#1083#1072'][4][0][135]'
                ListID = 135
                Appointment = 7
              end
              object ComboBoxSpec25: TComboBoxSpec
                AlignWithMargins = True
                Left = 473
                Top = 4
                Width = 163
                Height = 21
                Align = alLeft
                ItemHeight = 0
                TabOrder = 2
                Text = '['#1042#1080#1076#1055#1088#1086#1075#1088#1072#1084#1084#1099'][5][7][107]'
                OnChange = RichEditModify
                OnSelect = ComboBoxSpecSelect
                OnAfterSetItemID = ComboBoxSpecAfterSetItemID
                OnMouseWheelUp = ComboBoxSpecMouseWheelUp
                OnMouseWheelDown = ComboBoxSpecMouseWheelDown
                FieldName = #1042#1080#1076#1055#1088#1086#1075#1088#1072#1084#1084#1099
                FieldType = 5
                ParentID = 107
                Appointment = 7
                ListID = 1
              end
            end
          end
          object GroupBox14: TGroupBox
            Left = 5
            Top = 77
            Width = 720
            Height = 112
            Align = alTop
            Caption = #1044#1086#1096#1082#1086#1083#1100#1085#1080#1082
            Padding.Left = 3
            Padding.Top = 3
            Padding.Right = 3
            Padding.Bottom = 3
            TabOrder = 1
            object Panel127: TPanel
              Left = 5
              Top = 76
              Width = 710
              Height = 29
              Align = alTop
              TabOrder = 2
              object Label106: TLabel
                AlignWithMargins = True
                Left = 4
                Top = 4
                Width = 70
                Height = 21
                Align = alLeft
                Caption = #1043#1086#1076' '#1086#1073#1091#1095#1077#1085#1080#1103
                Layout = tlCenter
                ExplicitHeight = 13
              end
              object Label123: TLabel
                AlignWithMargins = True
                Left = 218
                Top = 4
                Width = 25
                Height = 21
                Align = alLeft
                Caption = '- 100'
                Layout = tlCenter
                ExplicitHeight = 13
              end
              object RichEditSpec106: TRichEditSpec
                AlignWithMargins = True
                Left = 80
                Top = 4
                Width = 132
                Height = 21
                Align = alLeft
                Lines.Strings = (
                  '['#1043#1086#1076#1054#1073#1091#1095#1077#1085#1080#1103'][2][7][0]')
                TabOrder = 0
                OnChange = RichEditModify
                FieldName = #1043#1086#1076#1054#1073#1091#1095#1077#1085#1080#1103
                FieldType = 2
                TextData = '['#1043#1086#1076#1054#1073#1091#1095#1077#1085#1080#1103'][2][7][0]'
                Appointment = 7
              end
            end
            object Panel128: TPanel
              Left = 5
              Top = 18
              Width = 710
              Height = 29
              Align = alTop
              TabOrder = 0
              object Label108: TLabel
                AlignWithMargins = True
                Left = 4
                Top = 4
                Width = 128
                Height = 21
                Align = alLeft
                Caption = #1042#1086#1089#1087#1080#1090#1072#1085#1080#1077' '#1080' '#1086#1073#1091#1095#1077#1085#1080#1077' '#1074
                Layout = tlCenter
                ExplicitHeight = 13
              end
              object Label109: TLabel
                AlignWithMargins = True
                Left = 403
                Top = 4
                Width = 44
                Height = 21
                Align = alLeft
                Caption = '   '#1075#1088#1091#1087#1087#1077
                Layout = tlCenter
                ExplicitHeight = 13
              end
              object SpeedButton61: TSpeedButton
                AlignWithMargins = True
                Left = 374
                Top = 4
                Width = 23
                Height = 21
                Align = alLeft
                Caption = '...'
                OnClick = SpeedButton61Click
                ExplicitLeft = 375
                ExplicitTop = 1
              end
              object SpeedButton62: TSpeedButton
                AlignWithMargins = True
                Left = 650
                Top = 4
                Width = 23
                Height = 21
                Align = alLeft
                Caption = '...'
                OnClick = SpeedButton62Click
                ExplicitLeft = 647
                ExplicitTop = 1
              end
              object RichEditSpec109: TRichEditSpec
                AlignWithMargins = True
                Left = 453
                Top = 4
                Width = 191
                Height = 21
                Align = alLeft
                Lines.Strings = (
                  '['#1042#1080#1076#1044#1057'][4][0][154]')
                TabOrder = 0
                WantReturns = False
                OnChange = RichEditModify
                OnExit = RichEditSpecExit
                OnKeyDown = RichEditSpecKeyDown
                OnKeyPress = RichEditSpecKeyPress
                OnAfterSetItemID = RichEditSpecAfterSetItemID
                FieldName = #1042#1080#1076#1044#1057
                FieldType = 4
                TextData = '['#1042#1080#1076#1044#1057'][4][0][154]'
                ListID = 154
                Appointment = 7
              end
              object RichEditSpec108: TRichEditSpec
                AlignWithMargins = True
                Left = 138
                Top = 4
                Width = 230
                Height = 21
                Align = alLeft
                Lines.Strings = (
                  '['#1042#1080#1076#1043#1088#1091#1087#1087#1099'][4][0][152]')
                TabOrder = 1
                WantReturns = False
                OnChange = RichEditModify
                OnExit = RichEditSpecExit
                OnKeyDown = RichEditSpecKeyDown
                OnKeyPress = RichEditSpecKeyPress
                OnAfterSetItemID = RichEditSpecAfterSetItemID
                FieldName = #1042#1080#1076#1043#1088#1091#1087#1087#1099
                FieldType = 4
                TextData = '['#1042#1080#1076#1043#1088#1091#1087#1087#1099'][4][0][152]'
                ListID = 152
                Appointment = 7
              end
            end
            object Panel129: TPanel
              Left = 5
              Top = 47
              Width = 710
              Height = 29
              Align = alTop
              TabOrder = 1
              object Label115: TLabel
                AlignWithMargins = True
                Left = 4
                Top = 4
                Width = 81
                Height = 13
                Align = alLeft
                Caption = #1056#1077#1072#1073#1080#1083#1080#1090#1072#1094#1080#1103' '#1074
                Layout = tlCenter
              end
              object Label116: TLabel
                AlignWithMargins = True
                Left = 335
                Top = 4
                Width = 109
                Height = 13
                Align = alLeft
                Caption = #1089#1080#1089#1090#1077#1084#1099' '#1089#1086#1094'. '#1079#1072#1097#1080#1090#1099
                Layout = tlCenter
              end
              object ComboBoxSpec26: TComboBoxSpec
                AlignWithMargins = True
                Left = 91
                Top = 4
                Width = 238
                Height = 21
                Align = alLeft
                ItemHeight = 0
                TabOrder = 0
                Text = '['#1042#1080#1076#1059#1095#1088#1077#1078#1076#1077#1085#1080#1103#1056#1077#1072#1073#1080#1083#1080#1090#1072#1094#1080#1080'][5][7][168]'
                OnSelect = ComboBoxSpecSelect
                OnAfterSetItemID = ComboBoxChanged
                FieldName = #1042#1080#1076#1059#1095#1088#1077#1078#1076#1077#1085#1080#1103#1056#1077#1072#1073#1080#1083#1080#1090#1072#1094#1080#1080
                FieldType = 5
                ParentID = 168
                Appointment = 7
                ListID = 1
              end
            end
          end
        end
        object Panel126: TPanel
          Left = 0
          Top = 0
          Width = 730
          Height = 29
          Align = alTop
          TabOrder = 0
          object SpeedButton55: TSpeedButton
            AlignWithMargins = True
            Left = 703
            Top = 4
            Width = 23
            Height = 21
            Align = alRight
            Caption = 'O'
            OnClick = SpeedButton55Click
            ExplicitLeft = 643
            ExplicitTop = 1
          end
          object Label144: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 63
            Height = 21
            Align = alLeft
            Caption = #1047#1072#1082#1083#1102#1095#1077#1085#1080#1077
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object RichEditSpec102: TRichEditSpec
            AlignWithMargins = True
            Left = 73
            Top = 4
            Width = 624
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1050#1086#1083#1083#1077#1075#1080#1072#1083#1100#1085#1086#1077#1047#1072#1082#1083#1102#1095#1077#1085#1080#1077'][1][7][0]')
            TabOrder = 0
            OnChange = RichEditChanged
            FieldName = #1050#1086#1083#1083#1077#1075#1080#1072#1083#1100#1085#1086#1077#1047#1072#1082#1083#1102#1095#1077#1085#1080#1077
            FieldType = 1
            TextData = '['#1050#1086#1083#1083#1077#1075#1080#1072#1083#1100#1085#1086#1077#1047#1072#1082#1083#1102#1095#1077#1085#1080#1077'][1][7][0]'
            Appointment = 7
          end
        end
        object Panel132: TPanel
          Left = 0
          Top = 309
          Width = 730
          Height = 29
          Align = alTop
          TabOrder = 5
          object Label121: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 89
            Height = 21
            Align = alLeft
            Caption = #1044#1086#1087'. '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1103
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object RichEditSpec112: TRichEditSpec
            AlignWithMargins = True
            Left = 99
            Top = 4
            Width = 627
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1044#1086#1087#1048#1085#1092#1086'][1][7][0]')
            TabOrder = 0
            OnChange = RichEditChanged
            FieldName = #1044#1086#1087#1048#1085#1092#1086
            FieldType = 1
            TextData = '['#1044#1086#1087#1048#1085#1092#1086'][1][7][0]'
            Appointment = 7
          end
        end
        object Panel133: TPanel
          Left = 0
          Top = 280
          Width = 730
          Height = 29
          Align = alTop
          TabOrder = 4
          object Label122: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 76
            Height = 21
            Align = alLeft
            Caption = #1054#1089#1086#1073#1086#1077' '#1084#1085#1077#1085#1080#1077
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object RichEditSpec113: TRichEditSpec
            AlignWithMargins = True
            Left = 86
            Top = 4
            Width = 640
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1054#1089#1086#1073#1086#1077#1052#1085#1077#1085#1080#1077'][1][7][0]')
            TabOrder = 0
            OnChange = RichEditChanged
            FieldName = #1054#1089#1086#1073#1086#1077#1052#1085#1077#1085#1080#1077
            FieldType = 1
            TextData = '['#1054#1089#1086#1073#1086#1077#1052#1085#1077#1085#1080#1077'][1][7][0]'
            Appointment = 7
          end
        end
        object Panel131: TPanel
          Left = 0
          Top = 251
          Width = 730
          Height = 29
          Align = alTop
          TabOrder = 3
          object Label117: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 278
            Height = 21
            Align = alLeft
            Caption = #1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080' '#1088#1086#1076#1080#1090#1077#1083#1103#1084' ('#1079#1072#1082#1086#1085#1085#1099#1084' '#1087#1088#1077#1076#1089#1090#1072#1074#1080#1090#1077#1083#1103#1084')'
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object SpeedButton57: TSpeedButton
            AlignWithMargins = True
            Left = 703
            Top = 4
            Width = 23
            Height = 21
            Align = alRight
            Caption = 'O'
            OnClick = SpeedButton57Click
            ExplicitLeft = 1000
            ExplicitTop = 1
          end
          object RichEditSpec111: TRichEditSpec
            AlignWithMargins = True
            Left = 288
            Top = 4
            Width = 409
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080#1056#1086#1076#1080#1090#1077#1083#1103#1084'][1][7][0]')
            TabOrder = 0
            OnChange = RichEditChanged
            FieldName = #1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080#1056#1086#1076#1080#1090#1077#1083#1103#1084
            FieldType = 1
            TextData = '['#1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080#1056#1086#1076#1080#1090#1077#1083#1103#1084'][1][7][0]'
            Appointment = 7
          end
        end
        object Panel130: TPanel
          Left = 0
          Top = 222
          Width = 730
          Height = 29
          Align = alTop
          TabOrder = 2
          object Label107: TLabel
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 129
            Height = 21
            Align = alLeft
            Caption = #1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080' '#1087#1077#1076#1072#1075#1086#1075#1072#1084
            Layout = tlCenter
            ExplicitHeight = 13
          end
          object SpeedButton56: TSpeedButton
            AlignWithMargins = True
            Left = 703
            Top = 4
            Width = 23
            Height = 21
            Align = alRight
            Caption = 'O'
            OnClick = SpeedButton56Click
            ExplicitLeft = 1000
            ExplicitTop = 1
          end
          object RichEditSpec110: TRichEditSpec
            AlignWithMargins = True
            Left = 139
            Top = 4
            Width = 558
            Height = 21
            Align = alClient
            Lines.Strings = (
              '['#1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080#1055#1077#1076#1072#1075#1086#1075#1072#1084'][1][7][0]')
            TabOrder = 0
            OnChange = RichEditChanged
            FieldName = #1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080#1055#1077#1076#1072#1075#1086#1075#1072#1084
            FieldType = 1
            TextData = '['#1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080#1055#1077#1076#1072#1075#1086#1075#1072#1084'][1][7][0]'
            Appointment = 7
          end
        end
      end
    end
  end
  object lb: THelpListBox
    Left = 485
    Top = 74
    Width = 112
    Height = 91
    Style = lbOwnerDrawVariable
    BevelInner = bvSpace
    BevelKind = bkTile
    BevelOuter = bvRaised
    ItemHeight = 13
    TabOrder = 1
    Visible = False
    OnClick = lbClick
    OnDrawItem = lbDrawItem
    OnMouseEnter = lbMouseEnter
    OnMouseLeave = lbMouseLeave
    OnFontChange = lbFontChange
  end
  object CoolBar1: TCoolBar
    Left = 0
    Top = 0
    Width = 742
    Height = 26
    AutoSize = True
    Bands = <
      item
        Control = ToolBar1
        ImageIndex = -1
        MinHeight = 22
        MinWidth = 40
        Width = 53
      end
      item
        Break = False
        Control = ToolBar3
        ImageIndex = -1
        MinHeight = 21
        Text = #1055#1086#1076#1089#1082#1072#1079#1082#1080
        Width = 221
      end
      item
        Break = False
        Control = ToolBar2
        ImageIndex = -1
        MinHeight = 21
        Text = #1044#1086#1083#1078#1085#1086#1089#1090#1100
        Width = 460
      end>
    object ToolBar1: TToolBar
      Left = 9
      Top = 0
      Width = 40
      Height = 22
      AutoSize = True
      ButtonWidth = 26
      Caption = 'ToolBar1'
      Images = Images.ImageList4
      List = True
      TabOrder = 0
      object ToolButton1: TToolButton
        Left = 0
        Top = 0
        Hint = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        AutoSize = True
        ImageIndex = 7
        OnClick = ToolButton1Click
      end
    end
    object ToolBar2: TToolBar
      Left = 348
      Top = 0
      Width = 386
      Height = 21
      ButtonHeight = 21
      Caption = 'ToolBar2'
      TabOrder = 1
      object Label146: TLabel
        Left = 0
        Top = 0
        Width = 57
        Height = 21
        Caption = #1044#1086#1083#1078#1085#1086#1089#1090#1100
        Layout = tlCenter
        Visible = False
      end
      object AppointBox: TComboBox
        Left = 57
        Top = 0
        Width = 145
        Height = 21
        Style = csDropDownList
        ItemHeight = 0
        TabOrder = 0
        OnSelect = AppointBoxSelect
      end
    end
    object ToolBar3: TToolBar
      Left = 122
      Top = 0
      Width = 150
      Height = 21
      ButtonHeight = 21
      Caption = 'ToolBar3'
      TabOrder = 2
      object Label145: TLabel
        Left = 0
        Top = 0
        Width = 54
        Height = 21
        Caption = #1055#1086#1076#1089#1082#1072#1079#1082#1080
        Layout = tlCenter
        Visible = False
      end
      object ComboBox1: TComboBox
        Left = 54
        Top = 0
        Width = 86
        Height = 21
        Style = csDropDownList
        ItemHeight = 13
        ItemIndex = 0
        TabOrder = 0
        Text = #1054#1090#1082#1083'.'
        Items.Strings = (
          #1054#1090#1082#1083'.'
          'Ctrl + '#1087#1088#1086#1073#1077#1083
          #1040#1074#1090#1086)
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 400
    Top = 80
  end
  object ImageList1: TImageList
    Left = 360
    Top = 80
    Bitmap = {
      494C010105000900040010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000003000000001002000000000000030
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00007F7F7F007F7F7F00BFBFBF007F7F7F00000000007F7F7F00BFBFBF007F7F
      7F007F7F7F000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000BFBF
      BF00BFBFBF00BFBFBF00BFBFBF007F7F7F00000000007F7F7F00BFBFBF00BFBF
      BF00BFBFBF00BFBFBF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000007F7F
      7F007F7F7F007F7F7F00BFBFBF00BFBFBF0000000000BFBFBF00BFBFBF007F7F
      7F007F7F7F007F7F7F0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000BFBF
      BF00BFBFBF00BFBFBF00BFBFBF00000000000000000000000000BFBFBF00BFBF
      BF00BFBFBF00BFBFBF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000007F7F
      7F007F7F7F007F7F7F007F7F7F000000000000000000000000007F7F7F007F7F
      7F007F7F7F007F7F7F0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000BFBF
      BF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBF
      BF00BFBFBF00BFBFBF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000BFBFBF000000000000000000000000000000000000000000BFBF
      BF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000BFBFBF000000000000000000000000000000000000000000BFBF
      BF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000BFBFBF000000000000000000000000000000000000000000BFBF
      BF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00007F7F7F007F7F7F00BFBFBF00000000000000000000000000BFBFBF007F7F
      7F007F7F7F000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000007F33
      1B00883313008A3712008A3B16008A3B16000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000000097433F009743
      3F00B59A9B00B59A9B00B59A9B00B59A9B00B59A9B00B59A9B00B59A9B009330
      300097433F0000000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000084351E008E3210007C32
      1F0000000000000000000000000093411200853F1E0000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF00FF00FF000000000097433F00D6686800C660
      6000E5DEDF0092292A0092292A00E4E7E700E0E3E600D9DFE000CCC9CC008F20
      1F00AF46460097433F00000000000000000000000000FFFFFF00000000000000
      0000000000000000000000000000FFFFFF000000000000000000000000000000
      00000000000000000000000000000000000035221D0035221D00000000000000
      0000000000000000000000000000000000008C421900984A1300984A13000000
      00000000000000000000000000000000000000000000FFFFFF00000000000000
      0000000000000000000000000000FFFFFF0000000000FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF00FF00FF000000000097433F00D0656600C25F
      5F00E9E2E20092292A0092292A00E2E1E300E2E6E800DDE2E400CFCCCF008F22
      2200AD46460097433F00000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      00000000000000000000000000000000000035221D001C6378000076A9000069
      9A00004C880000000000000000000000000000000000000000009A4E1500A859
      0F00A55A1200A65C1400B3681000AA62140000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF00FF00FF000000000097433F00D0656500C15D
      5D00ECE4E40092292A0092292A00DFDDDF00E1E6E800E0E5E700D3D0D2008A1E
      1E00AB44440097433F00000000000000000000000000FFFFFF00000000000000
      0000000000000000000000000000FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000002AAD80000B6EA00036C
      9700093094000B09830000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF00000000000000
      0000000000000000000000000000FFFFFF0000000000FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF00FF00FF000000000097433F00D0656500C15B
      5C00EFE6E600EDE5E500E5DEDF00E0DDDF00DFE0E200E0E1E300D6D0D200962A
      2A00B24A4A0097433F00000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      000000000000000000000000000000000000000000000281AB0000BEEE000316
      170007119C000C1698000B0C8300000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF00FF00FF000000000097433F00CD626300C860
      6000C9676700CC727200CA727100C6696900C4646400CC6D6C00CA666700C55D
      5D00CD65650097433F00000000000000000000000000FFFFFF00000000000000
      000000000000FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      000000000000000000000000000000000000000000000281AB00056AF200061C
      74000200000007119C000C1799000B0C83000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF00000000000000
      000000000000FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF00FF00FF000000000097433F00B6555300C27B
      7800D39D9C00D7A7A500D8A7A600D8A6A500D7A09F00D5A09F00D7A9A700D8AB
      AB00CC66670097433F00000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000B1CBB002555
      FF00061C74000200000007119C000C169C000B0C820000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00000000000000000000000000FF00FF00000000000000
      000000000000FF00FF00FF00FF00FF00FF000000000097433F00CC666700F9F9
      F900F9F9F900F9F9F900F9F9F900F9F9F900F9F9F900F9F9F900F9F9F900F9F9
      F900CC66670097433F00000000000000000000000000FFFFFF00000000000000
      0000FFFFFF00FFFFFF0000000000FFFFFF00000000000000000000000000FFFF
      FF00000000000000000000000000000000000000000000000000000000000F26
      BF002455FF00061C74000200000007119C000C169C000B0C8300000000000000
      00000000000000000000000000000000000000000000FFFFFF00000000000000
      0000FFFFFF00FFFFFF0000000000FFFFFF0000000000FF00FF0000000000FFFF
      FF0000000000FF00FF00FF00FF00FF00FF000000000097433F00CC666700F9F9
      F900F9F9F900F9F9F900F9F9F900F9F9F900F9F9F900F9F9F900F9F9F900F9F9
      F900CC66670097433F00000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF000000000000000000000000000000000000000000FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      00001028C2002455FF00061C74000200000007119C000C169C000A0C83000000
      00000000000000000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF000000000000000000FF00FF00FF00FF0000000000FFFF
      FF0000000000FF00FF00FF00FF00FF00FF000000000097433F00CC666700F9F9
      F900CDCDCD00CDCDCD00CDCDCD00CDCDCD00CDCDCD00CDCDCD00CDCDCD00F9F9
      F900CC66670097433F0000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000000000001129C4002454FF00061C74000200000007119C000B169D000B0C
      8300000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00000000000000000000000000000000000000000097433F00CC666700F9F9
      F900F9F9F900F9F9F900F9F9F900F9F9F900F9F9F900F9F9F900F9F9F900F9F9
      F900CC66670097433F0000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00000000000000000000000000000000000000
      00000000000000000000112CC9002455FF00061C74000200000007119C000711
      9C000A0C8300000000000000000000000000FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00000000000000000097433F00CC666700F9F9
      F900CDCDCD00CDCDCD00CDCDCD00CDCDCD00CDCDCD00CDCDCD00CDCDCD00F9F9
      F900CC66670097433F0000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000132FCD002354FF00061C7400000000000711
      9C00999CD900171895000000000000000000FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF0000000000000000000000000000000000FFFF
      FF00000000000000000000000000000000000000000097433F00CC666700F9F9
      F900F9F9F900F9F9F900F9F9F900F9F9F900F9F9F900F9F9F900F9F9F900F9F9
      F900CC66670097433F0000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000001531D1001E4EFF00061C7400A3A1
      9A007B7BD70000018F000000000000000000FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0000000000FFFF
      FF0000000000FF00FF00FF00FF00FF00FF00000000000000000097433F00F9F9
      F900F9F9F900F9F9F900F9F9F900F9F9F900F9F9F900F9F9F900F9F9F900F9F9
      F90097433F000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000001532D200ACBFFF006C76
      E1000000A600000000000000000000000000FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0000000000FFFF
      FF0000000000FF00FF00FF00FF00FF00FF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000002F31A400020E
      AA0000000000000000000000000000000000FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
      000000000000FF00FF00FF00FF00FF00FF00424D3E000000000000003E000000
      2800000040000000300000000100010000000000800100000000000000000000
      000000000000000000000000FFFFFF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FC1F000000000000F007000000000000
      E003000000000000C001000000000000C001000000000000C001000000000000
      C001000000000000C001000000000000E003000000000000F1C7000000000000
      F1C7000000000000F1C7000000000000F007000000000000F80F000000000000
      FC1F000000000000FFFF000000000000FFFF007FE0FFFF80C007007F8E7F8080
      8003007F3F1FBE808003007F07C080808003007F83FFBE808003007F81FF8080
      8003007F80FFB88080030047C07F83B880030047E03FB2A8800300C7F01F8328
      80030000F80FFFEF8003FE00FC0701018003FE00FE0301EF8003FFC7FF030028
      C007FFC7FF870028FFFFFFC7FFCF003800000000000000000000000000000000
      000000000000}
  end
  object PopupMenu1: TPopupMenu
    Left = 448
    Top = 80
    object N1: TMenuItem
      Caption = #1050#1086#1076' '#1087#1086#1083#1103
      ShortCut = 49219
      OnClick = OnPopupGetFieldNameClick
    end
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 200
    OnTimer = Timer1Timer
    Left = 328
    Top = 80
  end
  object MainMenu1: TMainMenu
    Left = 40
    Top = 24
    object N4: TMenuItem
      Caption = #1054#1090#1095#1105#1090#1099
      object N5: TMenuItem
        Caption = #1047#1072#1082#1083#1102#1095#1077#1085#1080#1077
        OnClick = Button1Click
      end
      object N6: TMenuItem
        Caption = #1055#1088#1086#1090#1086#1082#1086#1083
        OnClick = Button2Click
      end
      object Excel1: TMenuItem
        Caption = #1048#1084#1087#1086#1088#1090' '#1074' Excel'
        OnClick = Button3Click
      end
    end
  end
  object PopupMenu2: TPopupMenu
    Left = 408
    Top = 128
    object N7: TMenuItem
      Caption = #1054#1090#1082#1083'.'
    end
    object Ctrl1: TMenuItem
      Caption = 'Ctrl + '#1087#1088#1086#1073#1077#1083
    end
    object N8: TMenuItem
      Caption = #1040#1074#1090#1086
    end
  end
end
