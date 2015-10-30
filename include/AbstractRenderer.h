#ifndef ABSTRACTRENDERER_H
#define ABSTRACTRENDERER_H

#include "AbstractWindow.h"

class AbstractRenderer
{
    public:
        AbstractRenderer();
        virtual bool BindDisplay(AbstractWindow *_window) = 0;
        virtual ~AbstractRenderer();
    protected:
    private:
};

#endif // ABSTRACTRENDERER_H
