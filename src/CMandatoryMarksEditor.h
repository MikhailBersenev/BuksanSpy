#ifndef CMANDATORYMARKSEDITOR_H
#define CMANDATORYMARKSEDITOR_H
#include <QtSql>
#include <QDialog>

namespace Ui {
class CMandatoryMarksEditor;
}

class CMandatoryMarksEditor : public QDialog
{
    Q_OBJECT

public:
    explicit CMandatoryMarksEditor(QWidget *parent = nullptr, QString strUser = nullptr);
    ~CMandatoryMarksEditor();

private slots:
    void on_addMandatoryMark_pushButton_clicked();

    void on_DeleteMandatoryMark_pushButton_clicked();


private:
    Ui::CMandatoryMarksEditor *m_pUi;
    void fUpdateModels();
    QString m_strUsername;
    QSqlQueryModel m_mandatoryMarksModel;
};

#endif // CMANDATORYMARKSEDITOR_H
