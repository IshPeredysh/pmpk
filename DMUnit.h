//$$---- Form HDR ----
//---------------------------------------------------------------------------

#ifndef DMUnitH
#define DMUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TDM : public TDataModule
{
__published:	// IDE-managed Components
	TADOConnection *ADOConnection1;
	TADOQuery *OrgSelectQuery;
	TADOQuery *OrgInsertQuery;
	TADOQuery *OrgGetMaxQuery;
	TADOQuery *OrgUpdateQuery;
	TADOQuery *OrgDeleteQuery;
	TADOQuery *DiagnosQuery;
	TADOQuery *DiagnosInsertQuery;
	TADOQuery *DiagnosGetMaxQuery;
	TADOQuery *DiagnosUpdateQuery;
	TADOQuery *DiagnosDeleteQuery;
	TADOQuery *GDataQuery;
	TADOQuery *GDataInsertQuery;
	TADOQuery *GDataGetMaxQuery;
	TADOQuery *GDataUpdateQuery;
	TADOQuery *GDataDeleteQuery;
	TADOQuery *LangQuery;
	TADOQuery *LangInsertQuery;
	TADOQuery *LangGetMaxQuery;
	TADOQuery *LangUpdateQuery;
	TADOQuery *LangDeleteQuery;
	TADOQuery *RecomQuery;
	TADOQuery *RecomInsertQuery;
	TADOQuery *RecomGetMaxQuery;
	TADOQuery *RecomUpdateQuery;
	TADOQuery *RecomDeleteQuery;
	TADOQuery *ParentSelectQuery;
	TADOQuery *ObjectsQuery;
	TADOQuery *AppointmentQuery;
	TADOQuery *AppointmentInsertQuery;
	TADOQuery *AppointmentGetMaxQuery;
	TADOQuery *AppointmentUpdateQuery;
	TADOQuery *AppointmentDeleteQuery;
	TADOQuery *AttrAppointQuery;
	TADOQuery *AreaSelectQuery;
	TADOCommand *ADOCommand1;
	TADOQuery *ParentUpdateQuery;
	TADOQuery *BlobUpdateQuery;
	TADOQuery *BlobInsertQuery;
	TADOQuery *BlobDeleteQuery;
	TADOQuery *BlobSelectQuery;
	TADOQuery *SchoolTypeSelectQuery;
	TADOQuery *ProtocolQuery;
	TADOQuery *ProtocolInsertQuery;
	TADOQuery *ProtocolUpdateQuery;
	TADOQuery *GroupTypeSelectQuery;
	TADOQuery *KGartenTypeSelectQuery;
	TADOQuery *JournalChildUpdateQuery;
	TADOQuery *JournalChildInsertQuery;
	TADOQuery *JournQuery;
	TADOQuery *JournInsertQuery;
	TADOQuery *JournGetMaxQuery;
	TADOQuery *JournGetDocNoQuery;
	TADOQuery *JournUpdateQuery;
	TADOQuery *ChildrenSelectQuery;
	TADOQuery *ChildGetInfoQuery;
	TADOQuery *ChildrenUpdateQuery;
	TADOQuery *ChildrenGetMaxQuery;
	TADOQuery *ChildrenInsertQuery;
	TADOQuery *ProtocolFieldInsertQuery;
	TADOQuery *ProtocolFieldUpdateQuery;
	TADOQuery *ProtocolFieldDeleteQuery;
	TADOQuery *FieldExistsQuery;
	TADOQuery *ChildrenDeleteQuery;
	TADOQuery *ChildrenCheckQuery;
	TADOQuery *AreaGetMaxQuery;
	TADOQuery *AreaInsertQuery;
	TADOQuery *AreaUpdateQuery;
	TADOQuery *ParentInsertQuery;
	TADOQuery *ParentGetMaxQuery;
	TADOQuery *ParentCheckQuery;
	TADOQuery *ChildrenGetProtocolQuery;
	TADOQuery *JournByChildIDQuery;
	TADOQuery *ParentDeleteQuery;
	TADOQuery *ParentGetChildQuery;
	TADOQuery *ReportGetFieldsNameQuery;
	TADOQuery *ReportGetFieldsValueQuery;
	TADOQuery *JournChildCountQuery;
	TADOQuery *Report2GetFieldsValueQuery;
	TADOQuery *ProtocolDeleteQuery;
	TADOQuery *CheckFieldExistQuery;
	TADOQuery *AreaDeleteQuery;
	TADOQuery *OrgChildCountQuery;
	TADOQuery *DiagnosChildCountQuery;
	TADOQuery *GDataChildCountQuery;
	TADOQuery *RecomChildCountQuery;
	TADOQuery *AttrAppointUpdateQuery;
	TADOQuery *SchoolTypeGetMaxQuery;
	TADOQuery *SchoolTypeInsertQuery;
	TADOQuery *SchoolTypeUpdateQuery;
	TADOQuery *SchoolTypeDeleteQuery;
	TADOQuery *GroupTypeGetMaxQuery;
	TADOQuery *GroupTypeInsertQuery;
	TADOQuery *GroupTypeUpdateQuery;
	TADOQuery *GroupTypeDeleteQuery;
	TADOQuery *KGartenTypeGetMaxQuery;
	TADOQuery *KGartenTypeInsertQuery;
	TADOQuery *KGartenTypeUpdateQuery;
	TADOQuery *KGartenTypeDeleteQuery;
	TADOQuery *JournCloseQuery;
	TADOQuery *JournOpenQuery;
	TADOQuery *JournGetClosedQuery;
	TADOQuery *ReportAgeGroupsQuery;
	TADOQuery *ObjectsInsertQuery;
	TADOQuery *ObjectsGetMaxQuery;
	TADOQuery *ObjectsUpdateQuery;
	TADOQuery *ObjectsDeleteQuery;
	TADOQuery *ObjectsChildCountQuery;
	TADOQuery *ReportOrgTypeDistibQuery;
	TADOQuery *AppointJournInsertQuery;
	TADOQuery *AppointJournCheckQuery;
	TADOQuery *AppointJournDeleteQuery;
	TADOQuery *AppointJournCheckAllQuery;
	TADOQuery *AppointJournDeleteAllQuery;
	TADOQuery *BefoReportAgeGroupsQuery;
	TADOQuery *BeforeportOrgTypeDistribQuery;
	TADOQuery *CheckAppointJournQuery;
	TADOQuery *CreateAppointJournTableQuery;
	TADOQuery *AlterIDDocQuery;
	TADOQuery *AlterAppointIDQuery;
private:	// User declarations
public:		// User declarations
	__fastcall TDM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDM *DM;
//---------------------------------------------------------------------------
#endif
