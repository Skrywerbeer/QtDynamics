#include "collisiondetector.h"

CollisionDetector::CollisionDetector(QObject *parent) :
    QObject(parent) {}

void CollisionDetector::checkAllItems() {
	const qsizetype ITEM_COUNT = _items.count();
	if (ITEM_COUNT < 2)
		return;
	for (qsizetype i = 0; i < ITEM_COUNT; ++i)
		for (qsizetype j = i +1; j < ITEM_COUNT; ++j)
			collides(_items.at(i), _items.at(j));
}

QQmlListProperty<QQuickItem> CollisionDetector::items() {
	return {this, this,
	&CollisionDetector::appendItem,
	&CollisionDetector::itemCount,
	&CollisionDetector::itemAt,
	&CollisionDetector::clearItems,
	&CollisionDetector::replaceItem,
	&CollisionDetector::removeLastItem};
}

void CollisionDetector::appendItem(QQuickItem *item) {
	_items.append(item);
}

qsizetype CollisionDetector::itemCount() const {
	return _items.count();
}

QQuickItem *CollisionDetector::itemAt(qsizetype index) const {
	return _items.at(index);
}

void CollisionDetector::clearItems() {
	_items.clear();
}

void CollisionDetector::replaceItem(qsizetype index, QQuickItem *item) {
	_items.replace(index, item);
}

void CollisionDetector::removeLastItem() {
	_items.removeLast();
}

void CollisionDetector::appendItem(QQmlListProperty<QQuickItem> *list,
                                       QQuickItem *item) {
	reinterpret_cast<CollisionDetector *>(list->data)->appendItem(item);
}

qsizetype CollisionDetector::itemCount(QQmlListProperty<QQuickItem> *list) {
	return reinterpret_cast<CollisionDetector *>(list->data)->itemCount();
}

QQuickItem *CollisionDetector::itemAt(QQmlListProperty<QQuickItem> *list,
                                          qsizetype index) {
	return reinterpret_cast<CollisionDetector *>(list->data)->itemAt(index);
}

void CollisionDetector::clearItems(QQmlListProperty<QQuickItem> *list) {
	reinterpret_cast<CollisionDetector *>(list->data)->clearItems();
}

void CollisionDetector::replaceItem(QQmlListProperty<QQuickItem> *list,
                                        qsizetype index,
                                        QQuickItem *item) {
	reinterpret_cast<CollisionDetector *>(list->data)->replaceItem(index, item);
}

void CollisionDetector::removeLastItem(QQmlListProperty<QQuickItem> *list) {
	reinterpret_cast<CollisionDetector *>(list->data)->removeLastItem();
}
