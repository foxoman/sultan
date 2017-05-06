/*
 * messagehandler.h
 * Copyright 2017 - ~, Apin <apin.klas@gmail.com>
 *
 * This file is part of Turbin.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include "global_global.h"
#include <QList>

namespace LibG {

class Message;
class MessageBus;

class GLOBALSHARED_EXPORT MessageHandler
{
public:
    MessageHandler();
    virtual ~MessageHandler();
    void setMessageBus(MessageBus *bus);
    bool consumeMessage(Message *msg);
    void clearInterested();
    void sendMessage(Message *msg);

protected:
    MessageBus *mMessageBus;
    QList<int> mInterests;

    virtual void messageReceived(Message *msg) = 0;
};

}
#endif // MESSAGEHANDLER_H