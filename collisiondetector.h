#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H

#include <QObject>
#include <QQmlParserStatus>
#include <QQuickItem>

class CollisionDetector : public QObject, public QQmlParserStatus {
		Q_OBJECT
		Q_INTERFACES(QQmlParserStatus)
		Q_PROPERTY(QQuickItem *target \
		           READ target \
		           WRITE setTarget \
		           NOTIFY targetChanged)
		Q_PROPERTY(uint timerInterval \
		           READ timerInterval \
		           WRITE setTimerInterval \
		           NOTIFY timerIntervalChanged)
		Q_PROPERTY(bool timerRunning \
		           READ timerRunning \
		           WRITE setTimerRunning \
		           NOTIFY timerRunningChanged)
		Q_PROPERTY(QQmlListProperty<QQuickItem> items READ items)
	public:
		explicit CollisionDetector(QObject *parent = nullptr);

		Q_INVOKABLE virtual bool collides(QQuickItem *item) = 0;
		Q_INVOKABLE void checkAllItems();

		QQuickItem *target() const;
		void setTarget(QQuickItem *target);

		uint timerInterval() const;
		void setTimerInterval(uint interval);

		bool timerRunning() const;
		void setTimerRunning(bool run);

		void timerEvent(QTimerEvent *event) override;

		QQmlListProperty<QQuickItem> items();
		void appendItem(QQuickItem *item);
		qsizetype itemCount() const;
		QQuickItem *itemAt(qsizetype index) const;
		void clearItems();
		void replaceItem(qsizetype index, QQuickItem *item);
		void removeLastItem();

		void classBegin() override;
		void componentComplete() override;

	signals:
		void targetChanged();
		void timerIntervalChanged();
		void timerRunningChanged();
		void collision(QQuickItem *item);


	protected:
		QQuickItem *_target = nullptr;

		uint _timerInterval = 0;
		bool _timerRunning = false;
		int _timerID;


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
