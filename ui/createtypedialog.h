#pragma once

#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include "binaryninjaapi.h"
#include "dialogtextedit.h"
#include "uicontext.h"

class BINARYNINJAUIAPI CreateTypeDialog : public QDialog
{
	Q_OBJECT

	DialogTextEdit* m_code;

	BinaryViewRef m_data;
	std::map<BinaryNinja::QualifiedName, TypeRef> m_results;
	std::set<BinaryNinja::QualifiedName> m_typesAllowRedefinition;

  public:
	CreateTypeDialog(QWidget* parent, BinaryViewRef data, const QString& title, const QString& definition,
	    const std::set<BinaryNinja::QualifiedName>& typesAllowRedefinition = {});
	std::map<BinaryNinja::QualifiedName, TypeRef> getResults() { return m_results; }

  private Q_SLOTS:
	void createType();

  protected:
	virtual void showEvent(QShowEvent* e) override;
};
