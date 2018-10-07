/*
 * Radiator
 * Copyright (C) 2018  Stefan Böhmann
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef MODEL_ACCESSOR_H
#define MODEL_ACCESSOR_H

#include <QObject>
#include <QPointer>
#include <QAbstractItemModel>

class ModelAccessor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QAbstractItemModel* sourceModel READ sourceModel WRITE setSourceModel NOTIFY sourceModelChanged)
    Q_PROPERTY(int rowCount READ rowCount NOTIFY rowCountChanged)

public:
    explicit ModelAccessor(QObject *parent = nullptr);

    QAbstractItemModel* sourceModel() const;

    int rowCount() const;

    Q_INVOKABLE bool removeRow(int row);

public slots:
    void setSourceModel(QAbstractItemModel* sourceModel);

signals:
    void rowCountChanged();
    void sourceModelChanged();

private:
    QPointer<QAbstractItemModel> m_sourceModel;
};

#endif
