#include "linedelegate.h"
#include "QtWidgets"
#include "editgamedialog.h"
#include "QStyledItemDelegate"
lineDelegate::lineDelegate(QObject *parent): QStyledItemDelegate(parent) // Класс QStyledItemDelegate предоставляет средства отображения и редактирования элементов данных из модели
{

}


QWidget *lineDelegate::createEditor(QWidget *parent, //возвращает виджет для редактирования элемета, с индексом указанного для редактирования. Родительский виджет и параметр стиля используются для управления тем, как виджет отображается
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    QLineEdit* edt = new QLineEdit(parent);
    return edt;
}

void lineDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, //Задает данные, которые будут отображаться и редактироваться редактором из элемента модели данных, указанного индексом модели.
                                        const QModelIndex &index) const
{
    QLineEdit *myeditor = static_cast<QLineEdit*>(editor);
    QString value = myeditor->text();
    model->setData(index, value, Qt::EditRole);
}

void lineDelegate::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const
{
    QLineEdit *myeditor = qobject_cast<QLineEdit *>(editor);
    const QString currentText =  index.data(Qt::DisplayRole).toString();
    myeditor->setText(currentText);
}


void lineDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
  if (option.state & QStyle :: State_MouseOver)
  {
      QRect rect = option.rect;
      QBrush brush(Qt::yellow);

      painter->setBrush(brush);
      painter->drawRect(rect);
  }
  QStyledItemDelegate::paint(painter, option, index);
}
