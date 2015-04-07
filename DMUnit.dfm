object DM: TDM
  OldCreateOrder = False
  Height = 1313
  Width = 1039
  object ADOConnection1: TADOConnection
    ConnectionString = 
      'Provider=MSDASQL.1;Password=masterkey;Persist Security Info=True' +
      ';User ID=sysdba;Data Source=PMPK;Initial Catalog=PMPK'
    LoginPrompt = False
    Provider = 'MSDASQL.1'
    Left = 80
    Top = 16
  end
  object OrgSelectQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM sc36'
      'ORDER BY ParentID, Descr;')
    Left = 40
    Top = 80
  end
  object OrgInsertQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'descr'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 100
        Size = 100
        Value = Null
      end
      item
        Name = 'isfolder'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'ISMARK'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 1
        Size = 1
        Value = Null
      end
      item
        Name = 'ID'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'PARENTID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'VERSTAMP'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'OrgTypeID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      
        'INSERT INTO SC36 (DESCR, ISFOLDER, ISMARK, ID, PARENTID, VERSTAM' +
        'P, ORGTYPEID)'
      
        ' VALUES (:DESCR, :ISFOLDER, :ISMARK, :ID, :PARENTID, :VERSTAMP, ' +
        ':ORGTYPEID)')
    Left = 144
    Top = 80
  end
  object OrgGetMaxQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT MAX(ID) AS MaxID FROM SC36;')
    Left = 256
    Top = 80
  end
  object OrgUpdateQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctDynamic
    Parameters = <
      item
        Name = 'PARENTID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'descr'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 100
        Size = 100
        Value = Null
      end
      item
        Name = 'ISFOLDER'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'ISMARK'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 1
        Size = 1
        Value = Null
      end
      item
        Name = 'VERSTAMP'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'ORGTYPEID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'ID'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'Update SC36'
      'SET'
      'PARENTID=:PARENTID, '
      'DESCR=:DESCR, '
      'ISFOLDER=:ISFOLDER, '
      'ISMARK=:ISMARK, '
      'VERSTAMP=:VERSTAMP, '
      'ORGTYPEID=:ORGTYPEID'
      'WHERE ID=:ID')
    Left = 376
    Top = 80
  end
  object OrgDeleteQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'id'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'delete FROM SC36 a'
      'where a.id=:id'
      ';')
    Left = 488
    Top = 80
  end
  object DiagnosQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM sc39'
      'ORDER BY ParentID, Descr;')
    Left = 40
    Top = 128
  end
  object DiagnosInsertQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'descr'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 100
        Size = 100
        Value = Null
      end
      item
        Name = 'isfolder'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'ismark'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 1
        Size = 1
        Value = Null
      end
      item
        Name = 'ID'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'PARENTID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'VERSTAMP'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      
        'INSERT INTO SC39 (DESCR, ISFOLDER, ISMARK, ID, PARENTID, VERSTAM' +
        'P)'
      ' VALUES (:DESCR, :ISFOLDER, :ISMARK, :ID, :PARENTID, :VERSTAMP)')
    Left = 144
    Top = 128
  end
  object DiagnosGetMaxQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT MAX(ID) AS maxcode FROM SC39;')
    Left = 256
    Top = 128
  end
  object DiagnosUpdateQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctDynamic
    Parameters = <
      item
        Name = 'PARENTID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'descr'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 100
        Size = 100
        Value = Null
      end
      item
        Name = 'ISFOLDER'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'ISMARK'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 1
        Size = 1
        Value = Null
      end
      item
        Name = 'VERSTAMP'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'id'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'UPDATE SC39'
      'SET  '
      'PARENTID=:PARENTID, '
      'DESCR=:DESCR, '
      'ISFOLDER=:ISFOLDER, '
      'ISMARK=:ISMARK, '
      'VERSTAMP=:VERSTAMP'
      'WHERE ID=:ID;')
    Left = 376
    Top = 128
  end
  object DiagnosDeleteQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'id'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'delete from sc39'
      'where id=:id'
      ';')
    Left = 488
    Top = 128
  end
  object GDataQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM sc62'
      'ORDER BY ParentID, descr;')
    Left = 40
    Top = 176
  end
  object GDataInsertQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'DESCR'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 100
        Size = 100
        Value = Null
      end
      item
        Name = 'ISFOLDER'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'ISMARK'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 1
        Size = 1
        Value = Null
      end
      item
        Name = 'ID'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'PARENTID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'VERSTAMP'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      
        'INSERT INTO SC62 (DESCR, ISFOLDER, ISMARK, ID, PARENTID, VERSTAM' +
        'P)'
      ' VALUES (:DESCR, :ISFOLDER, :ISMARK, :ID, :PARENTID, :VERSTAMP)')
    Left = 144
    Top = 176
  end
  object GDataGetMaxQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT MAX(id) AS MaxID FROM SC62;')
    Left = 256
    Top = 176
  end
  object GDataUpdateQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctDynamic
    Parameters = <
      item
        Name = 'PARENTID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'descr'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 100
        Size = 100
        Value = Null
      end
      item
        Name = 'ISFOLDER'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'ISMARK'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 1
        Size = 1
        Value = Null
      end
      item
        Name = 'VERSTAMP'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'id'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'UPDATE SC62 '
      'SET '
      'PARENTID=:PARENTID, '
      'DESCR=:DESCR, '
      'ISFOLDER=:ISFOLDER, '
      'ISMARK=:ISMARK, '
      'VERSTAMP=:VERSTAMP'
      ''
      'WHERE ID=:ID; ')
    Left = 376
    Top = 176
  end
  object GDataDeleteQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'id'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'delete from sc62'
      'where id=:id'
      ';')
    Left = 488
    Top = 176
  end
  object LangQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM sc76'
      'ORDER BY descr;')
    Left = 40
    Top = 224
  end
  object LangInsertQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'descr'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 25
        Size = 25
        Value = Null
      end
      item
        Name = 'ismark'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 1
        Size = 1
        Value = Null
      end
      item
        Name = 'id'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'Verstamp'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'INSERT INTO SC76 (DESCR, ISMARK, ID, VERSTAMP)'
      ' VALUES (:DESCR, :ISMARK, :ID, :VERSTAMP)')
    Left = 144
    Top = 224
  end
  object LangGetMaxQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT MAX(id) AS MaxID FROM SC76;')
    Left = 256
    Top = 224
  end
  object LangUpdateQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctDynamic
    Parameters = <
      item
        Name = 'descr'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 25
        Size = 25
        Value = Null
      end
      item
        Name = 'ISMARK'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 1
        Size = 1
        Value = Null
      end
      item
        Name = 'VERSTAMP'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'id'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'UPDATE SC76 '
      'SET'
      'DESCR=:DESCR, '
      'ISMARK=:ISMARK, '
      'VERSTAMP=:VERSTAMP'
      'WHERE ID=:ID')
    Left = 376
    Top = 224
  end
  object LangDeleteQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'id'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'delete from sc76'
      'where id=:id'
      ';')
    Left = 488
    Top = 224
  end
  object RecomQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM sc121'
      'ORDER BY ParentID, descr;')
    Left = 40
    Top = 320
  end
  object RecomInsertQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'descr'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 100
        Size = 100
        Value = Null
      end
      item
        Name = 'isfolder'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'ismark'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 1
        Size = 1
        Value = Null
      end
      item
        Name = 'ID'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'VERSTAMP'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'PARENTID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      
        'INSERT INTO SC121 (DESCR, ISFOLDER, ISMARK, ID, VERSTAMP, PARENT' +
        'ID)'
      ' VALUES (:DESCR, :ISFOLDER, :ISMARK, :ID, :VERSTAMP, :PARENTID)')
    Left = 144
    Top = 320
  end
  object RecomGetMaxQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT MAX(id) AS MaxID FROM SC121;')
    Left = 256
    Top = 320
  end
  object RecomUpdateQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctDynamic
    Parameters = <
      item
        Name = 'PARENTID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'descr'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 100
        Size = 100
        Value = Null
      end
      item
        Name = 'ISFOLDER'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'ISMARK'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 1
        Size = 1
        Value = Null
      end
      item
        Name = 'VERSTAMP'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'id'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'update SC121 '
      'set '
      'PARENTID=:PARENTID, '
      'DESCR=:DESCR, '
      'ISFOLDER=:ISFOLDER, '
      'ISMARK=:ISMARK, '
      'VERSTAMP=:VERSTAMP'
      'where ID=:ID ;')
    Left = 376
    Top = 320
  end
  object RecomDeleteQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'id'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'delete from sc121'
      'where id=:id'
      ';')
    Left = 488
    Top = 320
  end
  object ParentSelectQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'select * from sc84;')
    Left = 40
    Top = 368
  end
  object ObjectsQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT *'
      'FROM Objects;')
    Left = 32
    Top = 464
  end
  object AppointmentQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM SC114;')
    Left = 40
    Top = 416
  end
  object AppointmentInsertQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'descr'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 50
        Size = 50
        Value = Null
      end
      item
        Name = 'ismark'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 1
        Size = 1
        Value = Null
      end
      item
        Name = 'verstamp'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'ID'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'INSERT INTO SC114 (DESCR, ISMARK, VERSTAMP, ID)'
      ' VALUES (:DESCR, :ISMARK, :VERSTAMP, :ID)')
    Left = 160
    Top = 416
  end
  object AppointmentGetMaxQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT MAX(ID) AS MaxID FROM SC114;')
    Left = 288
    Top = 416
  end
  object AppointmentUpdateQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctDynamic
    Parameters = <
      item
        Name = 'descr'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 50
        Size = 50
        Value = Null
      end
      item
        Name = 'ISMARK'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 1
        Size = 1
        Value = Null
      end
      item
        Name = 'VERSTAMP'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'id'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'UPDATE SC114 '
      'SET'
      'DESCR=:DESCR, '
      'ISMARK=:ISMARK, '
      'VERSTAMP=:VERSTAMP'
      'WHERE ID=:ID')
    Left = 440
    Top = 416
  end
  object AppointmentDeleteQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'id'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'delete from SC114'
      'where ID=:ID;')
    Left = 592
    Top = 416
  end
  object AttrAppointQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    SQL.Strings = (
      'SELECT  * FROM SC116;')
    Left = 40
    Top = 520
  end
  object AreaSelectQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM sc123;')
    Left = 40
    Top = 568
  end
  object ADOCommand1: TADOCommand
    Connection = ADOConnection1
    Parameters = <>
    Left = 200
    Top = 16
  end
  object ParentUpdateQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'DESCR'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 100
        Size = 100
        Value = Null
      end
      item
        Name = 'ISMARK'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 1
        Size = 1
        Value = Null
      end
      item
        Name = 'VERSTAMP'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'AGE'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'EDUCATION'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'BADHABIT'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'BADSTRAIN'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'FWORK'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 200
        Size = 200
        Value = Null
      end
      item
        Name = 'ID'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'UPDATE SC84 '
      'SET'
      'DESCR=:DESCR, '
      'ISMARK=:ISMARK, '
      'VERSTAMP=:VERSTAMP, '
      'AGE=:AGE, '
      'EDUCATION=:EDUCATION, '
      'BADHABIT=:BADHABIT, '
      'BADSTRAIN=:BADSTRAIN,'
      'FWORK=:FWORK'
      ''
      'WHERE ID=:ID')
    Left = 144
    Top = 368
  end
  object BlobUpdateQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'Block'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 80
        Size = 80
        Value = Null
      end
      item
        Name = 'FieldID'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 4
        Size = 4
        Value = Null
      end
      item
        Name = 'ObjID'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 9
        Size = 9
        Value = Null
      end
      item
        Name = 'BlockNo'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'UPDATE SBLOB'
      'SET '
      ''
      'Block=:Block '
      ''
      'WHERE (FieldID=:FieldID AND ObjID=:ObjID AND BlockNo=:BlockNo);'
      '')
    Left = 259
    Top = 272
  end
  object BlobInsertQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'FieldID'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 4
        Size = 4
        Value = Null
      end
      item
        Name = 'ObjID'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 9
        Size = 9
        Value = Null
      end
      item
        Name = 'BlockNo'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'Block'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 80
        Size = 80
        Value = Null
      end>
    SQL.Strings = (
      'INSERT INTO SBLOB (FieldID, ObjID, BlockNo, Block)'
      ' VALUES ('
      ':FieldID, '
      ':ObjID, '
      ':BlockNo, '
      ':Block '
      ')')
    Left = 147
    Top = 272
  end
  object BlobDeleteQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'FieldID'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 4
        Size = 4
        Value = Null
      end
      item
        Name = 'ObjID'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 9
        Size = 9
        Value = Null
      end
      item
        Name = 'BlockNo'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'DELETE FROM SBLOB'
      'WHERE FieldID=:FieldID AND ObjID=:ObjID AND BlockNo=:BlockNo')
    Left = 379
    Top = 272
  end
  object BlobSelectQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'ObjID'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 9
        Size = 9
        Value = Null
      end>
    SQL.Strings = (
      'SELECT * FROM SBLOB'
      'WHERE ObjID=:ObjID'
      'ORDER  BY FieldID, BlockNo;')
    Left = 43
    Top = 272
  end
  object SchoolTypeSelectQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM sc135;')
    Left = 56
    Top = 616
  end
  object ProtocolQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'iddoc'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'SELECT * '
      'FROM dt14'
      'where iddoc=:iddoc;')
    Left = 32
    Top = 768
  end
  object ProtocolInsertQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'SP26'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 250
        Size = 250
        Value = Null
      end
      item
        Name = 'TEXTDATA'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 184
        Size = 3000
        Value = Null
      end
      item
        Name = 'FIELDTYPE'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'LISTID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'ITEMID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'IDDOC'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      
        'INSERT INTO DT14 (SP26, TEXTDATA, FIELDTYPE, LISTID, ITEMID, IDD' +
        'oc)'
      ' VALUES (:SP26, :TEXTDATA, :FIELDTYPE, :LISTID, :ITEMID, :IDDOC)')
    Left = 144
    Top = 768
  end
  object ProtocolUpdateQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'SP26'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 250
        Size = 250
        Value = Null
      end
      item
        Name = 'TEXTDATA'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 184
        Size = 3000
        Value = Null
      end
      item
        Name = 'FIELDTYPE'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'LISTID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'ITEMID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'IDDOC'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'UPDATE DT14'
      'SET '
      'SP26=:SP26, '
      'TEXTDATA=:TEXTDATA, '
      'FIELDTYPE=:FIELDTYPE, '
      'LISTID=:LISTID, '
      'ITEMID=:ITEMID'
      'WHERE IDDOC=:IDDOC ')
    Left = 264
    Top = 768
  end
  object GroupTypeSelectQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM sc152;')
    Left = 56
    Top = 664
  end
  object KGartenTypeSelectQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM sc154;')
    Left = 56
    Top = 712
  end
  object JournalChildUpdateQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'childid'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'iddoc'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'Update dh14'
      'set childid=:childid'
      'where iddoc=:iddoc')
    Left = 56
    Top = 864
  end
  object JournalChildInsertQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'childid'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'iddoc'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'insert into dh14 (childid, iddoc)'
      'values(:childid, :iddoc)')
    Left = 192
    Top = 864
  end
  object JournQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <
      item
        Name = 'Date1'
        Attributes = [paNullable]
        DataType = ftDateTime
        NumericScale = 4
        Precision = 24
        Size = 16
        Value = Null
      end
      item
        Name = 'Date2'
        Attributes = [paNullable]
        DataType = ftDateTime
        NumericScale = 4
        Precision = 24
        Size = 16
        Value = Null
      end>
    SQL.Strings = (
      
        'SELECT a.IDDOC, a.FDATE, a.DOCNO, a.CLOSED, a.ACTCNT, a.VERSTAMP' +
        ', b.childid, (iif (sum(aj.APPOINTMENTID) > 0, 1, 0)) APPOINTMENT' +
        'ID'
      
        'FROM SJOURN a left join dh14 b on b.IDDOC=a.IDDOC left join APPO' +
        'INTJOURN aj on a.IDDOC=aj.IDDOC'
      'where a.FDate >= :Date1 and a.FDate <= :Date2'
      
        'group by a.IDDOC, a.FDATE, a.DOCNO, a.CLOSED, a.ACTCNT, a.VERSTA' +
        'MP, b.childid'
      'order by a.fdate, a.docno')
    Left = 24
    Top = 816
  end
  object JournInsertQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'IDDOC'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'FDATE'
        Attributes = [paNullable]
        DataType = ftDateTime
        NumericScale = 4
        Precision = 24
        Size = 16
        Value = Null
      end
      item
        Name = 'FTIME'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 6
        Size = 6
        Value = Null
      end
      item
        Name = 'DOCNO'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'CLOSED'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'ISMARK'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 1
        Size = 1
        Value = Null
      end
      item
        Name = 'ACTCNT'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 6
        Size = 6
        Value = Null
      end
      item
        Name = 'VERSTAMP'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      
        'INSERT INTO SJOURN (IDDOC, FDATE, FTIME, DOCNO, CLOSED, ISMARK, ' +
        'ACTCNT, VERSTAMP)'
      ' VALUES ('
      ':IDDOC, '
      ':FDATE, '
      ':FTIME, '
      ':DOCNO, '
      ':CLOSED, '
      ':ISMARK, '
      ':ACTCNT, '
      ':VERSTAMP'
      ')'
      '')
    Left = 104
    Top = 816
  end
  object JournGetMaxQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT max(IDDOC) MaxID'
      'from SJOURN')
    Left = 320
    Top = 816
  end
  object JournGetDocNoQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    SQL.Strings = (
      'SELECT docno FROM Sjourn'
      'WHERE iddoc = (SELECT max(iddoc) maxid'
      '     from Sjourn) ')
    Left = 440
    Top = 816
  end
  object JournUpdateQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'DocNo'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'FDate'
        Attributes = [paNullable]
        DataType = ftDateTime
        NumericScale = 4
        Precision = 24
        Size = 16
        Value = Null
      end
      item
        Name = 'IDDoc'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'update sjourn'
      'set  '
      'DocNo=:DocNo,'
      'FDate=:FDate'
      ''
      'where IDDoc=:IDDoc')
    Left = 208
    Top = 816
  end
  object ChildrenSelectQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM sc18'
      'ORDER BY descr;')
    Left = 48
    Top = 912
  end
  object ChildGetInfoQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <
      item
        Name = 'id'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 9
        Size = 9
        Value = Null
      end>
    SQL.Strings = (
      
        'SELECT sc18.ID child_id, sc18.DESCR fio, sc18.SP41 child_rojd, s' +
        'c123.ID raion_id, sc123.DESCR raion_name, '
      
        'sblob.FIELDID, sblob.OBJID, sblob.BLOCKNO, sblob.BLOCK, sc36.DES' +
        'CR org_name '
      'FROM sc18 INNER JOIN sblob ON sc18.ID = sblob.OBJID '
      'INNER JOIN sc123 ON sc18.sp125=sc123.id '
      'LEFT JOIN sc36 ON sc18.sp43=sc36.ID'
      'WHERE sc18.id=:id'
      'ORDER BY sblob.FieldID, sblob.BlockNo;')
    Left = 160
    Top = 912
  end
  object ChildrenUpdateQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'DESCR'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 100
        Size = 100
        Value = Null
      end
      item
        Name = 'ISFOLDER'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'ISMARK'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 1
        Size = 1
        Value = Null
      end
      item
        Name = 'Adress'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 255
        Size = 255
        Value = Null
      end
      item
        Name = 'History'
        Attributes = [paNullable, paLong]
        DataType = ftVarBytes
        Precision = 255
        Size = 2147483647
        Value = Null
      end
      item
        Name = 'ExtInfo'
        Attributes = [paNullable, paLong]
        DataType = ftVarBytes
        Precision = 255
        Size = 2147483647
        Value = Null
      end
      item
        Name = 'VERSTAMP'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'PLACESTUDY'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'FATHER'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'MOTHER'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'AREA'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'SP133'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'PARENTID'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'BIRTHDAY'
        Attributes = [paNullable]
        DataType = ftDateTime
        Precision = 10
        Size = 6
        Value = Null
      end
      item
        Name = 'SEX'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'ID'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'update SC18'
      'set'
      'DESCR=:DESCR, '
      'ISFOLDER=:ISFOLDER, '
      'ISMARK=:ISMARK, '
      'ADRESS=:ADRESS, '
      'HISTORY=:HISTORY, '
      'EXTINFO=:EXTINFO, '
      'VERSTAMP=:VERSTAMP, '
      'PLACESTUDY=:PLACESTUDY, '
      'FATHER=:FATHER, '
      'MOTHER=:MOTHER, '
      'AREA=:AREA, '
      'SP133=:SP133, '
      'PARENTID=:PARENTID, '
      'BIRTHDAY=:BIRTHDAY,'
      'SEX=:SEX'
      'where ID=:ID')
    Left = 272
    Top = 912
  end
  object ChildrenGetMaxQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'select max(ID) MaxID'
      'from sc18;')
    Left = 392
    Top = 912
  end
  object ChildrenInsertQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'DESCR'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 100
        Size = 100
        Value = Null
      end
      item
        Name = 'ISFOLDER'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'ISMARK'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 1
        Size = 1
        Value = Null
      end
      item
        Name = 'ADRESS'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 255
        Size = 255
        Value = Null
      end
      item
        Name = 'HISTORY'
        Attributes = [paNullable, paLong]
        DataType = ftVarBytes
        Precision = 255
        Size = 2147483647
        Value = Null
      end
      item
        Name = 'EXTINFO'
        Attributes = [paNullable, paLong]
        DataType = ftVarBytes
        Precision = 255
        Size = 2147483647
        Value = Null
      end
      item
        Name = 'ID'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'VERSTAMP'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'PLACESTUDY'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'FATHER'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'MOTHER'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'AREA'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'SP133'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'PARENTID'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'BIRTHDAY'
        Attributes = [paNullable]
        DataType = ftDateTime
        Precision = 10
        Size = 6
        Value = Null
      end
      item
        Name = 'SEX'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      
        'INSERT INTO SC18 (DESCR, ISFOLDER, ISMARK, ADRESS, HISTORY, EXTI' +
        'NFO, ID, VERSTAMP, PLACESTUDY, FATHER, MOTHER, AREA, SP133, PARE' +
        'NTID, BIRTHDAY, SEX)'
      
        ' VALUES (:DESCR, :ISFOLDER, :ISMARK, :ADRESS, :HISTORY, :EXTINFO' +
        ', :ID, :VERSTAMP, :PLACESTUDY, :FATHER, :MOTHER, :AREA, :SP133, ' +
        ':PARENTID, :BIRTHDAY, :SEX)')
    Left = 512
    Top = 912
  end
  object ProtocolFieldInsertQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'SP26'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 250
        Size = 250
        Value = Null
      end
      item
        Name = 'TEXTDATA'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 184
        Size = 3000
        Value = Null
      end
      item
        Name = 'FIELDTYPE'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'LISTID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'ITEMID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'IDDOC'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      
        'INSERT INTO DT14 (SP26, TEXTDATA, FIELDTYPE, LISTID, ITEMID, IDD' +
        'OC)'
      ' VALUES (:SP26, :TEXTDATA, :FIELDTYPE, :LISTID, :ITEMID, :IDDOC)')
    Left = 56
    Top = 960
  end
  object ProtocolFieldUpdateQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'TEXTDATA'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 184
        Size = 3000
        Value = Null
      end
      item
        Name = 'FIELDTYPE'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'LISTID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'ITEMID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'IDDOC'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'SP26'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 250
        Size = 250
        Value = Null
      end>
    SQL.Strings = (
      'update DT14 '
      'set '
      'textdata=:TEXTDATA, '
      'fieldtype=:FIELDTYPE, '
      'listid=:LISTID, '
      'itemid=:ITEMID'
      ''
      'where '
      'iddoc=:IDDOC and'
      'sp26=:SP26'
      '')
    Left = 192
    Top = 960
  end
  object ProtocolFieldDeleteQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'iddoc'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'sp26'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 250
        Size = 250
        Value = Null
      end>
    SQL.Strings = (
      'DELETE FROM dt14'
      'WHERE iddoc=:iddoc and sp26=:sp26')
    Left = 336
    Top = 960
  end
  object FieldExistsQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'iddoc'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'sp26'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 250
        Size = 250
        Value = Null
      end>
    SQL.Strings = (
      'SELECT count(*) cnt'
      'FROM dt14'
      'WHERE iddoc=:iddoc and sp26=:sp26')
    Left = 448
    Top = 960
  end
  object ChildrenDeleteQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'ID'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'DELETE FROM sc18'
      'WHERE ID=:ID;')
    Left = 632
    Top = 912
  end
  object ChildrenCheckQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'childid'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'SELECT count(*) cnt'
      'FROM DH14'
      'where childid=:childid')
    Left = 744
    Top = 912
  end
  object AreaGetMaxQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    SQL.Strings = (
      'select max(ID) MaxID'
      'from sc123;'
      '')
    Left = 192
    Top = 568
  end
  object AreaInsertQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'DESCR'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 50
        Size = 50
        Value = Null
      end
      item
        Name = 'ISFOLDER'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'ISMARK'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 1
        Size = 1
        Value = Null
      end
      item
        Name = 'ID'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'PARENTID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'VERSTAMP'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      
        'INSERT INTO SC123 (DESCR, ISFOLDER, ISMARK,  ID, PARENTID, VERST' +
        'AMP)'
      ' VALUES (:DESCR, :ISFOLDER, :ISMARK, :ID, :PARENTID, :VERSTAMP)')
    Left = 320
    Top = 568
  end
  object AreaUpdateQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'DESCR'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 50
        Size = 50
        Value = Null
      end
      item
        Name = 'ISFOLDER'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'ISMARK'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 1
        Size = 1
        Value = Null
      end
      item
        Name = 'PARENTID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'VERSTAMP'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'ID'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'update SC123 '
      'set'
      'DESCR=:DESCR, '
      'ISFOLDER=:ISFOLDER, '
      'ISMARK=:ISMARK, '
      'PARENTID=:PARENTID, '
      'VERSTAMP=:VERSTAMP'
      'where ID=:ID')
    Left = 464
    Top = 568
  end
  object ParentInsertQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'DESCR'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 100
        Size = 100
        Value = Null
      end
      item
        Name = 'ISMARK'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 1
        Size = 1
        Value = Null
      end
      item
        Name = 'ID'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'VERSTAMP'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'AGE'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'EDUCATION'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'BADHABIT'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'BADSTRAIN'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'FWORK'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 200
        Size = 200
        Value = Null
      end>
    SQL.Strings = (
      
        'INSERT INTO SC84 (DESCR, ISMARK, ID, VERSTAMP, AGE, EDUCATION, B' +
        'ADHABIT, BADSTRAIN, FWORK)'
      
        ' VALUES (:DESCR, :ISMARK, :ID, :VERSTAMP, :AGE, :EDUCATION, :BAD' +
        'HABIT, :BADSTRAIN, :FWORK)')
    Left = 256
    Top = 368
  end
  object ParentGetMaxQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    SQL.Strings = (
      'select max(ID) MaxID'
      'from sc84;')
    Left = 376
    Top = 368
  end
  object ParentCheckQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'fatherID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'MotherID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'SELECT count(*) cnt'
      'FROM sc18'
      'where father=:fatherID or mother=:MotherID'
      ''
      '')
    Left = 488
    Top = 368
  end
  object ChildrenGetProtocolQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'ChildID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'select IDDoc'
      'from dh14'
      'where ChildID=:ChildID')
    Left = 864
    Top = 912
  end
  object JournByChildIDQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'ChildID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      
        'SELECT a.IDDOC, a.FDATE, a.DOCNO, a.CLOSED, a.ACTCNT, a.VERSTAMP' +
        ', b.childid, aj.APPOINTMENTID '
      
        'from sjourn a inner join dh14 b on a.IDDOc = b.IDDoc left join A' +
        'PPOINTJOURN aj on a.IDDOC=aj.IDDOC'
      'where a.IDDoc in(Select IDDoc from dh14 where ChildID=:ChildID)')
    Left = 568
    Top = 816
  end
  object ParentDeleteQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'ID'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'DELETE FROM sc84'
      'WHERE ID=:ID;')
    Left = 616
    Top = 368
  end
  object ParentGetChildQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'fatherID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'MotherID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'SELECT ID'
      'FROM sc18'
      'where father=:fatherID or mother=:MotherID')
    Left = 736
    Top = 368
  end
  object ReportGetFieldsNameQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    SQL.Strings = (
      'select * from sc116'
      'order by descr')
    Left = 64
    Top = 1008
  end
  object ReportGetFieldsValueQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'fdate1'
        Attributes = [paNullable]
        DataType = ftDateTime
        NumericScale = 4
        Precision = 24
        Size = 16
        Value = Null
      end
      item
        Name = 'fdate2'
        Attributes = [paNullable]
        DataType = ftDateTime
        NumericScale = 4
        Precision = 24
        Size = 16
        Value = Null
      end
      item
        Name = 'sp26'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 250
        Size = 250
        Value = Null
      end>
    SQL.Strings = (
      
        'SELECT f.sp26, f.textdata, f.FIELDTYPE, f.LISTID, f.ITEMID, coun' +
        't(*) cnt'
      'FROM dt14 f inner join sjourn j on j.iddoc = f.iddoc'
      'where j.fdate>=:fdate1 and j.fdate<=:fdate2 and f.sp26 =:sp26'
      'group by f.sp26, f.textdata, f.FIELDTYPE, f.LISTID, f.ITEMID  '
      'order by cnt desc')
    Left = 208
    Top = 1008
  end
  object JournChildCountQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'fdate1'
        Attributes = [paNullable]
        DataType = ftDateTime
        NumericScale = 4
        Precision = 24
        Size = 16
        Value = Null
      end
      item
        Name = 'fdate2'
        Attributes = [paNullable]
        DataType = ftDateTime
        NumericScale = 4
        Precision = 24
        Size = 16
        Value = Null
      end>
    SQL.Strings = (
      'select count(*) cnt'
      'from sjourn j inner join dh14 c on j.iddoc = c.iddoc'
      'where( not (c.childid is null)) and (c.childid <> 0) and'
      'fdate>=:fdate1 and fdate<=:fdate2')
    Left = 328
    Top = 864
  end
  object Report2GetFieldsValueQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <
      item
        Name = 'sp26_1'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 250
        Size = 250
        Value = Null
      end
      item
        Name = 'fdate1'
        Attributes = [paNullable]
        DataType = ftDateTime
        NumericScale = 4
        Precision = 24
        Size = 16
        Value = Null
      end
      item
        Name = 'fdate2'
        Attributes = [paNullable]
        DataType = ftDateTime
        NumericScale = 4
        Precision = 24
        Size = 16
        Value = Null
      end
      item
        Name = 'sp26_2'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 250
        Size = 250
        Value = Null
      end>
    SQL.Strings = (
      
        'select t1.FieldType FieldType1, t1.listid listid1, t1.itemid ite' +
        'mid1, t2.FieldType FieldType2, t2.listid listid2, t2.itemid item' +
        'id2, count(t1.iddoc) cnt'
      'from '
      '    (select dt14.iddoc, FieldType, '
      '    iif(listid is null, 0, listid) as listid, '
      '    iif(itemid is null, 0, itemid) as itemid'
      '    from dt14 inner join sjourn on dt14.iddoc = sjourn.iddoc'
      
        '    where sp26=:sp26_1 and fdate>=:fdate1 and fdate<=:fdate2) t1' +
        ' '
      'inner join '
      '    (select dt14.iddoc, FieldType, '
      '    iif(listid is null, 0, listid) as listid, '
      '    iif(itemid is null, 0, itemid) as itemid'
      '    from dt14'
      '    where sp26=:sp26_2) t2        '
      'on t1.iddoc = t2.iddoc'
      
        'group by t1.FieldType, t1.listid, t1.itemid, t2.FieldType, t2.li' +
        'stid, t2.itemid'
      'order by t1.listid, t1.itemid, t2.listid, t2.itemid')
    Left = 64
    Top = 1064
  end
  object ProtocolDeleteQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'iddoc'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'delete from sjourn'
      'where iddoc=:iddoc')
    Left = 560
    Top = 960
  end
  object CheckFieldExistQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <
      item
        Name = 'ListID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'ItemID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'select count(*) cnt'
      'from dt14'
      'where ListID=:ListID and ItemID=:ItemID'
      ''
      '')
    Left = 688
    Top = 960
  end
  object AreaDeleteQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'ID'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'delete from SC123 '
      'where ID=:ID')
    Left = 600
    Top = 568
  end
  object OrgChildCountQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'ParentID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'select count(*) cnt'
      'from sc36'
      'where ParentID=:ParentID')
    Left = 592
    Top = 80
  end
  object DiagnosChildCountQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'ParentID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'select count(*) cnt'
      'from sc39'
      'where ParentID=:ParentID')
    Left = 592
    Top = 128
  end
  object GDataChildCountQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'ParentID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'select count(*) cnt'
      'from sc62'
      'where ParentID=:ParentID')
    Left = 592
    Top = 176
  end
  object RecomChildCountQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'ParentID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'select count(*) cnt'
      'from sc121'
      'where ParentID=:ParentID')
    Left = 592
    Top = 320
  end
  object AttrAppointUpdateQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'DESCR'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 100
        Size = 100
        Value = Null
      end
      item
        Name = 'ISMARK'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 1
        Size = 1
        Value = Null
      end
      item
        Name = 'VERSTAMP'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'APPOINTMENTID'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'FIELDTYPE'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'CAPTION'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 100
        Size = 100
        Value = Null
      end
      item
        Name = 'AnchorID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'ID'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'update SC116'
      'SET'
      'DESCR=:DESCR,'
      'ISMARK=:ISMARK,'
      'VERSTAMP=:VERSTAMP,'
      'APPOINTMENTID=:APPOINTMENTID,'
      'FIELDTYPE=:FIELDTYPE,'
      'CAPTION=:CAPTION,'
      'ANCHORID=:ANCHORID'
      'where ID=:ID')
    Left = 152
    Top = 520
  end
  object SchoolTypeGetMaxQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    SQL.Strings = (
      'select max(ID) MaxID'
      'from sc135;'
      '')
    Left = 192
    Top = 616
  end
  object SchoolTypeInsertQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'DESCR'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 25
        Size = 25
        Value = Null
      end
      item
        Name = 'ISMARK'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 1
        Size = 1
        Value = Null
      end
      item
        Name = 'ID'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'VERSTAMP'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'INSERT INTO SC135 (DESCR, ISMARK,  ID, VERSTAMP)'
      ' VALUES (:DESCR, :ISMARK, :ID, :VERSTAMP)')
    Left = 320
    Top = 616
  end
  object SchoolTypeUpdateQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'DESCR'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 25
        Size = 25
        Value = Null
      end
      item
        Name = 'ISMARK'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 1
        Size = 1
        Value = Null
      end
      item
        Name = 'VERSTAMP'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'ID'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'update SC135 '
      'set'
      'DESCR=:DESCR, '
      'ISMARK=:ISMARK, '
      'VERSTAMP=:VERSTAMP'
      'where ID=:ID')
    Left = 464
    Top = 616
  end
  object SchoolTypeDeleteQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'ID'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'delete from SC135 '
      'where ID=:ID')
    Left = 600
    Top = 616
  end
  object GroupTypeGetMaxQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    SQL.Strings = (
      'select max(ID) MaxID'
      'from sc152;'
      '')
    Left = 192
    Top = 664
  end
  object GroupTypeInsertQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'DESCR'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 100
        Size = 100
        Value = Null
      end
      item
        Name = 'ISMARK'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 1
        Size = 1
        Value = Null
      end
      item
        Name = 'ID'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'VERSTAMP'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'INSERT INTO SC152 (DESCR, ISMARK,  ID, VERSTAMP)'
      ' VALUES (:DESCR, :ISMARK, :ID, :VERSTAMP)')
    Left = 320
    Top = 664
  end
  object GroupTypeUpdateQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'DESCR'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 100
        Size = 100
        Value = Null
      end
      item
        Name = 'ISMARK'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 1
        Size = 1
        Value = Null
      end
      item
        Name = 'VERSTAMP'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'ID'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'update SC152'
      'set'
      'DESCR=:DESCR, '
      'ISMARK=:ISMARK, '
      'VERSTAMP=:VERSTAMP'
      'where ID=:ID')
    Left = 464
    Top = 664
  end
  object GroupTypeDeleteQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'ID'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'delete from SC152 '
      'where ID=:ID')
    Left = 600
    Top = 664
  end
  object KGartenTypeGetMaxQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    SQL.Strings = (
      'select max(ID) MaxID'
      'from sc154;'
      '')
    Left = 192
    Top = 712
  end
  object KGartenTypeInsertQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'DESCR'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 25
        Size = 25
        Value = Null
      end
      item
        Name = 'ISMARK'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 1
        Size = 1
        Value = Null
      end
      item
        Name = 'ID'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'VERSTAMP'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'INSERT INTO SC154 (DESCR, ISMARK,  ID, VERSTAMP)'
      ' VALUES (:DESCR, :ISMARK, :ID, :VERSTAMP)')
    Left = 320
    Top = 712
  end
  object KGartenTypeUpdateQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'DESCR'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 25
        Size = 25
        Value = Null
      end
      item
        Name = 'ISMARK'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 1
        Size = 1
        Value = Null
      end
      item
        Name = 'VERSTAMP'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'ID'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'update SC154'
      'set'
      'DESCR=:DESCR, '
      'ISMARK=:ISMARK, '
      'VERSTAMP=:VERSTAMP'
      'where ID=:ID')
    Left = 464
    Top = 712
  end
  object KGartenTypeDeleteQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'ID'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'delete from SC154 '
      'where ID=:ID')
    Left = 600
    Top = 712
  end
  object JournCloseQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'IDDoc'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'update sjourn'
      'set  '
      'Closed=0'
      ''
      'where IDDoc=:IDDoc')
    Left = 648
    Top = 768
  end
  object JournOpenQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'IDDoc'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'update sjourn'
      'set  '
      'Closed=1'
      ''
      'where IDDoc=:IDDoc')
    Left = 736
    Top = 768
  end
  object JournGetClosedQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'IDDoc'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'select closed'
      'from sjourn'
      'where IDDoc=:IDDoc')
    Left = 832
    Top = 768
  end
  object ReportAgeGroupsQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <
      item
        Name = 'fdate1'
        Attributes = [paNullable]
        DataType = ftDateTime
        NumericScale = 4
        Precision = 24
        Size = 16
        Value = Null
      end
      item
        Name = 'fdate2'
        Attributes = [paNullable]
        DataType = ftDateTime
        NumericScale = 4
        Precision = 24
        Size = 16
        Value = Null
      end>
    SQL.Strings = (
      'SELECT a.BIRTHDAY, c.FDATE'
      
        'FROM SC18 a inner join DH14 b on a.ID = b.CHILDID inner join SJO' +
        'URN c on b.IDDOC = c.IDDOC'
      'where  c.fdate>=:fdate1 and c.fdate<=:fdate2'
      'group by a.ID, a.BIRTHDAY, c.FDATE')
    Left = 208
    Top = 1064
  end
  object ObjectsInsertQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'descr'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 100
        Size = 100
        Value = Null
      end
      item
        Name = 'isfolder'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'ismark'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 1
        Size = 1
        Value = Null
      end
      item
        Name = 'ID'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'PARENTID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'VERSTAMP'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      
        'INSERT INTO Objects (DESCR, ISFOLDER, ISMARK, ID, PARENTID, VERS' +
        'TAMP)'
      ' VALUES (:DESCR, :ISFOLDER, :ISMARK, :ID, :PARENTID, :VERSTAMP)')
    Left = 144
    Top = 464
  end
  object ObjectsGetMaxQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT MAX(ID) AS maxcode FROM Objects;')
    Left = 256
    Top = 464
  end
  object ObjectsUpdateQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctDynamic
    Parameters = <
      item
        Name = 'PARENTID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'descr'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 100
        Size = 100
        Value = Null
      end
      item
        Name = 'ISFOLDER'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'ISMARK'
        Attributes = [paNullable]
        DataType = ftString
        Precision = 1
        Size = 1
        Value = Null
      end
      item
        Name = 'VERSTAMP'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'id'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'UPDATE Objects'
      'SET  '
      'PARENTID=:PARENTID, '
      'DESCR=:DESCR, '
      'ISFOLDER=:ISFOLDER, '
      'ISMARK=:ISMARK, '
      'VERSTAMP=:VERSTAMP'
      'WHERE ID=:ID;')
    Left = 376
    Top = 464
  end
  object ObjectsDeleteQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'id'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'delete from Objects'
      'where id=:id'
      ';')
    Left = 488
    Top = 464
  end
  object ObjectsChildCountQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'ParentID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'select count(*) cnt'
      'from Objects'
      'where ParentID=:ParentID')
    Left = 600
    Top = 464
  end
  object ReportOrgTypeDistibQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <
      item
        Name = 'fdate1'
        Attributes = [paNullable]
        DataType = ftDateTime
        NumericScale = 4
        Precision = 24
        Size = 16
        Value = Null
      end
      item
        Name = 'fdate2'
        Attributes = [paNullable]
        DataType = ftDateTime
        NumericScale = 4
        Precision = 24
        Size = 16
        Value = Null
      end>
    SQL.Strings = (
      
        'SELECT iif(a.DESCR is NULL, '#39#1053#1077' '#1091#1082#1072#1079#1072#1085#39', a.DESCR) Org, iif(b.DES' +
        'CR is NULL, '#39#1053#1077' '#1091#1082#1072#1079#1072#1085#39', b.DESCR) ORGTYPE, a.OrgTypeID, count(*)' +
        ' cnt'
      'FROM SC36 a inner join objects b on a.ORGTYPEID = b.ID '
      '            inner join sc18 c on c.PLACESTUDY = a.ID '
      '            inner join dh14 on dh14.CHILDID = c.ID'
      '            right join sjourn on dh14.IDDOC = SJOURN.IDDOC'
      'where  sjourn.fdate>=:fdate1 and sjourn.fdate<=:fdate2'
      'group by a.DESCR, a.ORGTYPEID, b.DESCR'
      'order by a.ORGTYPEID, a.Descr')
    Left = 344
    Top = 1064
  end
  object AppointJournInsertQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'AppointmentID'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'IDDoc'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'insert into APPOINTJOURN (AppointmentID, IDDoc)'
      'VALUES(:AppointmentID, :IDDoc)')
    Left = 56
    Top = 1171
  end
  object AppointJournCheckQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <
      item
        Name = 'AppointmentID'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'IDDoc'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'select AppointmentID, IDDoc'
      'from APPOINTJOURN'
      'where AppointmentID=:AppointmentID and IDDoc=:IDDoc')
    Left = 208
    Top = 1171
  end
  object AppointJournDeleteQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'AppointmentID'
        Size = -1
        Value = Null
      end
      item
        Name = 'IDDoc'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'delete from APPOINTJOURN'
      'where AppointmentID=:AppointmentID and IDDoc=:IDDoc')
    Left = 360
    Top = 1171
  end
  object AppointJournCheckAllQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <
      item
        Name = 'IDDoc'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'select AppointmentID, IDDoc'
      'from APPOINTJOURN'
      'where IDDoc=:IDDoc')
    Left = 512
    Top = 1171
  end
  object AppointJournDeleteAllQuery: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    SQL.Strings = (
      'delete from APPOINTJOURN')
    Left = 672
    Top = 1171
  end
  object BefoReportAgeGroupsQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <
      item
        Name = 'fdate1'
        Attributes = [paNullable]
        DataType = ftDateTime
        NumericScale = 4
        Precision = 24
        Size = 16
        Value = Null
      end
      item
        Name = 'fdate2'
        Attributes = [paNullable]
        DataType = ftDateTime
        NumericScale = 4
        Precision = 24
        Size = 16
        Value = Null
      end>
    SQL.Strings = (
      'SELECT a.ID, a.BIRTHDAY, c.FDATE'
      
        'FROM SC18 a inner join DH14 b on a.ID = b.CHILDID inner join SJO' +
        'URN c on b.IDDOC = c.IDDOC'
      'where  c.fdate>=:fdate1 and c.fdate<=:fdate2'
      'group by a.ID, a.BIRTHDAY, c.FDATE')
    Left = 208
    Top = 1120
  end
  object BeforeportOrgTypeDistribQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <
      item
        Name = 'fdate1'
        Attributes = [paNullable]
        DataType = ftDateTime
        NumericScale = 4
        Precision = 24
        Size = 16
        Value = Null
      end
      item
        Name = 'fdate2'
        Attributes = [paNullable]
        DataType = ftDateTime
        NumericScale = 4
        Precision = 24
        Size = 16
        Value = Null
      end>
    SQL.Strings = (
      
        'SELECT c.ID ChildID, iif(a.DESCR is NULL, '#39#1053#1077' '#1091#1082#1072#1079#1072#1085#39', a.DESCR) ' +
        'Org, a.ID OrgID, iif(b.DESCR is NULL, '#39#1053#1077' '#1091#1082#1072#1079#1072#1085#39', b.DESCR) ORGT' +
        'YPE, a.OrgTypeID'
      'FROM SC36 a inner join objects b on a.ORGTYPEID = b.ID '
      '            inner join sc18 c on c.PLACESTUDY = a.ID '
      '            inner join dh14 on dh14.CHILDID = c.ID'
      '            right join sjourn on dh14.IDDOC = SJOURN.IDDOC'
      'where  sjourn.fdate>=:fdate1 and sjourn.fdate<=:fdate2'
      'order by a.ORGTYPEID, a.Descr')
    Left = 376
    Top = 1120
  end
  object CheckAppointJournQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <
      item
        Name = 'AppointmentID'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end
      item
        Name = 'IDDoc'
        DataType = ftInteger
        Precision = 10
        Size = 4
        Value = Null
      end>
    SQL.Strings = (
      'select AppointmentID, IDDoc'
      'from APPOINTJOURN')
    Left = 56
    Top = 1235
  end
  object CreateAppointJournTableQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'CREATE TABLE APPOINTJOURN'
      '('
      '  IDDOC Integer NOT NULL,'
      '  APPOINTMENTID Integer NOT NULL,'
      '  PRIMARY KEY (IDDOC,APPOINTMENTID)'
      ');')
    Left = 216
    Top = 1235
  end
  object AlterIDDocQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'alter table APPOINTJOURN'
      'add constraint FK_APPOINTJOURN_IDDoc'
      'foreign key (IDDOC) '
      'references SJOURN (IDDOC)')
    Left = 368
    Top = 1235
  end
  object AlterAppointIDQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'alter table APPOINTJOURN'
      'add constraint FK_APPOINTJOURN_AppointID'
      'foreign key (APPOINTMENTID) '
      'references SC114 (ID)')
    Left = 504
    Top = 1235
  end
end
