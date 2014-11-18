/****************************************************************************
**
** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://www.qt.io/licensing.  For further information
** use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file.  Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
****************************************************************************/

#ifndef TIMELINERENDERSTATE_H
#define TIMELINERENDERSTATE_H

#include <QSGNode>
#include "timelinerenderpass.h"

namespace QmlProfiler {
namespace Internal {

class TimelineRenderState {
public:
    TimelineRenderState(qint64 start, qint64 end, qreal scale, int numPasses);
    ~TimelineRenderState();

    qint64 start() const;
    qint64 end() const;
    qreal scale() const;

    TimelineRenderPass::State *passState(int i);
    const TimelineRenderPass::State *passState(int i) const;
    void setPassState(int i, TimelineRenderPass::State *state);

    QSGNode *expandedRowRoot() const;
    QSGNode *collapsedRowRoot() const;
    QSGNode *expandedOverlayRoot() const;
    QSGNode *collapsedOverlayRoot() const;

    bool isEmpty() const;

private:
    QSGNode *m_expandedRowRoot;
    QSGNode *m_collapsedRowRoot;
    QSGNode *m_expandedOverlayRoot;
    QSGNode *m_collapsedOverlayRoot;

    qint64 m_start;
    qint64 m_end;

    qreal m_scale;  // "native" scale, this stays the same through the life time of a state

    QVector<TimelineRenderPass::State *> m_passes;
};

}
}

#endif // TIMELINERENDERSTATE_H
