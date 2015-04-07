object AppointmentForm: TAppointmentForm
  Left = 0
  Top = 0
  Caption = #1044#1086#1083#1078#1085#1086#1089#1090#1080
  ClientHeight = 251
  ClientWidth = 457
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  OnResize = FormResize
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object dg: TDrawGridSpec
    Left = 0
    Top = 0
    Width = 457
    Height = 251
    Align = alClient
    ColCount = 1
    DefaultRowHeight = 18
    FixedCols = 0
    TabOrder = 0
    OnDrawCell = dgDrawCell
    OnMouseWheelDown = dgMouseWheelDown
    OnMouseWheelUp = dgMouseWheelUp
    ColWidths = (
      488)
  end
end
