#ifndef MANDATORYMARKSEDITOR_H
#define MANDATORYMARKSEDITOR_H
#include <QtSql>
#include <QDialog>

namespace Ui {
class MandatoryMarksEditor;
}

class MandatoryMarksEditor : public QDialog
{
    Q_OBJECT

public:
    explicit MandatoryMarksEditor(QWidget *parent = nullptr);
    ~MandatoryMarksEditor();

private:
    Ui::MandatoryMarksEditor *ui;
    void UpdateModels();
    QSqlQueryModel MandatoryMarks_model;


};

#endif // MANDATORYMARKSEDITOR_H
