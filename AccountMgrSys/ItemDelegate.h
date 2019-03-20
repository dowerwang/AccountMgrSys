#pragma once
#pragma execution_character_set("utf-8") 

#include <QtGui>
#include <QtWidgets>
#include <QItemDelegate>
#include <QStyledItemDelegate>
#include "SQLiteHelper.h"
//����У�ֻ��ί��
//��������һ����벻�����Ǻ�
class  ReadOnlyDelegate : public  QItemDelegate
{
	Q_OBJECT
public:
	ReadOnlyDelegate(QObject *parent = 0) : QItemDelegate(parent) { }
	QWidget *createEditor(QWidget*parent, const QStyleOptionViewItem &option,
		const  QModelIndex &index)  const
	{
		return  NULL;
	}
};

//ID�У�ֻ������1��12������
//����QLineEditί�к�������ʽ�������������
class  UserIDDelegate : public  QItemDelegate
{
	Q_OBJECT
public:
	UserIDDelegate(QObject *parent = 0) : QItemDelegate(parent) { }
	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
		const  QModelIndex &index)  const
	{
		QLineEdit *editor = new  QLineEdit(parent);
		QRegExp regExp("[0-9]{0,10}");
		editor->setValidator(new  QRegExpValidator(regExp, parent));
		return  editor;
	}
	void  setEditorData(QWidget *editor, const  QModelIndex &index)  const
	{
		QString text = index.model()->data(index, Qt::EditRole).toString();
		QLineEdit *lineEdit = static_cast <QLineEdit*>(editor);
		lineEdit->setText(text);
	}
	void  setModelData(QWidget *editor, QAbstractItemModel *model,
		const  QModelIndex &index)  const
	{
		QLineEdit *lineEdit = static_cast <QLineEdit*>(editor);
		QString text = lineEdit->text();
		model->setData(index, text, Qt::EditRole);
	}
	void  updateEditorGeometry(QWidget *editor,
		const  QStyleOptionViewItem &option, const  QModelIndex &index) const
	{
		editor->setGeometry(option.rect);
	}
};

//�����У�����QSpinBoxί�н����������ƣ�ֻ������1��100֮�������
class  AgeDelegate : public  QItemDelegate
{
	Q_OBJECT
public:
	AgeDelegate(QObject *parent = 0) : QItemDelegate(parent) { }
	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
		const  QModelIndex &index)  const
	{
		QSpinBox *editor = new  QSpinBox(parent);
		editor->setMinimum(1);
		editor->setMaximum(100);
		return  editor;
	}
	void  setEditorData(QWidget *editor, const  QModelIndex &index)  const
	{
		int  value = index.model()->data(index, Qt::EditRole).toInt();
		QSpinBox *spinBox = static_cast <QSpinBox*>(editor);
		spinBox->setValue(value);
	}
	void  setModelData(QWidget *editor, QAbstractItemModel *model,
		const  QModelIndex &index)  const
	{
		QSpinBox *spinBox = static_cast <QSpinBox*>(editor);
		spinBox->interpretText();
		int  value = spinBox->value();
		model->setData(index, value, Qt::EditRole);
	}
	void  updateEditorGeometry(QWidget *editor,
		const  QStyleOptionViewItem &option, const  QModelIndex &index) const
	{
		editor->setGeometry(option.rect);
	}
};

//�˻��������
class  AccountEditorDelegate : public  QItemDelegate
{
	Q_OBJECT
public:
	AccountEditorDelegate(QObject *parent = 0) : QItemDelegate(parent) { }
	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
		const  QModelIndex &index)  const
	{
		if (index.column() == 2)
		{
			QComboBox *editor = new  QComboBox(parent);
			editor->addItem("��");
			editor->addItem("Ů");
			editor->addItem("����");
			return  editor;
		}
		if (index.column() == 3)
		{
			QComboBox *editor = new  QComboBox(parent);
			editor->addItem("��ͨ");
			editor->addItem("����");
			return  editor;
		}
	}
	void  setEditorData(QWidget *editor, const  QModelIndex &index)  const
	{
		QString text = index.model()->data(index).toString();
		QComboBox *comboBox = static_cast <QComboBox*>(editor);
		int  tindex = comboBox->findText(text);
		comboBox->setCurrentIndex(tindex);
	}
	void  setModelData(QWidget *editor, QAbstractItemModel *model,
		const  QModelIndex &index)  const
	{
		QComboBox *comboBox = static_cast <QComboBox*>(editor);
		QString text = comboBox->currentText();
		bool b = model->setData(index, text);
	}
	void  updateEditorGeometry(QWidget *editor,
		const  QStyleOptionViewItem &option, const  QModelIndex &index) const
	{
		editor->setGeometry(option.rect);
	}
};

//ҩƷ�������
class  MedicineEditorDelegate : public  QItemDelegate
{
	Q_OBJECT
public:
	MedicineEditorDelegate(QObject *parent = 0) : QItemDelegate(parent) { }
	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
		const  QModelIndex &index)  const
	{
		if (index.column() == 4)
		{
			QComboBox *editor = new  QComboBox(parent);
			editor->addItem("��");
			editor->addItem("��");
			editor->addItem("Ƭ");
			editor->addItem("ƿ");
			editor->addItem("֧");
			editor->addItem("����");
			return  editor;
		}
	}
	void  setEditorData(QWidget *editor, const  QModelIndex &index)  const
	{
		QString text = index.model()->data(index).toString();
		QComboBox *comboBox = static_cast <QComboBox*>(editor);
		int  tindex = comboBox->findText(text);
		comboBox->setCurrentIndex(tindex);
	}
	void  setModelData(QWidget *editor, QAbstractItemModel *model,
		const  QModelIndex &index)  const
	{
		QComboBox *comboBox = static_cast <QComboBox*>(editor);
		QString text = comboBox->currentText();
		bool b = model->setData(index, text);
	}
	void  updateEditorGeometry(QWidget *editor,
		const  QStyleOptionViewItem &option, const  QModelIndex &index) const
	{
		editor->setGeometry(option.rect);
	}
};

//ҩƷ�������
class  RecordStatusDelegate : public  QItemDelegate
{
	Q_OBJECT
public:
	RecordStatusDelegate(QObject *parent = 0) : QItemDelegate(parent) { }
	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
		const  QModelIndex &index)  const
	{
		if (index.column() == 5)
		{
			QComboBox *editor = new  QComboBox(parent);
			editor->addItem("�ѽ�");
			editor->addItem("δ��");
			return  editor;
		}
	}
	void  setEditorData(QWidget *editor, const  QModelIndex &index)  const
	{
		QString text = index.model()->data(index).toString();
		QComboBox *comboBox = static_cast <QComboBox*>(editor);
		int  tindex = comboBox->findText(text);
		comboBox->setCurrentIndex(tindex);
	}
	void  setModelData(QWidget *editor, QAbstractItemModel *model,
		const  QModelIndex &index)  const
	{
		QComboBox *comboBox = static_cast <QComboBox*>(editor);
		QString text = comboBox->currentText();
		bool b = model->setData(index, text);
		if (text == "�ѽ�")
			model->setData(index, QColor(Qt::green), Qt::BackgroundColorRole);
	}
	void  updateEditorGeometry(QWidget *editor,
		const  QStyleOptionViewItem &option, const  QModelIndex &index) const
	{
		editor->setGeometry(option.rect);
	}
};

//ͷ���У�ֻ���ڵ�Ԫ�������һ��Сͼ����
class  IconDelegate : public  QItemDelegate
{
	Q_OBJECT
public:
	IconDelegate(QObject *parent = 0) : QItemDelegate(parent) { }
	void  paint(QPainter *painter, const  QStyleOptionViewItem &option,
		const  QModelIndex & index)  const
	{
		//show.bmp���ڹ���Ŀ¼�е�һ��ͼƬ����ʵ����QQ��ͼ�������Ǻǣ�
		QPixmap pixmap = QPixmap("/temp/lengshuiji.png").scaled(24, 24);
		qApp->style()->drawItemPixmap(painter, option.rect, Qt::AlignCenter, QPixmap(pixmap));
	}
};

//�����࣬�����е�Ԫ���е��ַ�������ʾ
class  VIPModel : public  QStandardItemModel
{
	Q_OBJECT
public:
	VIPModel(QObject *parent = NULL) : QStandardItemModel(parent) { }
	VIPModel(int  row, int  column, QObject *parent = NULL)
		: QStandardItemModel(row, column, parent) { }
	QVariant data(const  QModelIndex &index, int  role = Qt::DisplayRole) const
	{
		if (Qt::TextAlignmentRole == role)
			return  Qt::AlignCenter;
		return  QStandardItemModel::data(index, role);
	}

};


class MuItemDelegate : public  QItemDelegate
{
	Q_OBJECT
public:
	QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
	{
		Q_UNUSED(index)
			return QSize(option.rect.width(), 50);
	}
	void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
	{
		if (index.isValid())
		{
			painter->save();
			// item ��������
			QRectF rect;
			rect.setX(option.rect.x());
			rect.setY(option.rect.y());
			rect.setWidth(option.rect.width() - 1);
			rect.setHeight(option.rect.height() - 1);

			QPainterPath path;
			path.moveTo(rect.topRight());
			path.lineTo(rect.topLeft());
			path.quadTo(rect.topLeft(), rect.topLeft());
			path.lineTo(rect.bottomLeft());
			path.quadTo(rect.bottomLeft(), rect.bottomLeft());
			path.lineTo(rect.bottomRight());
			path.quadTo(rect.bottomRight(), rect.bottomRight());
			path.lineTo(rect.topRight());
			path.quadTo(rect.topRight(), rect.topRight());

			// �����ͣ����ѡ��ʱ�ı䱳��ɫ
			if (option.state.testFlag(QStyle::State_MouseOver)) {
				painter->setPen(QPen(QColor("#ebeced")));
				painter->setBrush(QColor("#ebeced"));
				painter->drawPath(path);
			}
			if (option.state.testFlag(QStyle::State_Selected)) {
				painter->setPen(QPen(QColor("#e3e3e5")));
				painter->setBrush(QColor("#e3e3e5"));
				painter->drawPath(path);
			}

		}

	}
};


class RecordDelegate : public QStyledItemDelegate
{
	Q_OBJECT
public:
	RecordDelegate(QObject *parent = 0) : QStyledItemDelegate(parent) { }
	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
		const  QModelIndex &index)  const
	{
		if (index.column() == 5)
		{
			QComboBox *editor = new  QComboBox(parent);
			editor->addItem("�ѽ�");
			editor->addItem("δ��");
			return  editor;
		}
		else
			return  NULL;
	}
	void  setEditorData(QWidget *editor, const  QModelIndex &index)  const
	{
		if (index.column() == 5)
		{
			QString text = index.model()->data(index).toString();
			QComboBox *comboBox = static_cast <QComboBox*>(editor);
			int  tindex = comboBox->findText(text);
			comboBox->setCurrentIndex(tindex);
		}
	}
	void  setModelData(QWidget *editor, QAbstractItemModel *model,
		const  QModelIndex &index)  const
	{
		if (index.column() == 5)
		{
			QComboBox *comboBox = static_cast <QComboBox*>(editor);
			QString text = comboBox->currentText();
			bool b = model->setData(index, text);
			if (text == "�ѽ�")
				model->setData(index, QColor(Qt::green), Qt::BackgroundColorRole);
		}
	}
	void  updateEditorGeometry(QWidget *editor,
		const  QStyleOptionViewItem &option, const  QModelIndex &index) const
	{
		editor->setGeometry(option.rect);
	}
	void paint(QPainter* painter, const QStyleOptionViewItem & option, const QModelIndex &index) const
	{
		if (index.column() == 5)
		{
			QString text = index.model()->data(index).toString();
			if (text == "�ѽ�")
			{
				painter->save();
				QRectF rect;
				rect.setX(option.rect.x());
				rect.setY(option.rect.y());
				rect.setWidth(option.rect.width() - 1);
				rect.setHeight(option.rect.height() - 1);
				painter->setPen(QPen(Qt::white));
				painter->setBrush(QColor("#68d07e"));
				painter->drawRect(rect);
				QFont font;
				font.setPointSize(11);
				font.setBold(true);
				painter->setFont(font);
				painter->drawText(rect, Qt::AlignCenter, "�ѽ�");
				painter->restore();
			}
			else
			{
				painter->save();
				QRectF rect;
				rect.setX(option.rect.x());
				rect.setY(option.rect.y());
				rect.setWidth(option.rect.width() - 1);
				rect.setHeight(option.rect.height() - 1);
				painter->setPen(QPen(Qt::white));
				painter->setBrush(QColor("#e33e3e"));
				painter->drawRect(rect);
				QFont font;
				font.setPointSize(11);
				font.setBold(true);
				painter->setFont(font);
				painter->drawText(rect, Qt::AlignCenter, "δ��");
				painter->restore();
			}
		}
		if (index.column() == 2)
		{
			QString _showID = index.model()->data(index).toString();
			QString _showName = gDataBaseMgr->queryPatientNameByID(_showID);
			if(!_showName.isEmpty())
			{
				painter->save();
				if (option.state & QStyle::State_Selected)
				{
					painter->setPen(QPen(Qt::white));
					painter->fillRect(option.rect, option.palette.highlight());
				}
				else
					painter->setPen(QPen(Qt::black));
				QRectF rect;
				rect.setX(option.rect.x());
				rect.setY(option.rect.y());
				rect.setWidth(option.rect.width() - 1);
				rect.setHeight(option.rect.height() - 1);
				
				painter->drawText(rect, Qt::AlignCenter, QString("%1\n(%2)").arg(_showName).arg(_showID));
				
			}
		}
		QStyleOptionViewItem itemOption(option);
		
		if (itemOption.state & QStyle::State_HasFocus)
		{
			itemOption.state = itemOption.state ^ QStyle::State_HasFocus;
		}
		itemOption.displayAlignment = Qt::AlignCenter;
		if (index.column() != 5 && index.column() != 2)
			QStyledItemDelegate::paint(painter, itemOption, index);
	}
};

class MedicineDelegate : public QStyledItemDelegate
{
	Q_OBJECT
public:
	MedicineDelegate(QObject *parent = 0) : QStyledItemDelegate(parent) { }
	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
		const  QModelIndex &index)  const
	{
		if (index.column() == 4)
		{
			QComboBox *editor = new  QComboBox(parent);
			editor->addItem("��");
			editor->addItem("��");
			editor->addItem("Ƭ");
			editor->addItem("ƿ");
			editor->addItem("֧");
			editor->addItem("����");
			return  editor;
		}
	}
	void  setEditorData(QWidget *editor, const  QModelIndex &index)  const
	{
		if (index.column() == 4)
		{
			QString text = index.model()->data(index).toString();
			QComboBox *comboBox = static_cast <QComboBox*>(editor);
			int  tindex = comboBox->findText(text);
			comboBox->setCurrentIndex(tindex);
		}
	}
	void  setModelData(QWidget *editor, QAbstractItemModel *model,
		const  QModelIndex &index)  const
	{
		if (index.column() == 4)
		{
			QComboBox *comboBox = static_cast <QComboBox*>(editor);
			QString text = comboBox->currentText();
			bool b = model->setData(index, text);
		}
	}
	void  updateEditorGeometry(QWidget *editor,
		const  QStyleOptionViewItem &option, const  QModelIndex &index) const
	{
		editor->setGeometry(option.rect);
	}
	void paint(QPainter* painter, const QStyleOptionViewItem & option, const QModelIndex &index) const
	{
		QStyleOptionViewItem itemOption(option);
		if (itemOption.state & QStyle::State_HasFocus)
		{
			itemOption.state = itemOption.state ^ QStyle::State_HasFocus;
		}
		itemOption.displayAlignment = Qt::AlignCenter;
		QStyledItemDelegate::paint(painter, itemOption, index);
	}
};