#pragma once


class ItemDelegate: public QStyledItemDelegate
{
public:
    ItemDelegate(QObject* ob = nullptr): QStyledItemDelegate(ob) { }

    virtual void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override {
        if (option.state & QStyle::State_MouseOver) {
            painter->setPen(QColor(Qt::red));
        }
        return QStyledItemDelegate::paint(painter, option, index);
    }
};

