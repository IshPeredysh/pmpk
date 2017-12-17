object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = #1055#1052#1055#1050
  ClientHeight = 312
  ClientWidth = 414
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object MainMenu1: TMainMenu
    Left = 8
    Top = 8
    object N1: TMenuItem
      Caption = #1057#1087#1088#1072#1074#1086#1095#1085#1080#1082#1080
      object N2: TMenuItem
        Caption = #1044#1077#1090#1080
        OnClick = N2Click
      end
      object N3: TMenuItem
        Caption = #1056#1086#1076#1080#1090#1077#1083#1080
        OnClick = N3Click
      end
      object N4: TMenuItem
        Caption = #1054#1088#1075#1072#1085#1080#1079#1072#1094#1080#1080
        OnClick = N4Click
      end
      object N5: TMenuItem
        Caption = #1044#1080#1072#1075#1085#1086#1079#1099
        OnClick = N5Click
      end
      object N6: TMenuItem
        Caption = #1043#1088#1091#1087#1087#1099' '#1076#1072#1085#1085#1099#1093
        OnClick = N6Click
      end
      object N7: TMenuItem
        Caption = #1071#1079#1099#1082#1080
        OnClick = N7Click
      end
      object N8: TMenuItem
        Caption = #1044#1086#1083#1078#1085#1086#1089#1090#1080
        OnClick = N8Click
      end
      object N9: TMenuItem
        Caption = #1040#1090#1088#1080#1073#1091#1090#1099' '#1076#1086#1083#1078#1085#1086#1089#1090#1077#1081
        OnClick = N9Click
      end
      object N10: TMenuItem
        Caption = #1056#1077#1082#1086#1084#1077#1085#1076#1072#1094#1080#1080
        OnClick = N10Click
      end
      object N15: TMenuItem
        Caption = #1056#1072#1081#1086#1085#1099
        OnClick = N15Click
      end
      object N16: TMenuItem
        Caption = #1042#1099#1087#1086#1076#1072#1102#1097#1080#1077' '#1089#1087#1080#1089#1082#1080
        OnClick = N16Click
      end
    end
    object N11: TMenuItem
      Caption = #1055#1088#1086#1090#1086#1082#1086#1083#1099
      OnClick = N11Click
    end
    object N12: TMenuItem
      Caption = #1054#1090#1095#1105#1090#1099
      OnClick = N12Click
    end
    object N13: TMenuItem
      Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
      object N14: TMenuItem
        Caption = #1047#1072#1082#1088#1099#1090#1100' '#1087#1088#1086#1090#1086#1082#1086#1083#1099
        OnClick = N14Click
      end
      object N17: TMenuItem
        Caption = #1059#1082#1072#1079#1072#1090#1100' '#1087#1091#1090#1100' '#1082' '#1041#1044
        OnClick = N17Click
      end
      object N18: TMenuItem
        Caption = #1064#1088#1080#1092#1090
        OnClick = N18Click
      end
    end
  end
  object FontDialog1: TFontDialog
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    Options = []
    Left = 48
    Top = 8
  end
end
