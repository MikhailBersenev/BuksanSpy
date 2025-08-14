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
    explicit MandatoryMarksEditor(QWidget *parent = nullptr, QString user = nullptr);
    ~MandatoryMarksEditor();

private slots:
    void on_addMandatoryMark_pushButton_clicked();

    void on_DeleteMandatoryMark_pushButton_clicked();


private:
    Ui::MandatoryMarksEditor *ui;
    void UpdateModels();
    QString username;
    QSqlQueryModel MandatoryMarks_model;


};

#endif // MANDATORYMARKSEDITOR_H
