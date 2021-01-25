#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H

#include <QObject>
#include <QQuickItem>

class CollisionDetector : public QObject {
		Q_OBJECT
		Q_PROPERTY(QQmlListProperty<QQuickItem> items READ items)
	public:
		explicit CollisionDetector(QObject *parent = nullptr);

		Q_INVOKABLE virtual bool collides(QQuickItem *item1, QQuickItem *item2) = 0;
		Q_INVOKABLE void checkAllItems();

		QQmlListProperty<QQuickItem> items();
		void appendItem(QQuickItem *item);
		qsizetype itemCount() const;
		QQuickItem *itemAt(qsizetype index) const;
		void clearItems();
		void replaceItem(qsizetype index, QQuickItem *item);
		void removeLastItem();

	signals:
		void collision(QQuickItem *item1, QQuickItem *item2);

	private:
		QList<QQuickItem *> _items;
		static void appendItem(QQmlListProperty<QQuickItem> *list,
		                       QQuickItem *item);
		static qsizetype itemCount(QQmlListProperty<QQuickItem> *list);
		static QQuickItem *itemAt(QQmlListProperty<QQuickItem> *list,
		                          qsizetype index);
		static void clearItems(QQmlListProperty<QQuickItem> *list);
		static void replaceItem(QQmlListProperty<QQuickItem> *list,
		                 qsizetype index,
		                 QQuickItem *item);
		static void removeLastItem(QQmlListProperty<QQuickItem> *list);

};

#endif // COLLISIONDETECTOR_H
