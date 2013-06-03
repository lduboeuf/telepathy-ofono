/**
 * Copyright (C) 2013 Canonical, Ltd.
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License version 3, as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranties of MERCHANTABILITY,
 * SATISFACTORY QUALITY, or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authors: Tiago Salem Herrmann <tiago.herrmann@canonical.com>
 */

#include "protocol.h"
#include "connection.h"

#include <TelepathyQt/RequestableChannelClassSpec>
#include <TelepathyQt/RequestableChannelClassSpecList>

Protocol::Protocol(const QDBusConnection &dbusConnection, const QString &name)
    : Tp::BaseProtocol(dbusConnection, name)
{
    setRequestableChannelClasses(Tp::RequestableChannelClassSpecList() <<
                                 Tp::RequestableChannelClassSpec::textChat() <<
                                 Tp::RequestableChannelClassSpec::audioCall());

    setCreateConnectionCallback(memFun(this, &Protocol::createConnection));
}

Tp::BaseConnectionPtr Protocol::createConnection(const QVariantMap &parameters, Tp::DBusError *error) {
    Q_UNUSED(error);
    return Tp::BaseConnection::create<oFonoConnection>(QDBusConnection::sessionBus(), "ofono", name().toLatin1(), parameters);
}
