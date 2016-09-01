/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
****************************************************************************/

#pragma once

#include <QAbstractListModel>

#include <functional>

namespace ProjectExplorer {
namespace Internal {

class SessionModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum { DefaultSessionRole = Qt::UserRole+1, LastSessionRole, ActiveSessionRole, ProjectsPathRole, ProjectsDisplayRole };

    explicit SessionModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_SCRIPTABLE bool isDefaultVirgin() const;

signals:
    void sessionSwitched();

public slots:
    void resetSessions();
    void newSession();
    void cloneSession(const QString &session);
    void deleteSession(const QString &session);
    void renameSession(const QString &session);
    void switchToSession(const QString &session);

private:
    void runNewSessionDialog(const QString &suggestedName, std::function<void(const QString &)> createSession);
};

} // namespace Internal
} // namespace ProjectExplorer
