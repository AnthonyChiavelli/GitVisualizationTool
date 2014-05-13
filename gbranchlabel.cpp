#include <QGraphicsScene>
#include <QPainter>

#include "branch.h"
#include "gbranchlabel.h"
#include "gcommitnode.h"


GBranchLabel::GBranchLabel(QGraphicsItem *parent) : QGraphicsItem(parent) {
}

GBranchLabel::GBranchLabel(QString branchName){

    // Allow the object to be dragged around
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);

    this->branchName = branchName;
}

GBranchLabel::GBranchLabel(Branch *branch) {

    // Allow the object to be dragged around
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);

    this->branchName = QString(branch->getName().c_str());

}

QRectF GBranchLabel::boundingRect() const {
    return QRect(0,0, LABEL_WIDTH, LABEL_HEIGHT);
}

void GBranchLabel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

    // Render the rectangle
    this->renderLabelRectangle(painter);

    // Render the text
    this->renderLabelText(painter);
}

void GBranchLabel::renderLabelRectangle(QPainter *painter) {

    // Paint a rectangle
    painter->setBrush(LABEL_BG_COLOR);
    QRect rect = QRect(0, 0, LABEL_WIDTH, LABEL_HEIGHT);
    painter->drawRect(rect);
}

void GBranchLabel::renderLabelText(QPainter *painter) {

    // Set up font
    QFont font;
    int initialFontSize = 10;
    font.setPointSize(initialFontSize);

    // Branch name label metrics
    QFontMetrics fontMetrics(font);
    int labelTextWidth = fontMetrics.width(this->branchName);
    int labelTextHeight = fontMetrics.height();
    int labelHeightAdjustment = 13; // no idea why this is needed

    // Shrink down the text until it fits
    while(labelTextWidth > LABEL_WIDTH - 6) {
        // Don't go too small
        if (initialFontSize < 5) {
            // TODO handle extreme cases
            break;
        }
        font.setPointSize(--initialFontSize);
        QFontMetrics smallFontMetrics(font);
        labelTextWidth = smallFontMetrics.width(this->branchName);
        labelTextHeight = smallFontMetrics.height();
        labelHeightAdjustment--;
    }

    // Calculate margins necessary to center text in label
    int labelTextTopMargin = ((LABEL_HEIGHT - labelTextHeight) / 2) + labelHeightAdjustment;
    int labelTextLeftMargin = (LABEL_WIDTH - labelTextWidth) / 2;

    // Render the label
    painter->setBrush(LABEL_TEXT_COLOR);
    painter->setPen(LABEL_TEXT_COLOR);
    painter->setFont(font);
    QPointF labelTextPosition = QPointF(labelTextLeftMargin, labelTextTopMargin);
    painter->drawText(labelTextPosition, this->branchName);

}

QVariant GBranchLabel::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value) {

        // Get a pointer to our containing scene
        QGraphicsScene *thisScene = scene();
        // If this method is called before scene is set up, we'll get NULL
        if (thisScene != 0) {
            // Refresh everything in the scene
            thisScene->update();
        }

        // Pass along event
        return QGraphicsItem::itemChange(change, value);
}


void GBranchLabel::establishPosition(int branchNum) {
    // Situate label relative to commit node
    this->setPos(this->associatedCommit->sceneBoundingRect().right() +
                        BRANCH_LABEL_OFFSET + ((branchNum-1) * BRANCH_LABEL_DISTANCE), this->associatedCommit->sceneBoundingRect().top());
}

QString GBranchLabel::getBranchName() const { return branchName; }
void GBranchLabel::setBranchName(const QString &value) { branchName = value; }

GCommitNode *GBranchLabel::getAssociatedCommit() const { return associatedCommit; }
void GBranchLabel::setAssociatedCommit(GCommitNode *value) { associatedCommit = value; }
