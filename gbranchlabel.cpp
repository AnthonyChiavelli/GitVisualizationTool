#include "gbranchlabel.h"


GBranchLabel::GBranchLabel(QGraphicsItem *parent) : QGraphicsItem(parent) {

}

QRectF GBranchLabel::boundingRect() const {
    return QRect(0,0, LABEL_WIDTH, LABEL_HEIGHT);
}


void GBranchLabel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

    // Render the rectangle
    renderLabelRectangle();

    // Render the text
    renderLabelText();
}

void GBranchLabel::renderLabelRectangle() {

}

void GBranchLabel::renderLabelText() {
    int i;
}

QString GBranchLabel::getBranchName() const { return branchName; }
void GBranchLabel::setBranchName(const QString &value) { branchName = value; }

GCommitNode *GBranchLabel::getAssociatedCommit() const { return associatedCommit; }
void GBranchLabel::setAssociatedCommit(GCommitNode *value) { associatedCommit = value; }



