object ProgressForm: TProgressForm
  Left = 0
  Top = 0
  BorderStyle = bsToolWindow
  Caption = #1042#1099#1087#1086#1083#1085#1077#1085#1080#1077
  ClientHeight = 43
  ClientWidth = 242
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poOwnerFormCenter
  OnClose = FormClose
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 14
    Width = 3
    Height = 13
  end
  object ProgressBar1: TProgressBar
    Left = 168
    Top = 8
    Width = 57
    Height = 16
    TabOrder = 0
    Visible = False
  end
  object Timer1: TTimer
    Interval = 300
    OnTimer = Timer1Timer
    Left = 120
    Top = 16
  end
end
