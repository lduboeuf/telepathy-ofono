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

#ifndef VOICECALLPRIVATE_H
#define VOICECALLPRIVATE_H

#include <QDBusContext>

class VoiceCallPrivate : public QObject, protected QDBusContext {
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.ofono.VoiceCall")
public:
    VoiceCallPrivate(const QString &path, QObject *parent = 0);
    ~VoiceCallPrivate();
    QString objectPath() const;
Q_SIGNALS:
    void PropertyChanged(const QString &name, const QDBusVariant &value);
public Q_SLOTS:
    QVariantMap GetProperties();
    void SetProperty(const QString &name, const QDBusVariant &value);
    void Hangup();
    void Answer();
    void MockSetAlerting();
    void MockAnswer();
private:
    QVariantMap mProperties;
    QString mObjectPath;
};

extern QMap<QString, VoiceCallPrivate*> voiceCallData;
extern QMap<QString, QVariantMap> initialCallProperties;

#endif
