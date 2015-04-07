//$$---- EXE CPP ----
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Main.cpp", MainForm);
USEFORM("Childrens.cpp", ChildrensForm);
USEFORM("DMUnit.cpp", DM); /* TDataModule: File Type */
USEFORM("ChildrenInfo.cpp", ChildrenInfoForm);
USEFORM("Areas.cpp", AreasForm);
USEFORM("Parents.cpp", ParentsForm);
USEFORM("ParentsInfo.cpp", ParentsInfoForm);
USEFORM("Organizations.cpp", OrganizationsForm);
USEFORM("Diagnosis.cpp", DiagnosisForm);
USEFORM("GroupData.cpp", GroupDataForm);
USEFORM("Lang.cpp", LangForm);
USEFORM("Appointment.cpp", AppointmentForm);
USEFORM("AttrAppoint.cpp", AttrAppointForm);
USEFORM("Recommend.cpp", RecommendForm);
USEFORM("Protocol.cpp", ProtocolForm);
USEFORM("Journ.cpp", JournForm);
USEFORM("Progress.cpp", ProgressForm);
USEFORM("SchoolType.cpp", SchoolTypeForm);
USEFORM("GroupType.cpp", GroupTypeForm);
USEFORM("KGarten.cpp", KGartenForm);
USEFORM("JuornByChildUnit.cpp", JournByChildForm);
USEFORM("Report.cpp", ReportForm);
USEFORM("ComboBoxList.cpp", ComboBoxForm);
USEFORM("PathDB.cpp", PathDBForm);
USEFORM("BeforeReport.cpp", BeforeReportForm);
USEFORM("DrawChild.cpp", DrawChildForm);
USEFORM("ImagesDM.cpp", Images); /* TDataModule: File Type */
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TMainForm), &MainForm);
		Application->CreateForm(__classid(TChildrensForm), &ChildrensForm);
		Application->CreateForm(__classid(TDM), &DM);
		Application->CreateForm(__classid(TChildrenInfoForm), &ChildrenInfoForm);
		Application->CreateForm(__classid(TAreasForm), &AreasForm);
		Application->CreateForm(__classid(TParentsForm), &ParentsForm);
		Application->CreateForm(__classid(TParentsInfoForm), &ParentsInfoForm);
		Application->CreateForm(__classid(TOrganizationsForm), &OrganizationsForm);
		Application->CreateForm(__classid(TDiagnosisForm), &DiagnosisForm);
		Application->CreateForm(__classid(TGroupDataForm), &GroupDataForm);
		Application->CreateForm(__classid(TLangForm), &LangForm);
		Application->CreateForm(__classid(TAppointmentForm), &AppointmentForm);
		Application->CreateForm(__classid(TAttrAppointForm), &AttrAppointForm);
		Application->CreateForm(__classid(TRecommendForm), &RecommendForm);
		Application->CreateForm(__classid(TProtocolForm), &ProtocolForm);
		Application->CreateForm(__classid(TJournForm), &JournForm);
		Application->CreateForm(__classid(TProgressForm), &ProgressForm);
		Application->CreateForm(__classid(TSchoolTypeForm), &SchoolTypeForm);
		Application->CreateForm(__classid(TGroupTypeForm), &GroupTypeForm);
		Application->CreateForm(__classid(TKGartenForm), &KGartenForm);
		Application->CreateForm(__classid(TJournByChildForm), &JournByChildForm);
		Application->CreateForm(__classid(TReportForm), &ReportForm);
		Application->CreateForm(__classid(TComboBoxForm), &ComboBoxForm);
		Application->CreateForm(__classid(TPathDBForm), &PathDBForm);
		Application->CreateForm(__classid(TBeforeReportForm), &BeforeReportForm);
		Application->CreateForm(__classid(TDrawChildForm), &DrawChildForm);
		Application->CreateForm(__classid(TImages), &Images);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}

	}
	return 0;
}
//---------------------------------------------------------------------------
