#include "removeframecommand.h"

RemoveFrameCommand::RemoveFrameCommand(int removedFrame, Model *mod, QUndoCommand *parent) : QUndoCommand(parent)
{
    frameNumber = removedFrame;
    model = mod;
}

void RemoveFrameCommand::undo()
{

}

void RemoveFrameCommand::redo()
{
    model->removeFrameButtonClicked(frameNumber);
}
